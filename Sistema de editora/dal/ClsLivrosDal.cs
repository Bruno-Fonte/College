using dto;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data;
using System.Data.Sql;
using System.Data.SqlClient;
using System.Runtime.Remoting.Messaging;

namespace dal
{
    public class ClsLivrosDal
    {
        private SqlConnection _conexao;
        private SqlCommand _comandoSql;
        private SqlDataAdapter _adaptadorSql;
        private DataTable _tabela;
        private SqlDataReader _readerSql;

        public void Cadastrar(ClsLivroDto parLivros)
        {
            _conexao = new SqlConnection();
            _comandoSql = new SqlCommand();

            Int32 codigo = ObterProximoCodigoLivro();

            _comandoSql.Connection = _conexao;
            _comandoSql.CommandText = "insert into tbl_livros values " +
                "(@liv_id, @liv_nome, @liv_anopublicacao, @liv_isbn, @liv_observacoes, @edi_id);";

            _comandoSql.Parameters.Add("@liv_id", SqlDbType.Int).Value = codigo;
            _comandoSql.Parameters.Add("@liv_nome", SqlDbType.VarChar).Value = parLivros.Nome;
            _comandoSql.Parameters.Add("@liv_anopublicacao", SqlDbType.Int).Value = parLivros.Ano;
            _comandoSql.Parameters.Add("@liv_isbn", SqlDbType.Decimal).Value = parLivros.Isbn;
            _comandoSql.Parameters.Add("@liv_observacoes", SqlDbType.VarChar).Value = parLivros.Obs;
            _comandoSql.Parameters.Add("@edi_id", SqlDbType.Int).Value = parLivros.CodigoEdi;

            conexao.executarSql(_comandoSql);
        }

        public void Atualizar(ClsLivroDto parLivros)
        {
            _conexao = new SqlConnection();
            _comandoSql = new SqlCommand();

            _comandoSql.Connection = _conexao;
            _comandoSql.CommandText = "update tbl_livros set liv_nome = @liv_nome, " +
                                   "liv_anopublicacao = @liv_anopublicacao, liv_isbn = @liv_isbn, " +
                                   "liv_observacoes = @liv_observacoes, edi_id = @edi_id " +
                                   "where liv_id = @liv_id; ";

            _comandoSql.Parameters.Add("@liv_nome", SqlDbType.VarChar).Value = parLivros.Nome;
            _comandoSql.Parameters.Add("@liv_anopublicacao", SqlDbType.Int).Value = parLivros.Ano;
            _comandoSql.Parameters.Add("@liv_isbn", SqlDbType.Decimal).Value = parLivros.Isbn;
            _comandoSql.Parameters.Add("@liv_observacoes", SqlDbType.VarChar).Value = parLivros.Obs;
            _comandoSql.Parameters.Add("@edi_id", SqlDbType.Int).Value = parLivros.Codigo;
            _comandoSql.Parameters.Add("@liv_id", SqlDbType.Int).Value = parLivros.CodigoEdi;
            
            conexao.executarSql(_comandoSql);
        }

        public void Excluir(int codigo)
        {
            _conexao = new SqlConnection();
            _comandoSql = new SqlCommand();

            _comandoSql.Connection = _conexao;
            _comandoSql.CommandText = "delete from tbl_autoreslivros where liv_id = @liv_id; " +
                                   "delete from tbl_livros where liv_id = @liv_id; ";


            _comandoSql.Parameters.Add("@liv_id", SqlDbType.VarChar).Value = codigo;

            conexao.executarSql(_comandoSql);
        }

