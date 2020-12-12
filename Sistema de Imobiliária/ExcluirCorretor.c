#include <stdio.h>
#include <locale.h>

int ExcluirCorretor(){
	
	setlocale(LC_ALL,"Portuguese");	
	system("cls");
	
	//declara 3 variáveis do tipo FILE
	FILE* arquivo;				//um para o arquivo de corretores original
	FILE* copia_arquivo;		//um para copiar os cadastros não excluídos num segundo arquivo
	FILE* contador_arquivo;		//um para atualizar o número de cadastros
	char cpf[14], nome[300], creci[7], usu[100], senha[100];
	int idade, num_corretor, referencia, contadorarq, sair;
	
	arquivo = fopen("corretores.txt", "r");					//abre o arquivo original em modo leitura
	copia_arquivo = fopen("copia_corretores.txt", "w");		//abre o arquivo para cópia em modo gravação
	
	ExibirCorretor_Alterar_Excluir();
	
	printf("\nDigite o número do corretor que deseja excluir: "); scanf("%i", &num_corretor); getchar();	//pergunta ao usuário qual corretor deseja excluir
	
	//loop que passa por cada linha do arquivo original
	while(!feof(arquivo)){
		fscanf(arquivo, "%s %s %s %s %i %s %i\n", usu, senha, nome, cpf, &idade, creci, &referencia);
		
		//essa condição compara a referência do imóvel no arquivo com o número que o usuário digitou
		if(referencia != num_corretor){
			
			fprintf(copia_arquivo, "%s %s %s %s %i %s %i\n", usu, senha, nome, cpf, idade, creci, referencia);
		}
	}
	
	fclose(arquivo);
	fclose(copia_arquivo);
	
	//exclui o arquivo original e renomeia a cópia para o nome do original
	system("del corretores.txt");
	system("rename copia_corretores.txt corretores.txt");
	
	system("cls");
	
	//se não existir um corretor com o número que o usuário digitou, não haverá exclusão
	if (num_corretor > referencia){
		printf("\nNúmero não cadastrado, exclusão não concluída");
	}
	else{
		printf("\nExclusão concluída");
		
		//já que temos um corretor a menos, o arquivo que controla a quantidade de corretores cadastrados diminui 1
		contador_arquivo = fopen("contadorcorretores.txt", "r");		//abre o arquivo de número de corretores em modo leitura
		fscanf(contador_arquivo, "%i", &contadorarq);					//escaneia o número presente no arquivo
		fclose(contador_arquivo);										//fecha o arquivo
	
		contadorarq -= 1;				//diminui 1
	
		contador_arquivo = fopen("contadorcorretores.txt", "w");		//abre o arquivo de número de corretores em modo escrita
		fprintf(contador_arquivo, "%i", contadorarq);					//printa no arquivo o novo número
		fclose(contador_arquivo);										//fecha o arquivo
	}
	
	//Ao final, o usuário escolhe fazer outra exclusão, voltar ao menu anterior ou sair
	do{
		printf("\n\n[1] Fazer outra exclusão\n[2] Voltar ao menu de corretores\n[3] Sair\n\nQual opção desejada? "); scanf("%i", &sair); getchar();
		
		if(sair == 1){
			return 17;
		}
		else{
			if(sair == 2){
				return 9;
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
