using System;
using System.Collections.Generic;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using SistemaBlockchain.DAL;
using SistemaBlockchain.dto;
using SistemaBlockchain.Modelo;

namespace SistemaBlockchain
{
    public partial class NovoCartao : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if(!IsPostBack)
            {
                Page lastPage = (Page)Context.Handler;
                lblId.Text = ((Label)lastPage.FindControl("lblId")).Text;
                lblTipo.Text = ((Label)lastPage.FindControl("lblTipo")).Text;

                CarregarDropUsuarios();
            }
        }

        private bool Validacao()
        {

            if (txtNumCartao.Text.Length < 16 || txtNumCartao.Text.Trim() == "")
            {
                lblValidacao.ForeColor = Color.Red;
                lblValidacao.Text = "Número do cartão inválido!";
                return false;
            } 
            else if(txtLimite.Text.Length == 0 || txtLimite.Text.Trim() == "")
            {
                lblValidacao.ForeColor = Color.Red;
                lblValidacao.Text = "Insira um valor de limite!";
                return false;
            }
            else if (txtConta.Text.Length < 5 || txtConta.Text.Trim() == "")
            {
                lblValidacao.ForeColor = Color.Red;
                lblValidacao.Text = "Insira a conta!";
                return false;
            }

            try
            {
                decimal.Parse(txtNumCartao.Text);
            }
            catch (Exception)
            {
                lblValidacao.Text = "Caracteres no campo número do cartão inválidos!";
                return false;
            }

            try
            {
                decimal.Parse(txtConta.Text);
            }
            catch (Exception)
            {
                lblValidacao.Text = "Caracteres no campo conta inválidos!";
                return false;
            }

            return true;
        }

        public void CarregarDropUsuarios()
        {
            NovoCartaoBll NCBll = new NovoCartaoBll();

            ddlUsuario.DataSource = NCBll.CarregarDropUsuarios();
            ddlUsuario.DataTextField = "NOME_RAZAO";
            ddlUsuario.DataValueField = "ID_USUARIO";
            ddlUsuario.DataBind();
        }

        private void limpar()
        {
            txtLimite.Text = "";
            txtNumCartao.Text = "";
            txtConta.Text = "";
        }

        protected void btnConfirmar_Click(object sender, EventArgs e)
        {
            NovoCartaoBll NCBll = new NovoCartaoBll();
            NovoCartaoDto NCDto = new NovoCartaoDto();

            if (Validacao())
            {
                
                NCDto.IdUser = int.Parse(ddlUsuario.SelectedValue);
                NCDto.NumConta = Decimal.Parse(txtConta.Text);
                NCDto.TipoCartao = int.Parse(ddlTipo.SelectedValue);
                NCDto.NumCartao = Decimal.Parse(txtNumCartao.Text);
                
                if(ddlTipo.SelectedValue == "1")
                {
                    NCDto.Limite = Decimal.Parse(txtLimite.Text);
                    NCDto.Saldo = 0;
                    NCDto.Gastos = 0;
                }
                else
                {
                    NCDto.Limite = 0;
                    NCDto.Saldo = Decimal.Parse(txtLimite.Text);
                    NCDto.Gastos = 0;
                }
                

                if (NCBll.ValidarCartao(NCDto.NumCartao.ToString()))
                {
                    if (NCBll.ValidarConta(NCDto.NumConta.ToString()))
                    {
                        NCBll.CadastrarCartao(NCDto);
                        lblValidacao.Text = NCBll.msg;

                        AvisosBll AviBll = new AvisosBll();
                        AviBll.GerarAviso("Novo cartão de " + ddlTipo.SelectedItem.Text + " com n° de conta " + txtConta.Text + " cadastrado", int.Parse(ddlUsuario.SelectedValue));
                        limpar();
                    }
                    else
                    {
                        lblValidacao.Text = "Conta já existe!";
                    }
                }
                else
                {
                    lblValidacao.Text = "Cartão já existe!";
                }
            }
        }

        protected void ddlTipo_SelectedIndexChanged(object sender, EventArgs e)
        {
            if(ddlTipo.SelectedValue == "1")
            {
                lblLimite.Text = "Limite:";
            }
            else
            {
                lblLimite.Text = "Saldo:";

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