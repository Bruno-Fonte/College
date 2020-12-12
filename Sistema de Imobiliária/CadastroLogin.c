#include <stdio.h>
#include <locale.h>

FILE* arquivo;

int Cadastrologin(){	
	
	setlocale(LC_ALL, "Portuguese");
	
	char log[30], sen[30], nome[100], cpf[14], creci[7];
	int idade;
	
	printf("Informe o novo cadastro:\n\n");
	printf("Login................: "); gets(log);  // Informa o login e a senha, para cadastrar usuario.
	printf("Senha................: "); gets(sen);
	printf("Nome.................: "); gets(nome);
	printf("CPF (somente números): "); gets(cpf);
	printf("Idade................: "); scanf("%i", &idade);
	printf("CRECI................: "); gets(creci);
	getchar(); // limpa o <enter> do scanf anterior

	if(idade >= 18){
		
		arquivo = fopen("LoginUsuario.txt","a+"); // abrir o arquivo em modo gravação
		fprintf(arquivo,"%s %s %s %s %i %s\n", log, sen, nome, cpf, idade, creci); // escrever no arquivo
		fclose(arquivo); // fechar o uso do arquivo
		
		printf("\nUsuário cadastrado com sucesso!");
	}
	else{
		printf("\nUsuário não tem idade mínima para exercer a função de corretor\n\nUsuário não cadastrado");
	}
	
	printf("\nPressione qualquer tecla para voltar");
	getch();
	system("cls");	  
	return 4;  	
}

