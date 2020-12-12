#include <stdio.h>
#include <locale.h>

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

//fun��o que guarda a quantidade de im�veis ou usu�rios cadastrados
int contadorImoveis(char texto[]){		//fun��o int com par�metro char com vetor
	
	FILE* arquivo;
	int cod;
	
	arquivo = fopen(texto, "r");		//abre o arquivo em modo leitura
	fscanf(arquivo, "%i\n", &cod);		//l� o valor que est� no arquivo
	fclose(arquivo);					//fecha o arquivo
	
	cod ++;								//adiciona 1 ao valor lido
	
	arquivo = fopen(texto, "w");		//abre o arquivo em modo grava��o
	fprintf(arquivo, "%i\n", cod);		//imprime no arquivo o valor original do arquivo +1
	fclose(arquivo);					//fecha o arquivo
	
	return cod;							//fun��o retorna o valor original do arquivo +1
}

void cadastrarCorretor(){
	
	system("cls");			//atualiza a tela
	
	FILE* arquivo;
	FILE* contador_arquivo;
	char usu[100], senha[100], cpf[12], nome[300], creci[7];
	int idade, contador, contadorarq;
	
	arquivo = fopen("corretores.txt", "a+");					//abre o arquivo para cadastro em modo "append"
	contador_arquivo = fopen("contadorcorretores.txt", "r");	//abre o arquivo para contador de corretores
	
	contador = contadorImoveis("contadorcorretores.txt");		//vari�vel "contador" recebe a fun��o "contadorImoveis"
	
	printf("\t\tCadastro de Corretor\t\t");
	
	printf("\nCadastrando corretor: %i", contador);				//a vari�vel contador recebe o valor que est� no arquivo que controla a quantidade de corretores
	
	printf("\nPrimeiro nome do usu�rio: "); gets(usu);
	printf("\nSenha: "); gets(senha);
	printf("\nNome: "); gets(nome); espaco(nome);				//pergunta ao usu�rio os dados a serem cadastrados e logo em seguida � usada a fun��o "espa�o"
	printf("\nCPF (somente n�meros): "); gets(cpf);
	printf("\nIdade: "); scanf("%i", &idade); getchar();
	printf("\nCRECI: "); gets(creci);
	
	//como para exercer a fun��o de corretor � necess�rio ter mais de 18 anos, o programa n�o permite menores serem cadastrados
	if(idade >= 18){
		fprintf(arquivo, "%s %s %s %s %i %s %i\n", usu, senha, nome, cpf, idade, creci, contador);
		printf("\nCadastro efetuado");	
	}
	else{
		printf("\nIdade n�o permitida para exercer a profiss�o, cadastro n�o efetuado");
		
		//j� que o cadastro n�o pode ser efetuado, o arquivo que controla a quantidade de corretores diminui 1 unidade
		fscanf(contador_arquivo, "%i", &contadorarq);
		fclose(contador_arquivo);
	
		contadorarq -= 1;
	
		contador_arquivo = fopen("contadorcorretores.txt", "w");
		fprintf(contador_arquivo, "%i", contadorarq);
		fclose(contador_arquivo);
	}
	
	fclose(arquivo);
}

void exibirCorretor(){
	
	system("cls");
	
	int contador, contadorarq, idade;
	char cpf[14], nome[300], creci[7], usu[100], senha[100];
	
	FILE* arquivo;
	FILE* contador_arquivo;
	
	arquivo = fopen("corretores.txt", "r");		//abre o arquivo em modo leitura
	contador_arquivo = fopen("contadorcorretores.txt", "r");
	
	fscanf(contador_arquivo, "%i", &contadorarq);
	
	printf("Quantidade de corretores cadastrados: %i\n\n", contadorarq);
	
	if(contadorarq != 0){
		while(!feof(arquivo)){
			fscanf(arquivo, "%s %s %s %s %i %s %i\n", usu, senha, nome, cpf, &idade, creci, &contador);
			
			colocarEspaco(nome);	//chama a fun��o "colocarEspaco" para trocar o '+' pelo espa�o
			formatarCPF(cpf);		//chama a fun��o "formatarCPF" para exibir o cpf formatado
			
			printf("\nRefer�ncia do corretor: %i", contador);
			printf("\nPrimeiro nome do usu�rio: %s", usu);
			printf("\nSenha: %s", senha);
			printf("\nNome: %s", nome);
			printf("\nCPF: %s", cpf);
			printf("\nIdade: %i", idade);
			printf("\nCRECI: %s", creci);
			printf("\n");
		}
	}
	else{
		printf("N�o h� corretores cadastrados");
	}
	
	fclose(arquivo);
}

