#include <allegro.h>
#include <stdio.h>
#include <stdlib.h>
#include "botao.h"

int main() {
	allegro_init();
	set_color_depth(32);
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, 1000, 600, 0, 0);
	install_keyboard();
	install_mouse();
	install_sound(DIGI_AUTODETECT,MIDI_AUTODETECT, NULL);
//	show_mouse(screen);
	
	BITMAP *buffer = create_bitmap(1000,600);
	BITMAP *boneco = load_bitmap("boneco.bmp", NULL);
	BITMAP *terra = load_bitmap("terran_up.bmp", NULL);
	BITMAP *pedro = load_bitmap("PEDRIN.bmp", NULL);
	SAMPLE *loucura = load_sample("loucura.wav");
	SAMPLE *risos = load_sample("risos.wav");
	SAMPLE *bateu = load_sample("bateu.wav");
	SAMPLE *fundo = load_sample("fundo.wav");
			
	int x,y;
	int a = 20, b = 20;
	int vx = 777;
	int pontosM=0, pontosT=0;
	int vitoriasM=0, vitoriasT=0;
	play_sample(risos, 70,128,1000, 1);
	
	
while (!key[KEY_ESC]) {	
//	textprintf_ex(screen, font, 350, 10, makecol(250,250,250), -1, "Pressione Enter para iniciar o jogo");
//	textprintf_ex(screen, font, 165, 35, makecol(150,10,210), -1, "O objetivo do player do teclado eh escapar e completar 1000 pontos para conseguir escapar");
//	textprintf_ex(screen, font, 200, 47, makecol(150,10,210), -1, "O objetivo do player do mouse eh bater no outro e acabar com a vida do inimigo");
	blit(pedro, screen, 0,0,0,0,1000,600);
//	textprintf_ex(screen, font, 928, 587, makecol(50,100,255), -1, "MilaMatos");

	while(key[KEY_ENTER]){
		destroy_sample(risos);
		play_sample(fundo, 160,128,1000, 1);
		while (!key[KEY_ESC]) {
			textprintf_ex(buffer, font, 0, 565, makecol(250,250,250), -1, "Contagem de VITORIAS");
			textprintf_ex(buffer, font, 0, 580, makecol(250,250,250), -1, "Mouse: %d", vitoriasM);
			textprintf_ex(buffer, font, 0, 590, makecol(250,250,250), -1, "Teclado: %d", vitoriasT);
			
			if (mouse_b & 1){
	 			x = mouse_x;
	 			y = mouse_y;
	 		}
	 				
		 	if(key[KEY_RIGHT])	a+=5;
			if(key[KEY_LEFT])	a-=5;
			if(key[KEY_UP])	b-=5;
			if(key[KEY_DOWN])	b+=5;	
						
						
			rect(buffer, 180,500, 777, 520, makecol(250,0,0));
			rectfill(buffer, 180,500, vx, 520, makecol(250,0,0));
			textprintf_ex(buffer, font, 550, 10, makecol(0,10,250), -1, "Mouse: %d", pontosM);
			textprintf_ex(buffer, font, 550, 25, makecol(250,10,0), -1, "Teclado: %d", pontosT);
		
		
			blit(boneco, buffer, 0,0,mouse_x,mouse_y,50,50);
			blit(terra, buffer, 0,0,a,b,50,50);
	
			
			if(mouse_x+20 >= a-20 && mouse_x-20 <= a+20 && mouse_y+20 >= b-20 && mouse_y-20 <= b+20) {
				play_sample(bateu, 190,128,1000, 0);
				textprintf_ex(buffer, font, 500, 10, makecol(40,40,160), -1, "Bateu");
				vx = vx-2;
				pontosM++;		
			}
			
			if(mouse_x+20 < a-20 || mouse_x-20 > a+20 || mouse_y+20 < b-20 || mouse_y-20> b+20) {
				textprintf_ex(buffer, font, 480, 10, makecol(160,40,40), -1, "Escapou");
				pontosT++;		
			}
									
			draw_sprite(screen, buffer, 0,0);
			rest(2);
			clear(buffer);
			
			if(pontosM == 300) {
				play_sample(loucura, 170,128,1000, 0);
				vitoriasM++;
				clear(buffer);
				while (!key[KEY_ESC]) {
					textprintf_ex(screen, font, 350, 10, makecol(0,10,250), -1, "Mouse ganhou");
					textprintf_ex(screen, font, 300, 40, makecol(250,250,250), -1, "Pressione Enter para iniciar novamente o jogo");
					if(key[KEY_ENTER]){
						vx = 777;
						pontosM = 0;
						pontosT = 0;
						break;
					}	
				}
			}
			
			if(pontosT == 1000) {
				play_sample(loucura, 170,128,1000, 0);
				vitoriasT++;
				clear(buffer);
				while (!key[KEY_ESC]) {
					textprintf_ex(screen, font, 350, 10, makecol(250,10,0), -1, "Teclado ganhou");
					textprintf_ex(screen, font, 300, 40, makecol(250,250,250), -1, "Pressione Enter para iniciar novamente o jogo");
					if(key[KEY_ENTER]){
						vx = 777;
						pontosM = 0;
						pontosT = 0;
						break;
					}
				}	
			}
		
		}
	}
	
}
	
	destroy_bitmap(pedro);
	destroy_sample(fundo);
	destroy_sample(risos);
	destroy_sample(loucura);
	destroy_bitmap(buffer);
	return 0;
}
END_OF_MAIN()
