using dal;
using dto;
using System.Data;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace bll
{
    public class ClsLivroBll
    {
        public void Cadastrar(ClsLivroDto parLivros)
        {
            ClsLivrosDal livDal = new ClsLivrosDal();

            livDal.Cadastrar(parLivros);
        }

        public void Atualizar(ClsLivroDto parLivros)
        {
            ClsLivrosDal livDal = new ClsLivrosDal();

            livDal.Atualizar(parLivros);
        }

        public void Excluir(int codigo)
        {
            ClsLivrosDal livDal = new ClsLivrosDal();

            livDal.Excluir(codigo);
        }

        public List<ClsLivroDto> ObterLivros()
        {
            ClsLivrosDal livDal = new ClsLivrosDal();

            return livDal.ObterLivros();
        }

        public List<ClsLivroDto> ObterLivrosNome(String filtro)
        {
            ClsLivrosDal livDal = new ClsLivrosDal();

            return livDal.ObterLivrosNome(filtro);
        }

        public List<ClsLivroDto> ObterLivrosEditora(String filtro)
        {
            ClsLivrosDal livDal = new ClsLivrosDal();

            return livDal.ObterLivrosEditora(filtro);
        }

        public DataTable ObterDadosCombo(String sql)
        {
            ClsLivrosDal livDal = new ClsLivrosDal();

            return livDal.ObterDadosCombo(sql);
        }

        public Int32 ObterProximoCodigoLivro()
        {
            ClsLivrosDal livDal = new ClsLivrosDal();

            return livDal.ObterProximoCodigoLivro();
        }
    }
}
