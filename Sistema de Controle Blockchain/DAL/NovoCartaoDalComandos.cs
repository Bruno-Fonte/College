using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using SistemaBlockchain.dto;

namespace SistemaBlockchain.DAL
{
    public class NovoCartaoDalComandos
    {
        public bool tem = false;
        public String msg = "";
        SqlCommand _comando = new SqlCommand();
        Conexao _conexao = new Conexao();
        SqlDataAdapter _adaptador = new SqlDataAdapter();
        DataTable _tabela = new DataTable();
        SqlDataReader _data;

        public String CadastrarCartao(NovoCartaoDto parNC)
        {
            tem = false;

            _comando.CommandText = " insert into TB_CARTOES values " +
                                   " (@id_user, @num_conta, @tp_cartao, @num_cartao, @limite, @saldo, @gastos); ";

            _comando.Parameters.Add("@id_user", SqlDbType.Int).Value = parNC.IdUser;
            _comando.Parameters.Add("@num_conta", SqlDbType.Decimal).Value = parNC.NumConta;
            _comando.Parameters.Add("@tp_cartao", SqlDbType.Int).Value = parNC.TipoCartao;
            _comando.Parameters.Add("@num_cartao", SqlDbType.Decimal).Value = parNC.NumCartao;
            _comando.Parameters.Add("@limite", SqlDbType.Decimal).Value = parNC.Limite;
            _comando.Parameters.Add("@saldo", SqlDbType.Decimal).Value = parNC.Saldo;
            _comando.Parameters.Add("@gastos", SqlDbType.Decimal).Value = parNC.Gastos;

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

        public DataTable CarregarDropUsuarios()
        {
            
            _comando.Connection = _conexao.conectar();
            _comando.CommandText = " SELECT ID_USUARIO, NOME_RAZAO FROM TB_USUARIO WHERE TIPO_USUARIO != 1; ";

            try
            {  
                _tabela = new DataTable();
                _adaptador = new SqlDataAdapter(_comando);
                _adaptador.Fill(_tabela);
                _conexao.desconectar();

                tem = true;
                return _tabela;
            }

            catch (SqlException)
            {
                tem = false;
                return null;
            }
        }

        public bool ValidarCartao(String cartao)
        {
            _comando.CommandText = " SELECT num_cartao from tb_cartoes " +
                                   " where num_cartao = '" + cartao + "'; ";

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

        public bool ValidarConta(String conta)
        {
            _comando.CommandText = " SELECT num_conta from tb_cartoes " +
                                   " where num_conta = '" + conta + "'; ";

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