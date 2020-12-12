#include <stdio.h>
#include <locale.h>

//fun��o para alterar um cadastro
int AlterarImovel(){	//fun��o void sem par�metro
	
	setlocale(LC_ALL, "Portuguese");
	system("cls");		//atualiza a tela
	
	FILE* arquivo;
	FILE* copia_arquivo;				//abre dois arquivos
	char endereco[300], proprietario[100], ponto_referencia[300];
	char novo_endereco[300], novo_proprietario[100], novo_ponto_referencia[300];	
	int num_imovel, contador, metragem, aluguel, tipo, novo_aluguel, qtd_comodos, novo_metragem, novo_qtd_comodos, valor, novo_valor, novo_tipo, sair;			//vari�veis para ler e gravar no arquivo
	
	arquivo = fopen("imoveis.txt", "r");				//abre o arquivo com os cadastros em modo leitura
	copia_arquivo = fopen("copia_imoveis.txt", "w");	//abre um arquivo inicialmente vazio em modo grava��o
	
	ExibirImovel_Alterar_Excluir();
	
	printf("Digite o n�mero do im�vel que deseja alterar: "); scanf("%i", &num_imovel); getchar();		//pede a refer�ncia do im�vel
	
	while(!feof(arquivo)){			//loop que passa por cada linha do arquivo
		fscanf(arquivo, "%i %s %s %i %i %i %i %s %i\n", &tipo, proprietario, endereco, &valor, &aluguel, &metragem, &qtd_comodos, ponto_referencia, &contador);		//l� as vari�veis do arquivo
		
		if(contador != num_imovel){			//compara o n�mero que o usu�rio digitou com a refer�ncia cadastrada no arquivo
			fprintf(copia_arquivo, "%i %s %s %i %i %i %i %s %i\n", tipo, proprietario, endereco, valor, aluguel, metragem, qtd_comodos, ponto_referencia, contador);	//se for diferente, os 
		}																																//dados antigos s�o 
		else{																															//gravados num novo arquivo
		
			system("cls");		//atualiza a tela
			
			printf("\nInserindo os novos dados\n");			//se forem iguais, insere o novo cadastro
			
			printf("\nTipo de im�vel ([1] Residencial / [2] Comercial): "); scanf("%i", &novo_tipo); getchar();
			printf("\nNome do propriet�rio: "); gets(novo_proprietario); espaco(novo_proprietario);
			printf("\nEndere�o: "); gets(novo_endereco); espaco(novo_endereco);
			printf("\nValor do im�vel: "); scanf("%i", &novo_valor); getchar();
			printf("\nValor para aluguel: "); scanf("%i", &novo_aluguel); getchar();
			printf("\nMetragem: "); scanf("%i", &novo_metragem); getchar();
			printf("\nQuantidade de c�modos: "); scanf("%i", &novo_qtd_comodos); getchar();
			printf("\nPonto de refer�ncia: "); gets(novo_ponto_referencia); espaco(novo_ponto_referencia);
		
			fprintf(copia_arquivo, "%i %s %s %i %i %i %i %s %i\n", novo_tipo, novo_proprietario, novo_endereco, novo_valor, novo_aluguel, novo_metragem, novo_qtd_comodos, novo_ponto_referencia, contador);
		}
	}
	
	fclose(arquivo);
	fclose(copia_arquivo);
	
	system("del imoveis.txt");		//deleta o arquivo original e renomeia o arquivo novo para o nome do original
	system("rename copia_imoveis.txt imoveis.txt");
	
	system("cls");
	
	//se n�o existir um im�vel com o n�mero que o usu�rio digitou, n�o haver� altera��o
	if(num_imovel > contador){
		printf("\nN�mero n�o cadastrado, altera��o n�o conclu�da");
	}
	else{
		printf("\nAltera��o conclu�da");
	}
	
	//Ao final, o usu�rio escolhe voltar ao menu anterior ou sair
	do{
		printf("\n\n[1] Fazer outra altera��o\n[2] Voltar ao menu de im�veis\n[3] Sair\n\nQual op��o desejada? "); scanf("%i", &sair); getchar();
		
		if(sair == 1){
			return 12;
		}
		else{
			if(sair == 2){
				return 6;
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
