using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using bll;
using dto;

namespace ProjetoEditora
{
    public partial class frmCadastroAutor : Form
    {
        public frmCadastroAutor()
        {
            InitializeComponent();
        }

        private void carregarDadosNoGrid()
        {
            carregarDadosNoGrid(0, String.Empty);
        }

        private void carregarDadosNoGrid(int tipo, String filtro)
        {
            ClsAutorBll autBll = new ClsAutorBll();

            if(tipo == 0)
            {
                dgAutores.DataSource = autBll.ObterAutores();
            }
            else if (tipo == 1)
            {
                dgAutores.DataSource = autBll.ObterAutoresNome(filtro);
            }
            else if (tipo == 2)
            {
                dgAutores.DataSource = autBll.ObterAutoresPseudonimo(filtro);
            }
        }

        private void atualizarTela()
        {
            txtCodigo.Text = dgAutores["colId", dgAutores.CurrentRow.Index].Value.ToString();
            txtNome.Text = dgAutores["colNome", dgAutores.CurrentRow.Index].Value.ToString();
            txtPseudonimo.Text = dgAutores["colPseudonimo", dgAutores.CurrentRow.Index].Value.ToString();
            txtObs.Text = dgAutores["colObs", dgAutores.CurrentRow.Index].Value.ToString();
        }

        private Boolean validacao()
        {
            Boolean resultado = false;

            if (txtNome.Text.Trim() == "")
            {
                MessageBox.Show("Preencha o campo nome.");
                txtNome.Focus();
                resultado = false;
            }
            else if (txtPseudonimo.Text.Trim() == "")
            {
                MessageBox.Show("Preencha o campo pseudônimo.");
                txtPseudonimo.Focus();
                resultado = false;
            }
            else if (txtObs.Text.Trim() == "")
            {
                MessageBox.Show("Preencha o campo observações.");
                txtObs.Focus();
                resultado = false;
            }
            else
            {
                resultado = true;
            }

            return resultado;
        }

        private void limparTela()
        {
            ClsAutorBll autBll = new ClsAutorBll();

            txtCodigo.Text = Convert.ToString(autBll.obterProximoCodigo());
            txtNome.Clear();
            txtPseudonimo.Clear();
            txtObs.Clear();
        }

        private void btnCadastrar_Click(object sender, EventArgs e)
        {
            ClsAutoresDto autor = new ClsAutoresDto();
            ClsAutorBll cadastrar = new ClsAutorBll();

            if (validacao() == true)
            {
                autor.Nome = txtNome.Text;
                autor.Pseudonimo = txtPseudonimo.Text;
                autor.Obs = txtObs.Text;

                cadastrar.Cadastrar(autor);

                MessageBox.Show("Cadastrado com sucesso!");

                limparTela();
                carregarDadosNoGrid();
            } 
        }

        private void btnEditar_Click(object sender, EventArgs e)
        {
            ClsAutoresDto autor = new ClsAutoresDto();
            ClsAutorBll atualizar = new ClsAutorBll();

            if (validacao() == true)
            {
                autor.Codigo = int.Parse(txtCodigo.Text);
                autor.Nome = txtNome.Text;
                autor.Pseudonimo = txtPseudonimo.Text;
                autor.Obs = txtObs.Text;

                atualizar.Atualizar(autor);

                MessageBox.Show("Atualizado com sucesso!");

                limparTela();
                carregarDadosNoGrid();
            } 
        }

        private void btnExcluir_Click(object sender, EventArgs e)
        {
            int codigo;
            ClsAutorBll excluir = new ClsAutorBll();
            
            if (MessageBox.Show("Deseja mesmo excluir o cadastro?","Confirmar exclusão", MessageBoxButtons.YesNo) == DialogResult.Yes)
            {
                codigo = int.Parse(txtCodigo.Text);

                excluir.Excluir(codigo);

                MessageBox.Show("Excluído com sucesso!");


                limparTela();
                carregarDadosNoGrid();
            }

        }

        private void btnLimpar_Click(object sender, EventArgs e)
        {
            limparTela();
        }

        private void btnCarregarGrid_Click_1(object sender, EventArgs e)
        {
            if (cbFiltro.SelectedIndex == -1)
            {
                MessageBox.Show("Selecione uma opção de filtro!");
                cbFiltro.Focus();
            }
            else if (cbFiltro.SelectedIndex == 0)
            {
                carregarDadosNoGrid();
                atualizarTela();
                txtFiltro.Clear();
            }
            else if (cbFiltro.SelectedIndex == 1)
            {
                carregarDadosNoGrid(1, txtFiltro.Text);
                atualizarTela();
            }
            else if (cbFiltro.SelectedIndex == 2)
            {
                carregarDadosNoGrid(2, txtFiltro.Text);
                atualizarTela();
            }
        }

        private void dgAutores_SelectionChanged(object sender, EventArgs e)
        {
            atualizarTela();
        }

        private void dgAutores_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            atualizarTela();
        }

        private void frmCadastroAutor_Load(object sender, EventArgs e)
        {
            carregarDadosNoGrid();
        }
    }
}
