#include <stdio.h>
#include <locale.h>

//Função que, no fim, retorna ao menu do administrador
int AlterarCliente(){
	
	setlocale(LC_ALL, "Portuguese");
	system("cls");
	
	FILE* arquivo;
	FILE* copia_arquivo;				//abre dois arquivos
	char cpf[14], nome[100], cpf_cnpj[23], tel[12];
	char novo_cpf[14], novo_nome[100], novo_cpf_cnpj[23], novo_tel[12];
	int contador, num_cliente, sair, p;
	
	arquivo = fopen("clientes.txt", "r");				//abre o arquivo com os cadastros em modo leitura
	copia_arquivo = fopen("copia_clientes.txt", "w");	//abre um arquivo inicialmente vazio em modo gravação
	
	ExibirCliente_Alterar_Excluir();
	
	printf("\nDigite o número do cliente que deseja alterar: "); scanf("%i", &num_cliente); getchar();		//pede a referência do cliente
	
	while(!feof(arquivo)){			//loop que passa por cada linha do arquivo
		fscanf(arquivo, "%i %s %s %s %i\n", &p, nome, cpf_cnpj, tel, &contador);								//lê as variáveis do arquivo
		
		if(contador != num_cliente){			//compara o número que o usuário digitou com a referência cadastrada no arquivo
			fprintf(copia_arquivo, "%i %s %s %s %i\n", p, nome, cpf_cnpj, tel, contador);				//se for diferente, os dados são gravados num novo arquivo 
		}																														
		else{																							//se for igual, faz um novo cadastro								
			if(p == 1){
				system("cls");		//atualiza a tela
			
				printf("\nInserindo novo cadastro\n");
				printf("\nNome: "); gets(novo_nome); espaco(novo_nome);
				printf("\nCPF (somente números): "); gets(novo_cpf_cnpj);
				printf("\nTelefone (somente números): "); gets(novo_tel);
				
				fprintf(copia_arquivo, "%i %s %s %s %i\n", p, novo_nome, novo_cpf_cnpj, novo_tel, contador);
			}
			else{
				system("cls");		//atualiza a tela
			
				printf("\nInserindo novo cadastro\n");
				printf("\nNome: "); gets(novo_nome); espaco(novo_nome);
				printf("\nCNPJ (somente números): "); gets(novo_cpf_cnpj);
				printf("\nTelefone (somente números): "); gets(novo_tel);
				
				fprintf(copia_arquivo, "%i %s %s %s %i\n", p, novo_nome, novo_cpf_cnpj, novo_tel, contador);
			}
		}
	}
	
	fclose(arquivo);
	fclose(copia_arquivo);
	
	system("del clientes.txt");		//deleta o arquivo original e renomeia o arquivo novo para o nome do original
	system("rename copia_clientes.txt clientes.txt");
	
	system("cls");
	
	//se não existir um corretor com o número que o usuário digitou, não haverá alteração
	if(num_cliente > contador){
		printf("Número não cadastrado, alteração não concluída");
	}
	else{
		printf("Alteração concluída");
	}
	
	//Ao final, o usuário escolhe fazer outra alteração, voltar ao menu anterior ou sair
	do{
		printf("\n\n[1] Fazer outra alteração\n[2] Voltar ao menu de clientes\n[3] Sair\n\nQual opção desejada? "); scanf("%i", &sair); getchar();
		
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
					printf("Valor inválido, aperte qualquer tecla para tentar novamente");
					getch();
				}
			}
		}
	}
	
	while(sair != 1 || sair != 2 || sair != 3);
	
}

//Função que, no fim, retorna ao menu do corretor
int AlterarClienteCorretor(){
	
	setlocale(LC_ALL, "Portuguese");
	system("cls");
	
	FILE* arquivo;
	FILE* copia_arquivo;				//abre dois arquivos
	char cpf[14], nome[100], cpf_cnpj[23], tel[12];
	char novo_cpf[14], novo_nome[100], novo_cpf_cnpj[23], novo_tel[12];
	int contador, num_cliente, sair, p;
	
	arquivo = fopen("clientes.txt", "r");				//abre o arquivo com os cadastros em modo leitura
	copia_arquivo = fopen("copia_clientes.txt", "w");	//abre um arquivo inicialmente vazio em modo gravação
	
	ExibirCliente_Alterar_Excluir();
	
	printf("\nDigite o número do cliente que deseja alterar: "); scanf("%i", &num_cliente); getchar();		//pede a referência do cliente
	
	while(!feof(arquivo)){			//loop que passa por cada linha do arquivo
		fscanf(arquivo, "%i %s %s %s %i\n", &p, nome, cpf_cnpj, tel, &contador);								//lê as variáveis do arquivo
		
		if(contador != num_cliente){			//compara o número que o usuário digitou com a referência cadastrada no arquivo
			fprintf(copia_arquivo, "%i %s %s %s %i\n", p, nome, cpf_cnpj, tel, contador);				//se for diferente, os dados são gravados num novo arquivo 
		}																														
		else{																							//se for igual, faz um novo cadastro								
			if(p == 1){
				system("cls");		//atualiza a tela
			
				printf("\nInserindo novo cadastro\n");
				printf("\nNome: "); gets(novo_nome); espaco(novo_nome);
				printf("\nCPF (somente números): "); gets(novo_cpf_cnpj);
				printf("\nTelefone (somente números): "); gets(novo_tel);
				
				fprintf(copia_arquivo, "%i %s %s %s %i\n", p, novo_nome, novo_cpf_cnpj, novo_tel, contador);
			}
			else{
				system("cls");		//atualiza a tela
			
				printf("\nInserindo novo cadastro\n");
				printf("\nNome: "); gets(novo_nome); espaco(novo_nome);
				printf("\nCNPJ (somente números): "); gets(novo_cpf_cnpj);
				printf("\nTelefone (somente números): "); gets(novo_tel);
				
				fprintf(copia_arquivo, "%i %s %s %s %i\n", p, novo_nome, novo_cpf_cnpj, novo_tel, contador);
			}
		}
	}
	
	fclose(arquivo);
	fclose(copia_arquivo);
	
	system("del clientes.txt");		//deleta o arquivo original e renomeia o arquivo novo para o nome do original
	system("rename copia_clientes.txt clientes.txt");
	
	system("cls");
	
	//se não existir um corretor com o número que o usuário digitou, não haverá alteração
	if(num_cliente > contador){
		printf("Número não cadastrado, alteração não concluída");
	}
	else{
		printf("Alteração concluída");
	}
	
	//Ao final, o usuário escolhe fazer outra alteração, voltar ao menu anterior ou sair
	do{
		printf("\n\n[1] Fazer outra alteração\n[2] Voltar ao menu de clientes\n[3] Sair\n\nQual opção desejada? "); scanf("%i", &sair); getchar();
		
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
					printf("Valor inválido, aperte qualquer tecla para tentar novamente");
					getch();
				}
			}
		}
	}
	
	while(sair != 1 || sair != 2 || sair != 3);
	
}
