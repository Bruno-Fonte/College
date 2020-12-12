#include <stdio.h>
#include <locale.h>

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

//função que guarda a quantidade de imóveis ou usuários cadastrados
int contadorImoveis(char texto[]){		//função int com parâmetro char com vetor
	
	FILE* arquivo;
	int cod;
	
	arquivo = fopen(texto, "r");		//abre o arquivo em modo leitura
	fscanf(arquivo, "%i\n", &cod);		//lê o valor que está no arquivo
	fclose(arquivo);					//fecha o arquivo
	
	cod ++;								//adiciona 1 ao valor lido
	
	arquivo = fopen(texto, "w");		//abre o arquivo em modo gravação
	fprintf(arquivo, "%i\n", cod);		//imprime no arquivo o valor original do arquivo +1
	fclose(arquivo);					//fecha o arquivo
	
	return cod;							//função retorna o valor original do arquivo +1
}

void cadastrarCorretor(){
	
	system("cls");			//atualiza a tela
	
	FILE* arquivo;
	FILE* contador_arquivo;
	char usu[100], senha[100], cpf[12], nome[300], creci[7];
	int idade, contador, contadorarq;
	
	arquivo = fopen("corretores.txt", "a+");					//abre o arquivo para cadastro em modo "append"
	contador_arquivo = fopen("contadorcorretores.txt", "r");	//abre o arquivo para contador de corretores
	
	contador = contadorImoveis("contadorcorretores.txt");		//variável "contador" recebe a função "contadorImoveis"
	
	printf("\t\tCadastro de Corretor\t\t");
	
	printf("\nCadastrando corretor: %i", contador);				//a variável contador recebe o valor que está no arquivo que controla a quantidade de corretores
	
	printf("\nPrimeiro nome do usuário: "); gets(usu);
	printf("\nSenha: "); gets(senha);
	printf("\nNome: "); gets(nome); espaco(nome);				//pergunta ao usuário os dados a serem cadastrados e logo em seguida é usada a função "espaço"
	printf("\nCPF (somente números): "); gets(cpf);
	printf("\nIdade: "); scanf("%i", &idade); getchar();
	printf("\nCRECI: "); gets(creci);
	
	//como para exercer a função de corretor é necessário ter mais de 18 anos, o programa não permite menores serem cadastrados
	if(idade >= 18){
		fprintf(arquivo, "%s %s %s %s %i %s %i\n", usu, senha, nome, cpf, idade, creci, contador);
		printf("\nCadastro efetuado");	
	}
	else{
		printf("\nIdade não permitida para exercer a profissão, cadastro não efetuado");
		
		//já que o cadastro não pode ser efetuado, o arquivo que controla a quantidade de corretores diminui 1 unidade
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
			
			colocarEspaco(nome);	//chama a função "colocarEspaco" para trocar o '+' pelo espaço
			formatarCPF(cpf);		//chama a função "formatarCPF" para exibir o cpf formatado
			
			printf("\nReferência do corretor: %i", contador);
			printf("\nPrimeiro nome do usuário: %s", usu);
			printf("\nSenha: %s", senha);
			printf("\nNome: %s", nome);
			printf("\nCPF: %s", cpf);
			printf("\nIdade: %i", idade);
			printf("\nCRECI: %s", creci);
			printf("\n");
		}
	}
	else{
		printf("Não há corretores cadastrados");
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
	copia_arquivo = fopen("copia_corretores.txt", "w");	//abre um arquivo inicialmente vazio em modo gravação
	
	exibirCorretor();
	
	printf("\nDigite o número do corretor que deseja alterar: "); scanf("%i", &num_corretor); getchar();		//pede a referência do corretor
	
	while(!feof(arquivo)){			//loop que passa por cada linha do arquivo
		fscanf(arquivo, "%s %s %s %s %i %s %i\n", usu, senha, nome, cpf, &idade, creci, &contador);								//lê as variáveis do arquivo
		
		if(contador != num_corretor){			//compara o número que o usuário digitou com a referência cadastrada no arquivo
			fprintf(copia_arquivo, "%s %s %s %s %i %s %i\n", usu, senha, nome, cpf, idade, creci, contador);				//se for diferente, os dados são gravados num novo arquivo 
		}																														
		else{																							//se for igual, faz um novo cadastro								
			
			system("cls");		//atualiza a tela
			
			printf("\nInserindo novo cadastro\n");
			
			printf("Primeiro nome do usuário: "); gets(novo_usu);
			
			printf("Senha: "); gets(senha);						
			
			printf("\nNome: "); gets(novo_nome); espaco(novo_nome);
			
			printf("\nCPF (somente números): "); gets(novo_cpf);
			
			printf("\nIdade: "); scanf("%i", &novo_idade); getchar();
			
			printf("\nCRECI: "); gets(novo_creci);
			
			fprintf(copia_arquivo, "%s %s %s %s %i %s %i\n", novo_usu, novo_senha, novo_nome, novo_cpf, novo_idade, novo_creci, contador);
		}
	}
	
	fclose(arquivo);
	fclose(copia_arquivo);
	
	system("del corretores.txt");		//deleta o arquivo original e renomeia o arquivo novo para o nome do original
	system("rename copia_corretores.txt corretores.txt");
	
	//se não existir um corretor com o número que o usuário digitou, não haverá alteração
	if(num_corretor > contador){
		printf("\nNúmero não cadastrado, alteração não concluída");
	}
	else{
		printf("\nAlteração concluída");
	}
}

