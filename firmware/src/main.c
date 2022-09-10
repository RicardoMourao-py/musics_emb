#include <asf.h>

#include "gfx_mono_ug_2832hsweg04.h"
#include "gfx_mono_text.h"
#include "sysfont.h"

// Notes
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define REST      0

int mario_melody[] = {
	// Super Mario Bros theme
	// Score available at https://musescore.com/user/2123/scores/2145
	// Theme by Koji Kondo
	NOTE_E5,8, NOTE_E5,8, REST,8, NOTE_E5,8, REST,8, NOTE_C5,8, NOTE_E5,8, //1
	NOTE_G5,4, REST,4, NOTE_G4,8, REST,4,
	NOTE_C5,-4, NOTE_G4,8, REST,4, NOTE_E4,-4, // 3
	NOTE_A4,4, NOTE_B4,4, NOTE_AS4,8, NOTE_A4,4,
	NOTE_G4,-8, NOTE_E5,-8, NOTE_G5,-8, NOTE_A5,4, NOTE_F5,8, NOTE_G5,8,
	REST,8, NOTE_E5,4,NOTE_C5,8, NOTE_D5,8, NOTE_B4,-4,
	NOTE_C5,-4, NOTE_G4,8, REST,4, NOTE_E4,-4, // repeats from 3
	NOTE_A4,4, NOTE_B4,4, NOTE_AS4,8, NOTE_A4,4,
	NOTE_G4,-8, NOTE_E5,-8, NOTE_G5,-8, NOTE_A5,4, NOTE_F5,8, NOTE_G5,8,
	REST,8, NOTE_E5,4,NOTE_C5,8, NOTE_D5,8, NOTE_B4,-4,

	
	REST,4, NOTE_G5,8, NOTE_FS5,8, NOTE_F5,8, NOTE_DS5,4, NOTE_E5,8,//7
	REST,8, NOTE_GS4,8, NOTE_A4,8, NOTE_C4,8, REST,8, NOTE_A4,8, NOTE_C5,8, NOTE_D5,8,
	REST,4, NOTE_DS5,4, REST,8, NOTE_D5,-4,
	NOTE_C5,2, REST,2,

	REST,4, NOTE_G5,8, NOTE_FS5,8, NOTE_F5,8, NOTE_DS5,4, NOTE_E5,8,//repeats from 7
	REST,8, NOTE_GS4,8, NOTE_A4,8, NOTE_C4,8, REST,8, NOTE_A4,8, NOTE_C5,8, NOTE_D5,8,
	REST,4, NOTE_DS5,4, REST,8, NOTE_D5,-4,
	NOTE_C5,2, REST,2,

	NOTE_C5,8, NOTE_C5,4, NOTE_C5,8, REST,8, NOTE_C5,8, NOTE_D5,4,//11
	NOTE_E5,8, NOTE_C5,4, NOTE_A4,8, NOTE_G4,2,

	NOTE_C5,8, NOTE_C5,4, NOTE_C5,8, REST,8, NOTE_C5,8, NOTE_D5,8, NOTE_E5,8,//13
	REST,1,
	NOTE_C5,8, NOTE_C5,4, NOTE_C5,8, REST,8, NOTE_C5,8, NOTE_D5,4,
	NOTE_E5,8, NOTE_C5,4, NOTE_A4,8, NOTE_G4,2,
	NOTE_E5,8, NOTE_E5,8, REST,8, NOTE_E5,8, REST,8, NOTE_C5,8, NOTE_E5,4,
	NOTE_G5,4, REST,4, NOTE_G4,4, REST,4,
	NOTE_C5,-4, NOTE_G4,8, REST,4, NOTE_E4,-4, // 19
	
	NOTE_A4,4, NOTE_B4,4, NOTE_AS4,8, NOTE_A4,4,
	NOTE_G4,-8, NOTE_E5,-8, NOTE_G5,-8, NOTE_A5,4, NOTE_F5,8, NOTE_G5,8,
	REST,8, NOTE_E5,4, NOTE_C5,8, NOTE_D5,8, NOTE_B4,-4,

	NOTE_C5,-4, NOTE_G4,8, REST,4, NOTE_E4,-4, // repeats from 19
	NOTE_A4,4, NOTE_B4,4, NOTE_AS4,8, NOTE_A4,4,
	NOTE_G4,-8, NOTE_E5,-8, NOTE_G5,-8, NOTE_A5,4, NOTE_F5,8, NOTE_G5,8,
	REST,8, NOTE_E5,4, NOTE_C5,8, NOTE_D5,8, NOTE_B4,-4,

	NOTE_E5,8, NOTE_C5,4, NOTE_G4,8, REST,4, NOTE_GS4,4,//23
	NOTE_A4,8, NOTE_F5,4, NOTE_F5,8, NOTE_A4,2,
	NOTE_D5,-8, NOTE_A5,-8, NOTE_A5,-8, NOTE_A5,-8, NOTE_G5,-8, NOTE_F5,-8,
	
	NOTE_E5,8, NOTE_C5,4, NOTE_A4,8, NOTE_G4,2, //26
	NOTE_E5,8, NOTE_C5,4, NOTE_G4,8, REST,4, NOTE_GS4,4,
	NOTE_A4,8, NOTE_F5,4, NOTE_F5,8, NOTE_A4,2,
	NOTE_B4,8, NOTE_F5,4, NOTE_F5,8, NOTE_F5,-8, NOTE_E5,-8, NOTE_D5,-8,
	NOTE_C5,8, NOTE_E4,4, NOTE_E4,8, NOTE_C4,2,

	NOTE_E5,8, NOTE_C5,4, NOTE_G4,8, REST,4, NOTE_GS4,4,//repeats from 23
	NOTE_A4,8, NOTE_F5,4, NOTE_F5,8, NOTE_A4,2,
	NOTE_D5,-8, NOTE_A5,-8, NOTE_A5,-8, NOTE_A5,-8, NOTE_G5,-8, NOTE_F5,-8,
	
	NOTE_E5,8, NOTE_C5,4, NOTE_A4,8, NOTE_G4,2, //26
	NOTE_E5,8, NOTE_C5,4, NOTE_G4,8, REST,4, NOTE_GS4,4,
	NOTE_A4,8, NOTE_F5,4, NOTE_F5,8, NOTE_A4,2,
	NOTE_B4,8, NOTE_F5,4, NOTE_F5,8, NOTE_F5,-8, NOTE_E5,-8, NOTE_D5,-8,
	NOTE_C5,8, NOTE_E4,4, NOTE_E4,8, NOTE_C4,2,
	NOTE_C5,8, NOTE_C5,4, NOTE_C5,8, REST,8, NOTE_C5,8, NOTE_D5,8, NOTE_E5,8,
	REST,1,

	NOTE_C5,8, NOTE_C5,4, NOTE_C5,8, REST,8, NOTE_C5,8, NOTE_D5,4, //33
	NOTE_E5,8, NOTE_C5,4, NOTE_A4,8, NOTE_G4,2,
	NOTE_E5,8, NOTE_E5,8, REST,8, NOTE_E5,8, REST,8, NOTE_C5,8, NOTE_E5,4,
	NOTE_G5,4, REST,4, NOTE_G4,4, REST,4,
	NOTE_E5,8, NOTE_C5,4, NOTE_G4,8, REST,4, NOTE_GS4,4,
	NOTE_A4,8, NOTE_F5,4, NOTE_F5,8, NOTE_A4,2,
	NOTE_D5,-8, NOTE_A5,-8, NOTE_A5,-8, NOTE_A5,-8, NOTE_G5,-8, NOTE_F5,-8,
	
	NOTE_E5,8, NOTE_C5,4, NOTE_A4,8, NOTE_G4,2, //40
	NOTE_E5,8, NOTE_C5,4, NOTE_G4,8, REST,4, NOTE_GS4,4,
	NOTE_A4,8, NOTE_F5,4, NOTE_F5,8, NOTE_A4,2,
	NOTE_B4,8, NOTE_F5,4, NOTE_F5,8, NOTE_F5,-8, NOTE_E5,-8, NOTE_D5,-8,
	NOTE_C5,8, NOTE_E4,4, NOTE_E4,8, NOTE_C4,2,
	
	//game over sound
	NOTE_C5,-4, NOTE_G4,-4, NOTE_E4,4, //45
	NOTE_A4,-8, NOTE_B4,-8, NOTE_A4,-8, NOTE_GS4,-8, NOTE_AS4,-8, NOTE_GS4,-8,
	NOTE_G4,8, NOTE_D4,8, NOTE_E4,-2,
};

