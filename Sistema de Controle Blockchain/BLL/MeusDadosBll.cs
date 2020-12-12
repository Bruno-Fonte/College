using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Web;
using SistemaBlockchain.DAL;

namespace SistemaBlockchain.Modelo
{
    public class MeusDadosBll
    {
        public bool tem;
        public string msg = " ";
        public DataTable _tabela = new DataTable();

        public DataTable CarregarGridMeusDados(int id)
        {
            MeusDadosDalComandos MDDal = new MeusDadosDalComandos();

            _tabela = MDDal.CarregarGridMeusDados(id);

            if (MDDal.tem)
            {
                this.tem = true;
            }

            return _tabela;
        }

        public String EditarUsuario(int id, String nome, String cpf, String usuario)
        {
            MeusDadosDalComandos MDDal = new MeusDadosDalComandos();

            try
            {
                MDDal.EditarUsuario(id, nome, cpf, usuario);

                if (MDDal.tem)
                {
                    this.tem = true;
                }

                return MDDal.msg;
            }
            catch (Exception)
            {
                return MDDal.msg;
            }
        }
    }
}