void alterarCorretor(){
	
	system("cls");
	
	FILE* arquivo;
	FILE* copia_arquivo;				//abre dois arquivos
	char cpf[14], nome[300], creci[7], usu[100], senha[100];
	char novo_cpf[14], novo_nome[300], novo_creci[7], novo_usu[100], novo_senha[100];
	int contador, num_corretor, idade, novo_idade;
	
	arquivo = fopen("corretores.txt", "r");				//abre o arquivo com os cadastros em modo leitura
	copia_arquivo = fopen("copia_corretores.txt", "w");	//abre um arquivo inicialmente vazio em modo grava��o
	
	exibirCorretor();
	
	printf("\nDigite o n�mero do corretor que deseja alterar: "); scanf("%i", &num_corretor); getchar();		//pede a refer�ncia do corretor
	
	while(!feof(arquivo)){			//loop que passa por cada linha do arquivo
		fscanf(arquivo, "%s %s %s %s %i %s %i\n", usu, senha, nome, cpf, &idade, creci, &contador);								//l� as vari�veis do arquivo
		
		if(contador != num_corretor){			//compara o n�mero que o usu�rio digitou com a refer�ncia cadastrada no arquivo
			fprintf(copia_arquivo, "%s %s %s %s %i %s %i\n", usu, senha, nome, cpf, idade, creci, contador);				//se for diferente, os dados s�o gravados num novo arquivo 
		}																														
		else{																							//se for igual, faz um novo cadastro								
			
			system("cls");		//atualiza a tela
			
			printf("\nInserindo novo cadastro\n");
			
			printf("Primeiro nome do usu�rio: "); gets(novo_usu);
			
			printf("Senha: "); gets(senha);						
			
			printf("\nNome: "); gets(novo_nome); espaco(novo_nome);
			
			printf("\nCPF (somente n�meros): "); gets(novo_cpf);
			
			printf("\nIdade: "); scanf("%i", &novo_idade); getchar();
			
			printf("\nCRECI: "); gets(novo_creci);
			
			fprintf(copia_arquivo, "%s %s %s %s %i %s %i\n", novo_usu, novo_senha, novo_nome, novo_cpf, novo_idade, novo_creci, contador);
		}
	}
	
	fclose(arquivo);
	fclose(copia_arquivo);
	
	system("del corretores.txt");		//deleta o arquivo original e renomeia o arquivo novo para o nome do original
	system("rename copia_corretores.txt corretores.txt");
	
	//se n�o existir um corretor com o n�mero que o usu�rio digitou, n�o haver� altera��o
	if(num_corretor > contador){
		printf("\nN�mero n�o cadastrado, altera��o n�o conclu�da");
	}
	else{
		printf("\nAltera��o conclu�da");
	}
}

