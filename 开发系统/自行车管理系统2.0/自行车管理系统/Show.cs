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
    public partial class Show : Form
    {
        String FilePath = "";

        private bool equals(ListViewItem lt)
        {
            int i;
            for (i = 0; i < listView1.Items.Count; i++)
            {
                if (lt.Text == listView1.Items[0].SubItems[0].Text)
                    break;
            }
            if (i < listView1.Items.Count)
                return false;
            else 
                return true;
        }

        private void listView1_doubleClick(object sender, EventArgs e)
        {
            ALL all = new ALL(FilePath,listView1);
            all.Show();
            
        }
        public Show(String FilePath,String text)
        {
            InitializeComponent();
            this.FilePath = FilePath;
            listView1.Clear();
            listView1.Columns.Add("序号");
            listView1.Columns.Add("姓名");
            listView1.Columns[1].Width = 80;
            listView1.Columns.Add("班级");
            listView1.Columns[2].Width = 100;
            listView1.Columns.Add("联系电话");
            listView1.Columns[3].Width = 120;
            listView1.Columns.Add("寝室房间号");
            listView1.Columns[4].Width = 100;
            listView1.Columns.Add("自行车牌号");
            listView1.Columns[5].Width = 100;
            listView1.DoubleClick += new EventHandler(listView1_doubleClick);
            OleDbConnection conn=new OleDbConnection();
            conn.ConnectionString=@"Provider=Microsoft.Jet.OLEDB.4.0; Data Source=" + FilePath + ";Jet OLEDB:Database Password=2327085154";
            conn.Open();
            String name = "select * from [bike] where [姓名]='" + text + "'";
            String Class = "select * from [bike] where [班级]='" + text + "'";
            String p_number = "select * from [bike] where [联系电话]='" + text + "'";
            String room = "select * from [bike] where [寝室号]='" + text + "'";
            String bikeID = "select * from [bike] where [自行车牌号]='" + text + "'";
            OleDbCommand _name = new OleDbCommand(name, conn);
            OleDbCommand _Class = new OleDbCommand(Class, conn);
            OleDbCommand _p_number = new OleDbCommand(p_number, conn);
            OleDbCommand _room = new OleDbCommand(room, conn);
            OleDbCommand _bikeID = new OleDbCommand(bikeID, conn);
            OleDbDataReader na = _name.ExecuteReader();
            OleDbDataReader cl = _Class.ExecuteReader();
            OleDbDataReader pn = _p_number.ExecuteReader();
            OleDbDataReader ro = _room.ExecuteReader();
            OleDbDataReader bi = _bikeID.ExecuteReader();
            while (na.Read())
            {
                //构建一个ListView的数据，存入数据库数据，以便添加到listView1的行数据中
                ListViewItem lt = new ListViewItem();
                //将数据库数据转变成ListView类型的一行数据
                lt.Text = na["序号"].ToString();
                lt.SubItems.Add(na["姓名"].ToString());
                lt.SubItems.Add(na["班级"].ToString());
                lt.SubItems.Add(na["联系电话"].ToString());
                lt.SubItems.Add(na["寝室号"].ToString());
                lt.SubItems.Add(na["自行车牌号"].ToString());
                //将lt数据添加到listView1控件中
                listView1.Items.Add(lt);
            }
            while (cl.Read())
            {
                //构建一个ListView的数据，存入数据库数据，以便添加到listView1的行数据中
                ListViewItem lt = new ListViewItem();
                //将数据库数据转变成ListView类型的一行数据
                lt.Text = cl["序号"].ToString();
                if (!equals(lt))
                    break; 
                lt.SubItems.Add(cl["姓名"].ToString());
                lt.SubItems.Add(cl["班级"].ToString());
                lt.SubItems.Add(cl["联系电话"].ToString());
                lt.SubItems.Add(cl["寝室号"].ToString());
                lt.SubItems.Add(cl["自行车牌号"].ToString());
                //将lt数据添加到listView1控件中
                listView1.Items.Add(lt);
            }
            
             while (pn.Read())
             {
                 //构建一个ListView的数据，存入数据库数据，以便添加到listView1的行数据中
                 ListViewItem lt = new ListViewItem();
                 //将数据库数据转变成ListView类型的一行数据
                 lt.Text = pn["序号"].ToString();
                 if (!equals(lt))
                     break; 
                 lt.SubItems.Add(pn["姓名"].ToString());
                 lt.SubItems.Add(pn["班级"].ToString());
                 lt.SubItems.Add(pn["联系电话"].ToString());
                 lt.SubItems.Add(pn["寝室号"].ToString());
                 lt.SubItems.Add(pn["自行车牌号"].ToString());
                 //将lt数据添加到listView1控件中
                 listView1.Items.Add(lt);
             }
             while (ro.Read())
             {
                 //构建一个ListView的数据，存入数据库数据，以便添加到listView1的行数据中
                 ListViewItem lt = new ListViewItem();
                 //将数据库数据转变成ListView类型的一行数据
                 lt.Text = ro["序号"].ToString();
                 if (!equals(lt))
                     break; 
                 lt.SubItems.Add(ro["姓名"].ToString());
                 lt.SubItems.Add(ro["班级"].ToString());
                 lt.SubItems.Add(ro["联系电话"].ToString());
                 lt.SubItems.Add(ro["寝室号"].ToString());
                 lt.SubItems.Add(ro["自行车牌号"].ToString());
                 //将lt数据添加到listView1控件中
                 listView1.Items.Add(lt);
             }
             while (bi.Read())
             {
                 //构建一个ListView的数据，存入数据库数据，以便添加到listView1的行数据中
                 ListViewItem lt = new ListViewItem();
                 //将数据库数据转变成ListView类型的一行数据
                 lt.Text = bi["序号"].ToString();
                 if(!equals(lt))
                     break; ;
                 lt.SubItems.Add(bi["姓名"].ToString());
                 lt.SubItems.Add(bi["班级"].ToString());
                 lt.SubItems.Add(bi["联系电话"].ToString());
                 lt.SubItems.Add(bi["寝室号"].ToString());
                 lt.SubItems.Add(bi["自行车牌号"].ToString());
                 //将lt数据添加到listView1控件中
                 listView1.Items.Add(lt);
             }
             
        }

        private void listView1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }
    }
}
