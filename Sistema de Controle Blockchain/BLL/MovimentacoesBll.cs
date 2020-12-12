using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Web;
using SistemaBlockchain.DAL;
using SistemaBlockchain.dto;

namespace SistemaBlockchain.Modelo
{
    public class MovimentacoesBll
    {
        public bool tem;
        public String msg;
        public DataTable _tabela = new DataTable();

        public String EfetuarMovimentacao(MovimentacoesDto parMov)
        {
            MovimentacoesDalComandos MovDal = new MovimentacoesDalComandos();

            this.msg = MovDal.EfetuarMovimentacao(parMov);

            if (MovDal.tem)
            {
                this.tem = true;
            }

            return msg;
        }

        public Decimal ConsultarLimite(Decimal contaOrigem)
        {
            MovimentacoesDalComandos MovDal = new MovimentacoesDalComandos();

            return MovDal.ConsultarLimite(contaOrigem);
        }

        public Decimal ConsultarSaldo(Decimal contaOrigem)
        {
            MovimentacoesDalComandos MovDal = new MovimentacoesDalComandos();

            return MovDal.ConsultarSaldo(contaOrigem);
        }

        public Decimal ConsultarGasto(Decimal contaOrigem)
        {
            MovimentacoesDalComandos MovDal = new MovimentacoesDalComandos();

            return MovDal.ConsultarGasto(contaOrigem);
        }

        public void AtualizarSaldoOrigem(Decimal novoSaldo, Decimal contaOrigem)
        {
            MovimentacoesDalComandos MovDal = new MovimentacoesDalComandos();

            MovDal.AtualizarSaldoOrigem(novoSaldo, contaOrigem);
        }

        public void AtualizarSaldoDestino(Decimal novoSaldo, Decimal contaDestino)
        {
            MovimentacoesDalComandos MovDal = new MovimentacoesDalComandos();

            MovDal.AtualizarSaldoDestino(novoSaldo, contaDestino);
        }

        public void AtualizarGastoOrigem(Decimal novoSaldo, Decimal contaOrigem)
        {
            MovimentacoesDalComandos MovDal = new MovimentacoesDalComandos();

            MovDal.AtualizarGastoOrigem(novoSaldo, contaOrigem);
        }

        public DataTable ObterContas(int id)
        {
            MovimentacoesDalComandos MovDal = new MovimentacoesDalComandos();

            _tabela = MovDal.ObterContas(id);

            if (MovDal.tem)
            {
                this.tem = true;
            }

            return _tabela;
        }

        public bool ValidarContaDestino(Decimal conta)
        {
            MovimentacoesDalComandos MovDal = new MovimentacoesDalComandos();

            return MovDal.ValidarContaDestino(conta);
        }

        public int TipoConta(Decimal conta)
        {
            MovimentacoesDalComandos MovDal = new MovimentacoesDalComandos();

            return MovDal.TipoConta(conta);
        }

        public int TipoUsuario(Decimal conta)
        {
            MovimentacoesDalComandos MovDal = new MovimentacoesDalComandos();

            return MovDal.TipoUsuario(conta);
        }

        public String NomeUsuario(Decimal conta)
        {
            MovimentacoesDalComandos MovDal = new MovimentacoesDalComandos();

            return MovDal.NomeUsuario(conta);
        }
    }
}