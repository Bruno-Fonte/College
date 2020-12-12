#include <stdio.h>
#include <locale.h>

//fun��o para exibir os im�veis cadastrados
int ExibirImovel(){	//fun��o void sem par�metro
	
	setlocale(LC_ALL, "Portuguese");
	system("cls");		//atualiza a tela
	
	int contador, contadorarq, metragem, qtd_comodos, valor, sair, tipo, aluguel;
	char endereco[300], proprietario[300], ponto_referencia[300];
	
	FILE* arquivo;
	FILE* contador_arquivo;
	
	arquivo = fopen("imoveis.txt", "r");		//abre o arquivo em modo leitura
	contador_arquivo = fopen("contadorimoveis.txt", "r");		//abre um arquivo em modo leitura para salvar a refer�ncia 
	
	fscanf(contador_arquivo, "%i", &contadorarq);				//l� o valor dentro do arquivo de contador da quantidade de im�veis
	
	printf("Quantidade de im�veis cadastrados: %i\n\n", contadorarq);
	
	if(contadorarq != 0){
		while(!feof(arquivo)){
			fscanf(arquivo, "%i %s %s %i %i %i %i %s %i\n", &tipo, proprietario, endereco, &valor, &aluguel, &metragem, &qtd_comodos, ponto_referencia, &contador);
			
			colocarEspaco(ponto_referencia);	//chama a fun��o "colocarEspaco" para trocar o '+' pelo espa�o
			colocarEspaco(proprietario);
			colocarEspaco(endereco);
			
			printf("Refer�ncia do im�vel: %i\n", contador);
			
			if(tipo == 1){
				printf("Tipo de im�vel: Residencial\n");
			}
			else{
				printf("Tipo de im�vel: Comercial\n");
			}
			
			printf("Nome do propriet�rio: %s\n", proprietario);
			
			printf("Endere�o: %s\n", endereco);
			
			printf("Valor do im�vel: R$ %i,00\n", valor);
			
			printf("Valor para aluguel: R$ %i,00\n", aluguel);
			
			printf("Metragem do Im�vel: %i m�\n", metragem);
			
			printf("Quantidades de c�modos: %i\n", qtd_comodos);
			
			printf("Ponto de refer�ncia: %s\n", ponto_referencia);
			printf("\n");
		}
	}
	else{
		printf("N�o h� im�veis cadastrados\n");
	}
	
	fclose(arquivo);
	fclose(contador_arquivo);
	
	//Ao final, o usu�rio escolhe voltar ao menu anterior ou sair
	do{
		printf("\n[1] Voltar ao menu de im�veis\n[2] Sair\n\nQual op��o desejada? "); scanf("%i", &sair); getchar();
		
		if(sair == 1){
			return 6;
		}
		else{
			if(sair == 2){
				return 99;
			}
			else{
				printf("Valor inv�lido, aperte qualquer tecla para tentar novamente");
				getch();
			}
		}
	}
	
	while(sair != 1 || sair != 2);
}

