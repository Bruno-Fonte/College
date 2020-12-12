using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Web;
using SistemaBlockchain.DAL;
using SistemaBlockchain.dto;

namespace SistemaBlockchain.Modelo
{
    public class RelatoriosBll
    {
        public bool tem;
        public DataTable _tabela = new DataTable();

        public DataTable CarregarGridRelatorios(decimal conta)
        {
            RelatoriosDalComandos relDal = new RelatoriosDalComandos();

            _tabela = relDal.CarregarGridRelatorios(conta);

            if (relDal.tem)
            {
                this.tem = true;
            }

            return _tabela;
        }

        public DataTable ObterContas(int id)
        {
            RelatoriosDalComandos relDal = new RelatoriosDalComandos();

            _tabela = relDal.ObterContas(id);

            if (relDal.tem)
            {
                this.tem = true;
            }

            return _tabela;
        }

        public DataTable CarregarGridRelatoriosAdmin(int id)
        {
            RelatoriosDalComandos relDal = new RelatoriosDalComandos();

            _tabela = relDal.CarregarGridRelatoriosAdmin(id);

            if (relDal.tem)
            {
                this.tem = true;
            }

            return _tabela;
        }

        public DataTable CarregarDropUsuarios()
        {
            RelatoriosDalComandos relDal = new RelatoriosDalComandos();

            _tabela = relDal.CarregarDropUsuarios();

            if (relDal.tem)
            {
                this.tem = true;
            }

            return _tabela;
        }
    }
}