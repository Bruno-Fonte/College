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
	
	printf("[1] Filtrar por preço\n[2] Filtrar por quantidade de cômodos\n[3] Filtrar por metragem\n[4] Filtrar por tipo\n[5] Voltar\n[6] Sair");
	printf("\n\nQual opção desejada? "); scanf("%i", &op1); getchar();
	
	//primeiro switch para as opções do menu acima
	switch(op1){
		
		case 1:
			
			system("cls");
			
			printf("Digite o valor máximo do imóvel a ser pesquisado: R$ "); scanf("%i", &opp); getchar();
			
			system("cls");
			
			while(!feof(arquivo)){
					
				fscanf(arquivo, "%i %s %s %i %i %i %i %s %i\n", &tipo, proprietario, endereco, &valor, &aluguel, &metragem, &qtd_comodos, ponto_referencia, &contador);
					
				if(valor <= opp){
					
					colocarEspaco(ponto_referencia);	//chama a função "colocarEspaco" para trocar o '+' pelo espaço
					colocarEspaco(proprietario);
					colocarEspaco(endereco);
						
					printf("Referência do imóvel: %i\n", contador);
					
					if(tipo == 1){
						printf("Tipo de imóvel: Residencial\n");
					}
					else{
						printf("Tipo de imóvel: Comercial\n");
					}
						
					printf("Nome do proprietário: %s\n", proprietario);
						
					printf("Endereço: %s\n", endereco);
						
					printf("Valor do imóvel: R$ %i,00\n", valor);
					
					printf("Valor para aluguel: R$ %i,00\n", aluguel);
					
					printf("Metragem do Imóvel: %i m²\n", metragem);
						
					printf("Quantidades de cômodos: %i\n", qtd_comodos);
						
					printf("Ponto de referência: %s\n", ponto_referencia);
					printf("\n");
					
					c++;	//contador para controlar quantos imóveis foram exibidos
					
					}
				}
				
				if(c == 0){
					system("cls");
					printf("Não há imóveis com valor menor que %i cadastrados\n", opp);		//se nenhum imóvel foi exibido exibe essa mensagem
				}
			
			break;
		
		case 2:
			
			system("cls");
			
			printf("Digite o número de cômodos máximo a ser pesquisado: "); scanf("%i", &opc); getchar();
			
			system("cls");
			
			while(!feof(arquivo)){
					
				fscanf(arquivo, "%i %s %s %i %i %i %i %s %i\n", &tipo, proprietario, endereco, &valor, &aluguel, &metragem, &qtd_comodos, ponto_referencia, &contador);
					
				if(qtd_comodos <= opc){
					
					colocarEspaco(ponto_referencia);	//chama a função "colocarEspaco" para trocar o '+' pelo espaço
					colocarEspaco(proprietario);
					colocarEspaco(endereco);
						
					printf("Referência do imóvel: %i\n", contador);
					
					if(tipo == 1){
						printf("Tipo de imóvel: Residencial\n");
					}
					else{
						printf("Tipo de imóvel: Comercial\n");
					}
						
					printf("Nome do proprietário: %s\n", proprietario);
						
					printf("Endereço: %s\n", endereco);
						
					printf("Valor do imóvel: R$ %i,00\n", valor);
						
					printf("Valor para aluguel: R$ %i,00\n", aluguel);
					
					printf("Metragem do Imóvel: %i m²\n", metragem);
						
					printf("Quantidades de cômodos: %i\n", qtd_comodos);
						
					printf("Ponto de referência: %s\n", ponto_referencia);
					printf("\n");
					
					c++;	//contador para controlar quantos imóveis foram exibidos
					
					}
				}
				
				if(c == 0){
					system("cls");
					printf("Não há imóveis com %i cômodos ou menos cadastrados\n", opc);		//se nenhum imóvel foi exibido exibe essa mensagem
				}
			
			break;
			
		case 3:
			
			system("cls");
			
			printf("Digite o valor máximo de metragem a ser pesquisado: "); scanf("%i", &opm); getchar();
			
			system("cls");
			
			while(!feof(arquivo)){
					
				fscanf(arquivo, "%i %s %s %i %i %i %i %s %i\n", &tipo, proprietario, endereco, &valor, &aluguel, &metragem, &qtd_comodos, ponto_referencia, &contador);
					
				if(metragem <= opm){
					
					colocarEspaco(ponto_referencia);	//chama a função "colocarEspaco" para trocar o '+' pelo espaço
					colocarEspaco(proprietario);
					colocarEspaco(endereco);
						
					printf("Referência do imóvel: %i\n", contador);
					
					if(tipo == 1){
						printf("Tipo de imóvel: Residencial\n");
					}
					else{
						printf("Tipo de imóvel: Comercial\n");
					}
					
					printf("Nome do proprietário: %s\n", proprietario);
						
					printf("Endereço: %s\n", endereco);
						
					printf("Valor do imóvel: R$ %i,00\n", valor);
						
					printf("Valor para aluguel: R$ %i,00\n", aluguel);
					
					printf("Metragem do Imóvel: %i m²\n", metragem);
						
					printf("Quantidades de cômodos: %i\n", qtd_comodos);
						
					printf("Ponto de referência: %s\n", ponto_referencia);
					printf("\n");
					
					c++;		//contador para controlar quantos imóveis foram exibidos
					
					}
				}
				
			if (c == 0){
				system("cls");
				printf("Não há imóveis com menos de %i m² cadastrados\n", opm);		//se nenhum imóvel foi exibido exibe essa mensagem
			}
			break;
			
		case 4:
			
			system("cls");
			
			printf("[1] Residencial\n[2] Comercial\n\nDigite o tipo de imóvel a ser pesquisado: "); scanf("%i", &opt); getchar();
			
			system("cls");
			
			while(!feof(arquivo)){
					
				fscanf(arquivo, "%i %s %s %i %i %i %i %s %i\n", &tipo, proprietario, endereco, &valor, &aluguel, &metragem, &qtd_comodos, ponto_referencia, &contador);
					
				if(opt == tipo){
					
					colocarEspaco(ponto_referencia);	//chama a função "colocarEspaco" para trocar o '+' pelo espaço
					colocarEspaco(proprietario);
					colocarEspaco(endereco);
						
					printf("Referência do imóvel: %i\n", contador);
					
					if(tipo == 1){
						printf("Tipo de imóvel: Residencial\n");
					}
					else{
						printf("Tipo de imóvel: Comercial\n");
					}
					
					printf("Nome do proprietário: %s\n", proprietario);
						
					printf("Endereço: %s\n", endereco);
						
					printf("Valor do imóvel: R$ %i,00\n", valor);
						
					printf("Valor para aluguel: R$ %i,00\n", aluguel);
					
					printf("Metragem do Imóvel: %i m²\n", metragem);
						
					printf("Quantidades de cômodos: %i\n", qtd_comodos);
						
					printf("Ponto de referência: %s\n", ponto_referencia);
					printf("\n");
					
					c++;		//contador para controlar quantos imóveis foram exibidos
					
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
			printf("Opção incorreta, aperte qualquer tecla para retornar ao menu de pesquisa específica");
			getchar();
			return 14;
			break;
	}
	
	fclose(arquivo);
	
	//Ao final, o usuário escolhe voltar ao menu de imóveis, voltar ao menu de exibição personalizada ou sair
	do{
		printf("\n[1] Voltar ao menu de imóveis\n[2] Voltar ao menu de exibição personalizada\n[3] Sair\n\nQual opção desejada? "); scanf("%i", &sair); getchar();
		
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
					printf("Valor inválido, aperte qualquer tecla para tentar novamente");
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
	
	printf("[1] Filtrar por preço\n[2] Filtrar por quantidade de cômodos\n[3] Filtrar por metragem\n[4] Filtrar por tipo\n[5] Voltar\n[6] Sair");
	printf("\n\nQual opção desejada? "); scanf("%i", &op1); getchar();
	
	//primeiro switch para as opções do menu acima
	switch(op1){
		
		case 1:
			
			system("cls");
			
			printf("Digite o valor máximo do imóvel a ser pesquisado: R$ "); scanf("%i", &opp); getchar();
			
			system("cls");
			
			while(!feof(arquivo)){
					
				fscanf(arquivo, "%i %s %s %i %i %i %i %s %i\n", &tipo, proprietario, endereco, &valor, &aluguel, &metragem, &qtd_comodos, ponto_referencia, &contador);
					
				if(valor <= opp){
					
					colocarEspaco(ponto_referencia);	//chama a função "colocarEspaco" para trocar o '+' pelo espaço
					colocarEspaco(proprietario);
					colocarEspaco(endereco);
						
					printf("Referência do imóvel: %i\n", contador);
					
					if(tipo == 1){
						printf("Tipo de imóvel: Residencial\n");
					}
					else{
						printf("Tipo de imóvel: Comercial\n");
					}
						
					printf("Nome do proprietário: %s\n", proprietario);
						
					printf("Endereço: %s\n", endereco);
						
					printf("Valor do imóvel: R$ %i,00\n", valor);
					
					printf("Valor para aluguel: R$ %i,00\n", aluguel);
						
					printf("Metragem do Imóvel: %i m²\n", metragem);
						
					printf("Quantidades de cômodos: %i\n", qtd_comodos);
						
					printf("Ponto de referência: %s\n", ponto_referencia);
					printf("\n");
					
					c++;	//contador para controlar quantos imóveis foram exibidos
					
					}
				}
				
				if(c == 0){
					system("cls");
					printf("Não há imóveis com valor menor que %i cadastrados\n", opp);		//se nenhum imóvel foi exibido exibe essa mensagem
				}
			
			break;
		
		case 2:
			
			system("cls");
			
			printf("Digite o número de cômodos máximo a ser pesquisado: "); scanf("%i", &opc); getchar();
			
			system("cls");
			
			while(!feof(arquivo)){
					
				fscanf(arquivo, "%i %s %s %i %i %i %i %s %i\n", &tipo, proprietario, endereco, &valor, &aluguel, &metragem, &qtd_comodos, ponto_referencia, &contador);
					
				if(qtd_comodos <= opc){
					
					colocarEspaco(ponto_referencia);	//chama a função "colocarEspaco" para trocar o '+' pelo espaço
					colocarEspaco(proprietario);
					colocarEspaco(endereco);
						
					printf("Referência do imóvel: %i\n", contador);
					
					if(tipo == 1){
						printf("Tipo de imóvel: Residencial\n");
					}
					else{
						printf("Tipo de imóvel: Comercial\n");
					}
						
					printf("Nome do proprietário: %s\n", proprietario);
						
					printf("Endereço: %s\n", endereco);
						
					printf("Valor do imóvel: R$ %i,00\n", valor);
						
					printf("Valor para aluguel: R$ %i,00\n", aluguel);
					
					printf("Metragem do Imóvel: %i m²\n", metragem);
						
					printf("Quantidades de cômodos: %i\n", qtd_comodos);
						
					printf("Ponto de referência: %s\n", ponto_referencia);
					printf("\n");
					
					c++;	//contador para controlar quantos imóveis foram exibidos
					
					}
				}
				
				if(c == 0){
					system("cls");
					printf("Não há imóveis com %i cômodos ou menos cadastrados\n", opc);		//se nenhum imóvel foi exibido exibe essa mensagem
				}
			
			break;
			
		case 3:
			
			system("cls");
			
			printf("Digite o valor máximo de metragem a ser pesquisado: "); scanf("%i", &opm); getchar();
			
			system("cls");
			
			while(!feof(arquivo)){
					
				fscanf(arquivo, "%i %s %s %i %i %i %i %s %i\n", &tipo, proprietario, endereco, &valor, &aluguel, &metragem, &qtd_comodos, ponto_referencia, &contador);
					
				if(metragem <= opm){
					
					colocarEspaco(ponto_referencia);	//chama a função "colocarEspaco" para trocar o '+' pelo espaço
					colocarEspaco(proprietario);
					colocarEspaco(endereco);
						
					printf("Referência do imóvel: %i\n", contador);
					
					if(tipo == 1){
						printf("Tipo de imóvel: Residencial\n");
					}
					else{
						printf("Tipo de imóvel: Comercial\n");
					}
					
					printf("Nome do proprietário: %s\n", proprietario);
						
					printf("Endereço: %s\n", endereco);
						
					printf("Valor do imóvel: R$ %i,00\n", valor);
					
					printf("Valor para aluguel: R$ %i,00\n", aluguel);	
						
					printf("Metragem do Imóvel: %i m²\n", metragem);
						
					printf("Quantidades de cômodos: %i\n", qtd_comodos);
						
					printf("Ponto de referência: %s\n", ponto_referencia);
					printf("\n");
					
					c++;		//contador para controlar quantos imóveis foram exibidos
					
					}
				}
				
			if (c == 0){
				system("cls");
				printf("Não há imóveis com menos de %i m² cadastrados\n", opm);		//se nenhum imóvel foi exibido exibe essa mensagem
			}
			break;
		
		case 4:
			
			system("cls");
			
			printf("[1] Residencial\n[2] Comercial\n\nDigite o tipo de imóvel a ser pesquisado: "); scanf("%i", &opt); getchar();
			
			system("cls");
			
			while(!feof(arquivo)){
					
				fscanf(arquivo, "%i %s %s %i %i %i %i %s %i\n", &tipo, proprietario, endereco, &valor, &aluguel, &metragem, &qtd_comodos, ponto_referencia, &contador);
					
				if(opt == tipo){
					
					colocarEspaco(ponto_referencia);	//chama a função "colocarEspaco" para trocar o '+' pelo espaço
					colocarEspaco(proprietario);
					colocarEspaco(endereco);
						
					printf("Referência do imóvel: %i\n", contador);
					
					if(tipo == 1){
						printf("Tipo de imóvel: Residencial\n");
					}
					else{
						printf("Tipo de imóvel: Comercial\n");
					}
					
					printf("Nome do proprietário: %s\n", proprietario);
						
					printf("Endereço: %s\n", endereco);
						
					printf("Valor do imóvel: R$ %i,00\n", valor);
						
					printf("Valor para aluguel: R$ %i,00\n", aluguel);
					
					printf("Metragem do Imóvel: %i m²\n", metragem);
						
					printf("Quantidades de cômodos: %i\n", qtd_comodos);
						
					printf("Ponto de referência: %s\n", ponto_referencia);
					printf("\n");
					
					c++;		//contador para controlar quantos imóveis foram exibidos
					
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
			printf("Opção incorreta, aperte qualquer tecla para retornar ao menu de pesquisa específica");
			getchar();
			return 14;
			break;
	}
	
	//Ao final, o usuário escolhe voltar ao menu dos corretores, voltar ao menu de exibição personalizada ou sair
	do{
		printf("\n[1] Voltar ao menu de corretores\n[2] Voltar ao menu de exibição personalizada\n[3] Sair\n\nQual opção desejada? "); scanf("%i", &sair); getchar();
		
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
					printf("Valor inválido, aperte qualquer tecla para tentar novamente");
					getch();
				}
			}
		}
	}
	while(sair != 1 || sair != 2 || sair != 3);

	fclose(arquivo);
}
