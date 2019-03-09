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
using System.IO;

namespace 学生成绩管理系统
{
    public partial class Form1 : Form
    {
        //文件路径
        string filePath = System.AppDomain.CurrentDomain.SetupInformation.ApplicationBase + "Data.mdb";
        public Form1()
        {
            InitializeComponent();
            label1.BackColor = Color.Transparent;
            label2.BackColor = Color.Transparent;
            label3.BackColor = Color.Transparent;
            if (!File.Exists(filePath))
            {
               //创建数据库
                ADOX.CatalogClass Student = new ADOX.CatalogClass();
                Student.Create("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=" + filePath + ";Jet OLEDB:Database Password=2327085154;");
                
                //新建一个表[user]
                ADOX.TableClass user = new ADOX.TableClass();
                user.ParentCatalog = Student;
                user.Name = "user";
                //增加一个自动增长的字段ID
                ADOX.ColumnClass ID = new ADOX.ColumnClass();
                ID.ParentCatalog = Student;
                ID.Type = ADOX.DataTypeEnum.adInteger; // 必须先设置字段类型
                ID.Name = "ID";
                ID.Properties["Jet OLEDB:Allow Zero Length"].Value = false;
                ID.Properties["AutoIncrement"].Value = true;
                user.Columns.Append(ID, ADOX.DataTypeEnum.adInteger, 0);
                //增加一个文本字段username
                ADOX.ColumnClass username = new ADOX.ColumnClass();
                username.ParentCatalog = Student;
                username.Name = "用户名";
                username.Properties["Jet OLEDB:Allow Zero Length"].Value = false;
                user.Columns.Append(username, ADOX.DataTypeEnum.adVarChar, 20);
                //增加一个文本字段password
                ADOX.ColumnClass password = new ADOX.ColumnClass();
                password.ParentCatalog = Student;
                password.Name = "密码";
                password.Properties["Jet OLEDB:Allow Zero Length"].Value = false;
                user.Columns.Append(password, ADOX.DataTypeEnum.adVarChar, 20);
                //把表加进数据库
                Student.Tables.Append(user);
                System.Runtime.InteropServices.Marshal.ReleaseComObject(user);
                
                //新建表[student]
                ADOX.TableClass student = new ADOX.TableClass();
                student.ParentCatalog = Student;
                student.Name = "student";
                //增加一个自动增长的字段ID
                ADOX.ColumnClass _ID = new ADOX.ColumnClass();
                _ID.ParentCatalog = Student;
                _ID.Type = ADOX.DataTypeEnum.adInteger; // 必须先设置字段类型
                _ID.Name = "ID";
                _ID.Properties["Jet OLEDB:Allow Zero Length"].Value = false;
                _ID.Properties["AutoIncrement"].Value = true;
                student.Columns.Append(_ID, ADOX.DataTypeEnum.adInteger, 0);
                //增加一个文本字段xueHao
                ADOX.ColumnClass xueHao = new ADOX.ColumnClass();
                xueHao.ParentCatalog = Student;
                xueHao.Name = "学号";
                xueHao.Properties["Jet OLEDB:Allow Zero Length"].Value = false;
                student.Columns.Append(xueHao, ADOX.DataTypeEnum.adVarChar, 20);
                //增加一个文本字段name
                ADOX.ColumnClass name = new ADOX.ColumnClass();
                name.ParentCatalog = Student;
                name.Name = "姓名";
                name.Properties["Jet OLEDB:Allow Zero Length"].Value = false;
                student.Columns.Append(name, ADOX.DataTypeEnum.adVarChar, 20);
                //增加一个文本字段iD
                ADOX.ColumnClass iD = new ADOX.ColumnClass();
                iD.ParentCatalog = Student;
                iD.Name = "身份证号";
                iD.Properties["Jet OLEDB:Allow Zero Length"].Value = false;
                student.Columns.Append(iD, ADOX.DataTypeEnum.adVarChar, 20);
                //增加一个文本字段math
                ADOX.ColumnClass math = new ADOX.ColumnClass();
                math.ParentCatalog = Student;
                math.Type = ADOX.DataTypeEnum.adDouble;
                math.Name = "高数成绩";
                math.Properties["Jet OLEDB:Allow Zero Length"].Value = false;
                student.Columns.Append(math, ADOX.DataTypeEnum.adDouble, 20);
                //增加一个文本字段Eglish
                ADOX.ColumnClass Eglish = new ADOX.ColumnClass();
                Eglish.ParentCatalog = Student;
                Eglish.Type = ADOX.DataTypeEnum.adDouble;
                Eglish.Name = "英语成绩";
                Eglish.Properties["Jet OLEDB:Allow Zero Length"].Value = false;
                student.Columns.Append(Eglish, ADOX.DataTypeEnum.adDouble, 20);
                //增加一个文本字段C
                ADOX.ColumnClass C = new ADOX.ColumnClass();
                C.ParentCatalog = Student;
                C.Type = ADOX.DataTypeEnum.adDouble;
                C.Name = "C语言成绩";
                C.Properties["Jet OLEDB:Allow Zero Length"].Value = false;
                student.Columns.Append(C, ADOX.DataTypeEnum.adDouble, 20);
                //把表加进数据库
                Student.Tables.Append(student);
                System.Runtime.InteropServices.Marshal.ReleaseComObject(student);
                System.Runtime.InteropServices.Marshal.ReleaseComObject(Student);

                user = null;
                student = null;
                Student = null;
                GC.WaitForPendingFinalizers();
                GC.Collect();
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            this.WindowState = FormWindowState.Minimized; 
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string _username = textBox1.Text;
            string _password = textBox2.Text;
            if (_username == "")
            {
                MessageBox.Show("请输入用户名！", "提示", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
            }
            else if (_password == "")
            {
                MessageBox.Show("请输入密码！", "提示", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
            }
            else
            {
                OleDbConnection conn = new OleDbConnection();
                conn.ConnectionString = @"Provider=Microsoft.Jet.OLEDB.4.0; Data Source="+filePath;
                conn.Open();
                string str = "select * from [user] where [用户名]='" + _username + "'and [密码]='" + _password + "'";
                OleDbCommand cmd = new OleDbCommand(str, conn);
                OleDbDataReader reader = cmd.ExecuteReader();
                if (reader.Read())
                {
                    MainMenu ZhuCaiDan = new MainMenu(filePath);
                    ZhuCaiDan.Show();
                    this.Hide();
                }
                else
                {
                    MessageBox.Show("用户名或密码错误！", "提示", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                }
                conn.Close();
            }
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            
        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {
            
        }

        private void button2_Click(object sender, EventArgs e)
        {
            register ZhuCe = new register(filePath);
            ZhuCe.ShowDialog();
        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }
    }
}
