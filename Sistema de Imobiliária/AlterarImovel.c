#include <stdio.h>
#include <locale.h>

//função para alterar um cadastro
int AlterarImovel(){	//função void sem parâmetro
	
	setlocale(LC_ALL, "Portuguese");
	system("cls");		//atualiza a tela
	
	FILE* arquivo;
	FILE* copia_arquivo;				//abre dois arquivos
	char endereco[300], proprietario[100], ponto_referencia[300];
	char novo_endereco[300], novo_proprietario[100], novo_ponto_referencia[300];	
	int num_imovel, contador, metragem, aluguel, tipo, novo_aluguel, qtd_comodos, novo_metragem, novo_qtd_comodos, valor, novo_valor, novo_tipo, sair;			//variáveis para ler e gravar no arquivo
	
	arquivo = fopen("imoveis.txt", "r");				//abre o arquivo com os cadastros em modo leitura
	copia_arquivo = fopen("copia_imoveis.txt", "w");	//abre um arquivo inicialmente vazio em modo gravação
	
	ExibirImovel_Alterar_Excluir();
	
	printf("Digite o número do imóvel que deseja alterar: "); scanf("%i", &num_imovel); getchar();		//pede a referência do imóvel
	
	while(!feof(arquivo)){			//loop que passa por cada linha do arquivo
		fscanf(arquivo, "%i %s %s %i %i %i %i %s %i\n", &tipo, proprietario, endereco, &valor, &aluguel, &metragem, &qtd_comodos, ponto_referencia, &contador);		//lê as variáveis do arquivo
		
		if(contador != num_imovel){			//compara o número que o usuário digitou com a referência cadastrada no arquivo
			fprintf(copia_arquivo, "%i %s %s %i %i %i %i %s %i\n", tipo, proprietario, endereco, valor, aluguel, metragem, qtd_comodos, ponto_referencia, contador);	//se for diferente, os 
		}																																//dados antigos são 
		else{																															//gravados num novo arquivo
		
			system("cls");		//atualiza a tela
			
			printf("\nInserindo os novos dados\n");			//se forem iguais, insere o novo cadastro
			
			printf("\nTipo de imóvel ([1] Residencial / [2] Comercial): "); scanf("%i", &novo_tipo); getchar();
			printf("\nNome do proprietário: "); gets(novo_proprietario); espaco(novo_proprietario);
			printf("\nEndereço: "); gets(novo_endereco); espaco(novo_endereco);
			printf("\nValor do imóvel: "); scanf("%i", &novo_valor); getchar();
			printf("\nValor para aluguel: "); scanf("%i", &novo_aluguel); getchar();
			printf("\nMetragem: "); scanf("%i", &novo_metragem); getchar();
			printf("\nQuantidade de cômodos: "); scanf("%i", &novo_qtd_comodos); getchar();
			printf("\nPonto de referência: "); gets(novo_ponto_referencia); espaco(novo_ponto_referencia);
		
			fprintf(copia_arquivo, "%i %s %s %i %i %i %i %s %i\n", novo_tipo, novo_proprietario, novo_endereco, novo_valor, novo_aluguel, novo_metragem, novo_qtd_comodos, novo_ponto_referencia, contador);
		}
	}
	
	fclose(arquivo);
	fclose(copia_arquivo);
	
	system("del imoveis.txt");		//deleta o arquivo original e renomeia o arquivo novo para o nome do original
	system("rename copia_imoveis.txt imoveis.txt");
	
	system("cls");
	
	//se não existir um imóvel com o número que o usuário digitou, não haverá alteração
	if(num_imovel > contador){
		printf("\nNúmero não cadastrado, alteração não concluída");
	}
	else{
		printf("\nAlteração concluída");
	}
	
	//Ao final, o usuário escolhe voltar ao menu anterior ou sair
	do{
		printf("\n\n[1] Fazer outra alteração\n[2] Voltar ao menu de imóveis\n[3] Sair\n\nQual opção desejada? "); scanf("%i", &sair); getchar();
		
		if(sair == 1){
			return 12;
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
