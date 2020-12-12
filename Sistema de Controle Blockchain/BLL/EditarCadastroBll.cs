using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using SistemaBlockchain.DAL;
using System.Data;

namespace SistemaBlockchain.Modelo
{
    public class EditarCadastroBll
    {
        public bool tem;
        public string msg = " ";
        public DataTable _tabela = new DataTable();
     
        public DataTable CarregarGridEditarCadastros()
        {
            EditarCadastroDalComandos EdiCadDal = new EditarCadastroDalComandos();

            _tabela = EdiCadDal.CarregarGridEditarCadastros();

            if (EdiCadDal.tem)
            {
                this.tem = true;
            }

            return _tabela;
        }

        public String AdicionarUsuario(String nome, String cpf, String usuario, String senha, String tipo)
        {
            EditarCadastroDalComandos EdiCadDal = new EditarCadastroDalComandos();

            try
            {
                this.msg = EdiCadDal.AdicionarUsuario(nome, cpf, usuario, senha, tipo);

                if (EdiCadDal.tem)
                {
                    this.tem = true;
                }

                return msg;
            }
            catch (Exception)
            {
                throw;
            }
        }

        public void EditarUsuario(int id, String nome, String cpf, String usuario, String senha, String tipo)
        {
            EditarCadastroDalComandos EdiCadDal = new EditarCadastroDalComandos();

            try
            {
                EdiCadDal.EditarUsuario(id, nome, cpf, usuario, senha, tipo);

                if (EdiCadDal.tem)
                {
                    this.tem = true;
                    this.msg = EdiCadDal.msg;
                }
                else
                {
                    this.tem = false;
                    this.msg = EdiCadDal.msg;
                }
            }
            catch (Exception)
            {
                throw;
            }
        }

        public void ExcluirUsuario(int id)
        {
            EditarCadastroDalComandos EdiCadDal = new EditarCadastroDalComandos();

            try
            {
                EdiCadDal.ExcluirUsuario(id);

                if (EdiCadDal.tem)
                {
                    this.tem = true;
                    this.msg = EdiCadDal.msg;
                }
                else
                {
                    this.tem = false;
                    this.msg = EdiCadDal.msg;
                }
            }
            catch (Exception)
            {
                throw;
            }
        }
    }
}