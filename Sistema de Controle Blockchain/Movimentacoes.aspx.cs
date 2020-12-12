using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using SistemaBlockchain.dto;
using SistemaBlockchain.Modelo;

namespace SistemaBlockchain
{
    public partial class Movimentacoes : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                Page lastPage = (Page)Context.Handler;
                lblId.Text = ((Label)lastPage.FindControl("lblId")).Text;
                lblTipo.Text = ((Label)lastPage.FindControl("lblTipo")).Text;

                txtDescricao.Visible = false;

                CarregarDropContaOrigem(int.Parse(lblId.Text));
            }
        }

        public int TipoConta(Decimal conta)
        {
            MovimentacoesBll MovBll = new MovimentacoesBll();

            return MovBll.TipoConta(conta);
        }

        public int TipoUsuario(Decimal conta)
        {
            MovimentacoesBll MovBll = new MovimentacoesBll();

            return MovBll.TipoUsuario(conta);
        }

        public String NomeUsuario(Decimal conta)
        {
            MovimentacoesBll MovBll = new MovimentacoesBll();

            return MovBll.NomeUsuario(conta);
        }

        public void Limpar()
        {
            txtValor.Text = "";
            txtDescricao.Text = "";
            txtContaDestino.Text = "";
        }

        private bool Validacao()
        {
            if(txtValor.Text.Trim() == "")
            {
                lblValidacao.Text = "Insira um valor!";
                return false;
            }
            else if(txtContaDestino.Text.Length < 5)
            {
                lblValidacao.Text = "Conta de destino inválida!";
                return false;
            }
            else if (ddlContaOrigem.SelectedItem.Text.Equals(txtContaDestino.Text))
            {
                lblValidacao.Text = "Não é permitido fazer movimentações para a mesma conta!";
                return false;
            }
            else if (ddlTipos.SelectedValue == "2" && TipoConta(Decimal.Parse(ddlContaOrigem.SelectedItem.Text)) == 1)
            {
                lblValidacao.Text = "Não é permitido fazer transferência de cartões de crédito!";
                return false;
            }
            else if (TipoConta(Decimal.Parse(txtContaDestino.Text)) == 1)
            {
                lblValidacao.Text = "Não é permitido fazer transferências ou pagamentos para cartões de crédito!";
                return false;
            }
            else if(ddlTipos.SelectedValue == "1" && TipoUsuario(Decimal.Parse(txtContaDestino.Text)) != 3)
            {
                lblValidacao.Text = "Apenas contas de pessoa jurídica pode receber pagamentos!";
                return false;
            }
            else if (ddlTipos.SelectedValue == "1")
            {
                txtDescricao.Text = "Pagamento para empresa " + NomeUsuario(Decimal.Parse(txtContaDestino.Text));
            }
            else if(ddlTipos.SelectedValue == "2")
            {
                txtDescricao.Text = "Transferência da conta " + ddlContaOrigem.SelectedItem.Text + " para a conta " + txtContaDestino.Text;
            }
            
            return true;
        }

        public bool ValidarGasto(Decimal novoGasto, Decimal limite)
        {
            if(novoGasto > limite)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        public void CarregarDropContaOrigem(int id)
        {
            MovimentacoesBll MovBll = new MovimentacoesBll();

            ddlContaOrigem.DataSource = MovBll.ObterContas(id);
            ddlContaOrigem.DataTextField = "NUM_CONTA";
            ddlContaOrigem.DataBind();
        }

        public bool ValidarSaldo(Decimal valor, Decimal contaOrigem, Decimal contaDestino)
        {
            MovimentacoesBll MovBll = new MovimentacoesBll();

            Decimal limite = MovBll.ConsultarLimite(contaOrigem);

            Decimal valorMov = valor;
            Decimal valorSaldoOrigem = MovBll.ConsultarSaldo(contaOrigem);
            Decimal valorSaldoDestino = MovBll.ConsultarSaldo(contaDestino);
            Decimal valorGastoOrigem = MovBll.ConsultarGasto(contaOrigem);

            Decimal novoSaldoOrigem = valorSaldoOrigem - valorMov;
            Decimal novoSaldoDestino = valorSaldoDestino + valorMov;
            Decimal novoGastoOrigem = valorGastoOrigem + valorMov;

            if (TipoConta(contaOrigem) == 2 && novoSaldoOrigem < 0)
            {
                return false;
            }
            else
            {
                if(TipoConta(contaOrigem) == 1)
                {
                    MovBll.AtualizarGastoOrigem(novoGastoOrigem, contaOrigem);
                    MovBll.AtualizarSaldoDestino(novoSaldoDestino, contaDestino);

                    if(ValidarGasto(novoGastoOrigem, limite))
                    {
                        AvisosBll AviBll = new AvisosBll();

                        AviBll.GerarAviso("Limite excedido da conta " + ddlContaOrigem.SelectedItem.Text, int.Parse(lblId.Text));
                    }

                    return true;
                }
                else
                {
                    MovBll.AtualizarSaldoOrigem(novoSaldoOrigem, contaOrigem);
                    MovBll.AtualizarSaldoDestino(novoSaldoDestino, contaDestino);
                    return true;
                }
            }
        }

        protected void btnEfetuar_Click(object sender, EventArgs e)
        {
            MovimentacoesBll MovBll = new MovimentacoesBll();
            MovimentacoesDto MovDto = new MovimentacoesDto();
            
            if(Validacao())
            {
                MovDto.Descricao = txtDescricao.Text;
                MovDto.Valor = Decimal.Parse(txtValor.Text);
                MovDto.TipoMovimentacao = int.Parse(ddlTipos.SelectedValue);
                MovDto.NumContaOrigem = Decimal.Parse(ddlContaOrigem.SelectedItem.Text);
                MovDto.NumContaDestino = Decimal.Parse(txtContaDestino.Text);

                if (MovBll.ValidarContaDestino(MovDto.NumContaDestino))
                {
                    if (ValidarSaldo(MovDto.Valor, MovDto.NumContaOrigem, MovDto.NumContaDestino))
                    {
                        lblValidacao.Text = MovBll.EfetuarMovimentacao(MovDto);
                        Limpar();
                    }
                    else
                    {
                        lblValidacao.Text = "Saldo insuficiente!";
                    }
                }
                else
                {
                    lblValidacao.Text = "Conta destino não existe!";
                }
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