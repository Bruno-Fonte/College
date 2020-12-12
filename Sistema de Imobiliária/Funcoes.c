#include <stdio.h>
#include <locale.h>

//essa parte do programa serve apenas para salvar separadamente todas as fun��es utilizadas no cadastro, exibi��o, altera��o e exclus�o

//fun��o que l� o '+' gravado no arquivo e imprime um espa�o no lugar
void colocarEspaco(char texto[]){		//fun��o void com par�metro char com vetor
	
	int c;
	
	for(c = 0; c < strlen(texto); c++){		//faz o loop de acordo com o tamanho do texto do arquivo
		
		if(texto[c] == '+'){				//lendo cada caractere, se for um '+' ele coloca no lugar um espa�o
			texto[c] = ' ';
		}	
	}	
}

//fun��o que adiciona um '+' no lugar do espa�o na hora de gravar no arquivo
void espaco(char texto[]){		//fun��o void com par�metro char com vetor
	
	int c;
	
	for(c = 0; c <= strlen(texto); c++){		//faz o loop de acordo com o tamanho do texto do arquivo
		
		if(texto[c] == ' '){					//lendo cada caractere, se for um espa�o ele coloca no lugar um '+'
			texto[c] = '+';
		}
	}
}

//fun��o para formatar o cpf
void formatarCPF(char texto[]){		//fun��o void com par�metro char com vetor
	
	int c;
	char novo[14];
	
	//esse loop percorre todo o texto do cpf informado pelo usu�rio e faz
	//com que uma nova vari�vel receba os n�meros do cpf original
	for(c = 0; c < 15; c++){
		
		if(c != 3 || c != 7 || c != 11){
			if (c >= 4 && c <= 7){
				novo[c] = texto[c - 1];
			}
			else{
				if (c >= 8 && c <= 11){
					novo[c] = texto[c - 2];
				}
				else{
					if (c >= 12){
						novo[c] = texto[c - 3];	
					}
					else{
						novo[c] = texto[c];
					}
				}
			}
		}
	}
	
	//insere os pontos "." e os tra�os "-" onde necess�rio
	novo[3] = '.';
	novo[7] = '.';
	novo[11] = '-';
	
	for (c = 0; c < 15; c++){
		texto[c] = novo[c];
	}
}

void formatarCNPJ(char texto[]){
	
	char novo[17];
	int i;
	
	//esse loop percorre todo o texto do cnpj informado pelo usu�rio e faz
	//com que uma nova vari�vel receba os n�meros do cnpj original
	for(i = 0; i <= 17; i++){
		
		if(i != 2 || i != 6 || i != 10 || i != 15){
			if(i >= 3 && i <= 5){
				novo[i] = texto[i-1];
			}
			else{
				if(i >= 7 && i <= 9){
					novo[i] = texto[i-2];
				}
				else{
					if(i >= 11 && i <= 14){
						novo[i] = texto[i-3];
					}
					else{
						if(i >= 16 && i <= 17){
							novo[i] = texto[i-4];
						}
						else{
							novo[i] = texto[i];
						}
					}
				}
			}
		}
	}
	
	//insere os pontos "." , os tra�os "-" e as barras "/" onde necess�rio
	novo[2] = '.';
	novo[6] = '.';
	novo[10] = '/';
	novo[15] = '-';
	
	for (i = 0; i <= 17; i++){
		texto[i] = novo[i];
	}
	
}

void formatarTelefone(char texto[]){
	
	char novo[15];
	int i;
	
	//esse loop percorre todo o texto do telefone informado pelo usu�rio e faz
	//com que uma nova vari�vel receba os n�meros do telefone original
	for (i = 0; i <= 15; i++){
		if(i != 0 || i != 3 || i != 4 || i != 10){
			if(i <= 2){
				novo[i] = texto[i - 1];
			}
			else{
				if(i >= 5 && i <= 9){
					novo[i] = texto[i-3];
				}
				else{
					if(i >= 11){
						novo[i] = texto[i - 4];
					}
				}
			}
			
		}
	}
	
	//insere os parenteses "(" ")" , os tra�os "-" e os espa�os onde necess�rio
	novo[0] = '(';
	novo[3] = ')';
	novo[4] = ' ';
	novo[10] = '-';
	
	for(i = 0; i <= 15; i++){
		texto[i] = novo[i];
	}
	
}

//fun��o que guarda a quantidade de im�veis ou usu�rios cadastrados
int contadorImoveis(char texto[]){		//fun��o int com par�metro char com vetor
	
	FILE* arquivo;
	int contador;
	
	arquivo = fopen(texto, "r");		//abre o arquivo em modo leitura
	fscanf(arquivo, "%i\n", &contador);		//l� o valor que est� no arquivo
	fclose(arquivo);					//fecha o arquivo
	
	contador ++;								//adiciona 1 ao valor lido
	
	arquivo = fopen(texto, "w");		//abre o arquivo em modo grava��o
	fprintf(arquivo, "%i\n", contador);		//imprime no arquivo o novo valor
	fclose(arquivo);					//fecha o arquivo
	
	return contador;							//fun��o retorna o novo valor
}
