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
    public partial class input : Form
    {
        string filePath;
        public input(string filePath)
        {
            InitializeComponent();
            this.filePath = filePath;
        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void input_Load(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }
        
        private void button1_Click(object sender, EventArgs e)
        {
            string numble = textBox1.Text;
            string name = textBox2.Text;
            string ID = textBox3.Text;
            string math = textBox4.Text;
            string Eglish = textBox5.Text;
            string C = textBox6.Text;
            if (numble == "" || name == "" || ID == "" || math == "" || Eglish == "" || C == "")
            {
                MessageBox.Show("请填写完整信息！", "提示", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
            }
            else
            {
                OleDbConnection conn = new OleDbConnection();
                conn.ConnectionString = @"Provider=Microsoft.Jet.OLEDB.4.0; Data Source="+filePath;
                conn.Open();
                string str = "select * from [student] where [学号]='" + numble + "'";
                string st = "select * from [student] where [身份证号]='" + ID + "'";
                OleDbCommand cmd = new OleDbCommand(str, conn);//查询学号
                OleDbCommand cm = new OleDbCommand(st, conn);//查询身份证号
                OleDbDataReader reader = cmd.ExecuteReader();//读取学号
                OleDbDataReader reader_ID = cm.ExecuteReader();//读取身份证号
                if (reader.Read())
                {
                    MessageBox.Show("该学号已注册！", "提示", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
                }
                else if (reader_ID.Read())
                {
                    MessageBox.Show("该身份证号已注册！", "提示", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
                }
                else
                {
                    string sql = "insert into [student](学号,姓名,身份证号,高数成绩,英语成绩,C语言成绩)values('" + numble + "','" + name + "','" + ID + "','" + math + "','" + Eglish + "','" + C + "')";
                    OleDbCommand comm = new OleDbCommand(sql, conn);
                    int i = comm.ExecuteNonQuery();
                    conn.Close();
                    if (i > 0)
                    {
                        DialogResult nn = MessageBox.Show("录入成功！", "提示", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
                        this.Close();
                    }
                    else
                    {
                        MessageBox.Show("录入失败！请稍后重试！", "提示", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
                        this.Close();
                    }
                }
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            
        }

        private void button3_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        

        
    }
}
