namespace 自行车管理系统
{
    partial class Show
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Show));
            this.listView1 = new System.Windows.Forms.ListView();
            this.序号 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.姓名 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.班级 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.联系电话 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.寝室房间号 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.自行车牌号 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.SuspendLayout();
            // 
            // listView1
            // 
            this.listView1.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.序号,
            this.姓名,
            this.班级,
            this.联系电话,
            this.寝室房间号,
            this.自行车牌号});
            this.listView1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.listView1.FullRowSelect = true;
            this.listView1.Location = new System.Drawing.Point(0, 0);
            this.listView1.Name = "listView1";
            this.listView1.Size = new System.Drawing.Size(563, 444);
            this.listView1.TabIndex = 0;
            this.listView1.UseCompatibleStateImageBehavior = false;
            this.listView1.View = System.Windows.Forms.View.Details;
            this.listView1.SelectedIndexChanged += new System.EventHandler(this.listView1_SelectedIndexChanged);
            // 
            // 序号
            // 
            this.序号.Text = "序号";
            // 
            // 姓名
            // 
            this.姓名.Text = "姓名";
            this.姓名.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.姓名.Width = 80;
            // 
            // 班级
            // 
            this.班级.Text = "班级";
            this.班级.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.班级.Width = 100;
            // 
            // 联系电话
            // 
            this.联系电话.DisplayIndex = 4;
            this.联系电话.Text = "联系电话";
            this.联系电话.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.联系电话.Width = 120;
            // 
            // 寝室房间号
            // 
            this.寝室房间号.DisplayIndex = 3;
            this.寝室房间号.Text = "寝室房间号";
            this.寝室房间号.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.寝室房间号.Width = 100;
            // 
            // 自行车牌号
            // 
            this.自行车牌号.Text = "自行车牌号";
            this.自行车牌号.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.自行车牌号.Width = 100;
            // 
            // Show
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(563, 444);
            this.Controls.Add(this.listView1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.SizableToolWindow;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "Show";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "Show";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.ListView listView1;
        private System.Windows.Forms.ColumnHeader 序号;
        private System.Windows.Forms.ColumnHeader 姓名;
        private System.Windows.Forms.ColumnHeader 班级;
        private System.Windows.Forms.ColumnHeader 联系电话;
        private System.Windows.Forms.ColumnHeader 寝室房间号;
        private System.Windows.Forms.ColumnHeader 自行车牌号;
    }
}