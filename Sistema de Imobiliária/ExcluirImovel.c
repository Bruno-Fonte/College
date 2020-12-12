#include <stdio.h>
#include <locale.h>

//função para excluir um cadastro
int ExcluirImovel(){		//função void sem parâmetro
	
	setlocale(LC_ALL, "Portuguese");
	system("cls");			//atualiza a tela
	
	//declara 3 variáveis do tipo FILE
	FILE* arquivo;				//um para o arquivo de imóveis original
	FILE* copia_arquivo;		//um para copiar os cadastros não excluídos num segundo arquivo
	FILE* contador_arquivo;		//um para consertar a referência dos cadastros não excluídos
	char endereco[300], proprietario[100], ponto_referencia[300];
	int num_imovel, contador, contadorarq, metragem, qtd_comodos, valor, aluguel, tipo, sair;
	
	arquivo = fopen("imoveis.txt", "r");				//abre o arquivo original em modo leitura
	copia_arquivo = fopen("copia_imoveis.txt", "w");	//abre o arquivo para cópia em modo gravação
	
	ExibirImovel_Alterar_Excluir();		//exibe para o usuário os imóveis cadastrados 
	
	printf("Digite o número do imóvel que deseja excluir: "); scanf("%i", &num_imovel); getchar();	//pergunta ao usuário qual o imóvel deseja excluir
	
	//loop que passa por cada linha do arquivo original
	while(!feof(arquivo)){
		fscanf(arquivo, "%i %s %s %i %i %i %i %s %i\n", &tipo, proprietario, endereco, &valor, &aluguel, &metragem, &qtd_comodos, ponto_referencia, &contador);
		
		//essa condição compara a referência do imóvel no arquivo com o número que o usuário digitou
		if(contador != num_imovel){
			
			fprintf(copia_arquivo, "%i %s %s %i %i %i %i %s %i\n", tipo, proprietario, endereco, valor, aluguel, metragem, qtd_comodos, ponto_referencia, contador); 
		}
	}
	
	fclose(arquivo);
	fclose(copia_arquivo);
	
	system("cls");
	
	//exclui o arquivo original e renomeia a cópia para o nome do original
	system("del imoveis.txt");
	system("rename copia_imoveis.txt imoveis.txt");
	
	//se não existir um imóvel com o número que o usuário digitou, não haverá exclusão
	if (num_imovel > contador){
		printf("Número não cadastrado, exclusão não concluída");
	}
	else{
		printf("\nExclusão concluída");
		
		//já que temos um imóvel a menos, o arquivo que controla a quantidade de imóveis cadastrados diminui 1
		contador_arquivo = fopen("contadorimoveis.txt", "r");		//abre o arquivo de número de imóveis em modo leitura
		fscanf(contador_arquivo, "%i", &contadorarq);				//lê o número presente no arquivo
		fclose(contador_arquivo);									//fecha o arquivo
	
		contadorarq -= 1;											//o número do arquivo diminui em 1 unidade
	
		contador_arquivo = fopen("contadorimoveis.txt", "w");		//abre o arquivo em modo escrita
		fprintf(contador_arquivo, "%i", contadorarq);				//sobrescreve o valor antigo pelo valor atual
		fclose(contador_arquivo);									//fecha o arquivo
	}
	
	//Ao final, o usuário escolhe fazer outra exclusão, voltar ao menu anterior ou sair
	do{
		printf("\n\n[1] Fazer outra exclusão\n[2] Voltar ao menu de imóveis\n[3] Sair\n\nQual opção desejada? "); scanf("%i", &sair); getchar();
		
		if(sair == 1){
			return 13;
		}
		else{
			if(sair == 2){
				return 6;
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
