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
    public partial class Login : Form
    {
        public Login()
        {
            InitializeComponent();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            string _userName = textBox1.Text;
            string _password = textBox2.Text;
            string _type = comboBox1.Text;

            if (_userName == "")
            {
                MessageBox.Show("用户名为空！", "提示", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
            }
            else if (_password == "")
            {
                MessageBox.Show("密码为空！", "提示", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
            }
            else if (_password.Length < 6)
            {
                MessageBox.Show("密码不得低于6位数！", "提示", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
            }
            else
            {
                SqlConnection conn = new SqlConnection();
                conn.ConnectionString = "Server=.;database=Student;user id = sa;pwd=2327085154";
                conn.Open();
                string str = "select * from [Users] where [name]='" + _userName + "'and [pwd]='" + _password + "' and [type] = '"+_type+"'";
                SqlCommand cmd = new SqlCommand(str, conn);
                SqlDataReader reader = cmd.ExecuteReader();
                if (reader.Read())
                {
                    switch (_type.Split(' ')[0])
                    {
                        case "管理员":
                            new AdminMenu().Show();
                            this.Hide();
                            break;
                        case "学生":
                            new StuMenu().Show();
                            this.Hide();
                            break;
                        case "教师":
                            new TeaMenu().Show();
                            this.Hide();
                            break;
                    }
                    
                }
                else
                {
                    MessageBox.Show("用户名或密码错误！");
                }
                conn.Close();
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            new Repassword().ShowDialog();
        }


        private void Login_Load(object sender, EventArgs e)
        {
            SqlConnection conn = new SqlConnection();
            conn.ConnectionString = "Server=.;database=Student;user id = sa;pwd=2327085154";
            conn.Open();
            string str = "select distinct type from [Users] ";
            SqlDataAdapter adapter = new SqlDataAdapter(str, conn);
            DataSet ds = new DataSet();
            adapter.Fill(ds);
            conn.Close();
            comboBox1.DataSource = ds.Tables[0];

        }

      
    }
}
