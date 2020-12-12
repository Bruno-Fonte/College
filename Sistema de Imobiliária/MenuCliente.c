#include <stdio.h>
#include <locale.h>

int MenuCliente(){
	
	setlocale(LC_ALL, "Portuguese");
	system("cls");

	int opc, opcaologin;
	
	//Menu apresentado para op��es de clientes
	printf("[1] Cadastrar Cliente\n[2] Alterar Cliente\n[3] Excluir Cliente\n[4] Exibir Cliente\n[5] Voltar\n[6] Sair\n\n"); 
	
	printf("Qual op��o desejada? "); scanf("%i", &opc); getchar();
	
	switch(opc){
		
		case 1:							//se for a op��o 1, opcaologin recebe 15, que no menu chama a fun��o para cadastrar corretor
			opcaologin = 23;
			break;
		case 2:							//se for a op��o 2, opcaologin recebe 16, que no menu chama a fun��o para alterar corretor
			opcaologin = 25;
			break;
		case 3:							//se for a op��o 3, opcaologin recebe 17, que no menu chama a fun��o para excluir corretor
			opcaologin = 26;
			break;
		case 4:							//se for a op��o 4, opcaologin recebe 18, que no menu chama a fun��o para exibir corretor
			opcaologin = 24;
			break;
		case 5:							//se for op��o 5, opcaologin recebe 4, que no menu chama a fun��o do menu do ADM
			opcaologin = 4;
			break;
		case 6:							//se for op��o 6, opcaologin recebe 99, que no menu encerra o programa
			system("cls");
			opcaologin = 99;
			break;
		default:
			system("cls");
			printf("Op��o incorreta");
			printf("\n\nAperte uma tecla para voltar ao menu de clientes");
			getch();
			opcaologin = 9;
			break;
	}
	
	return opcaologin;		//retorna o valor de opcaologin
}

int MenuClienteCorretor(){
	
	setlocale(LC_ALL, "Portuguese");
	system("cls");

	int opc, opcaologin;
	
	//Menu apresentado para op��es de clientes
	printf("[1] Cadastrar Cliente\n[2] Alterar Cliente\n[3] Excluir Cliente\n[4] Exibir Cliente\n[5] Voltar\n[6] Sair\n\n"); 
	
	printf("Qual op��o desejada? "); scanf("%i", &opc); getchar();
	
	switch(opc){
		
		case 1:							//se for a op��o 1, opcaologin recebe 15, que no menu.c chama a fun��o para cadastrar corretor
			opcaologin = 28;
			break;
		case 2:							//se for a op��o 2, opcaologin recebe 16, que no menu.c chama a fun��o para alterar corretor
			opcaologin = 29;
			break;
		case 3:							//se for a op��o 3, opcaologin recebe 17, que no menu.c chama a fun��o para excluir corretor
			opcaologin = 30;
			break;
		case 4:							//se for a op��o 4, opcaologin recebe 18, que no menu.c chama a fun��o para exibir corretor
			opcaologin = 31;
			break;
		case 5:							//se for op��o 5, opcaologin recebe 4, que no menu.c chama a fun��o do menu do ADM
			opcaologin = 3;
			break;
		case 6:							//se for op��o 6, opcaologin recebe 99, que no menu.c encerra o programa
			system("cls");
			opcaologin = 99;
			break;
		default:
			system("cls");
			printf("Op��o incorreta");
			printf("\n\nAperte uma tecla para voltar ao menu de clientes");
			getch();
			opcaologin = 9;
			break;
	}
	
	return opcaologin;		//retorna o valor de opcaologin
}
