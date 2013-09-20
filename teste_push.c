#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"
#define TRUE 1
#define FALSE 0

int main(){
	int game_status = 0, option = 0, school = 0;

	//Nessa função todos os recursos do jogo serão instalados, como teclado, mouse etc...
	open_window();
	
	//Iniciando o jogo, escolhendo continuar de onde parou ou iniciar um novo jogo.
	printf("Menu Principal\n");
	scanf("%d", &option);
	switch(option){

		case 0:
			game_start();
		break;

		case 1:
			game_load();
		break;

		case 2:
			printf("Finalizando Jogo\n");
			return 0;
		break;
	}
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
	//Selecionando o nv, lembrando que se o usuário não estiver continuando um jogo, ele irá automaticamente para a primeira porta.
	printf("Selecione a porta\n");
	switch(door){
		case 0:
			open_door_1();
		break;
		case 1:
			open_door_2();
		break;
		case 2:
			open_door_();
		break;

	}

	return 0;
}