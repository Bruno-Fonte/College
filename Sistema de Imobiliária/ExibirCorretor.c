#include <stdio.h>
#include <locale.h>

int ExibirCorretor(){
	
	setlocale(LC_ALL, "Portuguese");
	system("cls");
	
	int contador, contadorarq, idade, sair;
	char cpf[14], nome[300], creci[7], usu[100], senha[100];
	
	FILE* arquivo;
	FILE* contador_arquivo;
	
	arquivo = fopen("corretores.txt", "r");		//abre o arquivo em modo leitura
	contador_arquivo = fopen("contadorcorretores.txt", "r");
	
	fscanf(contador_arquivo, "%i", &contadorarq);
	
	printf("Quantidade de corretores cadastrados: %i\n\n", contadorarq);
	
	if(contadorarq != 0){
		while(!feof(arquivo)){
			fscanf(arquivo, "%s %s %s %s %i %s %i\n", usu, senha, nome, cpf, &idade, creci, &contador);
			
			colocarEspaco(nome);	//chama a fun��o "colocarEspaco" para trocar o '+' pelo espa�o
			formatarCPF(cpf);		//chama a fun��o "formatarCPF" para exibir o cpf formatado
			
			printf("\nRefer�ncia do corretor: %i", contador);
			printf("\nPrimeiro nome do usu�rio: %s", usu);
			printf("\nSenha: %s", senha);
			printf("\nNome: %s", nome);
			printf("\nCPF: %s", cpf);
			printf("\nIdade: %i", idade);
			printf("\nCRECI: %s", creci);
			printf("\n");
		}
	}
	else{
		printf("N�o h� corretores cadastrados\n");
	}
	
	fclose(arquivo);
	fclose(contador_arquivo);
	
	//Ao final, o usu�rio escolhe voltar ao menu anterior ou sair
	do{
		printf("\n[1] Voltar ao menu de corretores\n[2] Sair\n\nQual op��o desejada? "); scanf("%i", &sair); getchar();
		
		if(sair == 1){
			return 9;
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

//fun��o para exibir os corretores cadastrados sem retornar valor,
//para os casos de alterar e excluir, para que o usu�rio veja os
//corretores cadastrados e selecionar qual deseja fazer a altera��o
//ou exclus�o
int ExibirCorretor_Alterar_Excluir(){
	
	setlocale(LC_ALL, "Portuguese");
	system("cls");
	
	int contador, contadorarq, idade, sair;
	char cpf[14], nome[300], creci[7], usu[100], senha[100];
	
	FILE* arquivo;
	FILE* contador_arquivo;
	
	arquivo = fopen("corretores.txt", "r");		//abre o arquivo em modo leitura
	contador_arquivo = fopen("contadorcorretores.txt", "r");
	
	fscanf(contador_arquivo, "%i", &contadorarq);
	
	printf("Quantidade de corretores cadastrados: %i\n\n", contadorarq);
	
	if(contadorarq != 0){
		while(!feof(arquivo)){
			fscanf(arquivo, "%s %s %s %s %i %s %i\n", usu, senha, nome, cpf, &idade, creci, &contador);
			
			colocarEspaco(nome);	//chama a fun��o "colocarEspaco" para trocar o '+' pelo espa�o
			formatarCPF(cpf);		//chama a fun��o "formatarCPF" para exibir o cpf formatado
			
			printf("\nRefer�ncia do corretor: %i", contador);
			printf("\nPrimeiro nome do usu�rio: %s", usu);
			printf("\nSenha: %s", senha);
			printf("\nNome: %s", nome);
			printf("\nCPF: %s", cpf);
			printf("\nIdade: %i", idade);
			printf("\nCRECI: %s", creci);
			printf("\n");
		}
	}
	else{
		printf("N�o h� corretores cadastrados");
	}
	
	fclose(arquivo);
	fclose(contador_arquivo);
}
