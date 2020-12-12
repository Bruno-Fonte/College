#include <stdio.h>
#include <locale.h>

//função para exibir os imóveis cadastrados
int ExibirImovel(){	//função void sem parâmetro
	
	setlocale(LC_ALL, "Portuguese");
	system("cls");		//atualiza a tela
	
	int contador, contadorarq, metragem, qtd_comodos, valor, sair, tipo, aluguel;
	char endereco[300], proprietario[300], ponto_referencia[300];
	
	FILE* arquivo;
	FILE* contador_arquivo;
	
	arquivo = fopen("imoveis.txt", "r");		//abre o arquivo em modo leitura
	contador_arquivo = fopen("contadorimoveis.txt", "r");		//abre um arquivo em modo leitura para salvar a referência 
	
	fscanf(contador_arquivo, "%i", &contadorarq);				//lê o valor dentro do arquivo de contador da quantidade de imóveis
	
	printf("Quantidade de imóveis cadastrados: %i\n\n", contadorarq);
	
	if(contadorarq != 0){
		while(!feof(arquivo)){
			fscanf(arquivo, "%i %s %s %i %i %i %i %s %i\n", &tipo, proprietario, endereco, &valor, &aluguel, &metragem, &qtd_comodos, ponto_referencia, &contador);
			
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
		}
	}
	else{
		printf("Não há imóveis cadastrados\n");
	}
	
	fclose(arquivo);
	fclose(contador_arquivo);
	
	//Ao final, o usuário escolhe voltar ao menu anterior ou sair
	do{
		printf("\n[1] Voltar ao menu de imóveis\n[2] Sair\n\nQual opção desejada? "); scanf("%i", &sair); getchar();
		
		if(sair == 1){
			return 6;
		}
		else{
			if(sair == 2){
				return 99;
			}
			else{
				printf("Valor inválido, aperte qualquer tecla para tentar novamente");
				getch();
			}
		}
	}
	
	while(sair != 1 || sair != 2);
}

//função para exibir os imóveis cadastrados sem retornar valor
//para os casos de alterar e excluir, para o usuário ver os imoveis
//cadastrados e selecionar qual deseja fazer a alteração
//ou exclusão
void ExibirImovel_Alterar_Excluir(){	//função void sem parâmetro
	
	setlocale(LC_ALL, "Portuguese");
	system("cls");		//atualiza a tela
	
	int contador, contadorarq, metragem, qtd_comodos, valor, aluguel, tipo, sair;
	char endereco[300], proprietario[300], ponto_referencia[300];
	
	FILE* arquivo;
	FILE* contador_arquivo;
	
	arquivo = fopen("imoveis.txt", "r");		//abre o arquivo em modo leitura
	contador_arquivo = fopen("contadorimoveis.txt", "r");		//abre um arquivo em modo leitura para salvar a referência 
	
	fscanf(contador_arquivo, "%i", &contadorarq);				//lê o valor dentro do arquivo de contador da quantidade de imóveis
	
	printf("Quantidade de imóveis cadastrados: %i\n\n", contadorarq);
	
	if(contadorarq != 0){
		while(!feof(arquivo)){
			fscanf(arquivo, "%i %s %s %i %i %i %i %s %i\n", &tipo, proprietario, endereco, &valor, &aluguel, &metragem, &qtd_comodos, ponto_referencia, &contador);
			
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
		}
	}
	else{
		printf("\nNão há imóveis cadastrados\n");
	}
	
	fclose(arquivo);
	fclose(contador_arquivo);
}

//função que, no fim, retorna ao menu do corretor
int ExibirImovel_Corretor(){	//função void sem parâmetro
	
	setlocale(LC_ALL, "Portuguese");
	system("cls");		//atualiza a tela
	
	int contador, contadorarq, metragem, qtd_comodos, valor, aluguel, tipo, sair;
	char endereco[300], proprietario[300], ponto_referencia[300];
	
	FILE* arquivo;
	FILE* contador_arquivo;
	
	arquivo = fopen("imoveis.txt", "r");		//abre o arquivo em modo leitura
	contador_arquivo = fopen("contadorimoveis.txt", "r");		//abre um arquivo em modo leitura para salvar a referência 
	
	fscanf(contador_arquivo, "%i", &contadorarq);				//lê o valor dentro do arquivo de contador da quantidade de imóveis
	
	printf("Quantidade de imóveis cadastrados: %i\n\n", contadorarq);
	
	if(contadorarq != 0){
		while(!feof(arquivo)){
			fscanf(arquivo, "%i %s %s %i %i %i %s %i\n", &tipo, proprietario, endereco, &valor, &aluguel, &metragem, &qtd_comodos, ponto_referencia, &contador);
			
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
		}
	}
	else{
		printf("\nNão há imóveis cadastrados\n");
	}
	
	fclose(arquivo);
	fclose(contador_arquivo);
	
	//Ao final, o usuário escolhe voltar ao menu anterior ou sair
	do{
		printf("\n[1] Voltar ao menu do corretor\n[2] Sair\n\nQual opção desejada? "); scanf("%i", &sair); getchar();
		
		if(sair == 1){
			return 3;
		}
		else{
			if(sair == 2){
				return 99;
			}
			else{
				printf("Valor inválido, aperte qualquer tecla para tentar novamente");
				getch();
			}
		}
	}
	
	while(sair != 1 || sair != 2);
}