//fun��o para exibir os im�veis cadastrados sem retornar valor
//para os casos de alterar e excluir, para o usu�rio ver os imoveis
//cadastrados e selecionar qual deseja fazer a altera��o
//ou exclus�o
void ExibirImovel_Alterar_Excluir(){	//fun��o void sem par�metro
	
	setlocale(LC_ALL, "Portuguese");
	system("cls");		//atualiza a tela
	
	int contador, contadorarq, metragem, qtd_comodos, valor, aluguel, tipo, sair;
	char endereco[300], proprietario[300], ponto_referencia[300];
	
	FILE* arquivo;
	FILE* contador_arquivo;
	
	arquivo = fopen("imoveis.txt", "r");		//abre o arquivo em modo leitura
	contador_arquivo = fopen("contadorimoveis.txt", "r");		//abre um arquivo em modo leitura para salvar a refer�ncia 
	
	fscanf(contador_arquivo, "%i", &contadorarq);				//l� o valor dentro do arquivo de contador da quantidade de im�veis
	
	printf("Quantidade de im�veis cadastrados: %i\n\n", contadorarq);
	
	if(contadorarq != 0){
		while(!feof(arquivo)){
			fscanf(arquivo, "%i %s %s %i %i %i %i %s %i\n", &tipo, proprietario, endereco, &valor, &aluguel, &metragem, &qtd_comodos, ponto_referencia, &contador);
			
			colocarEspaco(ponto_referencia);	//chama a fun��o "colocarEspaco" para trocar o '+' pelo espa�o
			colocarEspaco(proprietario);
			colocarEspaco(endereco);
			
			printf("Refer�ncia do im�vel: %i\n", contador);
			
			if(tipo == 1){
				printf("Tipo de im�vel: Residencial\n");
			}
			else{
				printf("Tipo de im�vel: Comercial\n");
			}
			
			printf("Nome do propriet�rio: %s\n", proprietario);
			
			printf("Endere�o: %s\n", endereco);
			
			printf("Valor do im�vel: R$ %i,00\n", valor);
			
			printf("Valor para aluguel: R$ %i,00\n", aluguel);
			
			printf("Metragem do Im�vel: %i m�\n", metragem);
			
			printf("Quantidades de c�modos: %i\n", qtd_comodos);
			
			printf("Ponto de refer�ncia: %s\n", ponto_referencia);
			printf("\n");
		}
	}
	else{
		printf("\nN�o h� im�veis cadastrados\n");
	}
	
	fclose(arquivo);
	fclose(contador_arquivo);
}

//fun��o que, no fim, retorna ao menu do corretor
int ExibirImovel_Corretor(){	//fun��o void sem par�metro
	
	setlocale(LC_ALL, "Portuguese");
	system("cls");		//atualiza a tela
	
	int contador, contadorarq, metragem, qtd_comodos, valor, aluguel, tipo, sair;
	char endereco[300], proprietario[300], ponto_referencia[300];
	
	FILE* arquivo;
	FILE* contador_arquivo;
	
	arquivo = fopen("imoveis.txt", "r");		//abre o arquivo em modo leitura
	contador_arquivo = fopen("contadorimoveis.txt", "r");		//abre um arquivo em modo leitura para salvar a refer�ncia 
	
	fscanf(contador_arquivo, "%i", &contadorarq);				//l� o valor dentro do arquivo de contador da quantidade de im�veis
	
	printf("Quantidade de im�veis cadastrados: %i\n\n", contadorarq);
	
	if(contadorarq != 0){
		while(!feof(arquivo)){
			fscanf(arquivo, "%i %s %s %i %i %i %s %i\n", &tipo, proprietario, endereco, &valor, &aluguel, &metragem, &qtd_comodos, ponto_referencia, &contador);
			
			colocarEspaco(ponto_referencia);	//chama a fun��o "colocarEspaco" para trocar o '+' pelo espa�o
			colocarEspaco(proprietario);
			colocarEspaco(endereco);
			
			printf("Refer�ncia do im�vel: %i\n", contador);
			
			if(tipo == 1){
				printf("Tipo de im�vel: Residencial\n");
			}
			else{
				printf("Tipo de im�vel: Comercial\n");
			}
			
			printf("Nome do propriet�rio: %s\n", proprietario);
			
			printf("Endere�o: %s\n", endereco);
			
			printf("Valor do im�vel: R$ %i,00\n", valor);
			
			printf("Valor para aluguel: R$ %i,00\n", aluguel);
			
			printf("Metragem do Im�vel: %i m�\n", metragem);
			
			printf("Quantidades de c�modos: %i\n", qtd_comodos);
			
			printf("Ponto de refer�ncia: %s\n", ponto_referencia);
			printf("\n");
		}
	}
	else{
		printf("\nN�o h� im�veis cadastrados\n");
	}
	
	fclose(arquivo);
	fclose(contador_arquivo);
	
	//Ao final, o usu�rio escolhe voltar ao menu anterior ou sair
	do{
		printf("\n[1] Voltar ao menu do corretor\n[2] Sair\n\nQual op��o desejada? "); scanf("%i", &sair); getchar();
		
		if(sair == 1){
			return 3;
		}
		else{
			if(sair == 2){
				return 99;
			}
			else{
				printf("Valor inv�lido, aperte qualquer tecla para tentar novamente");
				getch();
			}
		}
	}
	
	while(sair != 1 || sair != 2);
}
