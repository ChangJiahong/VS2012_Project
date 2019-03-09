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
    public partial class screen : Form
    {
        string filePath;
        public screen(string filePath)
        {
            InitializeComponent();
            this.filePath = filePath;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string str = "";
            OleDbConnection conn = new OleDbConnection();
            conn.ConnectionString = @"Provider=Microsoft.Jet.OLEDB.4.0; Data Source=" + filePath;
            conn.Open();
            if (comboBox1.Text == "选择科目" || comboBox2.Text == "选择分数")
            {
                MessageBox.Show("请选择筛选条件！");
            }
            else
            {
                listView1.Clear();
                listView1.Columns.Add("序号");
                listView1.Columns.Add("学号");
                listView1.Columns.Add("姓名");
                listView1.Columns.Add("身份证号");
                listView1.Columns.Add("高数成绩");
                listView1.Columns.Add("英语成绩");
                listView1.Columns.Add("C语言成绩");
                if (comboBox1.Text == "高数成绩")
                {
                    if (comboBox2.Text == "及格")
                        str = "select *from [student] where [高数成绩]>60 ";
                    else if (comboBox2.Text == "不及格")
                        str = "select *from [student] where [高数成绩]<60";
                }
                else if (comboBox1.Text == "英语成绩")
                {
                    if (comboBox2.Text == "及格")
                        str = "select *from [student] where [英语成绩]>60 ";
                    else if (comboBox2.Text == "不及格")
                        str = "select *from [student] where [英语成绩]<60";
                }
                else if (comboBox1.Text == "C语言成绩")
                {
                    if (comboBox2.Text == "及格")
                        str = "select *from [student] where [C语言成绩]>60";
                    else if (comboBox2.Text == "不及格")
                        str = "select *from [student] where [C语言成绩]<60";
                }
               
                OleDbCommand comm = new OleDbCommand(str, conn);
                OleDbDataReader dr = comm.ExecuteReader();
                while (dr.Read())
                {
                    //构建一个ListView的数据，存入数据库数据，以便添加到listView1的行数据中
                    ListViewItem lt = new ListViewItem();
                    //将数据库数据转变成ListView类型的一行数据
                    lt.Text = dr["ID"].ToString();
                    lt.SubItems.Add(dr["学号"].ToString());
                    lt.SubItems.Add(dr["姓名"].ToString());
                    lt.SubItems.Add(dr["身份证号"].ToString());
                    lt.SubItems.Add(dr["高数成绩"].ToString());
                    lt.SubItems.Add(dr["英语成绩"].ToString());
                    lt.SubItems.Add(dr["C语言成绩"].ToString());
                    //将lt数据添加到listView1控件中
                    listView1.Items.Add(lt);
                }
            }
            conn.Close();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void screen_Load(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
