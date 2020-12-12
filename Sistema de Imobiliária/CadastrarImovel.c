#include <stdio.h>
#include <locale.h>

//fun��o para cadastrar im�vel
int CadastrarImovel(){ //fun��o void sem par�metro
	
	setlocale(LC_ALL, "Portuguese");
	system("cls");		//atualiza a tela
	
	int referencia, contador, metragem, qtd_comodos, valor, aluguel, sair, tipo;
	char proprietario[300], endereco[300], ponto_referencia[300];		//vari�veis para guardar no arquivo
	FILE* arquivo;
	FILE* contador_arquivo;
	FILE* referencia_arquivo;			//declara tr�s arquivos textos
	
	arquivo = fopen("imoveis.txt", "a+");						//abre um arquivo em modo append para adicionar ao final do arquivo um novo cadastro
	contador_arquivo = fopen("contadorimoveis.txt", "r");		//abre um arquivo para atualizar o n�mero de cadastros
	referencia_arquivo = fopen("referenciaimoveis.txt", "r");		//abre um arquivo em modo leitura para salvar a refer�ncia 
	
	referencia = contadorImoveis("referenciaimoveis.txt");		//Vari�vel refer�ncia recebe o valor da fun��o contadorIm�veis do arquivo de refer�ncias
	
	printf("\t\tCadastro de Im�vel\n");
	
	printf("Cadastrando im�vel: %i\n", referencia);				//mostra na tela qual a refer�ncia do im�vel que est� sendo cadastrado
	
	printf("\nTipo de im�vel ([1] Residencial / [2] Comercial): "); scanf("%i", &tipo); getchar();
	
	printf("\nNome do propriet�rio: "); gets(proprietario); espaco(proprietario);			//salva as vari�veis e logo em seguida usa a fun��o "espa�o" onde necess�rio
	
	printf("\nEndere�o: "); gets(endereco); espaco(endereco);
	
	printf("\nValor do Im�vel: "); scanf("%i", &valor); getchar();
	
	printf("\nValor para aluguel: "); scanf("%i", &aluguel); getchar();
	
	printf("\nMetragem: "); scanf("%i", &metragem); getchar();
	
	printf("\nQuantidade de c�modos: "); scanf("%i", &qtd_comodos); getchar();
	
	printf("\nPonto de refer�ncia: "); gets(ponto_referencia); espaco(ponto_referencia);
	
	
	fprintf(arquivo, "%i %s %s %i %i %i %i %s %i\n", tipo, proprietario, endereco, valor, aluguel, metragem, qtd_comodos, ponto_referencia, referencia);		//salva no arquivo os dados e a refer�ncia
	
	//Chama a fun��o que adiciona mais um ao arquivo texto
	contadorImoveis("contadorimoveis.txt");
	
	fclose(arquivo);
	fclose(referencia_arquivo);
	fclose(contador_arquivo);
	
	system("cls");
	printf("Cadastro efetuado");
	
	//Ao final, o usu�rio escolhe voltar ao menu anterior ou sair
	do{
		printf("\n\n[1] Voltar ao menu de im�veis\n[2] Sair\n\nQual op��o desejada? "); scanf("%i", &sair); getchar();
		if(sair == 1){
			return 6;
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
