using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using SistemaBlockchain.DAL;
using SistemaBlockchain.Modelo;

namespace SistemaBlockchain
{
    public partial class MeusCartoes : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {    
                Page lastPage = (Page)Context.Handler;
                lblId.Text = ((Label)lastPage.FindControl("lblId")).Text;
                lblTipo.Text = ((Label)lastPage.FindControl("lblTipo")).Text;

                if(lblTipo.Text == "1")
                {
                    Server.Transfer("NovoCartao.aspx");
                }

                CarregarGridCartoesCredito();
                CarregarGridCartoesDebito();
            }
        }

        public void CarregarGridCartoesCredito()
        {
            MeusCartoesBll MCBll = new MeusCartoesBll();
            int id = int.Parse(lblId.Text);

            dgCartoesCredito.DataSource = MCBll.CarregarGridCartoesCredito(id);
            dgCartoesCredito.DataBind();

            if(dgCartoesCredito.DataSource == null)
            {
                lblCredito.Visible = false;
            }
        }

        public void CarregarGridCartoesDebito()
        {
            MeusCartoesBll MCBll = new MeusCartoesBll();
            int id = int.Parse(lblId.Text);

            dgCartoesDebito.DataSource = MCBll.CarregarGridCartoesDebito(id);
            dgCartoesDebito.DataBind();

            if (dgCartoesDebito.DataSource == null)
            {
                lblDebito.Visible = false;
            }
        }

        protected void btnSair_Click(object sender, EventArgs e)
        {
            Server.Transfer("default.aspx");
        }

        protected void btnMenu_Click(object sender, EventArgs e)
        {
            Server.Transfer("menu.aspx");
        }
    }
}