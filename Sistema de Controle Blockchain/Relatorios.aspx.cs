using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using SistemaBlockchain.Modelo;
using System.Data;
using System.Data.SqlClient;
using SistemaBlockchain.dto;

namespace SistemaBlockchain
{
    public partial class Relatorios : System.Web.UI.Page
    {
        RelatoriosBll RelBll = new RelatoriosBll();

        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                Page lastPage = (Page)Context.Handler;
                lblId.Text = ((Label)lastPage.FindControl("lblId")).Text;
                lblTipo.Text = ((Label)lastPage.FindControl("lblTipo")).Text;

                int id = int.Parse(lblId.Text);

                if(lblTipo.Text == "1")
                {
                    ObterUsuarios();

                    dgRelatorios.DataSource = RelBll.CarregarGridRelatoriosAdmin(int.Parse(ddlContas.SelectedValue));
                    dgRelatorios.DataBind();

                }
                else
                {
                    ObterContas(id);

                    dgRelatorios.DataSource = RelBll.CarregarGridRelatorios(decimal.Parse(ddlContas.SelectedItem.Text));
                    dgRelatorios.DataBind();
                }
            }
        }

        public void ObterContas(int id)
        {
            RelatoriosBll RelBll = new RelatoriosBll();
            
            ddlContas.DataSource = RelBll.ObterContas(id);
            ddlContas.DataTextField = "NUM_CONTA";
            ddlContas.DataBind();
        }

        public void ObterUsuarios()
        {
            RelatoriosBll RelBll = new RelatoriosBll();

            ddlContas.DataSource = RelBll.CarregarDropUsuarios();
            ddlContas.DataTextField = "NOME_RAZAO";
            ddlContas.DataValueField = "ID_USUARIO";
            ddlContas.DataBind();
        }

        protected void ddlContas_SelectedIndexChanged(object sender, EventArgs e)
        {
            if(lblTipo.Text == "1")
            {
                dgRelatorios.DataSource = RelBll.CarregarGridRelatoriosAdmin(int.Parse(ddlContas.SelectedValue));
                dgRelatorios.DataBind();
            }
            else if(lblTipo.Text == "2")
            {
                dgRelatorios.DataSource = RelBll.CarregarGridRelatorios(decimal.Parse(ddlContas.SelectedItem.Text));
                dgRelatorios.DataBind();
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