int melody[] = {
	  // Cantina BAnd - Star wars
	  // Score available at https://musescore.com/user/6795541/scores/1606876
	  NOTE_B4,-4, NOTE_E5,-4, NOTE_B4,-4, NOTE_E5,-4,
	  NOTE_B4,8,  NOTE_E5,-4, NOTE_B4,8, REST,8,  NOTE_AS4,8, NOTE_B4,8,
	  NOTE_B4,8,  NOTE_AS4,8, NOTE_B4,8, NOTE_A4,8, REST,8, NOTE_GS4,8, NOTE_A4,8, NOTE_G4,8,
	  NOTE_G4,4,  NOTE_E4,-2,
	  NOTE_B4,-4, NOTE_E5,-4, NOTE_B4,-4, NOTE_E5,-4,
	  NOTE_B4,8,  NOTE_E5,-4, NOTE_B4,8, REST,8,  NOTE_AS4,8, NOTE_B4,8,

	  NOTE_A4,-4, NOTE_A4,-4, NOTE_GS4,8, NOTE_A4,-4,
	  NOTE_D5,8,  NOTE_C5,-4, NOTE_B4,-4, NOTE_A4,-4,
	  NOTE_B4,-4, NOTE_E5,-4, NOTE_B4,-4, NOTE_E5,-4,
	  NOTE_B4,8,  NOTE_E5,-4, NOTE_B4,8, REST,8,  NOTE_AS4,8, NOTE_B4,8,
	  NOTE_D5,4, NOTE_D5,-4, NOTE_B4,8, NOTE_A4,-4,
	  NOTE_G4,-4, NOTE_E4,-2,
	  NOTE_E4, 2, NOTE_G4,2,
	  NOTE_B4, 2, NOTE_D5,2,

	  NOTE_F5, -4, NOTE_E5,-4, NOTE_AS4,8, NOTE_AS4,8, NOTE_B4,4, NOTE_G4,4,
};

