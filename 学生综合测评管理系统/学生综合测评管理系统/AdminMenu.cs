using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 学生综合测评管理系统
{
    public partial class AdminMenu : Form
    {
        public AdminMenu()
        {
            InitializeComponent();
            
        }

        private void Menu_FormClosed(object sender, FormClosedEventArgs e)
        {
            Application.Exit();
        }

        private void AdminMenu_Load(object sender, EventArgs e)
        {
            // TODO: 这行代码将数据加载到表“tea_XXDataSet.Tea_XX”中。您可以根据需要移动或删除它。
            this.tea_XXTableAdapter.Fill(this.tea_XXDataSet.Tea_XX);
            // TODO: 这行代码将数据加载到表“stu_XXDataSet.Stu_XX”中。您可以根据需要移动或删除它。
            this.stu_XXTableAdapter.Fill(this.stu_XXDataSet.Stu_XX);

            
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string Sno = textBox1.Text.Trim();
            string name = textBox2.Text.Trim();
            string zhuanye = textBox3.Text.Trim();
            string str = "select * from stu_XX where 1=1";
            if(!String.IsNullOrEmpty(Sno))
            {
                str+=" and 学号 = '"+Sno+"'";
            }
            if (!String.IsNullOrEmpty(name))
            {
                str += " and 姓名 like '%" + name + "%'";
            }
            if (!String.IsNullOrEmpty(zhuanye))
            {
                str += " and 专业 like '%" + zhuanye + "%'";
            }

            SqlConnection conn = new SqlConnection();
            conn.ConnectionString = "Server=.;database=Student;user id = sa;pwd=2327085154";
            conn.Open();
            SqlDataAdapter adapter = new SqlDataAdapter(str, conn);
            DataSet ds = new DataSet();
            adapter.Fill(ds);
            conn.Close();
            dataGridView1.DataSource = ds.Tables[0];


        }

        private void dataGridView1_CellContentDoubleClick(object sender, DataGridViewCellEventArgs e)
        {
            List<string> data = new List<string>();
            for(int i=0;i<dataGridView1.ColumnCount;i++)
            {
                data.Add(dataGridView1.Rows[e.RowIndex].Cells[i].Value.ToString().Trim());
            }
            new ItemShow(data).Show();

        }

        private void toolStripButton1_Click(object sender, EventArgs e)
        {
            panel2.Visible = true;
        }

        private void toolStripLabel1_Click(object sender, EventArgs e)
        {
            panel2.Visible = false;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            string Tno = textBox6.Text.Trim();
            string name = textBox5.Text.Trim();
            string str = "select * from Tea_XX where 1=1";
            if (!String.IsNullOrEmpty(Tno))
            {
                str += " and 教师工号 = '" + Tno + "'";
            }
            if (!String.IsNullOrEmpty(name))
            {
                str += " and 姓名 like '%" + name + "%'";
            }

            SqlConnection conn = new SqlConnection();
            conn.ConnectionString = "Server=.;database=Student;user id = sa;pwd=2327085154";
            conn.Open();
            SqlDataAdapter adapter = new SqlDataAdapter(str, conn);
            DataSet ds = new DataSet();
            adapter.Fill(ds);
            conn.Close();
            dataGridView2.DataSource = ds.Tables[0];
        }
    }
}
