#include <stdio.h>
#include <locale.h>

int MenuCorretor(){
	
	setlocale(LC_ALL, "Portuguese");
	system("cls");

	int opc, opcaologin;
	
	//Menu apresentado para opções de corretores
	printf("[1] Cadastrar Corretor\n[2] Alterar Corretor\n[3] Excluir Corretor\n[4] Exibir Corretor\n[5] Voltar\n[6] Sair\n\n"); 
	
	printf("Qual opção desejada? "); scanf("%i", &opc); getchar();
	
	switch(opc){
		
		case 1:							//se for a opção 1, opcaologin recebe 15, que no menu chama a função para cadastrar corretor
			opcaologin = 15;
			break;
		case 2:							//se for a opção 2, opcaologin recebe 16, que no menu chama a função para alterar corretor
			opcaologin = 16;
			break;
		case 3:							//se for a opção 3, opcaologin recebe 17, que no menu chama a função para excluir corretor
			opcaologin = 17;
			break;
		case 4:							//se for a opção 4, opcaologin recebe 18, que no menu chama a função para exibir corretor
			opcaologin = 18;
			break;
		case 5:							//se for opção 5, opcaologin recebe 4, que no menu chama a função do menu do ADM
			opcaologin = 4;
			break;
		case 6:							//se for opção 6, opcaologin recebe 99, que no menu encerra o programa
			system("cls");
			opcaologin = 99;
			break;
		default:
			system("cls");
			printf("Opção incorreta");
			printf("\n\nAperte uma tecla para voltar ao menu de corretores");
			getch();
			opcaologin = 9;
			break;
	}
	
	return opcaologin;		//retorna o valor de opcaologin
}
