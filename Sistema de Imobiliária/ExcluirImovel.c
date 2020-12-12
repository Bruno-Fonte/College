#include <stdio.h>
#include <locale.h>

//fun��o para excluir um cadastro
int ExcluirImovel(){		//fun��o void sem par�metro
	
	setlocale(LC_ALL, "Portuguese");
	system("cls");			//atualiza a tela
	
	//declara 3 vari�veis do tipo FILE
	FILE* arquivo;				//um para o arquivo de im�veis original
	FILE* copia_arquivo;		//um para copiar os cadastros n�o exclu�dos num segundo arquivo
	FILE* contador_arquivo;		//um para consertar a refer�ncia dos cadastros n�o exclu�dos
	char endereco[300], proprietario[100], ponto_referencia[300];
	int num_imovel, contador, contadorarq, metragem, qtd_comodos, valor, aluguel, tipo, sair;
	
	arquivo = fopen("imoveis.txt", "r");				//abre o arquivo original em modo leitura
	copia_arquivo = fopen("copia_imoveis.txt", "w");	//abre o arquivo para c�pia em modo grava��o
	
	ExibirImovel_Alterar_Excluir();		//exibe para o usu�rio os im�veis cadastrados 
	
	printf("Digite o n�mero do im�vel que deseja excluir: "); scanf("%i", &num_imovel); getchar();	//pergunta ao usu�rio qual o im�vel deseja excluir
	
	//loop que passa por cada linha do arquivo original
	while(!feof(arquivo)){
		fscanf(arquivo, "%i %s %s %i %i %i %i %s %i\n", &tipo, proprietario, endereco, &valor, &aluguel, &metragem, &qtd_comodos, ponto_referencia, &contador);
		
		//essa condi��o compara a refer�ncia do im�vel no arquivo com o n�mero que o usu�rio digitou
		if(contador != num_imovel){
			
			fprintf(copia_arquivo, "%i %s %s %i %i %i %i %s %i\n", tipo, proprietario, endereco, valor, aluguel, metragem, qtd_comodos, ponto_referencia, contador); 
		}
	}
	
	fclose(arquivo);
	fclose(copia_arquivo);
	
	system("cls");
	
	//exclui o arquivo original e renomeia a c�pia para o nome do original
	system("del imoveis.txt");
	system("rename copia_imoveis.txt imoveis.txt");
	
	//se n�o existir um im�vel com o n�mero que o usu�rio digitou, n�o haver� exclus�o
	if (num_imovel > contador){
		printf("N�mero n�o cadastrado, exclus�o n�o conclu�da");
	}
	else{
		printf("\nExclus�o conclu�da");
		
		//j� que temos um im�vel a menos, o arquivo que controla a quantidade de im�veis cadastrados diminui 1
		contador_arquivo = fopen("contadorimoveis.txt", "r");		//abre o arquivo de n�mero de im�veis em modo leitura
		fscanf(contador_arquivo, "%i", &contadorarq);				//l� o n�mero presente no arquivo
		fclose(contador_arquivo);									//fecha o arquivo
	
		contadorarq -= 1;											//o n�mero do arquivo diminui em 1 unidade
	
		contador_arquivo = fopen("contadorimoveis.txt", "w");		//abre o arquivo em modo escrita
		fprintf(contador_arquivo, "%i", contadorarq);				//sobrescreve o valor antigo pelo valor atual
		fclose(contador_arquivo);									//fecha o arquivo
	}
	
	//Ao final, o usu�rio escolhe fazer outra exclus�o, voltar ao menu anterior ou sair
	do{
		printf("\n\n[1] Fazer outra exclus�o\n[2] Voltar ao menu de im�veis\n[3] Sair\n\nQual op��o desejada? "); scanf("%i", &sair); getchar();
		
		if(sair == 1){
			return 13;
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
