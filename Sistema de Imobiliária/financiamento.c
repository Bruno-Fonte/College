#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int opcao;
float ajuros;

int menu(){
	
	printf("[1] Simular Financiamento\n[2] Voltar\n[3] Fechar");
	printf("\n\nQual op��o desejada? ");
	scanf("%i",&opcao); //digitar op��o
	getchar();
	
	return opcao; //retorna op��o digitada
}

int tipo(){
	
	system("cls");
	
	printf("[1] Simular financiamento em tabela Price\n[2] Simular financiamento em tabela Sac\n\nQual op��o desejada? ");
	scanf("%i",&opcao); getchar(); //informar op��o
	switch(opcao){
		case 1: price(); break; //se a op��o for 1, chama a fun��o price();
		case 2: sac(); break; //se a op��o for 2, chama a fun��o sac();
		default: printf("\n\nValor inv�lido"); break; //se n�o for nenhuma das op��es acima, valor � inv�lido
	}
	
	printf("\n\nJuros total: R$ %.2f", ajuros); //printa o valor total de juros
		
	printf("\n\nAperte qualquer tecla para continuar");
	getch();
	system("cls");
	
}

void price(){
	
	float imovel, entrada, anos, porc, meses, elevado, elevado1, financ, parcelas, c, saldo, juros, amortizacao;
	
	system("cls");
	
	printf("Valor a ser financiado: R$ ");
	scanf("%f",&financ); //digita o valor para financiar
	
	printf("\n\nMeses a financiar: "); 
	scanf("%f",&meses); //informar meses
	
	printf("\n\nTaxa (%%) de juros ao m�s: ");
	scanf("%f",& porc); //usu�rio informa a taxa em % para simular
	
	porc=porc/100; //taxa dividida por 100 para efetuar o calculo
	porc=1+porc; //valor de porcentagem soma 1, conforme a f�rmula da tabela no slide de matem�tica
	
 	// ATE AQUI CALCULA O PRIMEIRO VALOR PARA A PRIMEIRA FORMULA
	
	elevado=(pow(porc,meses))-1; //pow calcula n�meros elevados, no caso a TAXA em % elevado a MESES e subtrai 1 conforme a f�rmula
	
	elevado1=pow(porc,meses)*(porc-1); //mesemo conceito do c�lculo acima, por�m pow multiplica o valor da taxa
	
	parcelas=(elevado1/elevado)*financ; //divis�o dos c�lculos acima mutiplicado pelo valor a ser financiado
	
	getchar();
	system("cls");
	printf("\nTABELA PRICE\n");
	
	printf("\n  M�S\t\tPARCELAS\t\tAMORTIZA��ES\t\tJUROS\t\t\tSALDO DEVEDOR");
	
	saldo=financ; //saldo recebe valor a ser financiado
	
	ajuros=0; //acumulador de juros
	
	for(c=0;c<=meses;c++){ //loop com contador para meses
		
		if(c==0){
			printf("\n   %.0f\t\t\t\t\t\t\t\t\t\t\t%.2f", c, saldo); //aparece a primeira linha, no qual o m�s � 0 e o saldo ainda n�o foi calculado
		}
		else{
			juros=saldo*(porc-1); //juros recebe valor de saldo multiplicado pelo valor da taxa menos 1
			amortizacao=parcelas-juros; //amortiza��o recebe o valor de parcelas menos juros
			saldo=saldo-amortizacao; //saldo recebe valor de saldo menos amortiza��o
			ajuros+=juros; //acumulador de juros
			
			if(c==meses)
			{
				parcelas=parcelas+saldo; //reajuste de amortiza��o para saldo ficar zerado
				saldo=saldo-saldo;
			}
			
			if(parcelas>=0 && parcelas <=999) //todos if's imprimem valores linha a linha, conforme os c�lculos acima s�o feitos
			{									// if's s�o usados para alinhar as linhas conforme o tamanho dos valores, mantendo padr�o da tabela
				printf("\n   %.0f\t\t%.2f\t\t\t%.2f\t\t\t%.2f\t\t\t%.2f", c, parcelas, amortizacao, juros, saldo);
			}
			if(parcelas>=1000 && parcelas<=9999)
			{
				printf("\n   %.0f\t\t%.2f\t\t\t%.2f\t\t\t%.2f\t\t\t%.2f", c, parcelas, amortizacao, juros, saldo);
			}
			if(parcelas>=10000 && parcelas <=99999)
			{
				if(juros<10000)
				{
					if(amortizacao<10000)
					{
						printf("\n   %.0f\t\t%.2f\t\t%.2f\t\t\t%.2f\t\t\t%.2f", c, parcelas, amortizacao, juros, saldo);
					}
					else
					{
						printf("\n   %.0f\t\t%.2f\t\t%.2f\t\t%.2f\t\t\t%.2f", c, parcelas, amortizacao, juros, saldo);
					}
				}
				else
				{
					if(amortizacao<10000)
					{
						printf("\n   %.0f\t\t%.2f\t\t%.2f\t\t\t%.2f\t\t%.2f", c, parcelas, amortizacao, juros, saldo);
					}
					else
					{
						printf("\n   %.0f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f", c, parcelas, amortizacao, juros, saldo);
					}
				}
			}
			if(parcelas>=100000 && parcelas <=999999)
			{
				if(amortizacao<10000)
				{
					if(juros>=10000)
					{
						printf("\n   %.0f\t\t%.2f\t\t%.2f\t\t\t%.2f\t\t%.2f", c, parcelas, amortizacao, juros, saldo);
					}
					else
					{
						printf("\n   %.0f\t\t%.2f\t\t%.2f\t\t\t%.2f\t\t\t%.2f", c, parcelas, amortizacao, juros, saldo);
					}
				}
				else
				{
					if(juros>=10000)
					{
						printf("\n   %.0f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f", c, parcelas, amortizacao, juros, saldo);
					}
					else
					{
						printf("\n   %.0f\t\t%.2f\t\t%.2f\t\t%.2f\t\t\t%.2f", c, parcelas, amortizacao, juros, saldo);
					}
					
				}
			}
			if(parcelas>=1000000 && parcelas <=9999999)
			{
				if(amortizacao<10000)
				{
					printf("\n   %.0f\t\t%.2f\t\t%.2f\t\t\t%.2f\t\t%.2f", c, parcelas, amortizacao, juros, saldo);
				}
				else
				{
					printf("\n   %.0f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f", c, parcelas, amortizacao, juros, saldo);
				}
			}
			if(parcelas>=10000000 && parcelas <100000000)
			{
				if(amortizacao<10000)
				{
					printf("\n   %.0f\t\t%.2f\t\t%.2f\t\t\t%.2f\t\t%.2f", c, parcelas, amortizacao, juros, saldo);
				}
				else
				{
					printf("\n   %.0f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f", c, parcelas, amortizacao, juros, saldo);
				}
			}
			if(parcelas>= 100000000)
			{
				printf("\n   %.0f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f", c, parcelas, amortizacao, juros, saldo);
			}
		}
		
	}
	
}

