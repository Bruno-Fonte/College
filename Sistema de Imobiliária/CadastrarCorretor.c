#include <stdio.h>
#include <locale.h>

int CadastrarCorretor(){
	
	setlocale(LC_ALL, "Portuguese");
	system("cls");			//atualiza a tela
	
	FILE* arquivo;
	FILE* referencia_arquivo;
	FILE* contador_arquivo;
	char usu[100], senha[100], cpf[12], nome[300], creci[7];
	int idade, referencia, contador, contadorarq, sair;
	
	arquivo = fopen("corretores.txt", "a+");					//abre o arquivo para cadastro em modo "append"
	referencia_arquivo = fopen("referenciacorretores.txt", "r");	//abre o arquivo para salvar a refer�ncia dos corretores
	contador_arquivo = fopen("contadorcorretores.txt", "r");
	
	referencia = contadorImoveis("referenciacorretores.txt");		//vari�vel "contador" recebe a fun��o "contadorImoveis"
	
	printf("\t\tCadastro de Corretor\t\t");
	
	printf("\nCadastrando corretor: %i", referencia);				//a vari�vel contador recebe o valor que est� no arquivo que controla a quantidade de corretores
	
	printf("\n\nPrimeiro nome do usu�rio: "); gets(usu);
	printf("\nSenha: "); gets(senha);
	printf("\nNome: "); gets(nome); espaco(nome);				//pergunta ao usu�rio os dados a serem cadastrados e logo em seguida � usada a fun��o "espa�o"
	printf("\nCPF (somente n�meros): "); gets(cpf);
	printf("\nIdade: "); scanf("%i", &idade); getchar();
	printf("\nCRECI: "); gets(creci);
	
	//como para exercer a fun��o de corretor � necess�rio ter mais de 18 anos, o programa n�o permite menores serem cadastrados
	if(idade >= 18){
		fprintf(arquivo, "%s %s %s %s %i %s %i\n", usu, senha, nome, cpf, idade, creci, referencia);
		printf("\nCadastro efetuado");
		
		//Chama a fun��o que tualiza o n�mero de corretores cadastrados
		contadorImoveis("contadorcorretores.txt");
		
	}
	else{
		printf("\nIdade n�o permitida para exercer a profiss�o, cadastro n�o efetuado");
		
		//j� que o cadastro n�o pode ser efetuado, o arquivo que controla a quantidade de corretores diminui 1 unidade
		fscanf(contador_arquivo, "%i", &contadorarq);
		fclose(contador_arquivo);
	
		contadorarq -= 1;
	
		contador_arquivo = fopen("contadorcorretores.txt", "w");
		fprintf(contador_arquivo, "%i", contadorarq);
		fclose(contador_arquivo);
	}
	
	fclose(arquivo);
	fclose(referencia_arquivo);
	fclose(contador_arquivo);
	
	//Ao final, o usu�rio escolhe voltar ao menu anterior ou sair
	do{
		printf("\n\n[1] Voltar ao menu de corretores\n[2] Sair\n\nQual op��o desejada? "); scanf("%i", &sair); getchar();
		
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
