#ifdef FUNCOES
#define FUNCOES
#include "funcoes.c"
//Configurando teclado e mouse para funcionarem de acordo com o jogo.
void open_window();

//Opções iniciais para que o usuário possa fazer as configurações
//do personagem.
void first_menu();
void options_first_menu();
void sex_male();
void sex_famele();
void select_name();
void load();

//Escolha da matéria que vai jogar e também o nével.
void option_school();

void option_door();

//Aqui é definido a quantidade de experiencia que o usuário vai ganhar
//por acerto em cada jogo separadamente, cada nível vai ter uma quantidade
//de experiencia diferente.
void exp_math();
void key_math_lv2();
void key_math_lv3();

void exp_port();
void key_port_lv2();
void key_port_lv3();

void exp_ing();
void key_ing_lv2();
void key_ing_lv3();


#endif