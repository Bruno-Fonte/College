using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using SistemaBlockchain.Modelo;

namespace SistemaBlockchain
{
    public partial class Avisos : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                Page lastPage = (Page)Context.Handler;
                lblId.Text = ((Label)lastPage.FindControl("lblId")).Text;
                lblTipo.Text = ((Label)lastPage.FindControl("lblTipo")).Text;

                CarregarGridAvisos(int.Parse(lblId.Text));
            }
        }

        public void CarregarGridAvisos(int id)
        {
            AvisosBll AvisosBll = new AvisosBll();

            dgAvisosSistema.DataSource = AvisosBll.CarregarGridAvisosSistema(id);
            dgAvisosSistema.DataBind();
        }

        protected void dgAvisosSistema_RowDeleting(object sender, GridViewDeleteEventArgs e)
        {
            AvisosBll AvisosBll = new AvisosBll();

            AvisosBll.ExcluirAviso(int.Parse((dgAvisosSistema.Rows[e.RowIndex].FindControl("lblIdGrid") as Label).Text.Trim()));

            CarregarGridAvisos(int.Parse(lblId.Text));
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