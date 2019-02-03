/* The purpose of this program is to hold the Defintion form methods.
 * This form will get information from the Dictionary Editor Form.
 * Then send the information to the tables in the database. It will
 * also send information to the Illustration form.
 * 
 * 03/26/11- Started creating all classes and methods
 * 03/27/11- Finalized the classes and methods
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
    public partial class DefinitionForm : Form
    {
        Definition def;
        int defcount, illcount;
        DictionaryEditor parent;
        IllustrationForm illform;
        Illustration ill;

        public DefinitionForm(DictionaryEditor par, ref Headword hw, int i)
        {
            InitializeComponent();
            parent = par;
            defHeadBox.Text = hw.hword;
            defPOSBox.SelectedIndex = i;
            //create a new instance of definition class
            def = new Definition();
            defcount = parent.getHw.DefList.Count();
            def.Head = defHeadBox.Text;
            def.dNum = defcount++;
        }

        //---------------------------------------------------
        /* This is the okBtn_Click method. When OK is clicked, 
         * get the information from the form and other places 
         * and fill in the Definition object that you created 
         * in the constructor. Tell theHeadword to add this 
         * newly created Definition object to its List<Definition>.
         */
        private void okBtn_Click(object sender, EventArgs e)
        {
            //Get the information and add if to the definition object
            def.POS = defPOSBox.Text;
            def.sDef = defSDefBox.Text;
            def.Def = defDefBox.Text;
            def.Head = defHeadBox.Text;
            //def.dNum = defcount;
            parent.getHw.DefList.Add(def);
            this.Hide();
        }

        //---------------------------------------------------
        /* This is the addIllBtn_Click method. It opens the illustration
         * form and retrieve the illustration information and 
         * add it to the Illustration object, when clicked.
         */
        private void addIllBtn_Click(object sender, EventArgs e)
        {
            if (defDefBox.Text != "")
            {
                //new Illustration form
                illform = new IllustrationForm(defDefBox.Text);

                //if user clicks ok on the illustration form
                DialogResult dr = illform.ShowDialog();
                if (dr == DialogResult.OK)
                {
                    ill = new Illustration();
                    //illform.Show();
                    addIllustration();
                    //get the illustration number
                    illcount = parent.getHw.IllList.Count();
                    ill.setIllNum = illcount++;
                    illform.illDefBox.Text = def.Def;
                    ill.hword = def.Head;
                }
            }
            else
            {
                MessageBox.Show("You need to enter a definition.");
            }
        }
        //---------------------------------------------------
        /* This is the addIllustration method. It adds the 
         * illustration to the definition and headword.
         */
        public void addIllustration()
        {
            ill.hword = def.Head;
            ill.illustration = illform.illIllBox.Text;
            ill.translation = illform.illTransBox.Text;
            parent.getHw.IllList.Add(ill);
            def.IllList.Add(ill);
        }

        //When Cancel Button is clicked
        private void cnclBtn_Click(object sender, EventArgs e)
        {
            DictionaryEdit.DefinitionForm.ActiveForm.Dispose();
        }
    }
}
