using System.Data;
using System.Data.SqlClient;

namespace SistemaBlockchain.DAL
{
    public class RelatoriosDalComandos
    {
        public bool tem = false;
        SqlCommand _comando = new SqlCommand();
        Conexao _conexao = new Conexao();
        SqlDataAdapter _adaptador = new SqlDataAdapter();
        DataTable _tabela = new DataTable();

        public DataTable CarregarGridRelatorios(decimal conta)
        {
            tem = false;

            _comando.CommandText = " select m.DATA, m.HISTORICO, m.VALOR_MOVIMENTACAO, m.NUM_CONTA_ORIGEM, m.NUM_CONTA_DESTINO, " +
                                   " tm.NOME_MOVIMENTACAO, tc.NOME_CARTAO from TB_MOVIMENTACOES m inner join " +
                                   " TB_CARTOES c on m.NUM_CONTA_ORIGEM = c.NUM_CONTA inner join TB_TIPO_CARTAO tc on " +
                                   " tc.TIPO_CARTAO = c.TIPO_CARTAO inner join TB_TIPO_MOVIMENTACOES tm  " +
                                   " on tm.TIPO_MOVIMENTACAO = m.TIPO_MOVIMENTACAO where " +
                                   " (m.NUM_CONTA_DESTINO = @conta or m.NUM_CONTA_ORIGEM = @conta) " +
                                   " group by m.DATA, m.HISTORICO, m.NUM_CONTA_ORIGEM, m.VALOR_MOVIMENTACAO,  " +
                                   " m.NUM_CONTA_DESTINO, tm.NOME_MOVIMENTACAO, tc.NOME_CARTAO; ";

            _comando.Parameters.Add("@conta", SqlDbType.Decimal).Value = conta;



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

        public DataTable CarregarGridRelatoriosAdmin(int id)
        {
            tem = false;

            _comando.CommandText = " select m.DATA, m.HISTORICO, m.VALOR_MOVIMENTACAO, m.NUM_CONTA_ORIGEM, m.NUM_CONTA_DESTINO, " +
                                   " tm.NOME_MOVIMENTACAO, tc.NOME_CARTAO from TB_MOVIMENTACOES m inner join " +
                                   " TB_CARTOES c on (m.NUM_CONTA_DESTINO = c.NUM_CONTA) or (m.NUM_CONTA_ORIGEM = c.NUM_CONTA) inner join TB_TIPO_CARTAO tc on " +
                                   " tc.TIPO_CARTAO = c.TIPO_CARTAO inner join TB_TIPO_MOVIMENTACOES tm  " +
                                   " on tm.TIPO_MOVIMENTACAO = m.TIPO_MOVIMENTACAO where c.ID_USUARIO = @id " +
                                   " group by m.DATA, m.HISTORICO, m.NUM_CONTA_ORIGEM, m.VALOR_MOVIMENTACAO, " +
                                   " m.NUM_CONTA_DESTINO, tm.NOME_MOVIMENTACAO, tc.NOME_CARTAO; ";

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

        public DataTable CarregarDropUsuarios()
        {

            _comando.Connection = _conexao.conectar();
            _comando.CommandText = " SELECT ID_USUARIO, NOME_RAZAO FROM TB_USUARIO WHERE TIPO_USUARIO != 1";

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

        public DataTable ObterContas(int id)
        {
            try
            {
                _comando.Connection = _conexao.conectar();
                _comando.CommandText = " SELECT NUM_CONTA FROM TB_CARTOES where ID_USUARIO = @id; ";

                _comando.Parameters.Add("@id", SqlDbType.Int).Value = id;

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