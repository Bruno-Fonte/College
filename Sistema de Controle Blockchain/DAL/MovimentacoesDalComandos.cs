using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using SistemaBlockchain.dto;

namespace SistemaBlockchain.DAL
{
    public class MovimentacoesDalComandos
    {
        public bool tem = false;
        public String msg;
        SqlCommand _comando = new SqlCommand();
        Conexao _conexao = new Conexao();
        SqlDataAdapter _adaptador = new SqlDataAdapter();
        DataTable _tabela = new DataTable();
        SqlDataReader _data;

        public String EfetuarMovimentacao(MovimentacoesDto parMov)
        {
            tem = false;

            _comando.CommandText = " insert into TB_MOVIMENTACOES values " +
                                   " (current_timestamp, @descricao, @valor, @tipo_mov, " +
                                   " @conta_origem, @conta_destino); ";

            _comando.Parameters.Add("@descricao", SqlDbType.VarChar).Value = parMov.Descricao;
            _comando.Parameters.Add("@valor", SqlDbType.Decimal).Value = parMov.Valor;
            _comando.Parameters.Add("@tipo_mov", SqlDbType.Int).Value = parMov.TipoMovimentacao;
            _comando.Parameters.Add("@conta_origem", SqlDbType.Decimal).Value = parMov.NumContaOrigem;
            _comando.Parameters.Add("@conta_destino", SqlDbType.Decimal).Value = parMov.NumContaDestino;

            try
            {
                _comando.Connection = _conexao.conectar();
                _comando.ExecuteNonQuery();
                _conexao.desconectar();

                this.msg = "Transação efetuada!";
                tem = true;
            }
            catch (SqlException)
            {

                this.msg = "Erro com o banco de dados!";
            }

            return msg;
        }

        public Decimal ConsultarLimite(Decimal contaOrigem)
        {
            Decimal limite;

            _comando.CommandText = " select limite_cartao from tb_cartoes " +
                                   " where num_conta = @conta; ";

            _comando.Parameters.Add("@conta", SqlDbType.Decimal).Value = contaOrigem;

            _comando.Connection = _conexao.conectar();
            limite = Decimal.Parse(_comando.ExecuteScalar().ToString());

            _conexao.desconectar();

            return limite;
        }

        public Decimal ConsultarSaldo(Decimal contaOrigem)
        {
            Decimal saldo;

            _comando.CommandText = " select saldo_cartao from tb_cartoes " +
                                   " where num_conta = @conta; ";

            _comando.Parameters.Add("@conta", SqlDbType.Decimal).Value = contaOrigem;

            _comando.Connection = _conexao.conectar();
            saldo = Decimal.Parse(_comando.ExecuteScalar().ToString());

            _conexao.desconectar();

            return saldo;
        }

        public Decimal ConsultarGasto(Decimal contaOrigem)
        {
            Decimal gasto;

            _comando.CommandText = " select gastos_cartao from tb_cartoes " +
                                   " where num_conta = @conta; ";

            _comando.Parameters.Add("@conta", SqlDbType.Decimal).Value = contaOrigem;

            _comando.Connection = _conexao.conectar();
            gasto = Decimal.Parse(_comando.ExecuteScalar().ToString());

            _conexao.desconectar();

            return gasto;
        }

        public void AtualizarSaldoOrigem(Decimal novoSaldo, Decimal contaOrigem)
        {
            tem = false;

            _comando.CommandText = " update tb_cartoes set saldo_cartao = @novo_saldo where " +
                                   " num_conta = @conta_origem; ";


            _comando.Parameters.Add("@novo_saldo", SqlDbType.Decimal).Value = novoSaldo;
            _comando.Parameters.Add("@conta_origem", SqlDbType.Decimal).Value = contaOrigem;

            try
            {
                _comando.Connection = _conexao.conectar();
                _comando.ExecuteNonQuery();
                _conexao.desconectar();

                this.msg = "Transação efetuada!";
                tem = true;
            }
            catch (SqlException)
            {

                this.msg = "Erro com o banco de dados!";
            }
        }

