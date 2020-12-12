#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

FILE* arquivo;

int LoginAdm(){	
    
    setlocale(LC_ALL, "Portuguese");
    
    int sair = 0;
    int OpcaoLogin = 0;
     
    char Use[30]; // Usuario desejado 
    char Log[30]; // Senha desejada
    
    char UseU[30]; // Usuario do arquivo texto
    char LogU[30]; // Login do arquivo texto
     
	int U, S; // vari�veis que informam se o login � valido
     
	printf("Login................: "); gets(Use);  // Informa o login e a senha
	printf("Senha................: "); gets(Log);	
	
	arquivo = fopen("LoginAdm.txt","r"); // abrir arquivo em modo leitura
	
	while(!feof(arquivo)){
	
		fscanf(arquivo,"%s %s", UseU, LogU); 	// acessar os dados
		
		if (strcmp(Use, UseU) == 0){			// Faz a compara��o do login digitado, com o que esta no arquivo texto
			U = 0;
		}
		else{
			U = 1;
		}
		
		if(strcmp(Log, LogU) == 0){				// Faz a compara��o da senha digitado, com o que esta no arquivo texto
			S = 0;
		}
		else{
			S = 1;
		}
	}
	
	fclose(arquivo); // fechar o uso do arquivo
	
	//condi��o que valida o usu�rio e a senha digitados
	if (U == 0 && S == 0){
		printf("\nLogin realizado com Sucesso.");
		OpcaoLogin = 4;
	}
	else{		//se o usu�rio ou senha estiver errado, esse menu � apresentado
		printf("\n\nAdministrador n�o cadastrado.");
		printf("\n[1] Tentar novamente\n[2] Voltar\n[3] Sair\n\nQual op��o desejada? ");
		scanf("%i", &sair);
			
			switch(sair){
				case 1:
					OpcaoLogin = 2;
					break;
				case 2:
					OpcaoLogin = 0;
					break;
				case 3:
					OpcaoLogin = 99;
					break;
				
				default:
					OpcaoLogin = 2;
					getch();
					break;
			}
	}
	
	getchar(); // limpar o enter do scanf anterior
	system("cls");
	return OpcaoLogin;
}
