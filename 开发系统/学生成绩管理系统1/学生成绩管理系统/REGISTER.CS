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

namespace 学生成绩管理系统
{
    public partial class register : Form
    {
        string filePath;
        public register(string filePath)
        {
            InitializeComponent();
            this.filePath = filePath;
        }

        private void register_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click_1(object sender, EventArgs e)
        {
            string _username = textBox1.Text;
            string _password1 = textBox2.Text;
            string _password2 = textBox3.Text;
            if (_username == "")
            {
                MessageBox.Show("请输入用户名！", "提示", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
            }
            else if (_password1.Length<6)
            {
                if (_password1 == "")
                {
                    MessageBox.Show("请输入密码！", "提示", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
                }
                else
                {
                    MessageBox.Show("密码应不小于6位数！", "提示", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
                }
            }
            else if (_password2 != _password1)
            {
                MessageBox.Show("两次输入密码不一致！", "提示", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
            }
            else
            {
                OleDbConnection conn = new OleDbConnection();
                conn.ConnectionString = @"Provider=Microsoft.Jet.OLEDB.4.0; Data Source="+filePath;
                conn.Open();
                string str = "select * from [user] where [用户名]='" + _username + "'";
                OleDbCommand cmd = new OleDbCommand(str, conn);
                OleDbDataReader reader = cmd.ExecuteReader();
                if (reader.Read())
                {
                    MessageBox.Show("用户名重复");
                }
                else
                {
                    string sql = "insert into [user](用户名,密码)values('"+_username+"','"+_password1+"')";
                    OleDbCommand comm = new OleDbCommand(sql, conn);
                    int i = comm.ExecuteNonQuery();
                    conn.Close();
                    if (i > 0)
                    {
                        MessageBox.Show("注册成功！");
                        this.Close();
                    }
                    else
                    {
                        MessageBox.Show("注册失败!");
                    }
                }
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void label2_Click(object sender, EventArgs e)
        {

        }
    }
}