void excluirCorretor(){
	
	system("cls");
	
	//declara 3 variáveis do tipo FILE
	FILE* arquivo;				//um para o arquivo de corretores original
	FILE* copia_arquivo;		//um para copiar os cadastros não excluídos num segundo arquivo
	FILE* contador_arquivo;		//um para consertar a referência dos cadastros não excluídos
	char cpf[14], nome[300], creci[7], usu[100], senha[100];
	int idade, num_corretor, contador, contadorarq;
	
	arquivo = fopen("corretores.txt", "r");				//abre o arquivo original em modo leitura
	copia_arquivo = fopen("copia_corretores.txt", "w");	//abre o arquivo para cópia em modo gravação
	
	exibirCorretor();
	
	printf("\nDigite o número do corretor que deseja excluir: "); scanf("%i", &num_corretor); getchar();	//pergunta ao usuário qual corretor deseja excluir
	
	//loop que passa por cada linha do arquivo original
	while(!feof(arquivo)){
		fscanf(arquivo, "%s %s %s %s %i %s %i\n", usu, senha, nome, cpf, &idade, creci, &contador);
		
		//essa condição compara a referência do imóvel no arquivo com o número que o usuário digitou
		if(contador != num_corretor){
			
			//após fazer a comparação anterior, agora compara se a referência do imóvel cadastrado é maior que o número digitado
			//se for maior, o imóvel é salvo com o número da referência dele -1, assim todos os imóveis continuam com a referência na ordem 
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
	
	//exclui o arquivo original e renomeia a cópia para o nome do original
	system("del corretores.txt");
	system("rename copia_corretores.txt corretores.txt");
	
	//se não existir um corretor com o número que o usuário digitou, não haverá exclusão
	if (num_corretor > contador){
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
}

int MenuCorretor(){
	
	system("cls");

	int opc, opcaologin;
	
	printf("[1] Cadastrar Corretor\n[2] Alterar Corretor\n[3] Excluir Corretor\n[4] Exibir Corretor\n[5] Voltar\n[6] Sair\n\n"); 
	
	printf("Qual opção desejada? "); scanf("%i", &opc); getchar();
	
	switch(opc){
		
		case 1:
			cadastrarCorretor();		//se for a opção 1, chama a função "cadastrarCorretor"
			printf("\n\nAperte uma tecla para voltar ao menu de corretores");
			getch();
			opcaologin = 9;
			break;
		case 2:							//se for a opção 2, chama a função "alterarCorretor"
			alterarCorretor();
			printf("\n\nAperte uma tecla para voltar ao menu de corretores");
			getch();
			opcaologin = 9;
			break;
		case 3:							//se for a opção 3, chama a função "excluirCorretor"
			excluirCorretor();
			printf("\n\nAperte uma tecla para voltar ao menu de corretores");
			getch();
			opcaologin = 9;
			break;
		case 4:							//se for a opção 4, chama a função "exibirCorretor"
			exibirCorretor();
			printf("\n\nAperte uma tecla para voltar ao menu de corretores");
			getch();
			opcaologin = 9;
			break;
		case 5:				//se for opção 5, retorna ao menu principal
			opcaologin = 4;
			break;
		case 6:				//se for opção 6, encerra o programa
			system("cls");
			opcaologin = 99;
			break;
		default:
			system("cls");
			printf("Opção incorreta");
			printf("\n\nAperte uma tecla para voltar ao menu de corretores");
			getch();
			system("cls");
			return MenuCorretor();
			break;
	}
	
	return opcaologin;		//retorna o valor de opcaologin
}
