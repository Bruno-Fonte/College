using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace dto
{
    public class ClsEditorasDto : ClsBaseDto
    {
        private String _sigla;

        public String Sigla
        {
            get { return _sigla; }
            set { _sigla = value; }
        }
    }
}
