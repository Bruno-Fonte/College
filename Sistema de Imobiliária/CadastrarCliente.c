#include <stdio.h>
#include <locale.h>

//Fun��o que, no fim, retorna ao menu do administrador
int CadastrarCliente(){
	
	setlocale(LC_ALL, "Portuguese");
	system("cls");			//atualiza a tela
	
	FILE* arquivo;
	FILE* referencia_arquivo;
	FILE* contador_arquivo;
	char nome[100], cpf[14], cnpj[23], tel[12];
	int referencia, sair, p;
	p = 0;
	
	arquivo = fopen("clientes.txt", "a+");						//abre o arquivo para cadastro em modo "append"
	contador_arquivo = fopen("contadorclientes.txt", "r");
	referencia_arquivo = fopen("referenciaclientes.txt", "r");	//abre o arquivo para contador de clientes
	
	printf("\t\tCadastro de Cliente\t\t");
		
	printf("\n\n[1] Pessoa F�sica\n[2] Pessoa Jur�dica");
	printf("\n\nOp��o desejada: "); scanf("%i", &p); getchar();
	
	if(p == 1){
		system("cls");
		
		referencia = contadorImoveis("referenciaclientes.txt");		//vari�vel "referencia" recebe a fun��o "contadorImoveis"
		
		printf("\nCadastrando cliente: %i", referencia);
	
		printf("\n\nNome: "); gets(nome); espaco(nome);
		printf("\nCPF (somente n�meros): "); gets(cpf);
		printf("\nTelefone (somente n�meros): "); gets(tel);
		
		fprintf(arquivo, "%i %s %s %s %i\n", p, nome, cpf, tel, referencia);	
		printf("\nCadastro efetuado");
		
		//Chama a fun��o que atualiza o n�mero de cadastros
		contadorImoveis("contadorclientes.txt");
		
		
	}
	else{
		if(p == 2){
			system("cls");
			
			referencia = contadorImoveis("referenciaclientes.txt");		//vari�vel "referencia" recebe a fun��o "contadorImoveis"
			
			printf("\nCadastrando cliente: %i", referencia);			//a vari�vel contador recebe o valor que est� no arquivo que controla a quantidade de clientes
		
			printf("\n\nNome: "); gets(nome); espaco(nome);
			printf("\nCNPJ (somente n�meros): "); gets(cnpj);
			printf("\nTelefone (somente n�meros): "); gets(tel);
			
			fprintf(arquivo, "%i %s %s %s %i\n", p, nome, cnpj, tel, referencia);		
			printf("\nCadastro efetuado");
			
			//Chama a fun��o que atualiza o n�mero de cadastros
			contadorImoveis("contadorclientes.txt");
		}
		else{
			printf("\n\nOp��o incorreta, aperte qualquer tecla para tentar novamente");
			getch();
			return 23;
		}
	}
	
	
	fclose(arquivo);
	fclose(referencia_arquivo);
	fclose(contador_arquivo);
	
	//Ao final, o usu�rio escolhe voltar ao menu anterior ou sair
	do{
		printf("\n\n[1] Voltar ao menu de clientes\n[2] Sair\n\nQual op��o desejada? "); scanf("%i", &sair); getchar();
		
		if(sair == 1){
			return 22;
		}
		else{
			if(sair == 2){
				return 99;
			}
			else{
				printf("Valor inv�lido, aperte qualquer tecla para tentar novamente");
				getch();
			}
		}
	}
	
	while(sair != 1 || sair != 2);
	
}

//Fun��o que, no fim, retorna ao menu do corretor
int CadastrarClienteCorretor(){
	
setlocale(LC_ALL, "Portuguese");
	system("cls");			//atualiza a tela
	
	FILE* arquivo;
	FILE* referencia_arquivo;
	FILE* contador_arquivo;
	char nome[100], cpf[14], cnpj[23], tel[12];
	int referencia, sair, p;
	p = 0;
	
	arquivo = fopen("clientes.txt", "a+");						//abre o arquivo para cadastro em modo "append"
	contador_arquivo = fopen("contadorclientes.txt", "r");
	referencia_arquivo = fopen("referenciaclientes.txt", "r");	//abre o arquivo para contador de clientes
	
	printf("\t\tCadastro de Cliente\t\t");
		
	printf("\n\n[1] Pessoa F�sica\n[2] Pessoa Jur�dica");
	printf("\n\nOp��o desejada: "); scanf("%i", &p); getchar();
	
	if(p == 1){
		system("cls");
		
		referencia = contadorImoveis("referenciaclientes.txt");		//vari�vel "referencia" recebe a fun��o "contadorImoveis"
		
		printf("\nCadastrando cliente: %i", referencia);
	
		printf("\n\nNome: "); gets(nome); espaco(nome);
		printf("\nCPF (somente n�meros): "); gets(cpf);
		printf("\nTelefone (somente n�meros): "); gets(tel);
		
		fprintf(arquivo, "%i %s %s %s %i\n", p, nome, cpf, tel, referencia);	
		printf("\nCadastro efetuado");
		
		//Chama a fun��o que atualiza o n�mero de cadastros
		contadorImoveis("contadorclientes.txt");
		
		
	}
	else{
		if(p == 2){
			system("cls");
			
			referencia = contadorImoveis("referenciaclientes.txt");		//vari�vel "referencia" recebe a fun��o "contadorImoveis"
			
			printf("\nCadastrando cliente: %i", referencia);			//a vari�vel contador recebe o valor que est� no arquivo que controla a quantidade de clientes
		
			printf("\n\nNome: "); gets(nome); espaco(nome);
			printf("\nCNPJ (somente n�meros): "); gets(cnpj);
			printf("\nTelefone (somente n�meros): "); gets(tel);
			
			fprintf(arquivo, "%i %s %s %s %i\n", p, nome, cnpj, tel, referencia);		
			printf("\nCadastro efetuado");
			
			//Chama a fun��o que atualiza o n�mero de cadastros
			contadorImoveis("contadorclientes.txt");
		}
		else{
			printf("\n\nOp��o incorreta, aperte qualquer tecla para tentar novamente");
			getch();
			return 23;
		}
	}
	
	
	fclose(arquivo);
	fclose(referencia_arquivo);
	fclose(contador_arquivo);
	
	//Ao final, o usu�rio escolhe voltar ao menu anterior ou sair
	do{
		printf("\n\n[1] Voltar ao menu de clientes\n[2] Sair\n\nQual op��o desejada? "); scanf("%i", &sair); getchar();
		
		if(sair == 1){
			return 27;
		}
		else{
			if(sair == 2){
				return 99;
			}
			else{
				printf("Valor inv�lido, aperte qualquer tecla para tentar novamente");
				getch();
			}
		}
	}
	
	while(sair != 1 || sair != 2);
	
}
