#include <stdio.h>
#include <locale.h>

//essa parte do programa serve apenas para salvar separadamente todas as funções utilizadas no cadastro, exibição, alteração e exclusão

//função que lê o '+' gravado no arquivo e imprime um espaço no lugar
void colocarEspaco(char texto[]){		//função void com parâmetro char com vetor
	
	int c;
	
	for(c = 0; c < strlen(texto); c++){		//faz o loop de acordo com o tamanho do texto do arquivo
		
		if(texto[c] == '+'){				//lendo cada caractere, se for um '+' ele coloca no lugar um espaço
			texto[c] = ' ';
		}	
	}	
}

//função que adiciona um '+' no lugar do espaço na hora de gravar no arquivo
void espaco(char texto[]){		//função void com parâmetro char com vetor
	
	int c;
	
	for(c = 0; c <= strlen(texto); c++){		//faz o loop de acordo com o tamanho do texto do arquivo
		
		if(texto[c] == ' '){					//lendo cada caractere, se for um espaço ele coloca no lugar um '+'
			texto[c] = '+';
		}
	}
}

//função para formatar o cpf
void formatarCPF(char texto[]){		//função void com parâmetro char com vetor
	
	int c;
	char novo[14];
	
	//esse loop percorre todo o texto do cpf informado pelo usuário e faz
	//com que uma nova variável receba os números do cpf original
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
	
	//insere os pontos "." e os traços "-" onde necessário
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
	
	//esse loop percorre todo o texto do cnpj informado pelo usuário e faz
	//com que uma nova variável receba os números do cnpj original
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
	
	//insere os pontos "." , os traços "-" e as barras "/" onde necessário
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
	
	//esse loop percorre todo o texto do telefone informado pelo usuário e faz
	//com que uma nova variável receba os números do telefone original
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
	
	//insere os parenteses "(" ")" , os traços "-" e os espaços onde necessário
	novo[0] = '(';
	novo[3] = ')';
	novo[4] = ' ';
	novo[10] = '-';
	
	for(i = 0; i <= 15; i++){
		texto[i] = novo[i];
	}
	
}

//função que guarda a quantidade de imóveis ou usuários cadastrados
int contadorImoveis(char texto[]){		//função int com parâmetro char com vetor
	
	FILE* arquivo;
	int contador;
	
	arquivo = fopen(texto, "r");		//abre o arquivo em modo leitura
	fscanf(arquivo, "%i\n", &contador);		//lê o valor que está no arquivo
	fclose(arquivo);					//fecha o arquivo
	
	contador ++;								//adiciona 1 ao valor lido
	
	arquivo = fopen(texto, "w");		//abre o arquivo em modo gravação
	fprintf(arquivo, "%i\n", contador);		//imprime no arquivo o novo valor
	fclose(arquivo);					//fecha o arquivo
	
	return contador;							//função retorna o novo valor
}
