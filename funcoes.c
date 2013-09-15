#include <stdio.h>
#include <stdlib.h>
//#include <allegro5/allegro.h>

//funções principais, exenciais para outras funções.
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


//funções.

void open_window(){

	printf("Hello World!\n Screen!\n");

}

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

void open_math(){
	printf("Select School Math\n");
}

void open_ing(){
	printf("Select School English\n");
}

void open_port(){
	printf("Select School Portuguese\n");
}
