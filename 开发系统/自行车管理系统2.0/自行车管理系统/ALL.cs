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
using System.Drawing.Imaging;
using System.IO;

namespace 自行车管理系统
{
    public partial class ALL : Form
    {
        String FilePath = "";
        private void LoadImage(OleDbConnection conn,String bikeID)
        {
            OleDbCommand command = new OleDbCommand("select * from [bike] where [自行车牌号]='" + bikeID + "'", conn);
            OleDbDataReader dr = command.ExecuteReader();
            byte[] buff = null;
            if (dr.Read())
            {
                buff = (byte[])dr["自行车照片"];
            }
            
            //BitmapImage bi = new BitmapImage();
            MemoryStream ms = new MemoryStream(buff);
            Image image = System.Drawing.Image.FromStream(ms);
            pictureBox1.Image = image;
        }

        public ALL(String FilePath,ListView listView)
        {
            InitializeComponent();
            this.FilePath = FilePath;
            OleDbConnection conn = new OleDbConnection();
            conn.ConnectionString = @"Provider=Microsoft.Jet.OLEDB.4.0; Data Source=" + FilePath + ";Jet OLEDB:Database Password=2327085154";
            conn.Open();
            label7.Text = listView.FocusedItem.SubItems[1].Text;
            label8.Text = listView.FocusedItem.SubItems[2].Text;
            label9.Text = listView.FocusedItem.SubItems[3].Text;
            label10.Text = listView.FocusedItem.SubItems[4].Text;
            String bikeID = label11.Text = listView.FocusedItem.SubItems[5].Text;
            LoadImage(conn,bikeID);
            conn.Close();
        }

        private void ALL_Load(object sender, EventArgs e)
        {

        }
    }
}
