#include <locale.h>

int MenuFuncaoADM(){	
	
	setlocale(LC_ALL, "Portuguese");
	
	int opcaologin;
	system("cls");
	
	//Menu apresentado ao administrador
	printf("---Menu do Administrador---\n\n");
	
	printf("[1] Opções de imóvel");
	printf("\n[2] Opções de corretor");
	printf("\n[3] Opções de cliente");
	printf("\n[4] Simulação de financiamento");
	printf("\n[5] Voltar");
	printf("\n[6] Sair\n\n");
	printf("Escolha a opção desejada: ");
	
	scanf("%i", &opcaologin);
	
	//cases para retornar um valor ao menu.c
	switch(opcaologin){
		case 1:
			opcaologin = 6;
			break;
		case 2:	
			opcaologin = 9;
			break;
		case 3:
			opcaologin = 22;
			break;
		case 4:
			opcaologin = 7;
			break;
		case 5:
			opcaologin = 0;
			break;
		case 6:
			opcaologin = 99;
			break;	
			
		
		default:
			opcaologin = 4;
			printf("\n\nOpção inválida, aperte qualquer tecla para continuar");
			getch();
			break;
		}
	
	getchar();	
	system("cls");	
	return opcaologin;
}

