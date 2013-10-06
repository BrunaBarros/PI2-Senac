#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "funcoes.h"

//#include <allegro5/events.h>
#define TRUE 1
#define FALSE 0

	const int SCREEN_W = 800;
	const int SCREEN_H = 600;
	
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_BITMAP *background = NULL;
	ALLEGRO_BITMAP *start_menu_img = NULL;
	ALLEGRO_EVENT_QUEUE *sections_event = NULL;
	ALLEGRO_FONT *font_text = NULL;
	ALLEGRO_TIMER *timer = NULL, *tcont = 0;
	ALLEGRO_KEYBOARD *keyboard = NULL;


//---------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------
void menu_background(){
	al_draw_bitmap(start_menu_img, 0, 0, 0);
	al_flip_display();
}
//---------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------

void capture_event();

//---------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------

int main(){
	//variaveis que tem alguma coisa a ver com o jogados, como exp recebida e level
	int game_status = 0, option = 0, school = 0;

//---------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------

	//Variaveis internas relacionadas as bibliotecas usadas e erros do jogo em si.
	int status_allegro = 0, tecla = 0;
	//A variavel teclado tem 5 estados
	/*
	0 - Neutro
	1 - Tecla para cima
	2 - Tecla para Baixo
	3 - Tecla para Direita
	4 - Tecla para Esquerda
	*/
	

	//iniciando o Allegro e todos as suas bibliotecas e funções usadas.
	al_init();
	al_init_image_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_install_keyboard();

	//Iniciando o jogo.

	display = al_create_display(SCREEN_W, SCREEN_H);
	background = al_load_bitmap("img/background.jpg");
	start_menu_img = al_load_bitmap("img/start_screen.jpg");
	font_text = al_load_font("font/font.ttf", 50, 0);
	timer = al_create_timer(0.1);
	tcont = al_create_timer(1.0);
	sections_event = al_create_event_queue();

	al_set_window_title(display, "M.I.P. - Matemática, Português e Inglês");


	al_start_timer(timer);
	al_start_timer(tcont);

	//Qualquer valor que seja colocado apos a imagem, ira interferir na sua posição em relação a tela.
	al_draw_bitmap(background, 0,0,0);
	al_flip_display();

	//Verificando erros no allegro e suas bibliotecas.
	status_allegro = check_allegro(background, start_menu_img, sections_event, display, font_text, timer, tcont);

	if(status_allegro == -1){
		close_game(background, start_menu_img, sections_event, display, timer, tcont);
		return 0;
	}

	al_register_event_source(sections_event, al_get_keyboard_event_source());
	al_register_event_source(sections_event, al_get_display_event_source(display));


//---------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------


	menu_background();

	printf("Menu Principal\n");

	//capture_event();

	al_flip_display();

	al_draw_textf(font_text, al_map_rgb(0, 255, 255), SCREEN_H / 4, SCREEN_W / 4, ALLEGRO_ALIGN_LEFT, "Novo Jogo");
	al_draw_textf(font_text, al_map_rgb(0, 255, 255), SCREEN_H / (3.7), SCREEN_W / 3, ALLEGRO_ALIGN_LEFT, "Continuar");
	al_draw_textf(font_text, al_map_rgb(0, 255, 255), SCREEN_H / (3.4), SCREEN_W / (2.5), ALLEGRO_ALIGN_LEFT, "Sair do jogo");

	al_flip_display();


	option = capture_event_queue(SCREEN_H, SCREEN_W, keyboard, display, sections_event, tecla, font_text);

	if(option == -1){
		close_game(background, start_menu_img, sections_event, display, timer, tcont);
		return 0;
	}
	switch(option){

		case 0:
			game_start();
			printf("game_start\n");
		break;

		case 1:
			game_load();
			printf("game_load\n");
		break;

		case 2:

			printf("Finalizando Jogo\n");
			close_game(background, start_menu_img, sections_event, display, timer, tcont);
			return 0;
		break;
	}

//---------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------

	//Apos a escolha entre continuar ou começar novamente o usuário estará na tela de seleção de escolas
	printf("Selecione a escola\n");
	scanf("%d", &school);
	switch(school){
		case 0:
			open_math();
		break;

		case 1:
			open_ing();
		break;

		case 2:
			open_port();
		break;
	}
//---------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------
	return 0;
}