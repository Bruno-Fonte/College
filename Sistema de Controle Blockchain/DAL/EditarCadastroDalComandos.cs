using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Web;

namespace SistemaBlockchain.DAL
{
    public class EditarCadastroDalComandos
    {
        public bool tem = false;
        public String msg = "";
        SqlCommand _comando = new SqlCommand();
        Conexao _conexao = new Conexao();
        SqlDataAdapter _adaptador = new SqlDataAdapter();
        DataTable _tabela = new DataTable();

        public DataTable CarregarGridEditarCadastros()
        {
            tem = false;

            _comando.CommandText = " select id_usuario, nome_razao, cpf_cnpj, usuario_login, senha_login, tipo_usuario " +
                                   " from TB_USUARIO where tipo_usuario != 1; ";

            try
            {
                _comando.Connection = _conexao.conectar();
                _tabela = new DataTable();
                _adaptador = new SqlDataAdapter(_comando);
                _adaptador.Fill(_tabela);
                _conexao.desconectar();

                tem = true;

                return _tabela;

            }
            catch (SqlException)
            {
                return null;
            }
        }

        public String AdicionarUsuario(String nome, String cpf, String usuario, String senha, String tipo)
        {
            tem = false;

            _comando.CommandText = "insert into TB_USUARIO values " +
                                   " (@nome, @cpf, @usuario, @senha, @tipo); ";

            _comando.Parameters.Add("@nome", SqlDbType.VarChar).Value = nome;
            _comando.Parameters.Add("@cpf", SqlDbType.VarChar).Value = cpf;
            _comando.Parameters.Add("@usuario", SqlDbType.VarChar).Value = usuario;
            _comando.Parameters.Add("@senha", SqlDbType.VarChar).Value = senha;
            _comando.Parameters.Add("@tipo", SqlDbType.Int).Value = tipo;

            try
            {
                _comando.Connection = _conexao.conectar();
                _comando.ExecuteNonQuery();
                _conexao.desconectar();

                this.msg = "Adicionado com sucesso!";
                tem = true;
            }
            catch (SqlException)
            {
                this.msg = "Erro com o banco de dados!";
            }

            return msg;
        }

        public void EditarUsuario(int id, String nome, String cpf, String usuario, String senha, String tipo)
        {
            tem = false;

            _comando.CommandText = " update TB_USUARIO set nome_razao = @nome, cpf_cnpj = @cpf, " +
                                   " usuario_login = @usuario, senha_login = @senha, tipo_usuario = @tipo " +
                                   " where id_usuario = @id; ";

            _comando.Parameters.Add("@nome", SqlDbType.VarChar).Value = nome;
            _comando.Parameters.Add("@cpf", SqlDbType.VarChar).Value = cpf;
            _comando.Parameters.Add("@usuario", SqlDbType.VarChar).Value = usuario;
            _comando.Parameters.Add("@senha", SqlDbType.VarChar).Value = senha;
            _comando.Parameters.Add("@tipo", SqlDbType.Int).Value = tipo;
            _comando.Parameters.Add("@id", SqlDbType.Int).Value = id;

            try
            {
                _comando.Connection = _conexao.conectar();
                _comando.ExecuteNonQuery();
                _conexao.desconectar();

                this.msg = "Alterado com sucesso!";
                tem = true;
            }
            catch (SqlException)
            {
                this.msg = "Erro com o banco de dados!";
            }
        }

        public void ExcluirUsuario(int id)
        {
            tem = false;

            _comando.CommandText = " delete from tb_usuario " +
                                   " where id_usuario = @id; ";

            _comando.Parameters.Add("@id", SqlDbType.Int).Value = id;

            try
            {
                _comando.Connection = _conexao.conectar();
                _comando.ExecuteNonQuery();
                _conexao.desconectar();

                this.msg = "Excluído com sucesso!";
                tem = true;
            }
            catch (SqlException)
            {
                this.msg = "Erro com o banco de dados!";
            }
        }
    }
}