int harry_potter_melody[] = {
	// Hedwig's theme fromn the Harry Potter Movies
	// Socre from https://musescore.com/user/3811306/scores/4906610
	
	REST, 2, NOTE_D4, 4,
	NOTE_G4, -4, NOTE_AS4, 8, NOTE_A4, 4,
	NOTE_G4, 2, NOTE_D5, 4,
	NOTE_C5, -2,
	NOTE_A4, -2,
	NOTE_G4, -4, NOTE_AS4, 8, NOTE_A4, 4,
	NOTE_F4, 2, NOTE_GS4, 4,
	NOTE_D4, -1,
	NOTE_D4, 4,

	NOTE_G4, -4, NOTE_AS4, 8, NOTE_A4, 4, //10
	NOTE_G4, 2, NOTE_D5, 4,
	NOTE_F5, 2, NOTE_E5, 4,
	NOTE_DS5, 2, NOTE_B4, 4,
	NOTE_DS5, -4, NOTE_D5, 8, NOTE_CS5, 4,
	NOTE_CS4, 2, NOTE_B4, 4,
	NOTE_G4, -1,
	NOTE_AS4, 4,
	
	NOTE_D5, 2, NOTE_AS4, 4,//18
	NOTE_D5, 2, NOTE_AS4, 4,
	NOTE_DS5, 2, NOTE_D5, 4,
	NOTE_CS5, 2, NOTE_A4, 4,
	NOTE_AS4, -4, NOTE_D5, 8, NOTE_CS5, 4,
	NOTE_CS4, 2, NOTE_D4, 4,
	NOTE_D5, -1,
	REST,4, NOTE_AS4,4,

	NOTE_D5, 2, NOTE_AS4, 4,//26
	NOTE_D5, 2, NOTE_AS4, 4,
	NOTE_F5, 2, NOTE_E5, 4,
	NOTE_DS5, 2, NOTE_B4, 4,
	NOTE_DS5, -4, NOTE_D5, 8, NOTE_CS5, 4,
	NOTE_CS4, 2, NOTE_AS4, 4,
	NOTE_G4, -1,
	
};

/************************************************************************/
/* Defines                                                              */
/************************************************************************/
// Buzzer 
#define BUZZER_PIO           PIOC
#define BUZZER_PIO_ID        ID_PIOC
#define BUZZER_PIO_IDX       13
#define BUZZER_PIO_IDX_MASK  (1u << BUZZER_PIO_IDX)

// Button play song
#define START_PIO            PIOA
#define START_PIO_ID         ID_PIOA
#define START_PIO_IDX        11
#define START_PIO_IDX_MASK   (1u << START_PIO_IDX)

// Button stop song
#define PAUSE_PIO           PIOC
#define PAUSE_PIO_ID        ID_PIOC
#define PAUSE_PIO_IDX		31
#define PAUSE_PIO_IDX_MASK  (1u << PAUSE_PIO_IDX)

