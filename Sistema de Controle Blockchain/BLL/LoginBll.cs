using System;
using System.Collections.Generic;
using System.Data;
using SistemaBlockchain.DAL;
using SistemaBlockchain.dto;

namespace SistemaBlockchain.Modelo
{
    public class LoginBll
    {
        public bool tem;
        public string msg = " ";
        public DataTable _tabela = new DataTable();
        int cod;

        public bool acessar(String login, String senha)
        {
            LoginDalComandos loginDal = new LoginDalComandos();

            tem = loginDal.VerificarLogin(login, senha);

            this.msg = loginDal.msg;

            return tem;
        }

        public String cadastrarUsuario(UsuarioDto parUser)
        {
            LoginDalComandos loginDal = new LoginDalComandos();

            this.msg = loginDal.CadastrarUsuario(parUser);

            if (loginDal.tem)
            {
                this.tem = true; 
            }
            
            return msg;
        }

        public int obterCodigoUsuario(String usuario, String senha)
        {
            LoginDalComandos loginDal = new LoginDalComandos();

            this.cod = loginDal.ObterCodigoUsuario(usuario, senha);

            return cod;
        }

        public int obterTipoUsuario(String usuario, String senha)
        {
            LoginDalComandos loginDal = new LoginDalComandos();

            this.cod = loginDal.ObterTipoUsuario(usuario, senha);

            return cod;
        }

        public bool ValidarEmail(string email)
        {
            LoginDalComandos loginDal = new LoginDalComandos();

            return loginDal.ValidarEmail(email);
        }
    }
}