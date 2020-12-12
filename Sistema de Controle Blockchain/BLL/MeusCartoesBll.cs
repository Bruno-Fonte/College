using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Web;
using SistemaBlockchain.DAL;

namespace SistemaBlockchain.Modelo
{
    public class MeusCartoesBll
    {
        public bool tem;
        public DataTable _tabela = new DataTable();

        public DataTable CarregarGridCartoesCredito(int id)
        {
            MeusCartoesDalComandos cartoesDal = new MeusCartoesDalComandos();

            _tabela = cartoesDal.CarregarGridCartoesCredito(id);

            if (cartoesDal.tem)
            {
                this.tem = true;
            }

            return _tabela;
        }

        public DataTable CarregarGridCartoesDebito(int id)
        {
            MeusCartoesDalComandos cartoesDal = new MeusCartoesDalComandos();

            _tabela = cartoesDal.CarregarGridCartoesDebito(id);

            if (cartoesDal.tem)
            {
                this.tem = true;
            }

            return _tabela;
        }
    }
}