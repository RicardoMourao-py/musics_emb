#include <asf.h>


#include "mario.h"
#include "star_wars.h"
#include "harry_potter.h"
#include "notes.h"

#include "auxiliar.h"

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
   
	init();
	
	song mario;
	song star_wars;
	song harry_potter;
	
	create_struct(&mario, tempo_mario, mario_melody, sizeof(mario_melody) / sizeof(mario_melody[0]) / 2);
	create_struct(&star_wars, tempo_star_wars, star_wars_melody, sizeof(star_wars_melody) / sizeof(star_wars_melody[0]) / 2);
	create_struct(&harry_potter, tempo_harry_potter, harry_potter_melody, sizeof(harry_potter_melody) / sizeof(harry_potter_melody[0]) / 2);
	
	song songs[3] = {mario, star_wars, harry_potter};
	
	//int i = 0;
	
	write_song(i);
	while(1) {
		if (flag_change) {
			change_song();
			write_song(i);
			flag_change = 0;
		}
		if (flag_play) {
			play_song(songs[i]);
			gfx_mono_draw_rect(x_barra+2, y_barra+1, 80, 2, GFX_PIXEL_CLR);
			flag_play = 0;		
		}
	}
}
