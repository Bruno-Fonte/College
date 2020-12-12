using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Data;
using System.Data.Sql;
using System.Data.SqlClient;

namespace SistemaBlockchain.DAL
{
    public class Conexao
    {

        SqlConnection _conexao = new SqlConnection();
        SqlCommand _comandoSql;
        SqlDataAdapter _adaptadorSql;
        DataTable _tabela;

        public Conexao()
        {
            _conexao.ConnectionString = @"Data Source=LAPTOP-0TB2ULAC\SQLEXPRESS;Initial Catalog=Blockchain;Integrated Security=True";
        }

        public SqlConnection conectar()
        {
            if(_conexao.State == System.Data.ConnectionState.Closed)
            {
                _conexao.Open();
            }

            return _conexao;
        }

        public void desconectar()
        {
            if (_conexao.State == System.Data.ConnectionState.Open)
            {
                _conexao.Close();
            }
        }
    }
}