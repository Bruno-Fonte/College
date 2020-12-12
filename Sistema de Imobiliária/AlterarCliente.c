#include <stdio.h>
#include <locale.h>

//Fun��o que, no fim, retorna ao menu do administrador
int AlterarCliente(){
	
	setlocale(LC_ALL, "Portuguese");
	system("cls");
	
	FILE* arquivo;
	FILE* copia_arquivo;				//abre dois arquivos
	char cpf[14], nome[100], cpf_cnpj[23], tel[12];
	char novo_cpf[14], novo_nome[100], novo_cpf_cnpj[23], novo_tel[12];
	int contador, num_cliente, sair, p;
	
	arquivo = fopen("clientes.txt", "r");				//abre o arquivo com os cadastros em modo leitura
	copia_arquivo = fopen("copia_clientes.txt", "w");	//abre um arquivo inicialmente vazio em modo grava��o
	
	ExibirCliente_Alterar_Excluir();
	
	printf("\nDigite o n�mero do cliente que deseja alterar: "); scanf("%i", &num_cliente); getchar();		//pede a refer�ncia do cliente
	
	while(!feof(arquivo)){			//loop que passa por cada linha do arquivo
		fscanf(arquivo, "%i %s %s %s %i\n", &p, nome, cpf_cnpj, tel, &contador);								//l� as vari�veis do arquivo
		
		if(contador != num_cliente){			//compara o n�mero que o usu�rio digitou com a refer�ncia cadastrada no arquivo
			fprintf(copia_arquivo, "%i %s %s %s %i\n", p, nome, cpf_cnpj, tel, contador);				//se for diferente, os dados s�o gravados num novo arquivo 
		}																														
		else{																							//se for igual, faz um novo cadastro								
			if(p == 1){
				system("cls");		//atualiza a tela
			
				printf("\nInserindo novo cadastro\n");
				printf("\nNome: "); gets(novo_nome); espaco(novo_nome);
				printf("\nCPF (somente n�meros): "); gets(novo_cpf_cnpj);
				printf("\nTelefone (somente n�meros): "); gets(novo_tel);
				
				fprintf(copia_arquivo, "%i %s %s %s %i\n", p, novo_nome, novo_cpf_cnpj, novo_tel, contador);
			}
			else{
				system("cls");		//atualiza a tela
			
				printf("\nInserindo novo cadastro\n");
				printf("\nNome: "); gets(novo_nome); espaco(novo_nome);
				printf("\nCNPJ (somente n�meros): "); gets(novo_cpf_cnpj);
				printf("\nTelefone (somente n�meros): "); gets(novo_tel);
				
				fprintf(copia_arquivo, "%i %s %s %s %i\n", p, novo_nome, novo_cpf_cnpj, novo_tel, contador);
			}
		}
	}
	
	fclose(arquivo);
	fclose(copia_arquivo);
	
	system("del clientes.txt");		//deleta o arquivo original e renomeia o arquivo novo para o nome do original
	system("rename copia_clientes.txt clientes.txt");
	
	system("cls");
	
	//se n�o existir um corretor com o n�mero que o usu�rio digitou, n�o haver� altera��o
	if(num_cliente > contador){
		printf("N�mero n�o cadastrado, altera��o n�o conclu�da");
	}
	else{
		printf("Altera��o conclu�da");
	}
	
	//Ao final, o usu�rio escolhe fazer outra altera��o, voltar ao menu anterior ou sair
	do{
		printf("\n\n[1] Fazer outra altera��o\n[2] Voltar ao menu de clientes\n[3] Sair\n\nQual op��o desejada? "); scanf("%i", &sair); getchar();
		
		if(sair == 1){
			return 25;
		}
		else{
			if(sair == 2){
				return 22;
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

//Fun��o que, no fim, retorna ao menu do corretor
int AlterarClienteCorretor(){
	
	setlocale(LC_ALL, "Portuguese");
	system("cls");
	
	FILE* arquivo;
	FILE* copia_arquivo;				//abre dois arquivos
	char cpf[14], nome[100], cpf_cnpj[23], tel[12];
	char novo_cpf[14], novo_nome[100], novo_cpf_cnpj[23], novo_tel[12];
	int contador, num_cliente, sair, p;
	
	arquivo = fopen("clientes.txt", "r");				//abre o arquivo com os cadastros em modo leitura
	copia_arquivo = fopen("copia_clientes.txt", "w");	//abre um arquivo inicialmente vazio em modo grava��o
	
	ExibirCliente_Alterar_Excluir();
	
	printf("\nDigite o n�mero do cliente que deseja alterar: "); scanf("%i", &num_cliente); getchar();		//pede a refer�ncia do cliente
	
	while(!feof(arquivo)){			//loop que passa por cada linha do arquivo
		fscanf(arquivo, "%i %s %s %s %i\n", &p, nome, cpf_cnpj, tel, &contador);								//l� as vari�veis do arquivo
		
		if(contador != num_cliente){			//compara o n�mero que o usu�rio digitou com a refer�ncia cadastrada no arquivo
			fprintf(copia_arquivo, "%i %s %s %s %i\n", p, nome, cpf_cnpj, tel, contador);				//se for diferente, os dados s�o gravados num novo arquivo 
		}																														
		else{																							//se for igual, faz um novo cadastro								
			if(p == 1){
				system("cls");		//atualiza a tela
			
				printf("\nInserindo novo cadastro\n");
				printf("\nNome: "); gets(novo_nome); espaco(novo_nome);
				printf("\nCPF (somente n�meros): "); gets(novo_cpf_cnpj);
				printf("\nTelefone (somente n�meros): "); gets(novo_tel);
				
				fprintf(copia_arquivo, "%i %s %s %s %i\n", p, novo_nome, novo_cpf_cnpj, novo_tel, contador);
			}
			else{
				system("cls");		//atualiza a tela
			
				printf("\nInserindo novo cadastro\n");
				printf("\nNome: "); gets(novo_nome); espaco(novo_nome);
				printf("\nCNPJ (somente n�meros): "); gets(novo_cpf_cnpj);
				printf("\nTelefone (somente n�meros): "); gets(novo_tel);
				
				fprintf(copia_arquivo, "%i %s %s %s %i\n", p, novo_nome, novo_cpf_cnpj, novo_tel, contador);
			}
		}
	}
	
	fclose(arquivo);
	fclose(copia_arquivo);
	
	system("del clientes.txt");		//deleta o arquivo original e renomeia o arquivo novo para o nome do original
	system("rename copia_clientes.txt clientes.txt");
	
	system("cls");
	
	//se n�o existir um corretor com o n�mero que o usu�rio digitou, n�o haver� altera��o
	if(num_cliente > contador){
		printf("N�mero n�o cadastrado, altera��o n�o conclu�da");
	}
	else{
		printf("Altera��o conclu�da");
	}
	
	//Ao final, o usu�rio escolhe fazer outra altera��o, voltar ao menu anterior ou sair
	do{
		printf("\n\n[1] Fazer outra altera��o\n[2] Voltar ao menu de clientes\n[3] Sair\n\nQual op��o desejada? "); scanf("%i", &sair); getchar();
		
		if(sair == 1){
			return 25;
		}
		else{
			if(sair == 2){
				return 27;
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
