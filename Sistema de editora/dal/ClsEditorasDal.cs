using dto;
using dal;
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
    public class ClsEditorasDal
    {
        private SqlConnection _conexao;
        private SqlCommand _comandoSql;
        private SqlDataAdapter _adaptadorSql;
        private DataTable _tabela;
        private SqlDataReader _readerSql;

        public void Cadastrar(ClsEditorasDto parEditora)
        {
            parEditora.Codigo = ObterProximoCodigo();

            _comandoSql = new SqlCommand();
            _conexao = conexao.obterConexao();

            _comandoSql.Connection = _conexao;
            _comandoSql.CommandText = "insert into tbl_editoras values" +
                "(@edi_id, @edi_nome, @edi_sigla, @edi_observacoes);";

            _comandoSql.Parameters.Add("@edi_id", SqlDbType.Int).Value = parEditora.Codigo;
            _comandoSql.Parameters.Add("@edi_nome", SqlDbType.VarChar).Value = parEditora.Nome;
            _comandoSql.Parameters.Add("@edi_sigla", SqlDbType.VarChar).Value = parEditora.Sigla;
            _comandoSql.Parameters.Add("@edi_observacoes", SqlDbType.VarChar).Value = parEditora.Obs;

            _comandoSql.ExecuteNonQuery();

            conexao.fecharConexao(_conexao);
        }

        public void Atualizar(ClsEditorasDto parEditora)
        {
            _comandoSql = new SqlCommand();
            _conexao = conexao.obterConexao();

            _comandoSql.Connection = _conexao;
            _comandoSql.CommandText = "update tbl_editoras set edi_nome = @edi_nome, edi_sigla = @edi_sigla, " +
                                   "edi_observacoes = @edi_observacoes " +
                                   "where edi_id = @edi_id;";

            _comandoSql.Parameters.Add("@edi_nome", SqlDbType.VarChar).Value = parEditora.Nome;
            _comandoSql.Parameters.Add("@edi_sigla", SqlDbType.VarChar).Value = parEditora.Sigla;
            _comandoSql.Parameters.Add("@edi_observacoes", SqlDbType.VarChar).Value = parEditora.Obs;
            _comandoSql.Parameters.Add("@edi_id", SqlDbType.VarChar).Value = parEditora.Codigo;

            _comandoSql.ExecuteNonQuery();

            conexao.fecharConexao(_conexao);
        }

        public void Excluir(int codigo)
        {
            _comandoSql = new SqlCommand();
            _conexao = conexao.obterConexao();

            _comandoSql.Connection = _conexao;
            _comandoSql.CommandText = "delete from tbl_editoras where edi_id = @edi_id; ";

            _comandoSql.Parameters.Add("@edi_id", SqlDbType.VarChar).Value = codigo;

            _comandoSql.ExecuteNonQuery();

            conexao.fecharConexao(_conexao);
        }

        public List<ClsEditorasDto> ObterEditoras()
        {
            try
            {
                List<ClsEditorasDto> lista = new List<ClsEditorasDto>();

                ClsEditorasDto item;

                _conexao = conexao.obterConexao();
                _comandoSql = new SqlCommand();

                _comandoSql.Connection = _conexao;
                _comandoSql.CommandText = " select edi_id, edi_nome, " +
                                          " edi_sigla, edi_observacoes " +
                                          " from tbl_editoras; ";

                _readerSql = _comandoSql.ExecuteReader();

                while (_readerSql.Read())
                {
                    item = new ClsEditorasDto();
                    item.Codigo = Convert.ToInt32(_readerSql["edi_id"].ToString());
                    item.Nome = _readerSql["edi_nome"].ToString();
                    item.Sigla = _readerSql["edi_sigla"].ToString();
                    item.Obs = _readerSql["edi_observacoes"].ToString();

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

        public List<ClsEditorasDto> ObterEditorasNome(String filtro)
        {
            try
            {
                List<ClsEditorasDto> lista = new List<ClsEditorasDto>();

                ClsEditorasDto item;

                _conexao = conexao.obterConexao();
                _comandoSql = new SqlCommand();

                _comandoSql.Connection = _conexao;
                _comandoSql.CommandText = " select edi_id, edi_nome, " +
                                              " edi_sigla, edi_observacoes " +
                                              " from tbl_editoras " +
                                              " where edi_nome like " +
                                              " '" + filtro + "%' ; ";

                _readerSql = _comandoSql.ExecuteReader();

                while (_readerSql.Read())
                {
                    item = new ClsEditorasDto();
                    item.Codigo = Convert.ToInt32(_readerSql["edi_id"].ToString());
                    item.Nome = _readerSql["edi_nome"].ToString();
                    item.Sigla = _readerSql["edi_sigla"].ToString();
                    item.Obs = _readerSql["edi_observacoes"].ToString();

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
                "select isnull((max(edi_id) + 1), 1) as proximo " +
                "from tbl_editoras";

            prox = Int32.Parse(_comandoSql.ExecuteScalar().ToString());

            conexao.fecharConexao(_conexao); 

            return prox;
        }

    }
}
