#include <locale.h>

int MenuFuncao(){
	
	system("cls");
	
	setlocale(LC_ALL, "Portuguese");
	
	int opcaologin;
	
	//Menu apresentado ao corretor
	printf("---Menu do Corretor---\n\n");
	
	printf("[1] Simulação de financiamento");
	printf("\n[2] Imóveis cadastrados");
	printf("\n[3] Imóveis cadastrados (personalizado)");
	printf("\n[4] Opções de clientes");
	printf("\n[5] Voltar");
	printf("\n[6] Sair\n\n");
	printf("Escolha a opção desejada: ");
	
	//cases para retornar um valor ao menu.c
	scanf("%i", &opcaologin); getchar();
	
		switch(opcaologin){
				case 1:
					opcaologin = 21;
					break;
				case 2:
					opcaologin = 19;
					break;
				case 3:
					opcaologin = 20;
					break;
				case 4:
					opcaologin = 27;
					break;
				case 5:
					opcaologin = 0;
					break;
				case 6:
					opcaologin = 99;
					break;		
				default:
					opcaologin = 3;
					getch();
					break;
		}
			
	system("cls");	
	return opcaologin;
}
