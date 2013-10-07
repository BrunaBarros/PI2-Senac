#ifdef _FUNCOES_H_

#define _FUNCOES_H_
#include "funcoes.c"
//Configurando teclado e mouse para funcionarem de acordo com o jogo.
void open_window();

//A escolha do sexo do personagem, caso o usuário
//escolha continuar de onde parou no ultimo jogo
//o resultado da escolha salva aqui será usada
void game_start();
int select_sex();
int sex_male();
int sex_famale();

//Após a seleção do usuário, vai ser chamada o sexo relacionado

void select_name();

//A seguinte função salva todas as escolhas do usuário até o momento.
void game_save();

//Essa escolha resgatara todas as informações do usuário
//de arquivos feitos a partir das primeiras escolhas
void game_load();

//Escolha da matéria que vai jogar e também o nivel.
void option_school();

int option_door();

//Aqui é definido a quantidade de experiencia que o usuário vai ganhar
//por acerto em cada jogo separadamente, cada nível vai ter uma quantidade
//de experiencia diferente.
void open_math();
int exp_math();
int key_math_lv2();
int key_math_lv3();

void open_ing();
int exp_ing();
int key_ing_lv2();
int key_ing_lv3();

void open_port();
int exp_port();
int key_port_lv2();
int key_port_lv3();

//Allegro Functions
//Essa função faz a checagem de todas as funções do allegro iniciadas, elá é executada somente uma vez.
int check_allegro(ALLEGRO_BITMAP *background, ALLEGRO_BITMAP *start_menu_img, ALLEGRO_EVENT_QUEUE *sections_event, ALLEGRO_DISPLAY *display, ALLEGRO_FONT *font_text, ALLEGRO_TIMER *timer, ALLEGRO_TIMER *tcont);

//Essa captura de evento ira devolver a ação feita pelo usuário.

int capture_event_queue(int SCREEN_H, int SCREEN_W, ALLEGRO_KEYBOARD *keyboard, ALLEGRO_DISPLAY *display, ALLEGRO_EVENT_QUEUE *sections_event, int teclado, ALLEGRO_FONT *font_text);

//Fecha todas as funções do allegro, consequentemente fecha o jogo.
void close_game(ALLEGRO_BITMAP *background, ALLEGRO_BITMAP *start_menu_img, ALLEGRO_EVENT_QUEUE *sections_event, ALLEGRO_DISPLAY *display, ALLEGRO_TIMER *timer, ALLEGRO_TIMER *tcont);

//Efeitos de transição
void fadeout(int velocidade, int largura, int altura, ALLEGRO_DISPLAY *display);
void fadein(int velocidade, ALLEGRO_BITMAP *imagem);

#endif