void sac(){
	
	int op;
	float imovel, entrada, anos, porc, meses, elevado, elevado1, financ, parcelas, c, saldo, juros, amortizacao;
	
	system("cls");
	
	printf("Valor a ser financiado: R$ ");
	scanf("%f",&financ); //digita o valor para financiar
		
	printf("\n\nMeses a financiar: "); 
	scanf("%f",&meses); //informar meses
	
	printf("\n\nTaxa (%%) de juros ao m�s: ");
	scanf("%f",&porc); //usu�rio informa a taxa em % para simular
	
	getchar();
	system("cls");
	printf("\nTABELA SAC\n");
	
	printf("\n  M�S\t\tPARCELAS\t\tAMORTIZA��ES\t\tJUROS\t\t\tSALDO DEVEDOR"); //mostar a linha na qual ficara as colunas para formar uma tabela
	
	porc=porc/100; //divide o valor da taxa em 100 para utilizar nos c�lculos
	
	saldo=financ; //saldo recebe valor de financiamento
	
	amortizacao=financ/meses; //amortiza��o recebe valor da divis�o de financiamento (valor digitado pelo usu�rio) e a quantidade de meses (digitado pelo usu�rio)
	
	ajuros=0; //acumulador de juros
	
	for(c=0;c<=meses;c++){ //loop com contador de meses, rodando at� que que o contador de meses seja igual ao valor de meses digitado pelo usu�rio
		
		if(c==0){
			printf("\n   %.0f\t\t\t\t\t\t\t\t\t\t\t%.2f", c, saldo); //primeira linha da tabela, no qual o m�s � 0 e o saldo � o valor informado p/ financiar
		}
		else{
			juros=saldo*porc; //juros recebe valor da multiplica��o de saldo pela %
			parcelas=amortizacao+juros; //parcelas recebe valor de amortiza��o somando com valor de juros
			saldo=saldo-amortizacao; //saldo recebe valor de saldo subtraido de amortiza��o
			ajuros+=juros; //acumulador de juros
			
			if(c==meses)
			{
				parcelas=parcelas+saldo; //reajuste de parcela para saldo ficar zerado
				saldo=saldo-saldo;
			}
			
			if(parcelas>=0 && parcelas <=999) //todos if's imprimem valores linha a linha, conforme os c�lculos acima s�o feitos
			{									// if's s�o usados para alinhar as linhas conforme o tamanho dos valores, mantendo padr�o da tabela
				printf("\n   %.0f\t\t%.2f\t\t\t%.2f\t\t\t%.2f\t\t\t%.2f", c, parcelas, amortizacao, juros, saldo);
			}
			if(parcelas>=1000 && parcelas<=9999)
			{
				printf("\n   %.0f\t\t%.2f\t\t\t%.2f\t\t\t%.2f\t\t\t%.2f", c, parcelas, amortizacao, juros, saldo);
			}
			if(parcelas>=10000 && parcelas <=99999)
			{
				if(juros<9999)
				{
					printf("\n   %.0f\t\t%.2f\t\t%.2f\t\t\t%.2f\t\t\t%.2f", c, parcelas, amortizacao, juros, saldo);
				}
				else
				{
					printf("\n   %.0f\t\t%.2f\t\t%.2f\t\t\t%.2f\t\t%.2f", c, parcelas, amortizacao, juros, saldo);
				}
			}
			if(parcelas>=100000 && parcelas <=999999)
			{
				if(juros<10000)
				{
					printf("\n   %.0f\t\t%.2f\t\t%.2f\t\t%.2f\t\t\t%.2f", c, parcelas, amortizacao, juros, saldo);	
				}
				else
				{
					printf("\n   %.0f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f", c, parcelas, amortizacao, juros, saldo);
				}
			}
			if(parcelas>=1000000 && parcelas <=9999999)
			{
				printf("\n   %.0f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f", c, parcelas, amortizacao, juros, saldo);
			}
			if(parcelas>=10000000)
			{
				printf("\n   %.0f\t\t%.2f\t\t%.2f\t\t\t%.2f\t\t%.2f", c, parcelas, amortizacao, juros, saldo);
			}
			
		}
		
	}
		
}

