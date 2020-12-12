using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Data;
using System.Data.SqlClient;

namespace SistemaBlockchain.DAL
{
    public class MeusCartoesDalComandos
    {
        public bool tem = false;
        SqlCommand _comando = new SqlCommand();
        Conexao _conexao = new Conexao();
        SqlDataAdapter _adaptador = new SqlDataAdapter();
        DataTable _tabela = new DataTable();

        public DataTable CarregarGridCartoesCredito(int id)
        {
            tem = false;

            _comando.CommandText = " select num_cartao, gastos_cartao, " +
                                   " limite_cartao, num_conta from tb_cartoes " +
                                   " where id_usuario = @id and tipo_cartao = 1; ";

            _comando.Parameters.Add("@id", SqlDbType.Int).Value = id;


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

        public DataTable CarregarGridCartoesDebito(int id)
        {
            tem = false;

            _comando.CommandText = " select num_cartao, saldo_cartao, " +
                                   " num_conta from tb_cartoes " +
                                   " where id_usuario = @id and tipo_cartao = 2; ";

            _comando.Parameters.Add("@id", SqlDbType.Int).Value = id;


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
    }
}