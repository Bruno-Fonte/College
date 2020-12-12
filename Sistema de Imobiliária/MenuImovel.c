#include <stdio.h>
#include <locale.h>

int MenuImovel(){

	setlocale(LC_ALL, "Portuguese");
	system("cls");		//atualiza a tela
	
	int opi, opcaologin;
	
	//Menu apresentado para opções de imóveis
	printf("[1] Cadastrar Imóveis\n[2] Alterar Imóveis\n[3] Excluir Imóveis\n[4] Exibir Imóveis\n[5] Exibir Imóveis (Personalizado)\n[6] Voltar\n[7] Sair\n\n");
	
	printf("Qual opção desejada? "); scanf("%i", &opi); getchar();		//pergunta ao usuário a opção desejada
	
	switch(opi){
		
		case 1:				//se for a opção 1, opcaologin recebe o valor 11, que no menu.c chama a função "CadastrarImovel"
			opcaologin = 11;	
			break;
		case 2:				//se for a opção 2, opcaologin recebe o valor 12, que no menu.c chama a função "AlterarImovel"
			opcaologin = 12;
			break;
		case 3:				//se for a opção 3, opcaologin recebe o valor 13, que no menu.c chama a função "ExcluirImovel"
			opcaologin = 13;
			break;
		case 4:				//se for a opção 4, opcaologin recebe o valor 8, que no menu.c chama a função "ExibirImovel"
			opcaologin = 8;
			break;
		case 5:				//se for a opção 15, opcaologin recebe o valor 14, que no menu.c chama a função "ExibirPersonalizado"
			opcaologin = 14;
			break;
		case 6:				//se for opção 5, opcaologin recebe o valor 4, que no menu.c chama a função do menu do administrador
			opcaologin = 4;
			break;
		case 7:				//se for opção 6, opcaologin recebe o valor 99, que no menu.c encerra o programa
			system("cls");
			opcaologin = 99;
			break;
		default:			//default caso a opção digitada pelo usuário seja incorreta
			system("cls");			//atualiza a tela
			printf("Opção incorreta");
			printf("\n\nAperte uma tecla para voltar ao menu de imóveis");
			getch();
			opcaologin = 6;		//Caso entre no default, opcaologin recebe o valor 6, que no menu.c chama essa mesma função
			break;
	}
	
	system("cls");
	return opcaologin;
	
}
