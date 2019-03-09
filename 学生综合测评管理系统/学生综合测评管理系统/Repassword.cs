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
    public partial class Repassword : Form
    {
        public Repassword()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string old_pwd = textBox1.Text;
            string pwd1 = textBox2.Text;
            string pwd2 = textBox3.Text;
            string name = textBox4.Text;
            if (!old_pwd.Equals("") && !pwd1.Equals("") && !pwd2.Equals("") && !name.Equals(""))
            {
                if (!pwd2.Equals(pwd1))
                {
                    MessageBox.Show("密码不一致！", "提示", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
                }
                else
                {
                    SqlConnection conn = new SqlConnection();
                    conn.ConnectionString = "Server=.;database=Student;user id = sa;pwd=2327085154";
                    conn.Open();
                    string str = "select * from [Users] where [name]='" + name + "'and [password]='" + old_pwd + "'";
                    SqlCommand cmd = new SqlCommand(str, conn);
                    SqlDataReader reader = cmd.ExecuteReader();
                    if (reader.Read())
                    {
                        string str1 = "update Users set password = '" + pwd1 + "' where name='" + name + "'";
                        SqlCommand comm = new SqlCommand(str1, conn);
                        int i = comm.ExecuteNonQuery();
                        conn.Close();
                        if (i > 0)
                        {
                            MessageBox.Show("修改成功！");
                            this.Close();
                        }
                        else
                        {
                            MessageBox.Show("修改失败!");
                        }
                    }
                    else
                    {
                        MessageBox.Show("用户名或密码错误！");
                    }
                    conn.Close();
                }

            }
            else
            {
                MessageBox.Show("信息填写完整！", "提示", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
            }
        }
    }
}
