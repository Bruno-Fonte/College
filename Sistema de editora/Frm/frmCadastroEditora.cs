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
    public partial class frmCadastroEditora : Form
    {
        public frmCadastroEditora()
        {
            InitializeComponent();
        }

        private void carregarDadosNoGrid()
        {
            carregarDadosNoGrid(0, String.Empty);
        }

        private void carregarDadosNoGrid(int tipo, String filtro)
        {
            ClsEditoraBll ediBll = new ClsEditoraBll();

            if(tipo == 0)
            {
                dgEditoras.DataSource = ediBll.ObterEditoras();
            }
            else if(tipo == 1)
            {
                dgEditoras.DataSource = ediBll.ObterEditorasNome(filtro);
            }
        }

        private void atualizarTela()
        {
            txtCodigo.Text = dgEditoras["colId", dgEditoras.CurrentRow.Index].Value.ToString();
            txtNome.Text = dgEditoras["colNome", dgEditoras.CurrentRow.Index].Value.ToString();
            txtSigla.Text = dgEditoras["colSigla", dgEditoras.CurrentRow.Index].Value.ToString();
            txtObs.Text = dgEditoras["colObs", dgEditoras.CurrentRow.Index].Value.ToString();
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
            else if (txtSigla.Text.Trim() == "")
            {
                MessageBox.Show("Preencha o campo sigla.");
                txtSigla.Focus();
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
            ClsEditoraBll ediBll = new ClsEditoraBll();

            txtCodigo.Text = Convert.ToString(ediBll.ObterProximoCodigo());
            txtNome.Clear();
            txtObs.Clear();
            txtSigla.Clear();
        }

        private void btnCadastrar_Click(object sender, EventArgs e)
        {
            ClsEditorasDto editora = new ClsEditorasDto();
            ClsEditoraBll cadastrar = new ClsEditoraBll();

            if(validacao() == true)
            {
                editora.Nome = txtNome.Text;
                editora.Sigla = txtSigla.Text;
                editora.Obs = txtObs.Text;

                cadastrar.Cadastrar(editora);

                MessageBox.Show("Cadastrado com sucesso!");

                limparTela();
                carregarDadosNoGrid();
            }
        }

        private void btnEditar_Click(object sender, EventArgs e)
        {
            ClsEditorasDto editora = new ClsEditorasDto();
            ClsEditoraBll atualizar = new ClsEditoraBll();

            if (validacao() == true)
            {
                editora.Codigo = int.Parse(txtCodigo.Text);
                editora.Nome = txtNome.Text;
                editora.Sigla = txtSigla.Text;
                editora.Obs = txtObs.Text;

                atualizar.Atualizar(editora);

                MessageBox.Show("Atualizado com sucesso!");

                limparTela();
                carregarDadosNoGrid();
            }
        }

        private void btnExcluir_Click(object sender, EventArgs e)
        {
            int codigo;
            ClsEditoraBll excluir = new ClsEditoraBll();

            if (MessageBox.Show("Deseja mesmo excluir o cadastro?", "Confirmar exclusão", MessageBoxButtons.YesNo) == DialogResult.Yes)
            {
                codigo = int.Parse(txtCodigo.Text);

                excluir.Excluir(codigo);

                MessageBox.Show("Excluído com sucesso!");

                limparTela();
                carregarDadosNoGrid();
            }
        }

        private void setForm()
        {
            ClsEditoraBll ediBll = new ClsEditoraBll();

            txtCodigo.Text = Convert.ToString(ediBll.ObterProximoCodigo());
            txtNome.Focus();
        }

        private void btnCarregarGrid_Click(object sender, EventArgs e)
        {
            if(cbFiltro.SelectedIndex == -1)
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
        }

        private void btnLimpar_Click(object sender, EventArgs e)
        {
            limparTela();
        }

        private void dgEditoras_SelectionChanged(object sender, EventArgs e)
        {
            atualizarTela();
        }

        private void dgEditoras_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            atualizarTela();
        }

        private void frmCadastroEditora_Load(object sender, EventArgs e)
        {
            setForm();
            carregarDadosNoGrid();
        }
    }
}
