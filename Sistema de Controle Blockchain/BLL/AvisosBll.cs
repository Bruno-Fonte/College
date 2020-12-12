using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Web;
using SistemaBlockchain.DAL;

namespace SistemaBlockchain.Modelo
{
    public class AvisosBll
    {
        public bool tem;
        public DataTable _tabela = new DataTable();

        public DataTable CarregarGridAvisosSistema(int id)
        {
            AvisosDalComandos AvisosDal = new AvisosDalComandos();

            _tabela = AvisosDal.CarregarGridAvisosSistema(id);

            if (AvisosDal.tem)
            {
                this.tem = true;
            }

            return _tabela;
        }

        public void GerarAviso(String descricao, int id)
        {
            AvisosDalComandos AvisosDal = new AvisosDalComandos();

            AvisosDal.GerarAviso(descricao, id);
        }

        public void ExcluirAviso(int id)
        {
            AvisosDalComandos AvisosDal = new AvisosDalComandos();

            AvisosDal.ExcluirAviso(id);
        }
    }
}