using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data;
using System.Data.Sql;
using System.Data.SqlClient;

namespace dal
{
    public class conexao
    {
        private static String _stringConexao =
            "Data Source=LAPTOP-0TB2ULAC\\SQLEXPRESS; " +
            "Initial Catalog=dbEditoras; " +
            "Integrated Security=True;";

        private static SqlConnection _conexao;
        private static SqlCommand _comandoSql;
        private static SqlDataAdapter _adaptadorSql;
        private static DataTable _tabela;

        public static SqlConnection obterConexao()
        {
            try
            {
                _conexao = new SqlConnection(_stringConexao);
                _conexao.Open();

                return _conexao;
            }
            catch (Exception)
            {
                return null;
                throw;
            }
        }

        public static void fecharConexao(SqlConnection con)
        {
            try
            {
                if (con.State == ConnectionState.Open)
                {
                    con.Close();
                }
            }
            catch (Exception)
            {

                throw;
            }
        }

        public static void executarSql(SqlCommand _comandoSql)
        {
            _conexao = new SqlConnection(_stringConexao);
            _conexao.Open();

            _comandoSql.Connection = _conexao;
            _comandoSql.ExecuteNonQuery();

            _conexao.Close();
        }

        public static DataTable ObterDados(String sql)
        {
            _conexao = new SqlConnection(_stringConexao);
            _conexao.Open();

            _comandoSql = new SqlCommand();
            _comandoSql.Connection = _conexao;
            _comandoSql.CommandText = sql;

            _tabela = new DataTable();

            _adaptadorSql = new SqlDataAdapter(_comandoSql);
            _adaptadorSql.Fill(_tabela);

            _conexao.Close();

            return _tabela;
        }

        public static Int32 obterProximoCodigoEditora()
        {
            Int32 prox = 0;

            _conexao = new SqlConnection(_stringConexao);
            _conexao.Open();

            _comandoSql = new SqlCommand();
            _comandoSql.Connection = _conexao;
            _comandoSql.CommandText =
                "select isnull((max(edi_id) + 1), 1) as proximo " +
                "from tbl_editoras";

            prox = Int32.Parse(_comandoSql.ExecuteScalar().ToString());

            _conexao.Close();

            return prox;
        }

        public static Int32 obterProximoCodigoLivro()
        {
            Int32 prox = 0;

            _conexao = new SqlConnection(_stringConexao);
            _conexao.Open();

            _comandoSql = new SqlCommand();
            _comandoSql.Connection = _conexao;
            _comandoSql.CommandText =
                "select isnull((max(liv_id) + 1), 1) as proximo " +
                "from tbl_livros";

            prox = Int32.Parse(_comandoSql.ExecuteScalar().ToString());

            _conexao.Close();

            return prox;
        }

        public static Int32 obterProximoCodigoAutor()
        {
            Int32 prox = 0;

            _conexao = new SqlConnection(_stringConexao);
            _conexao.Open();

            _comandoSql = new SqlCommand();
            _comandoSql.Connection = _conexao;
            _comandoSql.CommandText =
                "select isnull((max(aut_id) + 1), 1) as proximo " +
                "from tbl_autores";

            prox = Int32.Parse(_comandoSql.ExecuteScalar().ToString());

            _conexao.Close();

            return prox;
        }
    }
}
