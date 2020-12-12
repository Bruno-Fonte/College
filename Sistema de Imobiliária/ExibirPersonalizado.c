#include <stdio.h>
#include <locale.h>

int ExibirPersonalizado(){
	
	setlocale(LC_ALL, "Portuguese");
	system("cls");
	
	FILE* arquivo;
	int c, op1, opp, opc, opm, opt, sair;
	
	int metragem, qtd_comodos, valor, contador, aluguel, tipo;
	char endereco[300], proprietario[300], ponto_referencia[300];
	
	arquivo = fopen("imoveis.txt", "r");
	
	c = 0;
	
	printf("[1] Filtrar por pre�o\n[2] Filtrar por quantidade de c�modos\n[3] Filtrar por metragem\n[4] Filtrar por tipo\n[5] Voltar\n[6] Sair");
	printf("\n\nQual op��o desejada? "); scanf("%i", &op1); getchar();
	
	//primeiro switch para as op��es do menu acima
	switch(op1){
		
		case 1:
			
			system("cls");
			
			printf("Digite o valor m�ximo do im�vel a ser pesquisado: R$ "); scanf("%i", &opp); getchar();
			
			system("cls");
			
			while(!feof(arquivo)){
					
				fscanf(arquivo, "%i %s %s %i %i %i %i %s %i\n", &tipo, proprietario, endereco, &valor, &aluguel, &metragem, &qtd_comodos, ponto_referencia, &contador);
					
				if(valor <= opp){
					
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
					
					c++;	//contador para controlar quantos im�veis foram exibidos
					
					}
				}
				
				if(c == 0){
					system("cls");
					printf("N�o h� im�veis com valor menor que %i cadastrados\n", opp);		//se nenhum im�vel foi exibido exibe essa mensagem
				}
			
			break;
		
		case 2:
			
			system("cls");
			
			printf("Digite o n�mero de c�modos m�ximo a ser pesquisado: "); scanf("%i", &opc); getchar();
			
			system("cls");
			
			while(!feof(arquivo)){
					
				fscanf(arquivo, "%i %s %s %i %i %i %i %s %i\n", &tipo, proprietario, endereco, &valor, &aluguel, &metragem, &qtd_comodos, ponto_referencia, &contador);
					
				if(qtd_comodos <= opc){
					
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
					
					c++;	//contador para controlar quantos im�veis foram exibidos
					
					}
				}
				
				if(c == 0){
					system("cls");
					printf("N�o h� im�veis com %i c�modos ou menos cadastrados\n", opc);		//se nenhum im�vel foi exibido exibe essa mensagem
				}
			
			break;
			
		case 3:
			
			system("cls");
			
			printf("Digite o valor m�ximo de metragem a ser pesquisado: "); scanf("%i", &opm); getchar();
			
			system("cls");
			
			while(!feof(arquivo)){
					
				fscanf(arquivo, "%i %s %s %i %i %i %i %s %i\n", &tipo, proprietario, endereco, &valor, &aluguel, &metragem, &qtd_comodos, ponto_referencia, &contador);
					
				if(metragem <= opm){
					
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
					
					c++;		//contador para controlar quantos im�veis foram exibidos
					
					}
				}
				
			if (c == 0){
				system("cls");
				printf("N�o h� im�veis com menos de %i m� cadastrados\n", opm);		//se nenhum im�vel foi exibido exibe essa mensagem
			}
			break;
			
		case 4:
			
			system("cls");
			
			printf("[1] Residencial\n[2] Comercial\n\nDigite o tipo de im�vel a ser pesquisado: "); scanf("%i", &opt); getchar();
			
			system("cls");
			
			while(!feof(arquivo)){
					
				fscanf(arquivo, "%i %s %s %i %i %i %i %s %i\n", &tipo, proprietario, endereco, &valor, &aluguel, &metragem, &qtd_comodos, ponto_referencia, &contador);
					
				if(opt == tipo){
					
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
					
					c++;		//contador para controlar quantos im�veis foram exibidos
					
					}
				}
			break;
			
		case 5:
			
			return 6;
			break;
		
		case 6:
		
			return 99;
			break;
			
		default:
			
			system("cls");
			printf("Op��o incorreta, aperte qualquer tecla para retornar ao menu de pesquisa espec�fica");
			getchar();
			return 14;
			break;
	}
	
	fclose(arquivo);
	
	//Ao final, o usu�rio escolhe voltar ao menu de im�veis, voltar ao menu de exibi��o personalizada ou sair
	do{
		printf("\n[1] Voltar ao menu de im�veis\n[2] Voltar ao menu de exibi��o personalizada\n[3] Sair\n\nQual op��o desejada? "); scanf("%i", &sair); getchar();
		
		if(sair == 1){
			return 6;
		}
		else{
			if(sair == 2){
				return 14;
			}
			else{
				if(sair == 3){
					return 99;
				}
				else{
					printf("Valor inv�lido, aperte qualquer tecla para tentar novamente");
					getch();
				}
			}
		}
	}
	while(sair != 1 || sair != 2 || sair != 3);

}

