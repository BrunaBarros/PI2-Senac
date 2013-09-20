#include <stdio.h>
#include <stdlib.h>
//#include "funcoes.c"
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
			game_status = 0;
		break;

		case 1:
			game_load();
			game_status = 1;
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

	//Escolhendo as portas

	if()


	return 0;
}