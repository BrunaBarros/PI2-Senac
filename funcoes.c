#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

//funções principais, exenciais para outras funções.

#define TRUE 1
#define FALSE 0

int sex_male(){
	printf("Select Male\n");
	return 0;
}
int sex_famale(){
	printf("Select Famale\n");
	return 1;
}
void game_start(){
	printf("Game Starting\n");
}
void game_load(){
	printf("Game Load\n");
}
void game_close(){
	printf("Game Close\n");
}

//---------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------


//funções.

int open_window(){
	printf("Hello World!\n Screen!\n");
}

//---------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------
/*void color_screen(int r, int g, int b){
al_clear_to_color(al_map_rgb(r,g,b));
//ALLEGRO_COLOR_SIZE(r, g, b);
//al_map_rgb(r,g,b);
}
*/
//---------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------

int select_sex(){
	int sexo = 0;
	scanf("%d", &sexo);
	switch(sexo){
		case 0:
			sex_male();
			return 0;
		break;
	//armazenamento de nome e escolha 
		case 1:
			sex_famale();
			return 1;
		break;
	//armazenamento de nome e escolha
	}
}

//---------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------

int option_school(){
	int school = 0;
	switch(school){

		case 0:
			return 0;
		
		break;

		case 1:

			return 1;

		break;

		case 2:

			return 2;

		break;

	}
}

//---------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------

void open_math(){
	printf("Select School Math\n");
}

//---------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------

void open_ing(){
	printf("Select School English\n");
}

//---------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------

void open_port(){
	printf("Select School Portuguese\n");
}

//---------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------
//close_game(background, start_menu_img, sections_event, display, timer, tcont);
void close_game(ALLEGRO_BITMAP *background, ALLEGRO_BITMAP *start_menu_img, ALLEGRO_EVENT_QUEUE *sections_event, ALLEGRO_DISPLAY *display, ALLEGRO_TIMER *timer, ALLEGRO_TIMER *tcont){


	al_destroy_bitmap(start_menu_img);
	al_destroy_bitmap(background);
	al_destroy_timer(timer);
	al_destroy_timer(tcont);
	al_destroy_event_queue(sections_event);
	al_destroy_display(display);

}


//---------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------

//Fazendo a verificação de erros.
int check_allegro(ALLEGRO_BITMAP *background, ALLEGRO_BITMAP *start_menu_img, ALLEGRO_EVENT_QUEUE *sections_event, ALLEGRO_DISPLAY *display, ALLEGRO_FONT *font_text, ALLEGRO_TIMER *timer, ALLEGRO_TIMER *tcont){

	if(!al_init()){
		fprintf(stderr, "Falha na inicialização do Allegro.\n");
		return -1;
	}
	
	if(!al_init_image_addon()){
		fprintf(stderr, "Falha na inicialização da biblioteca allegro_image.\n");
		return -1;
	}


	if(!display){
		fprintf(stderr, "Falha na inicialização da janela do jogo.\n");
		return -1;
	}

	if(!background){
		fprintf(stderr, "Falha ao carregar background.\n");
		return -1;
	}
	if(!start_menu_img){
		fprintf(stderr, "Falha ao carregar imagem do menu inicial\n" );
	}

	if(!sections_event){
		fprintf(stderr, "Falha nos eventos do jogo,\n");
		return -1;
	}

	if(!al_init_font_addon){
		fprintf(stderr, "Falha ao carregar a biblioteca com as fontes de texto do jogo.\n");
		return -1;
	}

	if(!font_text){
		fprintf(stderr, "Falha ao carregar as fontes de texto do jogo.\n");
	}

	if(!tcont){
		fprintf(stderr, "Falha ao criar contadores.\n");
		return -1;
	}

	return 1;
}
//---------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------

int capture_event_queue(int SCREEN_H, int SCREEN_W, ALLEGRO_KEYBOARD *keyboard, ALLEGRO_DISPLAY *display, ALLEGRO_EVENT_QUEUE *sections_event, int teclado, ALLEGRO_FONT *font_text){
	int key = 0;
	al_register_event_source(sections_event, al_get_display_event_source(display));
	al_flip_display();

		ALLEGRO_EVENT event;
		ALLEGRO_TIMEOUT timeout;
	while(TRUE){

		al_init_timeout(&timeout, 0.06);
	
		al_wait_for_event(sections_event, &event);
		
	
		if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
			return -1;
			break;
		}

		if(event.type == ALLEGRO_EVENT_KEY_DOWN){
			switch(event.keyboard.keycode){
				case ALLEGRO_KEY_UP:
					key = 1;
					printf("Seta = Cima\n");
					break;

				case  ALLEGRO_KEY_DOWN:
					key = 2;
					printf("Seta = Baixo\n");
					break;				

				case ALLEGRO_KEY_RIGHT:
					key = 3;
					printf("Seta = Direita\n");
					break;


				case ALLEGRO_KEY_LEFT:
					key = 4;
					printf("Seta = Esquerda\n");
					break;

			}
			return key;
		}
	}
}
//---------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------
void fadeout(int velocidade, int largura, int altura, ALLEGRO_DISPLAY *display){
	ALLEGRO_BITMAP *buffer = NULL;
	buffer = al_create_bitmap(largura, altura);
	al_set_target_bitmap(buffer);
	al_draw_bitmap(al_get_backbuffer(display), 0, 0, 0);
	al_set_target_bitmap(al_get_backbuffer(display));

	if(velocidade < 0)
		velocidade = 1;

	else if( velocidade > 15)
		velocidade = 15;

	float alfa;
	for(alfa = 0; alfa <=255; alfa += velocidade){
		al_clear_to_color(al_map_rgb(255 - alfa, 255 - alfa, 255 - alfa));
		//bool map_rgba = al_map_rgba( 255 - alfa, 255 - alfa, 255 - alfa, alfa);
		//al_draw_bitmap(buffer, map_rgba, 0, 0, 0);
		//al_draw_bitmap(buffer, al_map_rgba( 255 - alfa, 255 - alfa, 255 - alfa, alfa), 0, 0, 0);
		al_flip_display();
	}
	al_destroy_bitmap(buffer);
}
//---------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------
void fadein(int velocidade, ALLEGRO_BITMAP *imagem){
	/*if(velocidade < 0)
		velocidade = 1;

	else if(velocidade > 15)
		velocidade = 15;

	float alfa;

	for(alfa = 0; alfa <= 255; alfa += velocidade){
		al_clear_to_color(al_map_rgb(0, 0, 0));
		al_draw_bitmap(imagem,al_map_rgba(alfa, alfa, alfa, alfa)0, 0, 0, 0);
		al_flip_display();
		al_reset(0.005);
	}
	al_flip_display();*/
	printf("Hello\n");
}

//---------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------
void timeout(){
	
}