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
	referencia_arquivo = fopen("referenciacorretores.txt", "r");	//abre o arquivo para salvar a referência dos corretores
	contador_arquivo = fopen("contadorcorretores.txt", "r");
	
	referencia = contadorImoveis("referenciacorretores.txt");		//variável "contador" recebe a função "contadorImoveis"
	
	printf("\t\tCadastro de Corretor\t\t");
	
	printf("\nCadastrando corretor: %i", referencia);				//a variável contador recebe o valor que está no arquivo que controla a quantidade de corretores
	
	printf("\n\nPrimeiro nome do usuário: "); gets(usu);
	printf("\nSenha: "); gets(senha);
	printf("\nNome: "); gets(nome); espaco(nome);				//pergunta ao usuário os dados a serem cadastrados e logo em seguida é usada a função "espaço"
	printf("\nCPF (somente números): "); gets(cpf);
	printf("\nIdade: "); scanf("%i", &idade); getchar();
	printf("\nCRECI: "); gets(creci);
	
	//como para exercer a função de corretor é necessário ter mais de 18 anos, o programa não permite menores serem cadastrados
	if(idade >= 18){
		fprintf(arquivo, "%s %s %s %s %i %s %i\n", usu, senha, nome, cpf, idade, creci, referencia);
		printf("\nCadastro efetuado");
		
		//Chama a função que tualiza o número de corretores cadastrados
		contadorImoveis("contadorcorretores.txt");
		
	}
	else{
		printf("\nIdade não permitida para exercer a profissão, cadastro não efetuado");
		
		//já que o cadastro não pode ser efetuado, o arquivo que controla a quantidade de corretores diminui 1 unidade
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
	
	//Ao final, o usuário escolhe voltar ao menu anterior ou sair
	do{
		printf("\n\n[1] Voltar ao menu de corretores\n[2] Sair\n\nQual opção desejada? "); scanf("%i", &sair); getchar();
		
		if(sair == 1){
			return 9;
		}
		else{
			if(sair == 2){
				return 99;
			}
			else{
				printf("Valor inválido, aperte qualquer tecla para tentar novamente");
				getch();
			}
		}
	}
	
	while(sair != 1 || sair != 2);
	
}
