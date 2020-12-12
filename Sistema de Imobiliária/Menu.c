#include <stdio.h>
#include <locale.h>

int main() {
	
	setlocale(LC_ALL, "Portuguese");
	
	int sair = 0; // Variavel que encerra o programa
	int opcaologin = 0; // Variavel que mostra destino do programa
	
	while (sair == 0){	
			
		switch(opcaologin){
			
			case 0:
				opcaologin = OpcaoLogin(); // Recebe parametro para entrar nas op�oes
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
			
			case 6:	//Menu das op��es de im�vel
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
			
			case 8: //Fun��o para exibir os im�veis
				opcaologin = ExibirImovel();	
		
				if (opcaologin == 99){
					sair = 1;
				}
				break;
			
			case 9: //Menu das op��es de corretor
				opcaologin = MenuCorretor();
		
				if (opcaologin == 99){
					sair = 1;
				}
				break;
				
			case 11: //Fun��o para cadastrar im�veis
				opcaologin = CadastrarImovel();
				
				if (opcaologin == 99){
					sair = 1;
				}
				break;
			
			case 12: //Fun��o para alterar os cadastros de im�veis
				opcaologin = AlterarImovel();
				
				if (opcaologin == 99){
					sair = 1;
				}
				break;
			
			case 13: //Fun��o para excluir im�veis
				opcaologin = ExcluirImovel();
				
				if (opcaologin == 99){
					sair = 1;
				}
				break;
				
			case 14: //Fun��o das pesquisas personalizadas
				opcaologin = ExibirPersonalizado();
				
				if (opcaologin == 99){
					sair = 1;
				}
				break;
				
			case 15: //Fun��o para cadastro de um novo corretor
				opcaologin = CadastrarCorretor();
				
				if (opcaologin == 99){
					sair = 1;
				}
				break;
			
			case 16: //Fun��o para alterar um corretor
				opcaologin = AlterarCorretor();
				
				if (opcaologin == 99){
					sair = 1;
				}
				break;
				
			case 17: //Fun��o para excluir um corretor
				opcaologin = ExcluirCorretor();
				
				if (opcaologin == 99){
					sair = 1;
				}
				break;
			
			case 18: //Fun��o para exibir os corretores
				opcaologin = ExibirCorretor();
				
				if (opcaologin == 99){
					sair = 1;
				}
				break;
			
			case 19: //Fun��o para exibir os im�veis que retorna o menu do corretor
				opcaologin = ExibirImovel_Corretor();
				
				if (opcaologin == 99){
					sair = 1;
				}
				break;
			
			case 20: //Fun��o das pesquisas personalizadas que retorna o menu do corretor
				opcaologin = ExibirPersonalizado_Corretor();
				
				if (opcaologin == 99){
					sair = 1;
				}
				break;
				
			case 21: //Fun��o de financiamento que retorna o menu do corretor 
				opcaologin = FinanciamentoCorretor();
				
				if (opcaologin == 99){
					sair = 1;
				}
				break;
				
			case 22: //Menu das op��es de cliente
				opcaologin = MenuCliente();
				
				if (opcaologin == 99){
					sair = 1;
				}
				break;
			
			case 23: //Fun��o para cadastrar cliente
				opcaologin = CadastrarCliente();
				
				if (opcaologin == 99){
					sair = 1;
				}
				break;
				
			case 24: //Fun��o para exibir os clientes
				opcaologin = ExibirCliente();
				
				if (opcaologin == 99){
					sair = 1;
				}
				break;
				
			case 25: //Fun��o para alterar clientes
				opcaologin = AlterarCliente();
				
				if (opcaologin == 99){
					sair = 1;
				}
				break;
			
			case 26: //Fun��o para excluir clientes
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
			
			case 28: //Fun��o para cadastrar cliente que retorna ao menu do corretor
				opcaologin = CadastrarClienteCorretor();
				
				if (opcaologin == 99){
					sair = 1;
				}
				break;
				
			case 29: //Fun��o para alterar clientes que retorna ao menu do corretor
				opcaologin = AlterarClienteCorretor();
				
				if (opcaologin == 99){
					sair = 1;
				}
				break;
				
			case 30:  //Fun��o para excluir clientes que retorna ao menu do corretor
				opcaologin = ExcluirClienteCorretor();
				
				if (opcaologin == 99){
					sair = 1;
				}
				break;
				
			case 31:  //Fun��o para exibir clientes que retorna ao menu do corretor
				opcaologin = ExibirClienteCorretor();
				
				if (opcaologin == 99){
					sair = 1;
				}
		}
	}

	return 0;
}
