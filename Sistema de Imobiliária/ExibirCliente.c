#include <stdio.h>
#include <locale.h>

//Função que, no fim, retorna ao menu do administrador
int ExibirCliente(){
	
	setlocale(LC_ALL, "Portuguese");
	system("cls");
	
	int contador, contadorarq, sair, p, i;
	char nome[100], cpf_cnpj[23], cpf[15], cnpj[17], tel[15]; 
	
	FILE* arquivo;
	FILE* contador_arquivo;
	
	arquivo = fopen("clientes.txt", "r");		//abre o arquivo em modo leitura
	contador_arquivo = fopen("contadorclientes.txt", "r");
	
	fscanf(contador_arquivo, "%i", &contadorarq);
	
	printf("Quantidade de clientes cadastrados: %i\n\n", contadorarq);
	
	if(contadorarq != 0){
		while(!feof(arquivo)){
			fscanf(arquivo, "%i %s %s %s %i\n", &p, nome, cpf_cnpj, tel, &contador);
			
			if(p == 1){
				for(i = 0; i <= 15;i++){
					cpf[i] = cpf_cnpj[i];
				}
				
				colocarEspaco(nome);	//chama a função "colocarEspaco" para trocar o '+' pelo espaço
				formatarCPF(cpf);		//chama a função "formatarCPF" para exibir o cpf formatado
				formatarTelefone(tel);		//chama a função 'formatarTelefone" para exibir o telefone formatado
				
				printf("\nReferência do cliente: %i", contador);
				printf("\nNome: %s", nome);
				printf("\nCPF: %s", cpf);
				printf("\nTelefone para contato: %s", tel);
				printf("\n");
			}
			
			else{
				for(i = 0; i <= 17;i++){
					cnpj[i] = cpf_cnpj[i];
				}
				
				colocarEspaco(nome);	//chama a função "colocarEspaco" para trocar o '+' pelo espaço
				formatarCNPJ(cnpj);		//chama a função "formatarCPF" para exibir o cpf formatado
				formatarTelefone(tel);		//chama a função 'formatarTelefone" para exibir o telefone formatado
				
				printf("\nReferência do cliente: %i", contador);
				printf("\nNome: %s", nome);
				printf("\nCNPJ: %s", cnpj);
				printf("\nTelefone para contato: %s", tel);
				printf("\n");
			}
		}
	}
	else{
		printf("Não há clientes cadastrados\n");
	}
	
	fclose(arquivo);
	fclose(contador_arquivo);
	
	//Ao final, o usuário escolhe voltar ao menu anterior ou sair
	do{
		printf("\n[1] Voltar ao menu de clientes\n[2] Sair\n\nQual opção desejada? "); scanf("%i", &sair); getchar();
		
		if(sair == 1){
			return 22;
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

//Função que, no fim, retorna ao menu do corretor
int ExibirCliente_Alterar_Excluir(){
	
	setlocale(LC_ALL, "Portuguese");
	system("cls");
	
	int contador, contadorarq, sair, p, i;
	char nome[100], cpf_cnpj[23], cpf[15], cnpj[17], tel[15]; 
	
	FILE* arquivo;
	FILE* contador_arquivo;
	
	arquivo = fopen("clientes.txt", "r");		//abre o arquivo em modo leitura
	contador_arquivo = fopen("contadorclientes.txt", "r");
	
	fscanf(contador_arquivo, "%i", &contadorarq);
	
	printf("Quantidade de clientes cadastrados: %i\n\n", contadorarq);
	
	if(contadorarq != 0){
		while(!feof(arquivo)){
			fscanf(arquivo, "%i %s %s %s %i\n", &p, nome, cpf_cnpj, tel, &contador);
			
			if(p == 1){
				for(i = 0; i <= 15;i++){
					cpf[i] = cpf_cnpj[i];
				}
				
				colocarEspaco(nome);	//chama a função "colocarEspaco" para trocar o '+' pelo espaço
				formatarCPF(cpf);		//chama a função "formatarCPF" para exibir o cpf formatado
				formatarTelefone(tel);		//chama a função 'formatarTelefone" para exibir o telefone formatado
				
				printf("\nReferência do cliente: %i", contador);
				printf("\nNome: %s", nome);
				printf("\nCPF: %s", cpf);
				printf("\nTelefone para contato: %s", tel);
				printf("\n");
			}
			else{
				for(i = 0; i <= 17;i++){
					cnpj[i] = cpf_cnpj[i];
				}
				
				colocarEspaco(nome);	//chama a função "colocarEspaco" para trocar o '+' pelo espaço
				formatarCNPJ(cnpj);		//chama a função "formatarCNPJ" para exibir o CNPJ formatado
				formatarTelefone(tel);		//chama a função 'formatarTelefone" para exibir o telefone formatado
				
				printf("\nReferência do cliente: %i", contador);
				printf("\nNome: %s", nome);
				printf("\nCNPJ: %s", cnpj);
				printf("\nTelefone para contato: %s", tel);
				printf("\n");
			}
		}
	}
	else{
		printf("Não há clientes cadastrados\n");
	}
	
	fclose(arquivo);
	fclose(contador_arquivo);
}

int ExibirClienteCorretor(){
	
	setlocale(LC_ALL, "Portuguese");
	system("cls");
	
	int contador, contadorarq, sair, p, i;
	char nome[100], cpf_cnpj[23], cpf[15], cnpj[17], tel[15]; 
	
	FILE* arquivo;
	FILE* contador_arquivo;
	
	arquivo = fopen("clientes.txt", "r");		//abre o arquivo em modo leitura
	contador_arquivo = fopen("contadorclientes.txt", "r");
	
	fscanf(contador_arquivo, "%i", &contadorarq);
	
	printf("Quantidade de clientes cadastrados: %i\n\n", contadorarq);
	
	if(contadorarq != 0){
		while(!feof(arquivo)){
			fscanf(arquivo, "%i %s %s %s %i\n", &p, nome, cpf_cnpj, tel, &contador);
			
			if(p == 1){
				for(i = 0; i <= 15;i++){
					cpf[i] = cpf_cnpj[i];
				}
				
				colocarEspaco(nome);	//chama a função "colocarEspaco" para trocar o '+' pelo espaço
				formatarCPF(cpf);		//chama a função "formatarCPF" para exibir o cpf formatado
				formatarTelefone(tel);		//chama a função 'formatarTelefone" para exibir o telefone formatado
				
				printf("\nReferência do cliente: %i", contador);
				printf("\nNome: %s", nome);
				printf("\nCPF: %s", cpf);
				printf("\nTelefone para contato: %s", tel);
				printf("\n");
			}
			
			else{
				for(i = 0; i <= 17;i++){
					cnpj[i] = cpf_cnpj[i];
				}
				
				colocarEspaco(nome);	//chama a função "colocarEspaco" para trocar o '+' pelo espaço
				formatarCNPJ(cnpj);		//chama a função "formatarCPF" para exibir o cpf formatado
				formatarTelefone(tel);		//chama a função 'formatarTelefone" para exibir o telefone formatado
				
				printf("\nReferência do cliente: %i", contador);
				printf("\nNome: %s", nome);
				printf("\nCNPJ: %s", cnpj);
				printf("\nTelefone para contato: %s", tel);
				printf("\n");
			}
		}
	}
	else{
		printf("Não há clientes cadastrados\n");
	}
	
	fclose(arquivo);
	fclose(contador_arquivo);
	
	do{
		printf("\n[1] Voltar ao menu de clientes\n[2] Sair\n\nQual opção desejada? "); scanf("%i", &sair); getchar();
		
		if(sair == 1){
			return 27;
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
