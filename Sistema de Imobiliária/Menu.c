#include <stdio.h>
#include <locale.h>

int main() {
	
	setlocale(LC_ALL, "Portuguese");
	
	int sair = 0; // Variavel que encerra o programa
	int opcaologin = 0; // Variavel que mostra destino do programa
	
	while (sair == 0){	
			
		switch(opcaologin){
			
			case 0:
				opcaologin = OpcaoLogin(); // Recebe parametro para entrar nas opçoes
				break;	
			
			case 1:    // Login como usuario.
				opcaologin = LoginCorretor();
				
				if (opcaologin == 99){
					sair = 1;
				}				
				break;
			
			case 2:   // Login como ADM.
				opcaologin = LoginAdm();
				
				if (opcaologin == 99){
					sair = 1;
				}
				break;
			
			case 3: // Menu do Usuario.
				opcaologin = MenuFuncao(); 
				
				if (opcaologin == 99){
					sair = 1;
				}
				break;
			
			case 4: // Menu do ADM.
				opcaologin = MenuFuncaoADM(); 
				
				if (opcaologin == 99){
					sair = 1;
				}
				break;
			
			case 6:	//Menu das opções de imóvel
				opcaologin = MenuImovel();
				
				if (opcaologin == 99){
					sair = 1;
				}
				break;	
			case 7:	//Financiamento para ADM
				opcaologin = FinanciamentoADM(); 
				
				if (opcaologin == 99){
					sair = 1;
				}
				break;
			
			case 8: //Função para exibir os imóveis
				opcaologin = ExibirImovel();	
		
				if (opcaologin == 99){
					sair = 1;
				}
				break;
			
			case 9: //Menu das opções de corretor
				opcaologin = MenuCorretor();
		
				if (opcaologin == 99){
					sair = 1;
				}
				break;
				
			case 11: //Função para cadastrar imóveis
				opcaologin = CadastrarImovel();
				
				if (opcaologin == 99){
					sair = 1;
				}
				break;
			
			case 12: //Função para alterar os cadastros de imóveis
				opcaologin = AlterarImovel();
				
				if (opcaologin == 99){
					sair = 1;
				}
				break;
			
			case 13: //Função para excluir imóveis
				opcaologin = ExcluirImovel();
				
				if (opcaologin == 99){
					sair = 1;
				}
				break;
				
			case 14: //Função das pesquisas personalizadas
				opcaologin = ExibirPersonalizado();
				
				if (opcaologin == 99){
					sair = 1;
				}
				break;
				
			case 15: //Função para cadastro de um novo corretor
				opcaologin = CadastrarCorretor();
				
				if (opcaologin == 99){
					sair = 1;
				}
				break;
			
			case 16: //Função para alterar um corretor
				opcaologin = AlterarCorretor();
				
				if (opcaologin == 99){
					sair = 1;
				}
				break;
				
			case 17: //Função para excluir um corretor
				opcaologin = ExcluirCorretor();
				
				if (opcaologin == 99){
					sair = 1;
				}
				break;
			
			case 18: //Função para exibir os corretores
				opcaologin = ExibirCorretor();
				
				if (opcaologin == 99){
					sair = 1;
				}
				break;
			
			case 19: //Função para exibir os imóveis que retorna o menu do corretor
				opcaologin = ExibirImovel_Corretor();
				
				if (opcaologin == 99){
					sair = 1;
				}
				break;
			
			case 20: //Função das pesquisas personalizadas que retorna o menu do corretor
				opcaologin = ExibirPersonalizado_Corretor();
				
				if (opcaologin == 99){
					sair = 1;
				}
				break;
				
			case 21: //Função de financiamento que retorna o menu do corretor 
				opcaologin = FinanciamentoCorretor();
				
				if (opcaologin == 99){
					sair = 1;
				}
				break;
				
			case 22: //Menu das opções de cliente
				opcaologin = MenuCliente();
				
				if (opcaologin == 99){
					sair = 1;
				}
				break;
			
			case 23: //Função para cadastrar cliente
				opcaologin = CadastrarCliente();
				
				if (opcaologin == 99){
					sair = 1;
				}
				break;
				
			case 24: //Função para exibir os clientes
				opcaologin = ExibirCliente();
				
				if (opcaologin == 99){
					sair = 1;
				}
				break;
				
			case 25: //Função para alterar clientes
				opcaologin = AlterarCliente();
				
				if (opcaologin == 99){
					sair = 1;
				}
				break;
			
			case 26: //Função para excluir clientes
				opcaologin = ExcluirCliente();
				
				if (opcaologin == 99){
					sair = 1;
				}
				break;
				
			case 27: //Menu do cliente que retorna ao menu do corretor
				opcaologin = MenuClienteCorretor();
				
				if (opcaologin == 99){
					sair = 1;
				}
				break;
			
			case 28: //Função para cadastrar cliente que retorna ao menu do corretor
				opcaologin = CadastrarClienteCorretor();
				
				if (opcaologin == 99){
					sair = 1;
				}
				break;
				
			case 29: //Função para alterar clientes que retorna ao menu do corretor
				opcaologin = AlterarClienteCorretor();
				
				if (opcaologin == 99){
					sair = 1;
				}
				break;
				
			case 30:  //Função para excluir clientes que retorna ao menu do corretor
				opcaologin = ExcluirClienteCorretor();
				
				if (opcaologin == 99){
					sair = 1;
				}
				break;
				
			case 31:  //Função para exibir clientes que retorna ao menu do corretor
				opcaologin = ExibirClienteCorretor();
				
				if (opcaologin == 99){
					sair = 1;
				}
		}
	}

	return 0;
}
