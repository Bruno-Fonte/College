#include <stdio.h>
#include <locale.h>

int MenuImovel(){

	setlocale(LC_ALL, "Portuguese");
	system("cls");		//atualiza a tela
	
	int opi, opcaologin;
	
	//Menu apresentado para op��es de im�veis
	printf("[1] Cadastrar Im�veis\n[2] Alterar Im�veis\n[3] Excluir Im�veis\n[4] Exibir Im�veis\n[5] Exibir Im�veis (Personalizado)\n[6] Voltar\n[7] Sair\n\n");
	
	printf("Qual op��o desejada? "); scanf("%i", &opi); getchar();		//pergunta ao usu�rio a op��o desejada
	
	switch(opi){
		
		case 1:				//se for a op��o 1, opcaologin recebe o valor 11, que no menu.c chama a fun��o "CadastrarImovel"
			opcaologin = 11;	
			break;
		case 2:				//se for a op��o 2, opcaologin recebe o valor 12, que no menu.c chama a fun��o "AlterarImovel"
			opcaologin = 12;
			break;
		case 3:				//se for a op��o 3, opcaologin recebe o valor 13, que no menu.c chama a fun��o "ExcluirImovel"
			opcaologin = 13;
			break;
		case 4:				//se for a op��o 4, opcaologin recebe o valor 8, que no menu.c chama a fun��o "ExibirImovel"
			opcaologin = 8;
			break;
		case 5:				//se for a op��o 15, opcaologin recebe o valor 14, que no menu.c chama a fun��o "ExibirPersonalizado"
			opcaologin = 14;
			break;
		case 6:				//se for op��o 5, opcaologin recebe o valor 4, que no menu.c chama a fun��o do menu do administrador
			opcaologin = 4;
			break;
		case 7:				//se for op��o 6, opcaologin recebe o valor 99, que no menu.c encerra o programa
			system("cls");
			opcaologin = 99;
			break;
		default:			//default caso a op��o digitada pelo usu�rio seja incorreta
			system("cls");			//atualiza a tela
			printf("Op��o incorreta");
			printf("\n\nAperte uma tecla para voltar ao menu de im�veis");
			getch();
			opcaologin = 6;		//Caso entre no default, opcaologin recebe o valor 6, que no menu.c chama essa mesma fun��o
			break;
	}
	
	system("cls");
	return opcaologin;
	
}
