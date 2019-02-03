/* The purpose of this class is to handle the features 
 * of the Illustration Form.
 * 
 * 03/27/11- Started and finalized the class
 * 
 * Programmer: K. Johnson, B.Kesler, D. Parker  Current: 03/27/11
 */

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace DictionaryEdit
{
    public partial class IllustrationForm : Form
    {
        public IllustrationForm(string s)
        {
            InitializeComponent();
            //set the definition text
            illDefBox.Text = s;
        }

        private void okIllBtn_Click(object sender, EventArgs e)
        {
            Illustration illus = new Illustration();
            illus.illustration = getIll;
            illus.translation = getTrans;
        }
        //Properties
        public string getIll
        { get { return illIllBox.Text; } }

        public string getTrans
        { get { return illTransBox.Text; } }

        private void cnclIllBtn_Click(object sender, EventArgs e)
        {
            this.Dispose();
        }
    }
}