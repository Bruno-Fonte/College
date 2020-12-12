using dto;
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
    public class ClsAutoresDal
    {
        private SqlConnection _conexao;
        private SqlCommand _comandoSql;
        private SqlDataAdapter _adaptadorSql;
        private DataTable _tabela;
        private SqlDataReader _readerSql;

        public void Cadastrar(ClsAutoresDto parAutor)
        {
            Int32 codigo = ObterProximoCodigo();

            SqlCommand _comando = new SqlCommand();
            SqlConnection _conexao = new SqlConnection();

            _comando.Connection = _conexao;
            _comando.CommandText = "insert into tbl_autores values" +
                "(@aut_id, @aut_nome, @aut_pseudonimo, @aut_observacoes);";

            _comando.Parameters.Add("@aut_id", SqlDbType.Int).Value = codigo;
            _comando.Parameters.Add("@aut_nome", SqlDbType.VarChar).Value = parAutor.Nome;
            _comando.Parameters.Add("@aut_pseudonimo", SqlDbType.VarChar).Value = parAutor.Pseudonimo;
            _comando.Parameters.Add("@aut_observacoes", SqlDbType.VarChar).Value = parAutor.Obs;

            conexao.executarSql(_comando);
        }

        public void Atualizar(ClsAutoresDto parAutor)
        {
            SqlCommand _comando = new SqlCommand();
            SqlConnection _conexao = new SqlConnection();

            _comando.Connection = _conexao;
            _comando.CommandText = "update tbl_autores set aut_nome = @aut_nome, aut_pseudonimo = @aut_pseudonimo, " +
                                   "aut_observacoes = @aut_observacoes " +
                                   "where aut_id = @aut_id;";

            _comando.Parameters.Add("@aut_nome", SqlDbType.VarChar).Value = parAutor.Nome;
            _comando.Parameters.Add("@aut_pseudonimo", SqlDbType.VarChar).Value = parAutor.Pseudonimo;
            _comando.Parameters.Add("@aut_observacoes", SqlDbType.VarChar).Value = parAutor.Obs;
            _comando.Parameters.Add("@aut_id", SqlDbType.VarChar).Value = parAutor.Codigo;

            conexao.executarSql(_comando);
        }

        public void Excluir(int codigo)
        {
            SqlCommand _comando = new SqlCommand();
            SqlConnection _conexao = new SqlConnection();

            _comando.Connection = _conexao;
            _comando.CommandText = "delete from tbl_autoreslivros where aut_id = @aut_id; " +
                                   "delete from tbl_autores where aut_id = @aut_id; ";

            _comando.Parameters.Add("@aut_id", SqlDbType.VarChar).Value = codigo;

            conexao.executarSql(_comando);
        }

        public List<ClsAutoresDto> ObterAutores()
        {
            try
            {
                List<ClsAutoresDto> lista = new List<ClsAutoresDto>();

                ClsAutoresDto item;

                _conexao = conexao.obterConexao();
                _comandoSql = new SqlCommand();

                _comandoSql.Connection = _conexao;
                _comandoSql.CommandText = " select aut_id, aut_nome, " +
                                   " aut_pseudonimo, aut_observacoes " +
                                   " from tbl_autores; ";

                _readerSql = _comandoSql.ExecuteReader();

                while (_readerSql.Read())
                {
                    item = new ClsAutoresDto();
                    item.Codigo = int.Parse(_readerSql["aut_id"].ToString());
                    item.Nome = _readerSql["aut_nome"].ToString();
                    item.Pseudonimo = _readerSql["aut_pseudonimo"].ToString();
                    item.Obs = _readerSql["aut_observacoes"].ToString();

                    lista.Add(item);
                }

                _readerSql.Close();

                conexao.fecharConexao(_conexao);

                return lista;

            }
            catch (Exception)
            {
                return null;
                throw;
            }
        }

        public List<ClsAutoresDto> ObterAutoresNome(String filtro)
        {
            try
            {
                List<ClsAutoresDto> lista = new List<ClsAutoresDto>();

                ClsAutoresDto item;

                _conexao = conexao.obterConexao();
                _comandoSql = new SqlCommand();

                _comandoSql.Connection = _conexao;
                _comandoSql.CommandText = "select aut_id, aut_nome, " +
                                   " aut_pseudonimo, aut_observacoes " +
                                   " from tbl_autores where aut_nome " +
                                   " like '" + filtro + "%'; ";

                _readerSql = _comandoSql.ExecuteReader();

                while (_readerSql.Read())
                {
                    item = new ClsAutoresDto();
                    item.Codigo = int.Parse(_readerSql["aut_id"].ToString());
                    item.Nome = _readerSql["aut_nome"].ToString();
                    item.Pseudonimo = _readerSql["aut_pseudonimo"].ToString();
                    item.Obs = _readerSql["aut_observacoes"].ToString();

                    lista.Add(item);
                }

                _readerSql.Close();

                conexao.fecharConexao(_conexao);

                return lista;

            }
            catch (Exception)
            {
                return null;
                throw;
            }
        }

        public List<ClsAutoresDto> ObterAutoresPseudonimo(String filtro)
        {
            try
            {
                List<ClsAutoresDto> lista = new List<ClsAutoresDto>();

                ClsAutoresDto item;

                _conexao = conexao.obterConexao();
                _comandoSql = new SqlCommand();

                _comandoSql.Connection = _conexao;
                _comandoSql.CommandText = "select aut_id, aut_nome, " +
                                   " aut_pseudonimo, aut_observacoes " +
                                   " from tbl_autores where aut_pseudonimo " +
                                   " like '" + filtro + "%'; ";

                _readerSql = _comandoSql.ExecuteReader();

                while (_readerSql.Read())
                {
                    item = new ClsAutoresDto();
                    item.Codigo = int.Parse(_readerSql["aut_id"].ToString());
                    item.Nome = _readerSql["aut_nome"].ToString();
                    item.Pseudonimo = _readerSql["aut_pseudonimo"].ToString();
                    item.Obs = _readerSql["aut_observacoes"].ToString();

                    lista.Add(item);
                }

                _readerSql.Close();

                conexao.fecharConexao(_conexao);

                return lista;

            }
            catch (Exception)
            {
                return null;
                throw;
            }
        }

        public Int32 ObterProximoCodigo()
        {
            Int32 prox = 0;

            _conexao = conexao.obterConexao();

            _comandoSql = new SqlCommand();
            _comandoSql.Connection = _conexao;
            _comandoSql.CommandText =
                "select isnull((max(aut_id) + 1), 1) as proximo " +
                "from tbl_autores";

            prox = Int32.Parse(_comandoSql.ExecuteScalar().ToString());

            conexao.fecharConexao(_conexao);

            return prox;
        }
    }
}
