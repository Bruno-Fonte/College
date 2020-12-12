using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using SistemaBlockchain.DAL;
using SistemaBlockchain.Modelo;
using SistemaBlockchain.dto;

namespace SistemaBlockchain
{
    public partial class Cadastrar : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                CarregarDadosPessoa();
            }
        }

        private void CarregarDadosPessoa()
        {
            if(ddlTipo.SelectedValue == "1")
            {
                txtCPF.MaxLength = 11;
                lblNome.Text = "Nome";
                lblCpf.Text = "CPF";
            }
            else
            {
                txtCPF.MaxLength = 14;
                lblNome.Text = "Razão Social";
                lblCpf.Text = "CNPJ";
            }
        }

        private bool Validacao()
        {
            if(txtNome.Text.Length == 0 || txtNome.Text.Trim() == "")
            {
                lblValidacao.ForeColor = Color.Red;
                lblValidacao.Text = "Nome deve ser preenchido";
                return false;
            }
            else if(ddlTipo.SelectedValue == "1")
            {
                if (txtCPF.Text.Length != 11)
                {
                    lblValidacao.ForeColor = Color.Red;
                    lblValidacao.Text = "CPF inválido";
                    return false;
                }
            }
            else if(ddlTipo.SelectedValue == "2")
            {
                if (txtCPF.Text.Length != 14)
                {
                    lblValidacao.ForeColor = Color.Red;
                    lblValidacao.Text = "CNPJ inválido";
                    return false;
                }
            }
            else if (txtUsuario.Text.Length == 0 || txtUsuario.Text.Trim() == "" || !txtUsuario.Text.Contains("@") || !txtUsuario.Text.Contains(".com"))
            {
                lblValidacao.ForeColor = Color.Red;
                lblValidacao.Text = "E-mail inválido";
                txtUsuario.Focus();
                return false;
            }
            else if (txtSenha.Text.Length < 6 || txtSenha.Text.Trim() == "")
            {
                lblValidacao.ForeColor = Color.Red;
                lblValidacao.Text = "Senha deve conter ao menos 6 caracteres";
                txtSenha.Focus();
                return false;
            }
            else if (txtConfSenha.Text.Length < 6 || txtConfSenha.Text.Trim() == "")
            {
                lblValidacao.ForeColor = Color.Red;
                lblValidacao.Text = "Senha deve conter ao menos 6 caracteres";
                txtConfSenha.Focus();
                return false;
            }
            else if (txtConfSenha.Text != txtSenha.Text)
            {
                lblValidacao.ForeColor = Color.Red;
                lblValidacao.Text = "Senhas incompatíveis!";
                txtSenha.Focus();
                return false;
            }
            return true;
        }

        private void Limpar()
        {
            txtSenha.Text = "";
            txtNome.Text = "";
            txtCPF.Text = "";
            txtUsuario.Text = "";
            txtConfSenha.Text = "";
        }

        protected void btnCadastrar_Click(object sender, EventArgs e)
        {
            LoginBll loginBll = new LoginBll();
            UsuarioDto userDto = new UsuarioDto();

            if (Validacao())
            {
                userDto.Nome = txtNome.Text;
                userDto.CpfCnpj = txtCPF.Text;
                userDto.Login = txtUsuario.Text;
                userDto.Senha = txtSenha.Text;

                if (loginBll.ValidarEmail(userDto.Login))
                {
                    lblValidacao.Text = loginBll.cadastrarUsuario(userDto);
                    lblValidacao.Visible = true;

                    Limpar();
                }
                else
                {
                    lblValidacao.Text = "Email já existe, digite outro email!";
                    lblValidacao.Visible = true;
                }
            }
        }
    
        protected void ddlTipo_SelectedIndexChanged(object sender, EventArgs e)
        {
            CarregarDadosPessoa();
        }
    }
}