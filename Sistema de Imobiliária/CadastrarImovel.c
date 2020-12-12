#include <stdio.h>
#include <locale.h>

//função para cadastrar imóvel
int CadastrarImovel(){ //função void sem parâmetro
	
	setlocale(LC_ALL, "Portuguese");
	system("cls");		//atualiza a tela
	
	int referencia, contador, metragem, qtd_comodos, valor, aluguel, sair, tipo;
	char proprietario[300], endereco[300], ponto_referencia[300];		//variáveis para guardar no arquivo
	FILE* arquivo;
	FILE* contador_arquivo;
	FILE* referencia_arquivo;			//declara três arquivos textos
	
	arquivo = fopen("imoveis.txt", "a+");						//abre um arquivo em modo append para adicionar ao final do arquivo um novo cadastro
	contador_arquivo = fopen("contadorimoveis.txt", "r");		//abre um arquivo para atualizar o número de cadastros
	referencia_arquivo = fopen("referenciaimoveis.txt", "r");		//abre um arquivo em modo leitura para salvar a referência 
	
	referencia = contadorImoveis("referenciaimoveis.txt");		//Variável referência recebe o valor da função contadorImóveis do arquivo de referências
	
	printf("\t\tCadastro de Imóvel\n");
	
	printf("Cadastrando imóvel: %i\n", referencia);				//mostra na tela qual a referência do imóvel que está sendo cadastrado
	
	printf("\nTipo de imóvel ([1] Residencial / [2] Comercial): "); scanf("%i", &tipo); getchar();
	
	printf("\nNome do proprietário: "); gets(proprietario); espaco(proprietario);			//salva as variáveis e logo em seguida usa a função "espaço" onde necessário
	
	printf("\nEndereço: "); gets(endereco); espaco(endereco);
	
	printf("\nValor do Imóvel: "); scanf("%i", &valor); getchar();
	
	printf("\nValor para aluguel: "); scanf("%i", &aluguel); getchar();
	
	printf("\nMetragem: "); scanf("%i", &metragem); getchar();
	
	printf("\nQuantidade de cômodos: "); scanf("%i", &qtd_comodos); getchar();
	
	printf("\nPonto de referência: "); gets(ponto_referencia); espaco(ponto_referencia);
	
	
	fprintf(arquivo, "%i %s %s %i %i %i %i %s %i\n", tipo, proprietario, endereco, valor, aluguel, metragem, qtd_comodos, ponto_referencia, referencia);		//salva no arquivo os dados e a referência
	
	//Chama a função que adiciona mais um ao arquivo texto
	contadorImoveis("contadorimoveis.txt");
	
	fclose(arquivo);
	fclose(referencia_arquivo);
	fclose(contador_arquivo);
	
	system("cls");
	printf("Cadastro efetuado");
	
	//Ao final, o usuário escolhe voltar ao menu anterior ou sair
	do{
		printf("\n\n[1] Voltar ao menu de imóveis\n[2] Sair\n\nQual opção desejada? "); scanf("%i", &sair); getchar();
		if(sair == 1){
			return 6;
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
