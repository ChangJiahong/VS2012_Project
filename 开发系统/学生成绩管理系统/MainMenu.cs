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

namespace 学生成绩管理系统
{
    public partial class MainMenu : Form
    {
        string filePath;
        static int i = 1;
        public MainMenu(string filePath)
        {
            InitializeComponent();
            label1.BackColor =Color .Transparent ;
            this.filePath=filePath;
        }

        //壁纸
        private void button1_Click(object sender, EventArgs e)
        {
            //文件路径
            string str = System.AppDomain.CurrentDomain.SetupInformation.ApplicationBase+"image\\";
            string[] image = Directory.GetFiles(str);
            this.BackgroundImage = Image.FromFile(@image[i++]);
            if (i == image.Length)
                i = 0;
        }
        //关闭
        private void button2_Click(object sender, EventArgs e)
        {
            DialogResult GuanBi = MessageBox.Show("确定要关闭程序吗？", "", MessageBoxButtons.YesNo, MessageBoxIcon.Question);
            if(GuanBi ==DialogResult.Yes)
                Application.Exit();
        }
        //缩小
        private void button3_Click(object sender, EventArgs e)
        {
            this.WindowState = FormWindowState.Minimized; 
        }
        //输入
        private void button4_Click(object sender, EventArgs e)
        {
            input ShuRu = new input(filePath);
            ShuRu.ShowDialog();
            
        }

        private void button5_Click(object sender, EventArgs e)
        {
            screen ShaiXuan = new screen(filePath);
            ShaiXuan.ShowDialog();
        }

        private void button6_Click(object sender, EventArgs e)
        {

        }

        private void button7_Click(object sender, EventArgs e)
        {

        }

        private void button8_Click(object sender, EventArgs e)
        {

        }

        private void 文件ToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }
        
        private void 打开ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            OpenFileDialog DaKai = new OpenFileDialog();
            DaKai.InitialDirectory = "D:\\";
            DaKai.Filter = "txt files(*.txt)|*.txt|All files(*.*)|*.*";
            DaKai.FilterIndex = 0;
            DaKai.ShowDialog();

        }
        
        private void 另存为ToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }
        
        private void 保存ToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }


        private void 退出ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void toolStripComboBox1_Click(object sender, EventArgs e)
        {

        }

        private void 查询ToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }

        private void 显示全部ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            allShow xainShi = new allShow(filePath);
            xainShi.ShowDialog();
        }

       
        

       
    }
}
