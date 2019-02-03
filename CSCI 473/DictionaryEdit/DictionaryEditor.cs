/* The purpose of this program is to create a Dictionary Editor which well allow the user
 * to enter a word and see if it is in the dictionary. The dictionary is a word file
 * that contains all the words in the dictionary. It will check (ignoring upper or lower
 * case) the word entered compared to the one in the file. It will then send a message telling
 * the user if it is in the dictionary and what version of the dictionary.
 * 
 * 01/30/11 - Began work on the  program that included
 * - a Windows Forms application that contains the user interface 
 * - Paint method was overriden to draw a nice title
 * - Linked to the SpellChecker Program
 * 01/31/11 - Added Error Checking Features. Versioning was checking in Dr. Zerwekh's office.
 * Documentation added.
 * 02/12/11 - Added Exceptions, border, and clock to the program
 * 02/13/11 - Added Comments
 * 03/08/11 - Added Code for Word Events and Turn Button click
 * 03/27/11 - Added code for database for assignment 4
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
using SpellChecker;
using SemanticSocialAssister;
using System.Threading;
using System.Data.SqlClient;
using System.Configuration;

namespace DictionaryEdit
{
    /// <summary>
    /// This is the one and only class used in this program.
    /// It is the creation of the form and the calling of the 
    /// SpellCheck class created in SpellChecker.cs
    /// </summary>
    public partial class DictionaryEditor : Form
    {
        System.Windows.Forms.Timer time = new System.Windows.Forms.Timer();
        SpellCheck SCheck = new SpellCheck(); //creation of the SpellCheck class

        Headword theHeadword = new Headword();
        public Headword getHw
        { get { return theHeadword; } }
        public Headword setHw
        { set { theHeadword = value; } }

        //---------------------------------------------------
        // The constructor for the Window form
        public DictionaryEditor()
        {
            InitializeComponent();
            fillBox(); //Call to the fillBox Function

            CheckForIllegalCrossThreadCalls = false;

            //Set up the time for the clock
            time.Interval = 1000;
            time.Start();
            time.Tick += new EventHandler(time_Tick);

            verifyTable();
        }

        //---------------------------------------------------
        /* The purpose of this function is to check to see if 
         * the Headwords table is created inthe database. If
         * it is then you continue on, otherwise it will create 
         * table in the database.
         */
        public void verifyTable()
        {
            SqlConnection conn;
            //set up the string to connect to the database
            ConnectionStringSettings settings = ConfigurationManager.ConnectionStrings["Dictionary"];
            string connstr = settings.ConnectionString;
            //using the connection
            using (conn = new SqlConnection(connstr))
            {
                //open connection
                conn.Open();
                SqlCommand cmd = new SqlCommand();
                cmd.Connection = conn;
                //The query
                cmd.CommandText = "SELECT count (*) FROM sysobjects where name = 'Headwords'";
                //execute query
                int counter = (int)cmd.ExecuteScalar();

                //if the table doesn't exist create it
                if (counter == 0)
                {
                    //build the string to create the table
                    //cmd.CommandText = "CREATE TABLE Headwords (hwid int(identity) PRIMARY KEY,headword varchar(50), pos varchar(50), pronunciation varchar(50), semfields varchar(50), usage varchar(50), xref varchar(50));";
                    StringBuilder sb = new StringBuilder();
                    sb.Append("Create Table Headwords (hwid INT IDENTITY(1,1) PRIMARY KEY,");
                    sb.Append("headword VARCHAR(50),");
                    sb.Append("pos VARCHAR(50),");
                    sb.Append("pronunciation VARCHAR(50),");
                    sb.Append("semfields VARCHAR(200),");
                    sb.Append("usage VARCHAR(200),");
                    sb.Append("xref VARCHAR(200))");
                    string query = sb.ToString();
                    cmd = new SqlCommand(query);

                    //connect again
                    using (conn = new SqlConnection(connstr))
                    {
                        //try to create the table
                        try
                        {
                            cmd.Connection = conn;
                            conn.Open();
                            cmd.ExecuteNonQuery();
                        }
                        catch (SqlException se)
                        {
                            MessageBox.Show(se.Message);
                        }
                    }
                }
            }
        }

        //---------------------------------------------------
        /* When the Check button is clicked, The word that is in the 
         * field is checked via the SpellChecker. If nothing is in the
         * field then a message asking for the user to enter something
         * is displayed.
        */
        private void checkBtn_Click(object sender, EventArgs e)
        {
            //Initialize a class instance
            try
            {
                string input = headField.Text; //Input is gotten from the field
                string output; //string where the output will be stored

                if (input == null || input.Length == 0) //check to see if anything is in the field
                {
                    output = "Please enter a word"; //output a message for user to enter a word
                }
                else
                {
                    output = SCheck.CheckSpelling(input); //setting the output equal to what is returned
                }
                MessageBox.Show(output); //Message is sent to the user
            }
            catch (SpellException s)
            {
                //if the exception has an inner exception then print out that error message as well
                if (s.InnerException != null)
                {
                    //error message
                    MessageBox.Show(s.GetMessage() + "\n" + s.InnerException.Message);
                }
                else
                {
                    //print out the message withour an inner exception
                    MessageBox.Show(s.GetMessage() + "\n Spell Exception");
                }
            }
        }

        //---------------------------------------------------
        /* This function overrides the OnPaint function to allow
         * us to create a custom title for the form.
        */
        protected override void OnPaint(PaintEventArgs e)
        {
            base.OnPaint(e);
            Font f = new Font(FontFamily.GenericSansSerif, 24); //Create Custom font
            Graphics g = e.Graphics;
            int width = ClientSize.Width; //get the width of the form
            float fMiddle = width / 2; //find the middle of the form
            SizeF w = g.MeasureString("Dictionary Editor", f); //get the size of the title
            float x = fMiddle - (w.Width / 2); //find the middle of the form and subtract it from the 
            //middle of the form
            g.DrawString("Dictionary Editor", f, Brushes.Turquoise, x, 9); // draw the title

            //Draws a border around the edge of the form
            ControlPaint.DrawBorder(g, this.ClientRectangle, Color.DarkBlue, 10, ButtonBorderStyle.Solid,
                Color.DarkBlue, 10, ButtonBorderStyle.Solid, Color.DarkBlue, 10, ButtonBorderStyle.Solid,
                Color.DarkBlue, 10, ButtonBorderStyle.Solid);
        }

        //---------------------------------------------------
        /* When the Exit button is clicked, close the program
        */
        private void exitBtn_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        //---------------------------------------------------
        /* This function fills the textBoxes with the inforamtion 
         * from the dll
        */
        protected void fillBox()
        {
            SemanticSocialAssister.SemanticSocial SB = new SemanticSocialAssister.SemanticSocial();
            //loop through the list stored in the SemanticSocial class
            for (int i = 0; i < SB.ListCount; i++)
            {
                //Add the next Semantic word to the Semantic text box
                semanBox.Items.Add(SB[i].Semantic);
                //Add the next Social word to the Social text box
                socialBox.Items.Add(SB[i].Social);
            }
            //set the oth item in the POS box to be selected as the default
            posField.SelectedIndex = 0;
        }

        //---------------------------------------------------
        /* This function gets the time which will be put into  
         * the label to be shown on the form.
        */
        public string GetTime()
        {
            string TimeString = "";
            int hour = DateTime.Now.Hour;
            int min = DateTime.Now.Minute;
            int sec = DateTime.Now.Second;


            TimeString = (hour < 10) ? "0" + hour.ToString() : hour.ToString();
            TimeString += ":" + ((min < 10) ? "0" + min.ToString() : min.ToString());
            TimeString += ":" + ((sec < 10) ? "0" + sec.ToString() : sec.ToString());
            return TimeString;
        }

        //---------------------------------------------------
        /* This function puts the time into the label that is
         * on the form.
        */
        void time_Tick(object sender, EventArgs e)
        {
            if (sender == time)
            {
                clockLabel.Text = GetTime();
            }
        }

        private void turnBt_Click(object sender, EventArgs e)
        {
            if (turnBt.Text == "Turn Words On")
            {
                SCheck.WordEvent += new SpellChecker.SpellCheck.WordEventHandler(WordEvent); //install event handler
                turnBt.Text = "Turn Words Off"; //set the text to "turn words off"
            }
            else if (turnBt.Text == "Turn Words Off")
            {
                SCheck.WordEvent -= new SpellChecker.SpellCheck.WordEventHandler(WordEvent); //Remove eventhandler
                turnBt.Text = "Turn Words On"; //set the text to "turn words on"
            }
        }
        //---------------------------------------------------
        /* The purpose of this function is to changes 
         * the color of the button to red. Sends all 
         * of the data from the WordEventArgs object to 
         * their appropiate locations then sets the button
         * color back to light grey
         */
        public void WordEvent(object sender, WordEventArgs wea)
        {
            for (int k = 0; k < semanBox.Items.Count; k++)
            {
                semanBox.SetSelected(k, false);
            }
            for (int k = 0; k < socialBox.Items.Count; k++)
            {
                semanBox.SetSelected(k, false);
            }

            string[] semiArray;
            string[] socialArray;

            //set button clor to red
            turnBt.BackColor = Color.Red;
            //wait one second
            Thread.Sleep(1000);

            //send the data to their fields
            headField.Text = wea.getHeadword;
            posField.Text = wea.getPos1;
            pronField.Text = wea.getPronunciation;
            refBox.Text = wea.getCross;

            semiArray = wea.getSemantic.Split(',');
            socialArray = wea.getSocial.Split(',');

            for (int j = 0; j < semiArray.Count(); j++)
            {
                for (int i = 0; i < semanBox.Items.Count; i++)
                {
                    if (semanBox.Items[i].ToString() == semiArray[j])
                    {
                        semanBox.SetSelected(i, true);
                    }
                }
            }

            for (int j = 0; j < socialArray.Count(); j++)
            {
                for (int i = 0; i < socialBox.Items.Count; i++)
                {
                    if (socialBox.Items[i].ToString() == socialArray[j])
                    {
                        socialBox.SetSelected(i, true);
                    }
                }
            }
            //change button back to light grey
            turnBt.BackColor = Color.LightGray;
        }

        //---------------------------------------------------
        /* The purpose of this function is to get the data 
         * and adds it to the datatable
         */
        private void addBtn_Click(object sender, EventArgs e)
        {
            // if the headword, POS, and definition do exist
            if (headField.Text != null && posField.Text != null && theHeadword.DefList.Count() > 0)
            {
                StringBuilder cmdstr = new StringBuilder();
                StringBuilder cmdstr2 = new StringBuilder();
                StringBuilder semanList = new StringBuilder();
                StringBuilder socialList = new StringBuilder();
                SqlCommand cmd;
                string head, pos, pron, xref;

                for (int i = 0; i < semanBox.Items.Count; i++)
                {
                    if (semanBox.GetSelected(i))
                    {
                        semanList.Append(semanBox.Items[i]);
                        semanList.Append(",");
                    }
                }

                for (int i = 0; i < socialBox.Items.Count; i++)
                {
                    if (socialBox.GetSelected(i))
                    {
                        socialList.Append(socialBox.Items[i]);
                        socialList.Append(",");
                    }
                }

                //get the information that will be passed to the database
                head = headField.Text;
                pos = posField.Text;
                pron = pronField.Text;
                xref = refBox.Text;

                SqlConnection conn;
                //set up the string to connect to the database
                ConnectionStringSettings settings = ConfigurationManager.ConnectionStrings["Dictionary"];
                string connstr = settings.ConnectionString;
                //using the connection
                using (conn = new SqlConnection(connstr))
                {
                    //open connection
                    conn.Open();
                    cmd = new SqlCommand();
                    cmd.Connection = conn;
                    //insert data to table
                    cmdstr.Append("INSERT INTO Headwords (headword, pos, pronunciation, semfields, usage, xref) ");
                    cmdstr.Append("VALUES (@hword, @pos, @pron, @sem, @usage, @xref)");
                    cmd.CommandText = cmdstr.ToString();
                    cmd.Parameters.AddWithValue("@hword", head);
                    cmd.Parameters.AddWithValue("@pos", pos);
                    cmd.Parameters.AddWithValue("@pron", pron);
                    cmd.Parameters.AddWithValue("@sem", semanList.ToString());
                    cmd.Parameters.AddWithValue("@usage", socialList.ToString());
                    cmd.Parameters.AddWithValue("@xref", xref);
                    cmd.ExecuteNonQuery();

                    // query database
                    cmd = new SqlCommand();
                    cmd.Connection = conn;
                    string query;
                    int result;
                    query = "SELECT MAX (hwid) FROM Headwords";
                    cmd.CommandText = query;
                    result = (int)cmd.ExecuteScalar();
                    for (int i = 0; i < theHeadword.DefList.Count(); i++)
                    {
                        if (theHeadword.DefList[i].Head == headField.Text)
                        {
                            theHeadword.DefList[i].Id = result++;
                        }
                    }

                    int tempDnum = 0;
                    for (int i = 0; i < theHeadword.DefList.Count(); i++)
                    {
                        if (theHeadword.DefList[i].Head == headField.Text)
                        {
                            if (tempDnum <= theHeadword.DefList[i].dNum)
                            {
                                tempDnum = theHeadword.DefList[i].dNum;
                            }
                        }
                    }

                    //insert definitions into table
                    for (int i = 0; i < theHeadword.DefList.Count(); i++)
                    {
                        if (theHeadword.DefList[i].Head == headField.Text)
                        {
                            cmdstr = new StringBuilder();
                            tempDnum++;
                            cmdstr.Append("INSERT INTO Definitions VALUES (@hwid, @hword, @defnum, @pos, @definition, @shortdef)");
                            cmd.CommandText = cmdstr.ToString();
                            cmd.Parameters.AddWithValue("@hwid", theHeadword.DefList[i].Id);
                            cmd.Parameters.AddWithValue("@hword", theHeadword.DefList[i].Head);
                            cmd.Parameters.AddWithValue("@defnum", theHeadword.DefList[i].dNum);
                            cmd.Parameters.AddWithValue("@pos", theHeadword.DefList[i].POS);
                            cmd.Parameters.AddWithValue("@definition", theHeadword.DefList[i].Def);
                            cmd.Parameters.AddWithValue("@shortdef", theHeadword.DefList[i].sDef);
                            cmd.ExecuteNonQuery();

                            //insert illustrations into table
                            for (int j = 0; j < theHeadword.DefList[i].IllList.Count(); j++)
                            {
                                if (theHeadword.IllList[j].hword == headField.Text)
                                {
                                    theHeadword.IllList[j].hwid = theHeadword.DefList[i].Id;
                                    cmdstr2 = new StringBuilder();
                                    cmdstr2.Append("INSERT INTO Illustrations VALUES (@illhwid, @illhword, @illdefnum, @illus, @trans, @illnum)");
                                    cmd.CommandText = cmdstr2.ToString();
                                    cmd.Parameters.AddWithValue("@illhwid", theHeadword.IllList[j].hwid);
                                    cmd.Parameters.AddWithValue("@illhword", theHeadword.IllList[j].hword);
                                    cmd.Parameters.AddWithValue("@illdefnum", theHeadword.IllList[j].defnum);
                                    cmd.Parameters.AddWithValue("@illus", theHeadword.IllList[j].illustration);
                                    cmd.Parameters.AddWithValue("@trans", theHeadword.IllList[j].translation);
                                    cmd.Parameters.AddWithValue("@illnum", theHeadword.IllList[j].illnum);
                                    cmd.ExecuteNonQuery();
                                }
                            }
                        }
                    }

                    addBtn.Enabled = false;
                    adefBtn.Enabled = false;
                }
            }
            //if the headword, POS, and definition do not exist
            else
            {
                MessageBox.Show("Cannot procede until there is a headword, POS, and at least one definition");
            }
        }

        //---------------------------------------------------
        /* The purpose of this function is to clear all the fields, 
         * list boxes, and enable buttons when clicked.
         */
        private void clearBtn_Click(object sender, EventArgs e)
        {
            //clear text boxes
            semanBox.Text = null;
            headField.Text = null;
            socialBox.Text = null;
            pronField.Text = null;
            refBox.Text = null;
            posField.SelectedIndex = 0;

            //unselect in the list box
            for (int i = 0; i < semanBox.Items.Count; i++)
            {
                if (semanBox.GetSelected(i))
                {
                    semanBox.SetSelected(i, false);
                }
            }
            for (int i = 0; i < socialBox.Items.Count; i++)
            {
                if (socialBox.GetSelected(i))
                {
                    socialBox.SetSelected(i, false);
                }
            }

            //enable the buttons
            addBtn.Enabled = true;
            adefBtn.Enabled = true;
            //focus the cursor on the headword field
            Headword theHeadword = new Headword();
            //create a new headword opbject
            headField.Focus();
        }

        //---------------------------------------------------
        /* The purpose of this method is to start the 
         * Definition form. 
         */
        private void adefBtn_Click(object sender, EventArgs e)
        {
            if (headField.Text != "")
            {
                //set the headword for the headword object
                Headword hw = new Headword();
                hw.hword = headField.Text;
                int i = posField.SelectedIndex;
                //start a new instance of the definition form
                DefinitionForm defForm = new DefinitionForm(this, ref hw, i);
                defForm.Show();
            }
            else
            {
                MessageBox.Show("You need to enter a Headword.");
            }
        }
    }
}
