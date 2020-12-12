using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using SistemaBlockchain.DAL;

namespace SistemaBlockchain.Modelo
{
    public class MudarSenhaBll
    {
        public String msg;

        public int ValidarSenha(int id, String senha)
        {
            MudarSenhaDalComandos mudarDal = new MudarSenhaDalComandos();

            return mudarDal.ValidarSenha(id, senha);
        }

        public String MudarSenha(String id, String novaSenha)
        {
            MudarSenhaDalComandos mudarDal = new MudarSenhaDalComandos();

            mudarDal.MudarSenha(id, novaSenha);

            this.msg = mudarDal.msg;

            return this.msg;
        }
    }
}