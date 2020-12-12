using dto;
using dal;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data;

namespace bll
{
    public class ClsEditoraBll
    {
        public void Cadastrar(ClsEditorasDto parEditora)
        {
            ClsEditorasDal ediDal = new ClsEditorasDal();

            ediDal.Cadastrar(parEditora);
        }

        public void Atualizar(ClsEditorasDto parEditora)
        {
            ClsEditorasDal ediDal = new ClsEditorasDal();

            ediDal.Atualizar(parEditora);
        }

        public void Excluir(int codigo)
        {
            ClsEditorasDal ediDal = new ClsEditorasDal();

            ediDal.Excluir(codigo);
        }

        public Int32 ObterProximoCodigo()
        {
            ClsEditorasDal ediDal = new ClsEditorasDal();

            return ediDal.ObterProximoCodigo();
        }

        public List<ClsEditorasDto> ObterEditoras()
        {
            ClsEditorasDal ediDal = new ClsEditorasDal();

            return ediDal.ObterEditoras();
        }

        public List<ClsEditorasDto> ObterEditorasNome(String filtro)
        {
            ClsEditorasDal ediDal = new ClsEditorasDal();

            return ediDal.ObterEditorasNome(filtro);
        }

    }
}