void excluirCorretor(){
	
	system("cls");
	
	//declara 3 vari�veis do tipo FILE
	FILE* arquivo;				//um para o arquivo de corretores original
	FILE* copia_arquivo;		//um para copiar os cadastros n�o exclu�dos num segundo arquivo
	FILE* contador_arquivo;		//um para consertar a refer�ncia dos cadastros n�o exclu�dos
	char cpf[14], nome[300], creci[7], usu[100], senha[100];
	int idade, num_corretor, contador, contadorarq;
	
	arquivo = fopen("corretores.txt", "r");				//abre o arquivo original em modo leitura
	copia_arquivo = fopen("copia_corretores.txt", "w");	//abre o arquivo para c�pia em modo grava��o
	
	exibirCorretor();
	
	printf("\nDigite o n�mero do corretor que deseja excluir: "); scanf("%i", &num_corretor); getchar();	//pergunta ao usu�rio qual corretor deseja excluir
	
	//loop que passa por cada linha do arquivo original
	while(!feof(arquivo)){
		fscanf(arquivo, "%s %s %s %s %i %s %i\n", usu, senha, nome, cpf, &idade, creci, &contador);
		
		//essa condi��o compara a refer�ncia do im�vel no arquivo com o n�mero que o usu�rio digitou
		if(contador != num_corretor){
			
			//ap�s fazer a compara��o anterior, agora compara se a refer�ncia do im�vel cadastrado � maior que o n�mero digitado
			//se for maior, o im�vel � salvo com o n�mero da refer�ncia dele -1, assim todos os im�veis continuam com a refer�ncia na ordem 
			if(contador > num_corretor){
				fprintf(copia_arquivo, "%s %s %s %s %i %s %i\n", usu, senha, nome, cpf, idade, creci, (contador - 1));
			}
			else{
				fprintf(copia_arquivo, "%s %s %i %s %i\n", usu, senha, nome, cpf, idade, creci, contador);;
			}
		}
	}
	
	fclose(arquivo);
	fclose(copia_arquivo);
	
	//exclui o arquivo original e renomeia a c�pia para o nome do original
	system("del corretores.txt");
	system("rename copia_corretores.txt corretores.txt");
	
	//se n�o existir um corretor com o n�mero que o usu�rio digitou, n�o haver� exclus�o
	if (num_corretor > contador){
		printf("\nN�mero n�o cadastrado, exclus�o n�o conclu�da");
	}
	else{
		printf("\nExclus�o conclu�da");
		
		//j� que temos um corretor a menos, o arquivo que controla a quantidade de corretores cadastrados diminui 1
		contador_arquivo = fopen("contadorcorretores.txt", "r");		//abre o arquivo de n�mero de corretores em modo leitura
		fscanf(contador_arquivo, "%i", &contadorarq);					//escaneia o n�mero presente no arquivo
		fclose(contador_arquivo);										//fecha o arquivo
	
		contadorarq -= 1;				//diminui 1
	
		contador_arquivo = fopen("contadorcorretores.txt", "w");		//abre o arquivo de n�mero de corretores em modo escrita
		fprintf(contador_arquivo, "%i", contadorarq);					//printa no arquivo o novo n�mero
		fclose(contador_arquivo);										//fecha o arquivo
	}
}

int MenuCorretor(){
	
	system("cls");

	int opc, opcaologin;
	
	printf("[1] Cadastrar Corretor\n[2] Alterar Corretor\n[3] Excluir Corretor\n[4] Exibir Corretor\n[5] Voltar\n[6] Sair\n\n"); 
	
	printf("Qual op��o desejada? "); scanf("%i", &opc); getchar();
	
	switch(opc){
		
		case 1:
			cadastrarCorretor();		//se for a op��o 1, chama a fun��o "cadastrarCorretor"
			printf("\n\nAperte uma tecla para voltar ao menu de corretores");
			getch();
			opcaologin = 9;
			break;
		case 2:							//se for a op��o 2, chama a fun��o "alterarCorretor"
			alterarCorretor();
			printf("\n\nAperte uma tecla para voltar ao menu de corretores");
			getch();
			opcaologin = 9;
			break;
		case 3:							//se for a op��o 3, chama a fun��o "excluirCorretor"
			excluirCorretor();
			printf("\n\nAperte uma tecla para voltar ao menu de corretores");
			getch();
			opcaologin = 9;
			break;
		case 4:							//se for a op��o 4, chama a fun��o "exibirCorretor"
			exibirCorretor();
			printf("\n\nAperte uma tecla para voltar ao menu de corretores");
			getch();
			opcaologin = 9;
			break;
		case 5:				//se for op��o 5, retorna ao menu principal
			opcaologin = 4;
			break;
		case 6:				//se for op��o 6, encerra o programa
			system("cls");
			opcaologin = 99;
			break;
		default:
			system("cls");
			printf("Op��o incorreta");
			printf("\n\nAperte uma tecla para voltar ao menu de corretores");
			getch();
			system("cls");
			return MenuCorretor();
			break;
	}
	
	return opcaologin;		//retorna o valor de opcaologin
}