        public List<ClsLivroDto> ObterLivros()
        {
            try
            {
                List<ClsLivroDto> lista = new List<ClsLivroDto>();

                ClsLivroDto item;

                _conexao = conexao.obterConexao();
                _comandoSql = new SqlCommand();

                _comandoSql.Connection = _conexao;
                _comandoSql.CommandText = " select liv_id, liv_nome, " +
                                          " liv_anopublicacao, liv_isbn, " +
                                          " liv_observacoes, edi_nome " +
                                          " from tbl_livros l inner join " +
                                          " tbl_editoras e on l.edi_id = e.edi_id; " ;

                _readerSql = _comandoSql.ExecuteReader();

                while (_readerSql.Read())
                {
                    item = new ClsLivroDto();

                    item.Codigo = int.Parse(_readerSql["liv_id"].ToString());
                    item.Nome = _readerSql["liv_nome"].ToString();
                    item.Ano = int.Parse(_readerSql["liv_anopublicacao"].ToString());
                    item.Isbn = Decimal.Parse(_readerSql["liv_isbn"].ToString());
                    item.Obs = _readerSql["liv_observacoes"].ToString();
                    item.NomeEdi = _readerSql["edi_nome"].ToString();

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

        public List<ClsLivroDto> ObterLivrosNome(String filtro)
        {
            try
            {
                List<ClsLivroDto> lista = new List<ClsLivroDto>();

                ClsLivroDto item;

                _conexao = conexao.obterConexao();
                _comandoSql = new SqlCommand();

                _comandoSql.Connection = _conexao;
                _comandoSql.CommandText = " select liv_id, liv_nome, " +
                                              " liv_anopublicacao, liv_isbn, " +
                                              " liv_observacoes, edi_nome " +
                                              " from tbl_livros l inner join " +
                                              " tbl_editoras e on l.edi_id = e.edi_id " +
                                              " where liv_nome like '" + filtro + "%'; ";

                _readerSql = _comandoSql.ExecuteReader();

                while (_readerSql.Read())
                {
                    item = new ClsLivroDto();

                    item.Codigo = int.Parse(_readerSql["liv_id"].ToString());
                    item.Nome = _readerSql["liv_nome"].ToString();
                    item.Ano = int.Parse(_readerSql["liv_anopublicacao"].ToString());
                    item.Isbn = Decimal.Parse(_readerSql["liv_isbn"].ToString());
                    item.Obs = _readerSql["liv_observacoes"].ToString();
                    item.NomeEdi = _readerSql["edi_nome"].ToString();

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

        public List<ClsLivroDto> ObterLivrosEditora(String filtro)
        {
            try
            {
                List<ClsLivroDto> lista = new List<ClsLivroDto>();

                ClsLivroDto item;

                _conexao = conexao.obterConexao();
                _comandoSql = new SqlCommand();

                _comandoSql.Connection = _conexao;
                _comandoSql.CommandText = " select liv_id, liv_nome, " +
                                              " liv_anopublicacao, liv_isbn, " +
                                              " liv_observacoes, edi_nome " +
                                              " from tbl_livros l inner join " +
                                              " tbl_editoras e on l.edi_id = e.edi_id " +
                                              " where edi_nome like '" + filtro + "%'; ";

                _readerSql = _comandoSql.ExecuteReader();

                while (_readerSql.Read())
                {
                    item = new ClsLivroDto();

                    item.Codigo = int.Parse(_readerSql["liv_id"].ToString());
                    item.Nome = _readerSql["liv_nome"].ToString();
                    item.Ano = int.Parse(_readerSql["liv_anopublicacao"].ToString());
                    item.Isbn = Decimal.Parse(_readerSql["liv_isbn"].ToString());
                    item.Obs = _readerSql["liv_observacoes"].ToString();
                    item.NomeEdi = _readerSql["edi_nome"].ToString();

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

        /*public DataTable ObterDados(int tipo, String filtro)
        {
            try
            {
                if (tipo == 1)
                {
                    return conexao.ObterDados(" select liv_id, liv_nome, " +
                                              " liv_anopublicacao, liv_isbn, " +
                                              " liv_observacoes, edi_nome " +
                                              " from tbl_livros l inner join " +
                                              " tbl_editoras e on l.edi_id = e.edi_id " +
                                              " where liv_nome like '" + filtro + "%'; ");
                }
                else if (tipo == 2)
                {
                    return conexao.ObterDados(" select liv_id, liv_nome, " +
                                              " liv_anopublicacao, liv_isbn, " +
                                              " liv_observacoes, edi_nome " +
                                              " from tbl_livros l inner join " +
                                              " tbl_editoras e on l.edi_id = e.edi_id " +
                                              " where edi_nome like '" + filtro + "%'; ");
                }
                else
                {
                    return null;
                }
            }

            catch (Exception)
            {
                throw;
            }
        }*/

        public DataTable ObterDadosCombo(String sql)
        {
            return conexao.ObterDados(sql);
        }

        public Int32 ObterProximoCodigoLivro()
        {
            return conexao.obterProximoCodigoLivro();
        }
    }
}