// Button change song
#define SELECAO_PIO          PIOA
#define SELECAO_PIO_ID       ID_PIOA
#define SELECAO_PIO_IDX      19
#define SELECAO_PIO_IDX_MASK (1u << SELECAO_PIO_IDX)

// Led para o botão start/pause
#define LED_START_PIO           PIOC                
#define LED_START_PIO_ID        ID_PIOC       
#define LED_START_PIO_IDX       30                  
#define LED_START_PIO_IDX_MASK  (1 << LED_START_PIO_IDX)

/************************************************************************/
/* flags                                                                */
/************************************************************************/
volatile char flag_play = 0;
volatile char flag_pause = 0;
volatile char flag_change = 0;

/************************************************************************/
/* variaveis globais                                                    */
/************************************************************************/
int tempo_mario = 200;
int tempo = 140;
int tempo_harry_potter = 144;

/************************************************************************/
/* handler / callbacks                                                  */
/************************************************************************/

void start_callback(void) {
	flag_play = 1;
}

void pause_callback(void) {
	flag_pause = !flag_pause;
}


void selecao_callback(void) {
	flag_change += 1;
	if (flag_change > 2) {
		flag_change = 0;
	}
}

/************************************************************************/
/* funções                                                              */
/************************************************************************/
// Pisca led do botão start/stop
void blink_led_start_pause() {
	pio_clear(LED_START_PIO, LED_START_PIO_IDX_MASK); // 0
	delay_ms(500);
	pio_set(LED_START_PIO, LED_START_PIO_IDX_MASK);   // 1
}

void set_buzzer() {
	pio_set(BUZZER_PIO, BUZZER_PIO_IDX_MASK);
}

void clear_buzzer() {
	pio_clear(BUZZER_PIO, BUZZER_PIO_IDX_MASK);
}

// gera onde quadrada no pino do buzzer
void buzzer_test(int freq) {
	double t = 1E6/freq;
	set_buzzer(); // 1
	delay_us(t/2);
	clear_buzzer(); // 0
	delay_us(t/2);
}

void write_song(volatile char i) {
	if (i == 0) {
		gfx_mono_draw_string("           ", 30,5, &sysfont);
		gfx_mono_draw_string("Mario", 30,5, &sysfont);
	}
	else if (i == 1) {
		gfx_mono_draw_string("           ", 30,5, &sysfont);
		gfx_mono_draw_string("Star Wars", 30,5, &sysfont);
	} else {
		gfx_mono_draw_string("           ", 30,5, &sysfont);         
		gfx_mono_draw_string("Harry Potter", 30,5, &sysfont);
	}
}

void tone(int freq, int time){
	pio_clear(LED_START_PIO, LED_START_PIO_IDX_MASK); // 0
	int pulsos = (double) freq* (double) time/ 1000;
	for (int i = 0; i < pulsos; i++) {	
		buzzer_test(freq);
	}
	pio_set(LED_START_PIO, LED_START_PIO_IDX_MASK);   // 1
}

void play_song() {	
	int notes = sizeof(melody) / sizeof(melody[0]) / 2; // sizeof gives the number of bytes, each int value is composed of two bytes (16 bits)
	// there are two values per note (pitch and duration), so for each note there are four bytes
	int wholenote = (60000 * 4) / tempo; // this calculates the duration of a whole note in ms
	int divider = 0, noteDuration = 0;
	
	for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {
		if (!flag_pause) {
			// calculates the duration of each note
			divider = melody[thisNote + 1];
			noteDuration = (wholenote) / abs(divider);
			if (divider < 0) {
				noteDuration *= 1.5; // increases the duration in half for dotted notes
			}
			
			// we only play the note for 90% of the duration, leaving 10% as a pause
			tone(melody[thisNote], noteDuration);
			
			// Wait for the specief duration before playing the next note.
			delay_us(noteDuration);
			
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
					PIO_IT_EDGE,
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

/************************************************************************/
/* Main                                                                 */
/************************************************************************/
int main (void)
{
	board_init();
	sysclk_init();
	delay_init();

    // Init OLED
	gfx_mono_ssd1306_init();
  
    // Escreve na tela um circulo e um texto
    
	
	init();
	
  /* Insert application code here, after the board has been initialized. */
	while(1) {
		write_song(flag_change);
		if (flag_play) {
			play_song();
			flag_play = 0;		
		}
	}
}
