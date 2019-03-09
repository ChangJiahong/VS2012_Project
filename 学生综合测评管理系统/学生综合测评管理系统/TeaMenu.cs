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
    public partial class TeaMenu : Form
    {
        public TeaMenu()
        {
            InitializeComponent();
        }

        private void TeaMenu_Load(object sender, EventArgs e)
        {
            // TODO: 这行代码将数据加载到表“stu_CJBDataSet.Stu_CJB”中。您可以根据需要移动或删除它。
            this.stu_CJBTableAdapter.Fill(this.stu_CJBDataSet.Stu_CJB);
            // TODO: 这行代码将数据加载到表“stu_CJBDataSet.Stu_CJB”中。您可以根据需要移动或删除它。
            this.stu_CJBTableAdapter.Fill(this.stu_CJBDataSet.Stu_CJB);
           

        }

        private void TeaMenu_FormClosed(object sender, FormClosedEventArgs e)
        {
            Application.Exit();
        }

        private void dataGridView1_CellContentDoubleClick(object sender, DataGridViewCellEventArgs e)
        {
            comboBox1.Text = dataGridView1.Rows[e.RowIndex].Cells[2].Value.ToString().Trim();
            comboBox2.Text = dataGridView1.Rows[e.RowIndex].Cells[3].Value.ToString().Trim();
            comboBox3.Text = dataGridView1.Rows[e.RowIndex].Cells[4].Value.ToString().Trim();
            comboBox4.Text = dataGridView1.Rows[e.RowIndex].Cells[5].Value.ToString().Trim();
            textBox1.Text = dataGridView1.Rows[e.RowIndex].Cells[0].Value.ToString().Trim();
            textBox3.Text = dataGridView1.Rows[e.RowIndex].Cells[3].Value.ToString().Trim();
        }
    }
}
