using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace dto
{
    public class ClsAutoresDto : ClsBaseDto
    {
        private String _sigla;
        private String _pseudonimo;

        public String Pseudonimo
        {
            get { return _pseudonimo; }
            set { _pseudonimo = value; }
        }

        public String Sigla
        {
            get { return _sigla; }
            set { _sigla = value; }
        }
    }
}