int FinanciamentoCorretor() {
	
	setlocale(LC_ALL, "portuguese");
	
	menu(); //chama a fun��o menu();
	
	switch(opcao){ //recebe valor de op��o, que foi dado na fun��o menu();
		case 1: tipo(); break; //se a op��o for 1, chama a fun��o cadastrar();
		case 2: return 3; break; //se a op��o for 2, retorna ao meu do corretor
		case 3: return 99; break; //se for op��o 3, encerra o programa
		default: printf("\n\nValor inv�lido"); break; //qualquer outro valor retorna a mensagem de inv�lido
	}
	
	system("cls");
    return 21; //retorna ao in�cio;
	
}

int FinanciamentoADM() {
	
	setlocale(LC_ALL, "portuguese");
	
	menu(); //chama a fun��o menu();
	
	switch(opcao){ //recebe valor de op��o, que foi dado na fun��o menu();
		case 1: tipo(); break; //se a op��o for 1, chama a fun��o cadastrar();
		case 2: return 4; break; //se a op��o for 2, retorna ao meu do ADM
		case 3: return 99; break; //se for op��o 3, encerra o programa
		default: printf("\n\nValor inv�lido"); break; //qualquer outro valor retorna a mensagem de inv�lido
	}
	
	system("cls");
    return 7; //retorna ao in�cio;
	
}
