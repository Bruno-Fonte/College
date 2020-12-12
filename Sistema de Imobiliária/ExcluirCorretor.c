#include <stdio.h>
#include <locale.h>

int ExcluirCorretor(){
	
	setlocale(LC_ALL,"Portuguese");	
	system("cls");
	
	//declara 3 vari�veis do tipo FILE
	FILE* arquivo;				//um para o arquivo de corretores original
	FILE* copia_arquivo;		//um para copiar os cadastros n�o exclu�dos num segundo arquivo
	FILE* contador_arquivo;		//um para atualizar o n�mero de cadastros
	char cpf[14], nome[300], creci[7], usu[100], senha[100];
	int idade, num_corretor, referencia, contadorarq, sair;
	
	arquivo = fopen("corretores.txt", "r");					//abre o arquivo original em modo leitura
	copia_arquivo = fopen("copia_corretores.txt", "w");		//abre o arquivo para c�pia em modo grava��o
	
	ExibirCorretor_Alterar_Excluir();
	
	printf("\nDigite o n�mero do corretor que deseja excluir: "); scanf("%i", &num_corretor); getchar();	//pergunta ao usu�rio qual corretor deseja excluir
	
	//loop que passa por cada linha do arquivo original
	while(!feof(arquivo)){
		fscanf(arquivo, "%s %s %s %s %i %s %i\n", usu, senha, nome, cpf, &idade, creci, &referencia);
		
		//essa condi��o compara a refer�ncia do im�vel no arquivo com o n�mero que o usu�rio digitou
		if(referencia != num_corretor){
			
			fprintf(copia_arquivo, "%s %s %s %s %i %s %i\n", usu, senha, nome, cpf, idade, creci, referencia);
		}
	}
	
	fclose(arquivo);
	fclose(copia_arquivo);
	
	//exclui o arquivo original e renomeia a c�pia para o nome do original
	system("del corretores.txt");
	system("rename copia_corretores.txt corretores.txt");
	
	system("cls");
	
	//se n�o existir um corretor com o n�mero que o usu�rio digitou, n�o haver� exclus�o
	if (num_corretor > referencia){
		printf("\nN�mero n�o cadastrado, exclus�o n�o conclu�da");
	}
	else{
		printf("\nExclus�o conclu�da");
		
		//j� que temos um corretor a menos, o arquivo que controla a quantidade de corretores cadastrados diminui 1
		contador_arquivo = fopen("contadorcorretores.txt", "r");		//abre o arquivo de n�mero de corretores em modo leitura
		fscanf(contador_arquivo, "%i", &contadorarq);					//escaneia o n�mero presente no arquivo
		fclose(contador_arquivo);										//fecha o arquivo
	
		contadorarq -= 1;				//diminui 1
	
		contador_arquivo = fopen("contadorcorretores.txt", "w");		//abre o arquivo de n�mero de corretores em modo escrita
		fprintf(contador_arquivo, "%i", contadorarq);					//printa no arquivo o novo n�mero
		fclose(contador_arquivo);										//fecha o arquivo
	}
	
	//Ao final, o usu�rio escolhe fazer outra exclus�o, voltar ao menu anterior ou sair
	do{
		printf("\n\n[1] Fazer outra exclus�o\n[2] Voltar ao menu de corretores\n[3] Sair\n\nQual op��o desejada? "); scanf("%i", &sair); getchar();
		
		if(sair == 1){
			return 17;
		}
		else{
			if(sair == 2){
				return 9;
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
