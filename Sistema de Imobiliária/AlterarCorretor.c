#include <stdio.h>
#include <locale.h>

int AlterarCorretor(){
	
	setlocale(LC_ALL, "Portuguese");
	system("cls");
	
	FILE* arquivo;
	FILE* copia_arquivo;				//abre dois arquivos
	char cpf[14], nome[300], creci[7], usu[100], senha[100];
	char novo_cpf[14], novo_nome[300], novo_creci[7], novo_usu[100], novo_senha[100];
	int referencia, num_corretor, idade, novo_idade, sair;
	
	arquivo = fopen("corretores.txt", "r");				//abre o arquivo com os cadastros em modo leitura
	copia_arquivo = fopen("copia_corretores.txt", "w");	//abre um arquivo inicialmente vazio em modo grava��o
	
	ExibirCorretor_Alterar_Excluir();
	
	printf("\nDigite o n�mero do corretor que deseja alterar: "); scanf("%i", &num_corretor); getchar();		//pede a refer�ncia do corretor
	
	while(!feof(arquivo)){			//loop que passa por cada linha do arquivo
		fscanf(arquivo, "%s %s %s %s %i %s %i\n", usu, senha, nome, cpf, &idade, creci, &referencia);								//l� as vari�veis do arquivo
		
		if(referencia != num_corretor){			//compara o n�mero que o usu�rio digitou com a refer�ncia cadastrada no arquivo
			fprintf(copia_arquivo, "%s %s %s %s %i %s %i\n", usu, senha, nome, cpf, idade, creci, referencia);				//se for diferente, os dados s�o gravados num novo arquivo 
		}																														
		else{																							//se for igual, faz um novo cadastro								
			
			system("cls");		//atualiza a tela
			
			printf("\nInserindo novo cadastro\n");
			
			printf("\nPrimeiro nome do usu�rio: "); gets(novo_usu);
			
			printf("\nSenha: "); gets(novo_senha);						
			
			printf("\nNome: "); gets(novo_nome); espaco(novo_nome);
			
			printf("\nCPF (somente n�meros): "); gets(novo_cpf);
			
			printf("\nIdade: "); scanf("%i", &novo_idade); getchar();
			
			printf("\nCRECI: "); gets(novo_creci);
			
			fprintf(copia_arquivo, "%s %s %s %s %i %s %i\n", novo_usu, novo_senha, novo_nome, novo_cpf, novo_idade, novo_creci, referencia);
		}
	}
	
	fclose(arquivo);
	fclose(copia_arquivo);
	
	system("del corretores.txt");		//deleta o arquivo original e renomeia o arquivo novo para o nome do original
	system("rename copia_corretores.txt corretores.txt");
	
	system("cls");
	
	//se n�o existir um corretor com o n�mero que o usu�rio digitou, n�o haver� altera��o
	if(num_corretor > referencia){
		printf("\nN�mero n�o cadastrado, altera��o n�o conclu�da");
	}
	else{
		printf("\nAltera��o conclu�da");
	}
	
	
	//Ao final, o usu�rio escolhe fazer outra altera��o, voltar ao menu anterior ou sair
	do{
		printf("\n\n[1] Fazer outra altera��o\n[2] Voltar ao menu de corretores\n[3] Sair\n\nQual op��o desejada? "); scanf("%i", &sair); getchar();
		
		if(sair == 1){
			return 16;
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
