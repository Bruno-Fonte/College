using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data;
using dal;
using dto;

namespace bll
{
    public class ClsAutorBll
    {
        public void Cadastrar(ClsAutoresDto parAutor)
        {
            ClsAutoresDal autDal = new ClsAutoresDal();

            autDal.Cadastrar(parAutor);
        }

        public void Atualizar(ClsAutoresDto parAutor)
        {
            ClsAutoresDal autDal = new ClsAutoresDal();

            autDal.Atualizar(parAutor);
        }

        public void Excluir(int codigo)
        {
            ClsAutoresDal autDal = new ClsAutoresDal();

            autDal.Excluir(codigo);
        }

        public List<ClsAutoresDto> ObterAutores()
        {
            ClsAutoresDal autDal = new ClsAutoresDal();

            return autDal.ObterAutores();
        }

        public List<ClsAutoresDto> ObterAutoresNome(String filtro)
        {
            ClsAutoresDal autDal = new ClsAutoresDal();

            return autDal.ObterAutoresNome(filtro);
        }

        public List<ClsAutoresDto> ObterAutoresPseudonimo(String filtro)
        {
            ClsAutoresDal autDal = new ClsAutoresDal();

            return autDal.ObterAutoresPseudonimo(filtro);
        }

        public Int32 obterProximoCodigo()
        {
            ClsAutoresDal autDal = new ClsAutoresDal();

            return autDal.ObterProximoCodigo();
        }
    }
}
