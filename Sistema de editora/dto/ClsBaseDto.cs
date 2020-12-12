using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace dto
{
    public class ClsBaseDto
    {
        private Int32 _codigo;
        private String _nome;
        private String _obs;

        public Int32 Codigo
        {
            get { return _codigo; }
            set { _codigo = value; }
        }

        public String Nome
        {
            get { return _nome; }
            set { _nome = value; }
        }

        public String Obs
        {
            get { return _obs; }
            set { _obs = value; }
        }
    }
}
