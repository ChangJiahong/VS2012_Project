using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 学生综合测评管理系统
{
    public partial class StuMenu : Form
    {
        public StuMenu()
        {
            InitializeComponent();
        }

        private void toolStripLabel1_Click(object sender, EventArgs e)
        {
            panel2.Visible = false;
        }

        private void toolStripLabel2_Click(object sender, EventArgs e)
        {
            panel2.Visible = true;
        }

        private void StuMenu_Load(object sender, EventArgs e)
        {
            panel2.Visible = false;
        }

        private void StuMenu_FormClosed(object sender, FormClosedEventArgs e)
        {
            Application.Exit();
        }
    }
}
