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

namespace 自行车管理系统
{
    public partial class Input : Form
    {
        String filePath="";
        String fileName="";
        String FilePath;
        public Input(String FilePath)
        {
            InitializeComponent();
            this.FilePath = FilePath;
        }

        static byte[] GetBytes(string str)
        {
            byte[] bytes = new byte[str.Length * sizeof(char)];
            System.Buffer.BlockCopy(str.ToCharArray(), 0, bytes, 0, bytes.Length);
            return bytes;
        }

        static string GetString(byte[] bytes)
        {
            char[] chars = new char[bytes.Length / sizeof(char)];
            System.Buffer.BlockCopy(bytes, 0, chars, 0, bytes.Length);
            return new string(chars);
        }

        private void SaveImage(String filePath,OleDbConnection conn,String bikeID)
        {
            FileStream fs=new FileStream (filePath,FileMode.Open);
            BinaryReader br = new BinaryReader(fs);
            byte[] buffer = br.ReadBytes((int)fs.Length);
            //String str = GetString(buffer);
            OleDbCommand command = new OleDbCommand("update [bike] set [自行车照片]=@pic where 自行车牌号='" + bikeID + "'", conn);
            //OleDbCommand command =new OleDbCommand ("update [bike] set [自行车照片]=@pic where 自行车牌号='"+bikeID+"'",conn);
            command.Parameters.AddWithValue("@pic",buffer);
            command.ExecuteNonQuery();
            br.Close();
            fs.Close();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            OpenFileDialog DaKai = new OpenFileDialog();
            DaKai.InitialDirectory = "D://";
            DaKai.Filter = "jpg图片文件(*.jpg)|*.jpg|png图片文件(*.png)|*.png";
            DaKai.FilterIndex = 0;
            DaKai.ShowDialog();
            DaKai.RestoreDirectory = true;
            filePath=DaKai.FileName.ToString();  //获取文件路径
            fileName=System.IO.Path.GetFileName(DaKai.FileName);           //得到文件名
            //String fileName=filePath.Substring(filePath.LastIndexOf("//"+1));  //获取不带路径文件名//错误
            textBox5.Text=fileName;
            
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            String name = textBox1.Text;
            String Class = textBox2.Text;
            String p_numble = textBox6.Text;
            String room = textBox3.Text;
            String bikeID = textBox4.Text;
            if (name == "" || Class == "" || p_numble == "" || room == "" || bikeID == "" || bikeID == ""|| filePath=="" )
            {
                MessageBox.Show("请填写完整信息！", "提示", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
            }
            else
            {
                OleDbConnection conn = new OleDbConnection();
                conn.ConnectionString = @"Provider=Microsoft.Jet.OLEDB.4.0; Data Source=" + FilePath + ";Jet OLEDB:Database Password=2327085154";
                conn.Open();
                string st = "select * from [bike] where [自行车牌号]='" + bikeID + "'";
                OleDbCommand cm = new OleDbCommand(st, conn);//查询自行车号
                OleDbDataReader reader = cm.ExecuteReader();//读取自行车号
                if (reader.Read())
                {
                    MessageBox.Show("该辆自行车已录入！", "提示", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
                }
                else
                {
                    string sql = "insert into [bike](姓名,班级,联系电话,寝室号,自行车牌号)values('" + name + "','" + Class + "','" + p_numble + "','" + room + "','" + bikeID + "')";
                    OleDbCommand comm = new OleDbCommand(sql, conn);
                    int i = comm.ExecuteNonQuery();
                    try
                    {
                        SaveImage(@filePath, conn, bikeID);
                    }
                    catch (Exception ex)
                    {
                        MessageBox.Show("录入失败！请稍后重试！错误提示："+ex.Message, "提示", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
                        this.Close();
                    }
                    finally
                    {
                        conn.Close();
                        if (i > 0)
                        {
                            MessageBox.Show("录入成功！", "提示", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
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
        }
    }
}
