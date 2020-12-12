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
    public partial class frmCadastrarLivro : Form
    {
        public frmCadastrarLivro()
        {
            InitializeComponent();
            carregarDadosNoGrid();
            setForm();
            carregarCombo();
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
            else if (txtAno.Text.Trim() == "")
            {
                MessageBox.Show("Preencha o campo ano de publicação.");
                txtAno.Focus();
                resultado = false;
            }
            else if (txtIsbn.Text.Trim() == "")
            {
                MessageBox.Show("Preencha o campo ISBN.");
                txtIsbn.Focus();
                resultado = false;
            }
            else if (txtObs.Text.Trim() == "")
            {
                MessageBox.Show("Preencha o campo observações.");
                txtObs.Focus();
                resultado = false;
            }
            else if (txtCodigoEdi.Text.Trim() == "")
            {
                MessageBox.Show("Preencha o campo ID da editora.");
                txtCodigoEdi.Focus();
                resultado = false;
            }
            else
            {
                resultado = true;
            }

            return resultado;
        }

        private void carregarDadosNoGrid()
        {
            carregarDadosNoGrid(0, String.Empty);
        }

        private void carregarDadosNoGrid(int tipo, String filtro)
        {
            dgLivros.AutoGenerateColumns = false;
            dgLivros.SelectionMode = DataGridViewSelectionMode.FullRowSelect;

            ClsLivroBll livBll = new ClsLivroBll();

            if(tipo == 0)
            {
                dgLivros.DataSource = livBll.ObterLivros();
            }
            else if(tipo == 1)
            {
                dgLivros.DataSource = livBll.ObterLivrosNome(filtro);
            }
            else if (tipo == 2)
            {
                dgLivros.DataSource = livBll.ObterLivrosEditora(filtro);
            }
        }
        
        private void atualizarTela()
        {
            
            txtCodigo.Text = dgLivros["colId", dgLivros.CurrentRow.Index].Value.ToString();
            txtNome.Text = dgLivros["colNome", dgLivros.CurrentRow.Index].Value.ToString();
            txtAno.Text = dgLivros["colAno", dgLivros.CurrentRow.Index].Value.ToString();
            txtIsbn.Text = dgLivros["colIsbn", dgLivros.CurrentRow.Index].Value.ToString();
            txtObs.Text = dgLivros["colObs", dgLivros.CurrentRow.Index].Value.ToString();
        }

        private void btnCadastrar_Click(object sender, EventArgs e)
        {
            ClsLivroDto livro = new ClsLivroDto();
            ClsLivroBll cadastrar = new ClsLivroBll();
            
            if (validacao() == true)
            {
                livro.Nome = txtNome.Text;
                livro.Ano = int.Parse(txtAno.Text);
                livro.Isbn = Decimal.Parse(txtIsbn.Text);
                livro.Obs = txtObs.Text;
                livro.CodigoEdi = txtCodigoEdi.SelectedIndex + 1;

                cadastrar.Cadastrar(livro);

                MessageBox.Show("Cadastrado com sucesso!");

                limparTela();
                carregarDadosNoGrid();
            }
        }

        private void btnEditar_Click(object sender, EventArgs e)
        {
            ClsLivroDto livro = new ClsLivroDto();
            ClsLivroBll atualizar = new ClsLivroBll();

            if (validacao() == true)
            {
                livro.Codigo = int.Parse(txtCodigo.Text);
                livro.Nome = txtNome.Text;
                livro.Ano = int.Parse(txtAno.Text);
                livro.Isbn = Decimal.Parse(txtIsbn.Text);
                livro.Obs = txtObs.Text;
                livro.CodigoEdi = int.Parse(txtCodigoEdi.Text) + 1;

                atualizar.Atualizar(livro);

                MessageBox.Show("Atualizado com sucesso!");

                limparTela();
                carregarDadosNoGrid();
            }
        }

        private void btnExcluir_Click(object sender, EventArgs e)
        {
            int codigo;
            ClsLivroBll excluir = new ClsLivroBll();

            if (MessageBox.Show("Deseja mesmo excluir o cadastro?", "Confirmar exclusão", MessageBoxButtons.YesNo) == DialogResult.Yes)
            {
                codigo = int.Parse(txtCodigo.Text);

                excluir.Excluir(codigo);

                MessageBox.Show("Excluído com sucesso!");

                limparTela();
                carregarDadosNoGrid();
            }
        }

        private void limparTela()
        {
            ClsLivroBll livBll = new ClsLivroBll();

            txtCodigo.Text = Convert.ToString(livBll.ObterProximoCodigoLivro());
            txtNome.Clear();
            txtAno.Clear();
            txtIsbn.Clear();
            txtObs.Clear();
        }

        private void setForm()
        {
            ClsLivroBll livBll = new ClsLivroBll();

            txtCodigo.Text = Convert.ToString(livBll.ObterProximoCodigoLivro());
            txtNome.Focus();
        }

        private void btnCarregarGridLivros_Click(object sender, EventArgs e)
        {
            carregarDadosNoGrid();
        }


        private void btnLimpar_Click(object sender, EventArgs e)
        {
            limparTela();
        }

        private void carregarCombo()
        {
            ClsLivroBll livBll = new ClsLivroBll();
            
            txtCodigoEdi.DataSource =
                livBll.ObterDadosCombo("select edi_id, edi_nome from tbl_editoras; ");

        }
        private void btnCarregarGrid_Click(object sender, EventArgs e)
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

        private void frmCadastrarLivro_Load(object sender, EventArgs e)
        {
            // TODO: This line of code loads data into the 'dbeditorasDataSet1.tbl_editoras' table. You can move, or remove it, as needed.
            this.tbl_editorasTableAdapter1.Fill(this.dbeditorasDataSet1.tbl_editoras);
            // TODO: This line of code loads data into the 'dbeditorasDataSet.tbl_editoras' table. You can move, or remove it, as needed.
            this.tbl_editorasTableAdapter.Fill(this.dbeditorasDataSet.tbl_editoras);

        }

        private void dgLivros_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            atualizarTela();
        }


        private void dgLivros_SelectionChanged(object sender, EventArgs e)
        {
            atualizarTela();
        }
    }
}
