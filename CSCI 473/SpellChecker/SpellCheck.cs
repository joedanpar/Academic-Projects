/* The purpose of this program is to create the SpellCheck Class. This
 * class will be called in the DictionaryEdit program to check to see if
 * the word in the Field is in the Dictionary and if it is spelled correctly.
 * If it is not in the Dictionarry the user it notified.
 * 
 * 01/30/11 - Began work on the  program that included
 * 02/12/11 - Added Exceptions to CheckSpelling funciton
 *            and added SpellException Class
 * 02/13/11 - Added Comments
 * 
 * Programmer: K. Johnson, B. Kesler, D. Parker Current: 02/13/11
 */

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Reflection;
using System.Runtime.Serialization;
using System.Security.Permissions;
using System.Threading;

namespace SpellChecker
{
    /// <summary>
    /// This is the one and only class used in this program.
    /// It compares the input from the field to that of 
    /// the text file. It then returns a string with information
    /// it found or that the word is not in the text file.
    /// </summary>
    /// 

    public class SpellCheck
    {
        List<string> spellList = new List<string>(); //list where the words are kept to be compared for spelling
        List<WordEventArgs> defineList = new List<WordEventArgs>(); //list of word definitions
        string string1;

        //delegate for the event
        public delegate void WordEventHandler(object sender, WordEventArgs wea);
        //event for the WordEventArgs
        public event WordEventHandler WordEvent;


        /* This method get a random WordEventArgs from the readList 
         * and the fires the event
         */
        public void RandWordEvent(Object sender)
        {
            Random random = new Random();
            int randomNum = random.Next(0, defineList.Count());
            if (WordEvent != null)
            {
                WordEvent(sender, defineList[randomNum]);
            }
        }

        //---------------------------------------------------
        /* This function reads the list of words from the text
         * file and puts them in a list for them to be compared
         * later on.
        */
        public SpellCheck() : base()
        {
            using (StreamReader reader = new StreamReader("WordList.txt"))
            {
                string line;
                while ((line = reader.ReadLine()) != null)
                {
                    spellList.Add(line);          // Add to list.
                }
            }
            ReadDefinition();

            //timer delegate useing the OnWordEvent method
            TimerCallback timerDelegate = new TimerCallback(RandWordEvent);

            //Timer that calls the WordEvent every 10 seconds
            Timer time = new Timer(timerDelegate, WordEvent, 10000, 10000);
        }

        //---------------------------------------------------
        /* This function reads the list of words from the text
         * file of definitions and puts them in a list.
        */
        public void ReadDefinition()
        {
            //read the file in
            StreamReader read = new StreamReader("WordDefinitions.txt");
            string line;
            string[] array;

            //loop through until the end of the file
            while((line = read.ReadLine()) != null)
            {
                //parse the line of the file
                array = line.Split('*');
                //store the parsed parts into a WordEventArgs object
                WordEventArgs args = new WordEventArgs(array[0], array[1], array[2], array[3], array[4], array[5], array[6], array[7], array[8], array[9]);
                //add it to the list
                defineList.Add(args);
            }
            read.Close();
        }

        //---------------------------------------------------
        /* Checks the spelling of the inputted string (from user)
         * with the words in the list. It will return a string
         * saying Invalid spelling if the input doesn't match,
         * otherwise it will return a string with more information.
        */
        public string CheckSpelling(String s)
        {
           int first = 10; //for divide by zero
           int second = 0; //for divide by zero

           //Throw Exception if the word is "aaa"
           if (s == "aaa")
           {
               throw new SpellException("Word was aaa");
           }
           //Divide by zero if the word is "bbb"
           if (s == "bbb")
           {
               first = first / second;
           }
           //Try to divide by zero if the word is "ccc"
           //and then throw a SpellException
           if (s == "ccc")
           {
               try
               {
                   first = first / second;
               }
               catch (DivideByZeroException d)
               {
                   throw new SpellException(this.ToString(), "Word was ccc", d);
               }
           }
           for (int i = 0; i < spellList.Count; i++) //loop thorugh list
           {
               if (spellList[i] != s.ToLower()) //compare if the word is not in the list
               {
                   string1 = "Invalid Spelling"; //output
               }
               else //if the word is not in the list
               {
                   Assembly a = Assembly.GetExecutingAssembly(); //get the information
                   string name = a.FullName;  //convert the name to string
                   string1 = "Word " + s + " is spelled correctly." + "\nFullname: " + name + "\nVersion: " + Version(); //output
                   return string1; //break from loop and return the output
               }
           }
           return string1; 
        }

        //---------------------------------------------------
        /* This function finds the version number and returns
         * it. Ths function is called by the CheckSpelling 
         * function.
        */
        public string Version()
        {
            Assembly a = Assembly.GetExecutingAssembly(); //get the information
            string version = a.GetName().Version.ToString(); //convert the number to string
            return version; //return version number
        }
    }

    /* This class is the SpellException Class that will throw an
     * exception if certain requirements are met.
     */
    public class SpellException : ApplicationException
    {
        protected String str; //Ctring for error message

        //First base constructor
        public SpellException() : base()
        {
        }
        //Second constructor. Takes an error message string
        public SpellException(String s) : base(s)
        {
            str = s;
        }
        //Third constructor. Takes an error message string,
        //and an inner exception
        public SpellException(String s, Exception inner) : base(s, inner)
        {
            str = s;
        }
        //Fourth constructor. Takes an error message string,
        //a string property "sender" and an inner eceptions
        public SpellException(String sender, String s, Exception inner) : base(s, inner)
        {
            str = s;
        }
        //string property "Sender"
        public String Sender
        {
            get
            {
                return Sender;
            }
            set
            {
                Sender = value;
            }
        }
        //returns the message for the error
        public String GetMessage()
        {
            return str;
        }
    }

    /* This class is the WordEventArgs Class that will hold the 
     * infromation from the WordDefinition.txt
     */
    public class WordEventArgs : EventArgs
    {
        string headword, pos1, pronunciation, SemanticFields, SocialUsage, CrossReferences, defNum, pos2, definition, shortDef;

        //constuctor sets the variables
        public WordEventArgs(string h, string poss, string pro, string sem, string social, string reff, string num, string poss2, string def, string sDef)
        {
            headword = h;
            pos1 = poss;
            pronunciation = pro;
            SemanticFields = sem;
            SocialUsage = social;
            CrossReferences = reff;
            defNum = num;
            pos2 = poss2;
            definition = def;
            shortDef = sDef;
        }

        //property to get the headword
        public string getHeadword
        {
            get
            {
                return headword;
            }
        }
        //property to get the pos1
        public string getPos1
        {
            get
            {
                return pos1;
            }
        }
        //property to get the pronunciation
        public string getPronunciation
        {
            get
            {
                return pronunciation;
            }
        }
        //property to get the semantic fields
        public string getSemantic
        {
            get
            {
                return SemanticFields;
            }
        }
        //property to get the social usages fields
        public string getSocial
        {
            get
            {
                return SocialUsage;
            }
        }
        //property to get the cross references
        public string getCross
        {
            get
            {
                return CrossReferences;
            }
        }
    }
}
