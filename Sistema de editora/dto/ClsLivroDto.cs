using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace dto
{
    public class ClsLivroDto : ClsBaseDto
    {
        private Int32 _ano;
        private decimal _isbn;
        private Int32 _codigoEdi;
        private String _nomeEdi;

        
        public Int32 Ano
        {
            get { return _ano; }
            set { _ano = value; }
        }

        public decimal Isbn
        {
            get { return _isbn; }
            set { _isbn = value; }
        }

        public Int32 CodigoEdi
        {
            get { return _codigoEdi; }
            set { _codigoEdi = value; }
        }

        public String NomeEdi
        {
            get { return _nomeEdi; }
            set { _nomeEdi = value; }
        }
    }
}
