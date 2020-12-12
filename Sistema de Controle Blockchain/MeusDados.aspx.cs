using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data;
using System.Data.Sql;
using System.Data.SqlClient;
using SistemaBlockchain.DAL;
using SistemaBlockchain.Modelo;

namespace SistemaBlockchain
{
    public partial class MeusDados : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                Page lastPage = (Page)Context.Handler;
                lblId.Text = ((Label)lastPage.FindControl("lblId")).Text;
                lblTipo.Text = ((Label)lastPage.FindControl("lblTipo")).Text;

                CarregarDadosNoGrid(int.Parse(lblId.Text));
            }
        }

        private void CarregarDadosNoGrid(int id)
        {
            MeusDadosBll MDBll = new MeusDadosBll();

            dgDados.DataSource = MDBll.CarregarGridMeusDados(id);
            dgDados.DataBind();
        }

        protected void btnMudarSenha_Click(object sender, EventArgs e)
        {
            Server.Transfer("MudarSenha.aspx");
        }

        protected void dgDados_RowEditing(object sender, GridViewEditEventArgs e)
        {
            dgDados.EditIndex = e.NewEditIndex;
            CarregarDadosNoGrid(int.Parse(lblId.Text));
        }

        protected void dgDados_RowCancelingEdit(object sender, GridViewCancelEditEventArgs e)
        {
            dgDados.EditIndex = -1;
            CarregarDadosNoGrid(int.Parse(lblId.Text));
        }

        protected void dgDados_RowUpdating(object sender, GridViewUpdateEventArgs e)
        {
            MeusDadosBll MDBll = new MeusDadosBll();

            try
            {
                MDBll.EditarUsuario
                               (int.Parse((dgDados.Rows[e.RowIndex].FindControl("lblIdGrid") as Label).Text.Trim()),
                               (dgDados.Rows[e.RowIndex].FindControl("txtNomeRazao") as TextBox).Text.Trim(),
                               (dgDados.Rows[e.RowIndex].FindControl("txtCpfCnpj") as TextBox).Text.Trim(),
                               (dgDados.Rows[e.RowIndex].FindControl("txtUsuario") as TextBox).Text.Trim());

                dgDados.EditIndex = -1;
                CarregarDadosNoGrid(int.Parse(lblId.Text));

                lblValidacao.Text = MDBll.msg;
            }
            catch (Exception)
            {
                lblValidacao.Text = MDBll.msg;
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