using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.Data.OleDb;
using ADOX;

namespace 自行车管理系统
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
            button1.ButtonStyle();
            button2.ButtonStyle();
            button3.ButtonStyle();
            //创建数据库
            if (!File.Exists(filePath))
            {
                //创建数据库
                ADOX.CatalogClass Bike = new ADOX.CatalogClass();
                Bike.Create("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=" + filePath + ";Jet OLEDB:Database Password=2327085154;");

                //新建一个表[user]
                ADOX.TableClass user = new ADOX.TableClass();
                user.ParentCatalog = Bike;
                user.Name = "user";
                //增加一个自动增长的字段ID
                ADOX.ColumnClass ID = new ADOX.ColumnClass();
                ID.ParentCatalog = Bike;
                ID.Type = ADOX.DataTypeEnum.adInteger; // 必须先设置字段类型
                ID.Name = "ID";
                ID.Properties["Jet OLEDB:Allow Zero Length"].Value = false;
                ID.Properties["AutoIncrement"].Value = true;
                user.Columns.Append(ID, ADOX.DataTypeEnum.adInteger, 0);
                //增加一个文本字段username
                ADOX.ColumnClass username = new ADOX.ColumnClass();
                username.ParentCatalog = Bike;
                username.Name = "用户名";
                username.Properties["Jet OLEDB:Allow Zero Length"].Value = false;
                user.Columns.Append(username, ADOX.DataTypeEnum.adVarChar, 20);
                //增加一个文本字段password
                ADOX.ColumnClass password = new ADOX.ColumnClass();
                password.ParentCatalog = Bike;
                password.Name = "密码";
                password.Properties["Jet OLEDB:Allow Zero Length"].Value = false;
                user.Columns.Append(password, ADOX.DataTypeEnum.adVarChar, 20);
                //把表加进数据库
                Bike.Tables.Append(user);
                System.Runtime.InteropServices.Marshal.ReleaseComObject(user);

                //新建表[bike]
                ADOX.TableClass bike = new ADOX.TableClass();
                bike.ParentCatalog = Bike;
                bike.Name = "bike";
                //增加一个自动增长的字段 序号
                ADOX.ColumnClass _ID = new ADOX.ColumnClass();
                _ID.ParentCatalog = Bike;
                _ID.Type = ADOX.DataTypeEnum.adInteger; // 必须先设置字段类型
                _ID.Name = "序号";
                _ID.Properties["Jet OLEDB:Allow Zero Length"].Value = false;
                _ID.Properties["AutoIncrement"].Value = true;
                bike.Columns.Append(_ID, ADOX.DataTypeEnum.adInteger, 0);
                //增加一个文本字段name
                ADOX.ColumnClass name = new ADOX.ColumnClass();
                name.ParentCatalog = Bike;
                name.Name = "姓名";
                name.Properties["Jet OLEDB:Allow Zero Length"].Value = false;
                bike.Columns.Append(name, ADOX.DataTypeEnum.adVarChar, 40);
                //增加一个文本字段Class
                ADOX.ColumnClass Class = new ADOX.ColumnClass();
                Class.ParentCatalog = Bike;
                Class.Name = "班级";
                Class.Properties["Jet OLEDB:Allow Zero Length"].Value = false;
                bike.Columns.Append(Class, ADOX.DataTypeEnum.adVarChar, 100);
                //增加一个文本字段pNumber
                ADOX.ColumnClass pNumber = new ADOX.ColumnClass();
                pNumber.ParentCatalog = Bike;
                pNumber.Name = "联系电话";
                pNumber.Properties["Jet OLEDB:Allow Zero Length"].Value = false;
                bike.Columns.Append(pNumber, ADOX.DataTypeEnum.adVarChar, 20);
                //增加一个文本字段room
                ADOX.ColumnClass room = new ADOX.ColumnClass();
                room.ParentCatalog = Bike;
                room.Name = "寝室号";
                room.Properties["Jet OLEDB:Allow Zero Length"].Value = false;
                bike.Columns.Append(room, ADOX.DataTypeEnum.adVarChar, 20);
                //增加一个文本字段bikeID
                ADOX.ColumnClass bikeID = new ADOX.ColumnClass();
                bikeID.ParentCatalog = Bike;
                bikeID.Name = "自行车牌号";
                bikeID.Properties["Jet OLEDB:Allow Zero Length"].Value = false;
                bike.Columns.Append(bikeID, ADOX.DataTypeEnum.adVarChar, 20);
                //增加一个文本字段image
                ADOX.ColumnClass image = new ADOX.ColumnClass();
                image.ParentCatalog = Bike;
                
                image.Name = "自行车照片";
                image.Properties["Jet OLEDB:Allow Zero Length"].Value = false;
                bike.Columns.Append(image, ADOX.DataTypeEnum.adLongVarChar, 1000);
                //把表加进数据库
                Bike.Tables.Append(bike);
                System.Runtime.InteropServices.Marshal.ReleaseComObject(bike);
                System.Runtime.InteropServices.Marshal.ReleaseComObject(bike);

                user = null;
                bike = null;
                Bike = null;
                GC.WaitForPendingFinalizers();
                GC.Collect();
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
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
                conn.ConnectionString = @"Provider=Microsoft.Jet.OLEDB.4.0; Data Source=" + filePath+";Jet OLEDB:Database Password=2327085154";
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

        private void button3_Click(object sender, EventArgs e)
        {
            register ZhuCe = new register(filePath);
            ZhuCe.ShowDialog();
        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

    }
}
