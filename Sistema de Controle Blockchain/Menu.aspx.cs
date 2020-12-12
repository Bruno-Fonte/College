using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using SistemaBlockchain.BLL;

namespace SistemaBlockchain
{
    public partial class Menu : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                MenuBll MenuBll = new MenuBll();
                Page lastPage = (Page)Context.Handler;
                lblId.Text = ((Label)lastPage.FindControl("lblId")).Text;

                lblTipo.Text = ((Label)lastPage.FindControl("lblTipo")).Text;

                lblNome.Text = "Olá, " + MenuBll.ObterNome(int.Parse(lblId.Text));

                if(lblTipo.Text == "1")
                {
                    btnMeusCartoes.Text = "Novo Cartão";
                }

                if(lblTipo.Text != "1")
                {
                    btnEditarCadastro.Visible = false;
                }
            }
        }

        protected void btnRelatorios_Click(object sender, EventArgs e)
        {
            Server.Transfer("Relatorios.aspx");
        }

        protected void btnAvisos_Click(object sender, EventArgs e)
        {
            Server.Transfer("Avisos.aspx");
        }

        protected void btnMeusDados_Click(object sender, EventArgs e)
        {
            Server.Transfer("MeusDados.aspx");
        }

        protected void btnMovimentacoes_Click(object sender, EventArgs e)
        {
            Server.Transfer("Movimentacoes.aspx");
        }

        protected void btnEditarCadastro_Click(object sender, EventArgs e)
        {
            Server.Transfer("EditarCadastro.aspx");
        }

        protected void btnMeusCartoes_Click(object sender, EventArgs e)
        {
            Server.Transfer("MeusCartoes.aspx");
        }
    }
}