int ExibirPersonalizado_Corretor(){
	
	setlocale(LC_ALL, "Portuguese");
	system("cls");
	
	FILE* arquivo;
	int c, op1, opp, opc, opm, opt, sair;
	
	int metragem, qtd_comodos, valor, contador, aluguel, tipo;
	char endereco[300], proprietario[300], ponto_referencia[300];
	
	arquivo = fopen("imoveis.txt", "r");
	
	c = 0;
	
	printf("[1] Filtrar por pre�o\n[2] Filtrar por quantidade de c�modos\n[3] Filtrar por metragem\n[4] Filtrar por tipo\n[5] Voltar\n[6] Sair");
	printf("\n\nQual op��o desejada? "); scanf("%i", &op1); getchar();
	
	//primeiro switch para as op��es do menu acima
	switch(op1){
		
		case 1:
			
			system("cls");
			
			printf("Digite o valor m�ximo do im�vel a ser pesquisado: R$ "); scanf("%i", &opp); getchar();
			
			system("cls");
			
			while(!feof(arquivo)){
					
				fscanf(arquivo, "%i %s %s %i %i %i %i %s %i\n", &tipo, proprietario, endereco, &valor, &aluguel, &metragem, &qtd_comodos, ponto_referencia, &contador);
					
				if(valor <= opp){
					
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
					
					c++;	//contador para controlar quantos im�veis foram exibidos
					
					}
				}
				
				if(c == 0){
					system("cls");
					printf("N�o h� im�veis com valor menor que %i cadastrados\n", opp);		//se nenhum im�vel foi exibido exibe essa mensagem
				}
			
			break;
		
		case 2:
			
			system("cls");
			
			printf("Digite o n�mero de c�modos m�ximo a ser pesquisado: "); scanf("%i", &opc); getchar();
			
			system("cls");
			
			while(!feof(arquivo)){
					
				fscanf(arquivo, "%i %s %s %i %i %i %i %s %i\n", &tipo, proprietario, endereco, &valor, &aluguel, &metragem, &qtd_comodos, ponto_referencia, &contador);
					
				if(qtd_comodos <= opc){
					
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
					
					c++;	//contador para controlar quantos im�veis foram exibidos
					
					}
				}
				
				if(c == 0){
					system("cls");
					printf("N�o h� im�veis com %i c�modos ou menos cadastrados\n", opc);		//se nenhum im�vel foi exibido exibe essa mensagem
				}
			
			break;
			
		case 3:
			
			system("cls");
			
			printf("Digite o valor m�ximo de metragem a ser pesquisado: "); scanf("%i", &opm); getchar();
			
			system("cls");
			
			while(!feof(arquivo)){
					
				fscanf(arquivo, "%i %s %s %i %i %i %i %s %i\n", &tipo, proprietario, endereco, &valor, &aluguel, &metragem, &qtd_comodos, ponto_referencia, &contador);
					
				if(metragem <= opm){
					
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
					
					c++;		//contador para controlar quantos im�veis foram exibidos
					
					}
				}
				
			if (c == 0){
				system("cls");
				printf("N�o h� im�veis com menos de %i m� cadastrados\n", opm);		//se nenhum im�vel foi exibido exibe essa mensagem
			}
			break;
		
		case 4:
			
			system("cls");
			
			printf("[1] Residencial\n[2] Comercial\n\nDigite o tipo de im�vel a ser pesquisado: "); scanf("%i", &opt); getchar();
			
			system("cls");
			
			while(!feof(arquivo)){
					
				fscanf(arquivo, "%i %s %s %i %i %i %i %s %i\n", &tipo, proprietario, endereco, &valor, &aluguel, &metragem, &qtd_comodos, ponto_referencia, &contador);
					
				if(opt == tipo){
					
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
					
					c++;		//contador para controlar quantos im�veis foram exibidos
					
					}
				}
			break;
		
		case 5:
			
			return 3;
			break;
		
		case 6:
		
			return 99;
			break;
			
		default:
			
			system("cls");
			printf("Op��o incorreta, aperte qualquer tecla para retornar ao menu de pesquisa espec�fica");
			getchar();
			return 14;
			break;
	}
	
	//Ao final, o usu�rio escolhe voltar ao menu dos corretores, voltar ao menu de exibi��o personalizada ou sair
	do{
		printf("\n[1] Voltar ao menu de corretores\n[2] Voltar ao menu de exibi��o personalizada\n[3] Sair\n\nQual op��o desejada? "); scanf("%i", &sair); getchar();
		
		if(sair == 1){
			return 3;
		}
		else{
			if(sair == 2){
				return 20;
			}
			else{
				if(sair == 3){
					return 99;
				}
				else{
					printf("Valor inv�lido, aperte qualquer tecla para tentar novamente");
					getch();
				}
			}
		}
	}
	while(sair != 1 || sair != 2 || sair != 3);

	fclose(arquivo);
}
