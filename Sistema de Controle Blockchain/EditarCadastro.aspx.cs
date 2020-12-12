using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using SistemaBlockchain.Modelo;

namespace SistemaBlockchain
{
    public partial class EditarCadastro : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                Page lastPage = (Page)Context.Handler;
                lblId.Text = ((Label)lastPage.FindControl("lblId")).Text;
                lblTipo.Text = ((Label)lastPage.FindControl("lblTipo")).Text;

                CarregarDadosNoGrid();
            }
        }

        private void CarregarDadosNoGrid()
        {
            EditarCadastroBll EdiCadBll = new EditarCadastroBll();

            dgCadastros.DataSource = EdiCadBll.CarregarGridEditarCadastros();
            dgCadastros.DataBind();
        }

        protected void dgCadastros_RowCommand(object sender, GridViewCommandEventArgs e)
        {
            EditarCadastroBll ediCadBll = new EditarCadastroBll();

            try
            {
                if (e.CommandName.Equals("AddNew"))
                {
                    String msg = ediCadBll.AdicionarUsuario
                        ((dgCadastros.FooterRow.FindControl("txtNomeRazaoFooter") as TextBox).Text.Trim(),
                        (dgCadastros.FooterRow.FindControl("txtCpfCnpjFooter") as TextBox).Text.Trim(),
                        (dgCadastros.FooterRow.FindControl("txtUsuarioFooter") as TextBox).Text.Trim(),
                        (dgCadastros.FooterRow.FindControl("txtSenhaFooter") as TextBox).Text.Trim(),
                        (dgCadastros.FooterRow.FindControl("txtTipoFooter") as TextBox).Text.Trim());

                    CarregarDadosNoGrid();
                }

                lblValidacao.Text = ediCadBll.msg;
            }
            catch (Exception)
            {
                lblValidacao.Text = ediCadBll.msg;
            }
        }

        protected void dgCadastros_RowEditing(object sender, GridViewEditEventArgs e)
        {
            dgCadastros.EditIndex = e.NewEditIndex;
            CarregarDadosNoGrid();
        }

        protected void dgCadastros_RowCancelingEdit(object sender, GridViewCancelEditEventArgs e)
        {
            dgCadastros.EditIndex = -1;
            CarregarDadosNoGrid();
        }

        protected void dgCadastros_RowUpdating(object sender, GridViewUpdateEventArgs e)
        {
            EditarCadastroBll ediCadBll = new EditarCadastroBll();

            try
            {
                ediCadBll.EditarUsuario
                                (int.Parse((dgCadastros.Rows[e.RowIndex].FindControl("lblIdGrid") as Label).Text.Trim()),
                                (dgCadastros.Rows[e.RowIndex].FindControl("txtNomeRazao") as TextBox).Text.Trim(),
                                (dgCadastros.Rows[e.RowIndex].FindControl("txtCpfCnpj") as TextBox).Text.Trim(),
                                (dgCadastros.Rows[e.RowIndex].FindControl("txtUsuario") as TextBox).Text.Trim(),
                                (dgCadastros.Rows[e.RowIndex].FindControl("txtSenha") as TextBox).Text.Trim(),
                                (dgCadastros.Rows[e.RowIndex].FindControl("txtTipo") as TextBox).Text.Trim());

                dgCadastros.EditIndex = -1;
                CarregarDadosNoGrid();

                lblValidacao.Text = ediCadBll.msg;
            }
            catch (Exception)
            {
                lblValidacao.Text = ediCadBll.msg;
            }
        }

        protected void dgCadastros_RowDeleting(object sender, GridViewDeleteEventArgs e)
        {
            EditarCadastroBll ediCadBll = new EditarCadastroBll();

            try
            {
                ediCadBll.ExcluirUsuario(int.Parse((dgCadastros.Rows[e.RowIndex].FindControl("lblIdGrid") as Label).Text.Trim()));

                CarregarDadosNoGrid();

                lblValidacao.Text = ediCadBll.msg;
            }
            catch (Exception)
            {
                lblValidacao.Text = ediCadBll.msg;
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