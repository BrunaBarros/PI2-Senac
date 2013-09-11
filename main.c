#include <stdio.h>
#include "funcoes.h"
#define NAME 10
int main(){
	int sexo = 0, escola = 0, porta = 0, salve = 0; 
	char nome[NAME];

	//Iniciando o jogo, escolhendo continuar de onde parou ou iniciar um novo jogo.
	open_window();

	first_menu(salve);

	printf("\n0 - INICIAR NOVO JOGO\n1 - CONTINUAR\n2 - SAIR\n");
	/* caso tenha o armazenamento de fases --- 
	tentar não ultilizar o  Zero como escolha, pois não é comum em jogos e usuários não são programadores */
	scanf("%d", &option);
	
	if(option == 0){
		if(sexo == 0)
			sex_male();
//--------------------------------------armazenamento de nome e escolha 
		else
			sex_famale();
//--------------------------------------armazenamento de nome e escolha
		option_name();

		scanf("%d", &escola);

// -------------- declara variavel e usa o SWITH CASE é melhor para essa quantidade de escolha, vai deixar o código mais legível 
// -------------  deixar a ordem das escolhas no programa, na ordem do jogo em si, MIP , matemática, inglês e português
		if(escola == 0){
			open_math();
		}
		else if(escola == 1){
			open_port();
		}

		else{
			open_ing();

		}
	}

	else if(option == 1){
		menu_load();

	}

	else
		close();

	return 0;
}