        public void AtualizarSaldoDestino(Decimal novoSaldo, Decimal contaDestino)
        {
            tem = false;

            _comando.CommandText = " update tb_cartoes set saldo_cartao = @novo_saldo where " +
                                   " num_conta = @conta_destino; ";


            _comando.Parameters.Add("@novo_saldo", SqlDbType.Decimal).Value = novoSaldo;
            _comando.Parameters.Add("@conta_destino", SqlDbType.Decimal).Value = contaDestino;

            try
            {
                _comando.Connection = _conexao.conectar();
                _comando.ExecuteNonQuery();
                _conexao.desconectar();

                this.msg = "Transação efetuada!";
                tem = true;
            }
            catch (SqlException)
            {

                this.msg = "Erro com o banco de dados!";
            }
        }

        public void AtualizarGastoOrigem(Decimal novoSaldo, Decimal contaOrigem)
        {
            tem = false;

            _comando.CommandText = " update tb_cartoes set gastos_cartao = @novo_saldo where " +
                                   " num_conta = @conta_origem; ";


            _comando.Parameters.Add("@novo_saldo", SqlDbType.Decimal).Value = novoSaldo;
            _comando.Parameters.Add("@conta_origem", SqlDbType.Decimal).Value = contaOrigem;

            try
            {
                _comando.Connection = _conexao.conectar();
                _comando.ExecuteNonQuery();
                _conexao.desconectar();

                this.msg = "Transação efetuada!";
                tem = true;
            }
            catch (SqlException)
            {

                this.msg = "Erro com o banco de dados!";
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
                tem = false;
                return null;
            }
        }

        public bool ValidarContaDestino(Decimal conta)
        {
            try
            {
                _comando.Connection = _conexao.conectar();
                _comando.CommandText = " SELECT NUM_CONTA FROM TB_CARTOES where NUM_CONTA = @conta; ";

                _comando.Parameters.Add("@conta", SqlDbType.Int).Value = conta;

                _comando.Connection = _conexao.conectar();
                _data = _comando.ExecuteReader();

                if (_data.HasRows)
                {
                    _conexao.desconectar();
                    return true;
                }
                else
                {
                    _conexao.desconectar();
                    return false;
                }
            }

            catch (SqlException)
            {
                this.msg = "Erro com banco de dados!";
                return false;
            }
        }

        public int TipoConta(Decimal conta)
        {
            int tipo;

            _comando.CommandText = " select tipo_cartao from tb_cartoes " +
                                   " where num_conta = @conta; ";

            _comando.Parameters.Add("@conta", SqlDbType.Decimal).Value = conta;

            _comando.Connection = _conexao.conectar();

            tipo = int.Parse(_comando.ExecuteScalar().ToString());

            _conexao.desconectar();

            return tipo;
        }

        public int TipoUsuario(Decimal conta)
        {
            int tipo;

            _comando.CommandText = " select u.TIPO_USUARIO from TB_USUARIO u inner join TB_CARTOES c " +
                                   " on c.ID_USUARIO = u.ID_USUARIO where c.NUM_CONTA = @conta; ";

            _comando.Parameters.Add("@conta", SqlDbType.Decimal).Value = conta;

            _comando.Connection = _conexao.conectar();

            tipo = int.Parse(_comando.ExecuteScalar().ToString());

            _conexao.desconectar();

            return tipo;
        }

        public String NomeUsuario(Decimal conta)
        {
            String nome;

            _comando.CommandText = " select u.NOME_RAZAO from TB_USUARIO u inner join TB_CARTOES c " +
                                   " on c.ID_USUARIO = u.ID_USUARIO where c.NUM_CONTA = @conta; ";

            _comando.Parameters.Add("@conta", SqlDbType.Decimal).Value = conta;

            _comando.Connection = _conexao.conectar();

            nome = _comando.ExecuteScalar().ToString();

            _conexao.desconectar();

            return nome;
        }
    }
}