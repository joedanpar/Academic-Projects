/* The purpose of this program is to hold the thress classes which will
 * be used by the forms to enter data into the database. The three classes
 * are the Headword, Definition, and Illustration class.
 * 
 * 03/26/11- Started creating all classes
 * 03/27/11- Finalized the classes and their gets and sets
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
using System.Data.SqlClient;

namespace DictionaryEdit
{

    //---------------------------------------------------
    /* This is the Headword class. It holds the infromation
     * for a Headwords as would be needed to add to a database
     * table. It contains get, set and add methods.
     */
    public class Headword
    {
        public string hword, pos, pronunciaton, semantic, social, crossref;
        public List<Definition> DefList;
        public List<Illustration> IllList;
        public Headword()
        {
            DefList = new List<Definition>();
            IllList = new List<Illustration>();
        }
        public string Head
        {
            get { return hword; }
            set { hword = value; }
        }
        public string POS
        {
            get { return pos; }
            set { pos = value; }
        }

    }

    //---------------------------------------------------
    /* This is the Definition class. It holds the infromation
     * for a Definition as would be needed to add to a database
     * table. It contains get, set and add methods.
     */
    public class Definition
    {
        string hword, pos, definition, shortdef;
        int hwid, defnum;
        public List<Illustration> IllList;

        public Definition()
        {
            IllList = new List<Illustration>();
        }

        public string Head
        {
            get { return hword; }
            set { hword = value; }
        }
        public string POS
        {
            get { return pos; }
            set { pos = value; }
        }
        public string Def
        {
            get { return definition; }
            set { definition = value; }
        }
        public string sDef
        {
            get { return shortdef; }
            set { shortdef = value; }
        }
        public int Id
        {
            get { return hwid; }
            set { hwid = value; }
        }
        public int dNum
        {
            get { return defnum; }
            set { defnum = value; }
        }

    }

    //---------------------------------------------------
    /* This is the Illustration class. It holds the infromation
     * for a Illustration as would be needed to add to a database
     * table. It contains get, set and add methods.
     */
    public class Illustration
    {
        public string illustration, translation, hword;
        public int hwid, defnum, illnum, id;

        public Illustration()
        { }

        public string getIll
        { get { return illustration; } }

        public string getTrans
        { get { return translation; } }

        public int setIllNum
        { set { illnum = value; } }
    }
}