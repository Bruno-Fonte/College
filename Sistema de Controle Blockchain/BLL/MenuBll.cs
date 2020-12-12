using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using SistemaBlockchain.DAL;

namespace SistemaBlockchain.BLL
{
    public class MenuBll
    {
        public String ObterNome(int id)
        {
            MenuDalComandos MenuDal = new MenuDalComandos();

            return MenuDal.ObterNome(id);
        }
    }
}