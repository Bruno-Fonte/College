using System;
using System.Data;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Web;

namespace SistemaBlockchain.DAL
{
    public class MudarSenhaDalComandos
    {
        public bool tem = false;
        public String msg = "";
        SqlCommand _comando = new SqlCommand();
        Conexao _conexao = new Conexao();

        public int ValidarSenha(int id, String senha)
        {
            int qtd;

            _comando.CommandText = " select count(id_usuario) from tb_usuario where id_usuario = @id " +
                                   " and senha_login = @senha; ";

            _comando.Parameters.Add("@id", SqlDbType.Int).Value = id;
            _comando.Parameters.Add("@senha", SqlDbType.VarChar).Value = senha;

            _comando.Connection = _conexao.conectar();

            qtd = int.Parse(_comando.ExecuteScalar().ToString());

            _conexao.desconectar();

            return qtd;
        }
        
        public String MudarSenha(String id, String novaSenha)
        {
            tem = false;

            _comando.CommandText = " update TB_USUARIO set SENHA_LOGIN = @senha_login " +
                                   " WHERE ID_USUARIO = @id_user; ";

            _comando.Parameters.Add("@id_user", SqlDbType.Int).Value = id;
            _comando.Parameters.Add("@senha_login", SqlDbType.VarChar).Value = novaSenha;
            try
            {
                _comando.Connection = _conexao.conectar();
                _comando.ExecuteNonQuery();
                _conexao.desconectar();

                this.msg = "Senha atualizada com sucesso!";
                tem = true;
            }
            catch (SqlException)
            {
                this.msg = "Erro com o banco de dados!";
            }

            return msg;
        }
    }
}