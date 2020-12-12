#include <stdio.h>
#include <locale.h>

//Fun��o que, no fim, retorna ao menu do administrador
int ExcluirCliente(){
	
	setlocale(LC_ALL,"Portuguese");	
	system("cls");
	
	//declara 3 vari�veis do tipo FILE
	FILE* arquivo;				//um para o arquivo de corretores original
	FILE* copia_arquivo;		//um para copiar os cadastros n�o exclu�dos num segundo arquivo
	FILE* contador_arquivo;		//um para consertar a refer�ncia dos cadastros n�o exclu�dos
	char cpf[14], nome[100], cpf_cnpj[23], tel[12];
	int num_cliente, contador, contadorarq, sair, p;
	
	arquivo = fopen("clientes.txt", "r");				//abre o arquivo original em modo leitura
	copia_arquivo = fopen("copia_clientes.txt", "w");	//abre o arquivo para c�pia em modo grava��o
	
	ExibirCliente_Alterar_Excluir();
	
	printf("\nDigite o n�mero do cliente que deseja excluir: "); scanf("%i", &num_cliente); getchar();	//pergunta ao usu�rio qual corretor deseja excluir
	
	//loop que passa por cada linha do arquivo original
	while(!feof(arquivo)){
		fscanf(arquivo, "%i %s %s %s %i\n", &p, nome, cpf_cnpj, tel, &contador);
		
		//essa condi��o compara a refer�ncia do cliente no arquivo com o n�mero que o usu�rio digitou
		if(contador != num_cliente){
			
			fprintf(copia_arquivo, "%i %s %s %s %i\n", p, nome, cpf_cnpj, tel, contador);
		}
	}
	
	fclose(arquivo);
	fclose(copia_arquivo);
	
	//exclui o arquivo original e renomeia a c�pia para o nome do original
	system("del clientes.txt");
	system("rename copia_clientes.txt clientes.txt");
	
	system("cls");
	
	//se n�o existir um cliente com o n�mero que o usu�rio digitou, n�o haver� exclus�o
	if (num_cliente > contador){
		printf("N�mero n�o cadastrado, exclus�o n�o conclu�da");
	}
	else{
		printf("Exclus�o conclu�da");
		
		//j� que temos um cliente a menos, o arquivo que controla a quantidade de clientes cadastrados diminui 1
		contador_arquivo = fopen("contadorclientes.txt", "r");			//abre o arquivo de n�mero de clientes em modo leitura
		fscanf(contador_arquivo, "%i", &contadorarq);					//escaneia o n�mero presente no arquivo
		fclose(contador_arquivo);										//fecha o arquivo
	
		contadorarq -= 1;				//diminui 1
	
		contador_arquivo = fopen("contadorclientes.txt", "w");			//abre o arquivo de n�mero de clientes em modo escrita
		fprintf(contador_arquivo, "%i", contadorarq);					//printa no arquivo o novo n�mero
		fclose(contador_arquivo);										//fecha o arquivo
	}
	
	//Ao final, o usu�rio escolhe fazer outra exclus�o, voltar ao menu anterior ou sair
	do{
		printf("\n\n[1] Fazer outra exclus�o\n[2] Voltar ao menu de corretores\n[3] Sair\n\nQual op��o desejada? "); scanf("%i", &sair); getchar();
		
		if(sair == 1){
			return 26;
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
int ExcluirClienteCorretor(){
	
	setlocale(LC_ALL,"Portuguese");	
	system("cls");
	
	//declara 3 vari�veis do tipo FILE
	FILE* arquivo;				//um para o arquivo de corretores original
	FILE* copia_arquivo;		//um para copiar os cadastros n�o exclu�dos num segundo arquivo
	FILE* contador_arquivo;		//um para consertar a refer�ncia dos cadastros n�o exclu�dos
	char cpf[14], nome[100], cpf_cnpj[23], tel[12];
	int num_cliente, contador, contadorarq, sair, p;
	
	arquivo = fopen("clientes.txt", "r");				//abre o arquivo original em modo leitura
	copia_arquivo = fopen("copia_clientes.txt", "w");	//abre o arquivo para c�pia em modo grava��o
	
	ExibirCliente_Alterar_Excluir();
	
	printf("\nDigite o n�mero do cliente que deseja excluir: "); scanf("%i", &num_cliente); getchar();	//pergunta ao usu�rio qual corretor deseja excluir
	
	//loop que passa por cada linha do arquivo original
	while(!feof(arquivo)){
		fscanf(arquivo, "%i %s %s %s %i\n", &p, nome, cpf_cnpj, tel, &contador);
		
		//essa condi��o compara a refer�ncia do cliente no arquivo com o n�mero que o usu�rio digitou
		if(contador != num_cliente){
			
			fprintf(copia_arquivo, "%i %s %s %s %i\n", p, nome, cpf_cnpj, tel, contador);
		}
	}
	
	fclose(arquivo);
	fclose(copia_arquivo);
	
	//exclui o arquivo original e renomeia a c�pia para o nome do original
	system("del clientes.txt");
	system("rename copia_clientes.txt clientes.txt");
	
	system("cls");
	
	//se n�o existir um cliente com o n�mero que o usu�rio digitou, n�o haver� exclus�o
	if (num_cliente > contador){
		printf("N�mero n�o cadastrado, exclus�o n�o conclu�da");
	}
	else{
		printf("Exclus�o conclu�da");
		
		//j� que temos um cliente a menos, o arquivo que controla a quantidade de clientes cadastrados diminui 1
		contador_arquivo = fopen("contadorclientes.txt", "r");			//abre o arquivo de n�mero de clientes em modo leitura
		fscanf(contador_arquivo, "%i", &contadorarq);					//escaneia o n�mero presente no arquivo
		fclose(contador_arquivo);										//fecha o arquivo
	
		contadorarq -= 1;				//diminui 1
	
		contador_arquivo = fopen("contadorclientes.txt", "w");			//abre o arquivo de n�mero de clientes em modo escrita
		fprintf(contador_arquivo, "%i", contadorarq);					//printa no arquivo o novo n�mero
		fclose(contador_arquivo);										//fecha o arquivo
	}
	
	//Ao final, o usu�rio escolhe fazer outra exclus�o, voltar ao menu anterior ou sair
	do{
		printf("\n\n[1] Fazer outra exclus�o\n[2] Voltar ao menu de clientes\n[3] Sair\n\nQual op��o desejada? "); scanf("%i", &sair); getchar();
		
		if(sair == 1){
			return 30;
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
