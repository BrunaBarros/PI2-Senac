#include <stdio.h>
#include <allegro/allegre5>

void open_window(){}

void first_menu(){
}

void options_first_menu(int option){

	if(option == 0){
		start();
	}
	else if(option == 1){
		load();
	}
	else{
		close();
	}
}