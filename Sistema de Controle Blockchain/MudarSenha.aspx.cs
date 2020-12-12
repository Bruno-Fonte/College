using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using SistemaBlockchain.Modelo;

namespace SistemaBlockchain
{
    public partial class MudarSenha : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            Page lastPage = (Page)Context.Handler;
            lblId.Text = ((Label)lastPage.FindControl("lblId")).Text;
            lblTipo.Text = ((Label)lastPage.FindControl("lblTipo")).Text;
        }

        protected bool validarCampos(String senha, String confSenha)
        {
            if (senha.Equals(confSenha))
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        protected void limparTela()
        {
            txtConfNovaSenha.Text = "";
            txtNovaSenha.Text = "";
            txtSenhaAtual.Text = "";
        }

        protected bool ValidarSenha()
        {
            MudarSenhaBll mudarBll = new MudarSenhaBll();
            
            if (mudarBll.ValidarSenha(int.Parse(lblId.Text), txtSenhaAtual.Text) == 1)
            {
                if(validarCampos(txtNovaSenha.Text, txtConfNovaSenha.Text))
                {
                    if (txtNovaSenha.Text.Trim().Length < 6 || txtConfNovaSenha.Text.Trim().Length < 6)
                    {
                        lblValidacao.Visible = true;
                        lblValidacao.Text = "A nova senha deve possuir no mínimo 6 caracteres!";
                        return false;
                    }
                    return true;
                }
                else
                {
                    lblValidacao.Visible = true;
                    lblValidacao.Text = "Senhas incompatíveis!";
                    return false;
                }
            }
            else
            {
                lblValidacao.Visible = true;
                lblValidacao.Text = "Senha atual incorreta!";
                return false;
            }
        }

        protected void btnAlterarSenha_Click(object sender, EventArgs e)
        {
            try
            {
                if (ValidarSenha())
                {
                    MudarSenhaBll MudarBll = new MudarSenhaBll();
                    AvisosBll AvisosBll = new AvisosBll();

                    MudarBll.MudarSenha(lblId.Text, txtNovaSenha.Text);

                    lblValidacao.Visible = true;
                    lblValidacao.Text = MudarBll.msg;

                    AvisosBll.GerarAviso("Senha alterada", int.Parse(lblId.Text));

                    limparTela();
                }
            }
            catch (Exception)
            {
                throw;
            }
        }

        protected void btnSair_Click(object sender, EventArgs e)
        {
            Server.Transfer("default.aspx");
        }

        protected void btnVoltar_Click(object sender, EventArgs e)
        {
            Server.Transfer("MeusDados.aspx");
        }
    }
}