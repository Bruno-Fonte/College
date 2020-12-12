using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Web;
using SistemaBlockchain.DAL;
using SistemaBlockchain.dto;

namespace SistemaBlockchain.Modelo
{
    public class NovoCartaoBll
    {
        public bool tem;
        public string msg = " ";

        public String CadastrarCartao(NovoCartaoDto parNC)
        {
            NovoCartaoDalComandos NCDal = new NovoCartaoDalComandos();

            this.msg = NCDal.CadastrarCartao(parNC);

            if (NCDal.tem)
            {
                this.tem = true;
            }

            return msg;
        }

        public DataTable CarregarDropUsuarios()
        {
            NovoCartaoDalComandos NCDal = new NovoCartaoDalComandos();

            return NCDal.CarregarDropUsuarios();
        }

        public bool ValidarCartao(String cartao)
        {
            NovoCartaoDalComandos NCDal = new NovoCartaoDalComandos();

            this.msg = NCDal.msg;

            return NCDal.ValidarCartao(cartao);
        }

        public bool ValidarConta(String conta)
        {
            NovoCartaoDalComandos NCDal = new NovoCartaoDalComandos();

            this.msg = NCDal.msg;

            return NCDal.ValidarConta(conta);
        }
    }
}