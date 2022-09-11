/*
 * auxiliar.h
 *
 * Created: 10/09/2022 22:43:53
 *  Author: adney
 */ 


#ifndef AUXILIAR_H_
#define AUXILIAR_H_

#include "asf.h"
#include "gfx_mono_ug_2832hsweg04.h"
#include "gfx_mono_text.h"
#include "sysfont.h"

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

// Progress bar
#define comprimento_barra 80
#define largura_barra 4
#define x_barra 29
#define y_barra 22

/************************************************************************/
/* structs                                                              */
/************************************************************************/
typedef struct {
	int tempo;
	int *melody;
	int notes;
} song;

/************************************************************************/
/* flags                                                                */
/************************************************************************/
extern volatile char flag_play;
extern volatile char flag_pause;
extern volatile char flag_change;
extern int i;
/************************************************************************/
/* variaveis globais                                                    */
/************************************************************************/
#define tempo_mario 200
#define tempo_star_wars 140
#define tempo_harry_potter 144


/************************************************************************/
/* prototypes                                                           */
/************************************************************************/
void start_callback(void);
void pause_callback(void);
void selecao_callback(void);
void blink_led_start_pause(void);
void set_buzzer(void);
void clear_buzzer(void);
void buzzer_test(int freq);
void write_song(int i);
void tone(int freq, int time);
void change_song();
void create_struct (song *musica, int tempo, int *melody, int notes);
void play_song(song musica);
void init(void);


#endif /* AUXILIAR_H_ */