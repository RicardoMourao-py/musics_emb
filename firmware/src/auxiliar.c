/*
 * auxiliar.c
 *
 * Created: 10/09/2022 22:41:19
 *  Author: adney
 */ 

#include "auxiliar.h"
#include "asf.h"
#include "gfx_mono_ug_2832hsweg04.h"
#include "gfx_mono_text.h"
#include "sysfont.h"

/************************************************************************/
/* handler / callbacks                                                  */
/************************************************************************/
volatile char flag_play = 0;
volatile char flag_pause = 0;
volatile char flag_change = 0;
int i = 0;

void start_callback(void) {
	flag_play = 1;
}

void pause_callback(void) {
	flag_pause = !flag_pause;
}


void selecao_callback(void) {
	flag_change = 1;
}

/************************************************************************/
/* funções                                                              */
/************************************************************************/
void blink_led_start_pause() {
	pio_clear(LED_START_PIO, LED_START_PIO_IDX_MASK); 
	delay_ms(500);
	pio_set(LED_START_PIO, LED_START_PIO_IDX_MASK);   
}

void set_buzzer() {
	pio_set(BUZZER_PIO, BUZZER_PIO_IDX_MASK);
}

void clear_buzzer() {
	pio_clear(BUZZER_PIO, BUZZER_PIO_IDX_MASK);
}

void buzzer_test(int freq) {
	double t = 1E6/freq;
	set_buzzer(); // 1
	delay_us(t/2);
	clear_buzzer(); // 0
	delay_us(t/2);
}

void write_song(int i) {
	if (i == 0) {
		gfx_mono_draw_string("                   ", 10,2, &sysfont);
		gfx_mono_draw_string("mario", 10,2, &sysfont);
	}
	else if (i == 1) {
		gfx_mono_draw_string("                   ", 10,2, &sysfont);
		gfx_mono_draw_string("star wars", 10,2, &sysfont);
		} else {
		gfx_mono_draw_string("                   ", 10,2, &sysfont);
		gfx_mono_draw_string("harry potter", 10,2, &sysfont);
	}
}

void tone(int freq, int time){
	pio_clear(LED_START_PIO, LED_START_PIO_IDX_MASK); 
	int pulsos = (double) freq* (double) time/ 1000;
	for (int i = 0; i < pulsos; i++) {
		buzzer_test(freq);
	}
	pio_set(LED_START_PIO, LED_START_PIO_IDX_MASK);  
}

void change_song() {
	i+=1;
	if (i > 2) {
		i = 0;
	}
}

void create_struct (song *musica, int tempo, int *melody, int notes) {
	musica -> tempo = tempo;
	musica -> melody = &melody[0];
	musica -> notes = notes;
}

void play_song(song musica) {
	
	// there are two values per note (pitch and duration), so for each note there are four bytes
	int wholenote = (60000 * 4) / musica.tempo; // this calculates the duration of a whole note in ms
	int divider = 0, noteDuration = 0;
	
	int passos = musica.notes;
	int largura_pixel = comprimento_barra/passos;
	int cont  = 1;
	
	for (int thisNote = 0; thisNote < musica.notes * 2; thisNote = thisNote + 2) {
		if (!flag_pause) {
			// calculates the duration of each note
			divider = musica.melody[thisNote + 1];
			noteDuration = (wholenote) / abs(divider);
			if (divider < 0) {
				noteDuration *= 1.5; // increases the duration in half for dotted notes
			}
			
			// we only play the note for 90% of the duration, leaving 10% as a pause
			tone(musica.melody[thisNote], noteDuration);
			
			// Wait for the specief duration before playing the next note.
			delay_us(noteDuration);
			
			gfx_mono_draw_rect(x_barra+1, y_barra+1, ((double)comprimento_barra/musica.notes*cont)+1, 2, GFX_PIXEL_SET);
			cont++;
			
			} else {
			thisNote = thisNote - 2;
		}
	}
}

void init(void){
	// Initialize the board clock
	sysclk_init();

	// Desativa WatchDog Timer
	WDT->WDT_MR = WDT_MR_WDDIS;
	
	pmc_enable_periph_clk(LED_START_PIO_ID);
	pio_set_output(LED_START_PIO, LED_START_PIO_IDX_MASK, 0, 0, 0);
	pio_set(LED_START_PIO, LED_START_PIO_IDX_MASK);
	
	// Buzzer configures
	pmc_enable_periph_clk(BUZZER_PIO_ID);
	pio_set_output(BUZZER_PIO, BUZZER_PIO_IDX_MASK, 0, 0, 0);
	pio_pull_up(BUZZER_PIO, BUZZER_PIO_IDX_MASK, 1);
	
	pmc_enable_periph_clk(START_PIO_ID);
	pmc_enable_periph_clk(PAUSE_PIO_ID);
	pmc_enable_periph_clk(SELECAO_PIO_ID);
	
	pio_configure(START_PIO, PIO_INPUT, START_PIO_IDX_MASK, PIO_PULLUP | PIO_DEBOUNCE);
	pio_configure(SELECAO_PIO, PIO_INPUT, SELECAO_PIO_IDX_MASK, PIO_PULLUP | PIO_DEBOUNCE);
	pio_configure(PAUSE_PIO, PIO_INPUT, PAUSE_PIO_IDX_MASK, PIO_PULLUP | PIO_DEBOUNCE);
	
	pio_set_debounce_filter(START_PIO, START_PIO_IDX_MASK, 60);
	pio_set_debounce_filter(SELECAO_PIO, SELECAO_PIO_IDX_MASK, 60);
	pio_set_debounce_filter(PAUSE_PIO_IDX_MASK, PAUSE_PIO_IDX_MASK, 60);
	
	// Handlers
	pio_handler_set(START_PIO,
	START_PIO_ID,
	START_PIO_IDX_MASK,
	PIO_IT_FALL_EDGE,
	start_callback);
	
	pio_handler_set(PAUSE_PIO,
	PAUSE_PIO_ID,
	PAUSE_PIO_IDX_MASK,
	PIO_IT_FALL_EDGE,
	pause_callback);
	
	pio_handler_set(SELECAO_PIO,
	SELECAO_PIO_ID,
	SELECAO_PIO_IDX_MASK,
	PIO_IT_FALL_EDGE,
	selecao_callback);
	
	pio_enable_interrupt(START_PIO, START_PIO_IDX_MASK);
	pio_enable_interrupt(PAUSE_PIO, PAUSE_PIO_IDX_MASK);
	pio_enable_interrupt(SELECAO_PIO, SELECAO_PIO_IDX_MASK);
	
	pio_get_interrupt_status(START_PIO);
	pio_get_interrupt_status(PAUSE_PIO);
	pio_get_interrupt_status(SELECAO_PIO);
	
	NVIC_EnableIRQ(START_PIO_ID);
	NVIC_SetPriority(START_PIO_ID, 4);
	
	NVIC_EnableIRQ(PAUSE_PIO_ID);
	NVIC_SetPriority(PAUSE_PIO_ID, 4);
	
	NVIC_EnableIRQ(SELECAO_PIO_ID);
	NVIC_SetPriority(SELECAO_PIO_ID, 4);
}