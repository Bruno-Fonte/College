using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using SistemaBlockchain.Modelo;

namespace SistemaBlockchain
{
    public partial class Default : System.Web.UI.Page
    {
        LoginBll loginBll = new LoginBll();

        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void btnLogin_Click(object sender, EventArgs e)
        {
            if (ValidarCamposLogin())
            {
                if (ValidarLogin())
                {
                    Server.Transfer("Menu.aspx");
                }
                else
                {
                    lblTeste.ForeColor = Color.Red;
                    lblTeste.Text = "Login negado!";
                }
            }
        }

        private bool ValidarCamposLogin()
        {
            if (txtLogin.Text.Length == 0 || txtLogin.Text.Trim() == "" || !txtLogin.Text.Contains("@") || !txtLogin.Text.Contains(".com"))
            {
                lblTeste.ForeColor = Color.Red;
                lblTeste.Text = "E-mail inválido";
                txtLogin.Focus();
                return false;
            }
            return true;
        }

        private bool ValidarLogin()
        {
            if (loginBll.acessar(txtLogin.Text, txtSenha.Text))
            {
                lblId.Text = Convert.ToString(loginBll.obterCodigoUsuario(txtLogin.Text, txtSenha.Text));
                lblTipo.Text = Convert.ToString(loginBll.obterTipoUsuario(txtLogin.Text, txtSenha.Text));

                return true;
            }
            else
            {
                return false;
            }
        }
    }
}