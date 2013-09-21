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



#endif