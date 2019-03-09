using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.OleDb;

namespace 自行车管理系统
{
    public partial class MainMenu : Form
    {
        String filePath = "";
        public MainMenu(String filePath)
        {
            InitializeComponent();
            this.filePath = filePath;
            label1.BackColor = Color.Transparent;
            button1.ButtonStyle();
            button2.ButtonStyle();
            button3.ButtonStyle();
            button4.ButtonStyle();
            button5.ButtonStyle();
            Button6.ButtonStyle();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            DialogResult GuanBi = MessageBox.Show("确定要关闭程序吗？", "", MessageBoxButtons.YesNo, MessageBoxIcon.Question);
            if (GuanBi == DialogResult.Yes)
                Application.Exit();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.WindowState = FormWindowState.Minimized;
        }

        private void Button6_Click(object sender, EventArgs e)
        {
            if (this.WindowState == FormWindowState.Normal)
            {
                this.WindowState = FormWindowState.Maximized;
            }
            else if(this.WindowState == FormWindowState.Maximized)
            {
                this.WindowState = FormWindowState.Normal;
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            Input input = new Input(filePath);
            input.ShowDialog();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            Delete delete = new Delete(filePath);
            delete.ShowDialog();
        }
        //查找
        private void button3_Click(object sender, EventArgs e)
        {
            String text = textBox1.Text;
            if (text == "")
            {
                MessageBox.Show("查询数据不能为空");
            }
            else
            {
                Show show = new Show(filePath, text);
                show.ShowDialog();
            }
        }
    }
}
