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
    public partial class Delete : Form
    {
        String FilePath;
        public Delete(String FilePath)
        {
            InitializeComponent();
            this.FilePath=FilePath;
        }

        private void listView1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            String bikeID=textBox1.Text;
            DialogResult delete = MessageBox.Show("是否确定删除", "提示", MessageBoxButtons.YesNo, MessageBoxIcon.Asterisk);
            if (delete == DialogResult.Yes)
            {
                OleDbConnection conn = new OleDbConnection();
                conn.ConnectionString = @"Provider=Microsoft.Jet.OLEDB.4.0; Data Source=" + FilePath + ";Jet OLEDB:Database Password=2327085154";
                conn.Open();
                String str = "delete from [bike] where [自行车牌号]='" + bikeID + "'";
                OleDbCommand comm = new OleDbCommand(str, conn);
                int i = comm.ExecuteNonQuery();
                if (i > 0)
                {
                    MessageBox.Show("删除成功！", "提示", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
                    this.Close();
                }
                else
                {
                    MessageBox.Show("删除失败！请稍后重试！", "提示", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
                    this.Close();
                }
                conn.Close();
            }
        }

    }
}
