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
    public partial class ItemShow : Form
    {
        public ItemShow(List<string> data)
        {
            InitializeComponent();
            textBox1.Text = data[0];
            textBox2.Text = data[1];
            textBox3.Text = data[3];
            textBox4.Text = data[4];
            textBox5.Text = data[5];
            textBox6.Text = data[6];
            if(data[2].Equals("男"))
            {
                radioButton1.Select();
            }
            else if (data[2].Equals("女"))
            {
                radioButton2.Select();
            }

        }

        private void ItemShow_Load(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void button1_Click(object sender, EventArgs e)
        {

        }
    }
}
