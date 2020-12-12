using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ProjetoEditora
{
    public partial class frmPrincipal : Form
    {
        public frmPrincipal()
        {
            InitializeComponent();
        }

        private void editoraToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            frmCadastroEditora frmEdi = new frmCadastroEditora();

            frmEdi.ShowDialog();
        }

        private void autorToolStripMenuItem_Click(object sender, EventArgs e)
        {
            frmCadastroAutor frmAut = new frmCadastroAutor();

            frmAut.ShowDialog();
        }

        private void livroToolStripMenuItem_Click(object sender, EventArgs e)
        {
            frmCadastrarLivro frmLiv = new frmCadastrarLivro();

            frmLiv.ShowDialog();
        }
    }
}
