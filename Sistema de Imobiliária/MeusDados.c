#include <stdio.h>
#include <locale.h>

int MeusDados(){
	
	int contador, contadorarq, idade;
	char cpf[14], nome[300], creci[7], usu[100], usu_1[100], senha[100];
	
	FILE* arquivo;
	
	printf("Confirme seu nome de usuário: "); gets(usu_1);
	
	system("cls");
	
	arquivo = fopen("corretores.txt", "r");		//abre o arquivo em modo leitura
		
	while(!feof(arquivo)){
		fscanf(arquivo, "%s %s %s %s %i %s %i\n", usu, senha, nome, cpf, &idade, creci, &contador);
		
		if(strcmp(usu_1, usu) == 0){
		
			colocarEspaco(nome);	//chama a função "colocarEspaco" para trocar o '+' pelo espaço
			formatarCPF(cpf);		//chama a função "formatarCPF" para exibir o cpf formatado
			
			printf("\nReferência do corretor: %i", contador);
			printf("\nPrimeiro nome do usuário: %s", usu);
			printf("\nSenha: %s", senha);
			printf("\nNome: %s", nome);
			printf("\nCPF: %s", cpf);
			printf("\nIdade: %i", idade);
			printf("\nCRECI: %s", creci);
			printf("\n");
		}
	}
	
	fclose(arquivo);
	
	printf("\nPressione qualquer tecla para voltar ao menu");
	getch();
	
	return 3;
}
