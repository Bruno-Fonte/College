using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using SistemaBlockchain.dto;

namespace SistemaBlockchain.DAL
{
    public class LoginDalComandos
    {
        public bool tem = false;
        public String msg = "";
        SqlCommand _comando = new SqlCommand();
        Conexao _conexao = new Conexao();
        SqlDataReader _data;
        SqlDataAdapter _adaptador = new SqlDataAdapter();
        DataTable _tabela = new DataTable();

        public bool VerificarLogin(String login, String senha)
        {

            _comando.CommandText = "select usuario_login, senha_login from TB_USUARIO " +
                                    "where usuario_login = @usuario and senha_login = @senha; ";

            _comando.Parameters.Add("@usuario", SqlDbType.VarChar).Value = login;
            _comando.Parameters.Add("@senha", SqlDbType.VarChar).Value = senha;

            try
            {
                _comando.Connection = _conexao.conectar();
                _data = _comando.ExecuteReader();

                if (_data.HasRows)
                {
                    tem = true;
                    this.msg = "Login efetuado com sucesso!";
                }
                _conexao.desconectar();
                _data.Close();
            }
            catch (SqlException)
            {
                this.msg = "Erro com Banco de Dados!";
            }

            return tem;
        }

        public String CadastrarUsuario(UsuarioDto parUser)
        {
            tem = false;

            _comando.CommandText = "insert into TB_USUARIO values " +
                                   " (@nome, @cpf, @usuario, @senha, 2); ";

            _comando.Parameters.Add("@nome", SqlDbType.VarChar).Value = parUser.Nome;
            _comando.Parameters.Add("@cpf", SqlDbType.VarChar).Value = parUser.CpfCnpj;
            _comando.Parameters.Add("@usuario", SqlDbType.VarChar).Value = parUser.Login;
            _comando.Parameters.Add("@senha", SqlDbType.VarChar).Value = parUser.Senha;

            try
            {
                _comando.Connection = _conexao.conectar();
                _comando.ExecuteNonQuery();
                _conexao.desconectar();

                this.msg = "Cadastrado com sucesso!";
                tem = true;
            }
            catch (SqlException)
            {

                this.msg = "Erro com o banco de dados!";
            }

            return msg;
        }

        public int ObterCodigoUsuario(String usuario, String senha)
        {
            int codigo = 0;

            _comando.CommandText = " SELECT ID_USUARIO from TB_USUARIO " +
                                   " where USUARIO_LOGIN = '" + usuario + "' and SENHA_LOGIN = '" + senha + "' ;";

            _comando.Connection = _conexao.conectar();
            _data = _comando.ExecuteReader();

            if (_data.HasRows)
            {
                _conexao.desconectar();
                _conexao.conectar();

                _comando.CommandText = " SELECT ID_USUARIO from TB_USUARIO " +
                                   " where USUARIO_LOGIN = '" + usuario + "' and SENHA_LOGIN = '" + senha + "' ;";

                codigo = int.Parse(_comando.ExecuteScalar().ToString());
            }
            else
            {
                _conexao.desconectar();
            }

            return codigo;
        }

        public int ObterTipoUsuario(String usuario, String senha)
        {
            int tipo = 0;

            _comando.CommandText = " SELECT ID_USUARIO from TB_USUARIO " +
                                   " where USUARIO_LOGIN = '" + usuario + "' and SENHA_LOGIN = '" + senha + "' ;";

            _comando.Connection = _conexao.conectar();
            _data = _comando.ExecuteReader();

            if (_data.HasRows)
            {
                _conexao.desconectar();
                _conexao.conectar();

                _comando.CommandText = " SELECT TIPO_USUARIO from TB_USUARIO " +
                                   " where USUARIO_LOGIN = '" + usuario + "' and SENHA_LOGIN = '" + senha + "' ;";

                tipo = int.Parse(_comando.ExecuteScalar().ToString());
            }
            else
            {
                _conexao.desconectar();
            }

            return tipo;
        }

        public bool ValidarEmail(string email)
        {
            _comando.CommandText = " SELECT id_usuario from TB_USUARIO " +
                                   " where usuario_login = '" + email + "'; ";

            _comando.Connection = _conexao.conectar();
            _data = _comando.ExecuteReader();

            if (_data.HasRows)
            {
                _conexao.desconectar();
                return false;
            }
            else
            {
                _conexao.desconectar();
                return true;
            }
        }
    }
}