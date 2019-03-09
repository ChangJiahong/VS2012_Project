using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Drawing;

namespace System.Windows.Forms
{
    class MyButton:Button
    {
        /// <summary>  
        /// 设置透明按钮样式  
        /// </summary>  
        public void ButtonStyle()
        {
            this.FlatStyle = FlatStyle.Flat;//样式  
            //btn.ForeColor = Color.Transparent;//前景  
            this.BackColor = Color.Transparent;//去背景  
            this.FlatAppearance.BorderSize = 0;//去边线  
            this.FlatAppearance.MouseOverBackColor = Color.Turquoise;//鼠标经过  
            this.FlatAppearance.MouseDownBackColor = Color.Transparent;//鼠标按下  
        }  
    }
}
