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
		return opcaologin;						//Se a op��o digitada for v�lida, retorna seu valor ao menu.c
	}
	else{ //
		printf("\nValor inv�lido, aperte qualquer tecla para tentar novamente");
		getch();
		return 0;								//Se n�o for v�lida, exibe mensagem de erro e retorna ao in�cio
	}
	
}
