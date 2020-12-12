#include <locale.h>

int OpcaoLogin(){
	
	setlocale(LC_ALL, "Portuguese");
	
	int opcaologin;
	
	//Menu inicial
	system("cls");
	printf("[1] Login como corretor.");
	printf("\n[2] Login como administrador.");
	printf("\n\nEscolha o tipo de login: ");
	scanf("%i", &opcaologin); getchar();	
	
	if(opcaologin == 1 || opcaologin == 2){
		system("cls");	
		return opcaologin;						//Se a opção digitada for válida, retorna seu valor ao menu.c
	}
	else{ //
		printf("\nValor inválido, aperte qualquer tecla para tentar novamente");
		getch();
		return 0;								//Se não for válida, exibe mensagem de erro e retorna ao início
	}
	
}
