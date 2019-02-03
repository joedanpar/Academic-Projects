/* The purpose of this program is to make the form visible and to start the program
 * running.
 * 
 * 01/30/11 - Created by Visual Studios
 * 02/12/11 - Added Application_ThreadException function
 * 02/13/11 - Added Comments
 * Programmer: K. Johnson, B.Kesler, D. Parker  Current: 02/13/11
 */

using System;
using System.Collections.Generic;
using System.Linq;
using System.Windows.Forms;
using System.Drawing;
using System.Threading;
using System.Diagnostics;
using System.IO;

namespace DictionaryEdit
{
    static class Program 
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);

            Application.ThreadException += new System.Threading.ThreadExceptionEventHandler(Application_ThreadException);

            DictionaryEditor f = new DictionaryEditor();
            Application.Run(f);
        }

        //---------------------------------------------------
        /* the purpose of this function is to handle all other 
         * Exceptions that are not handled by the exceptions
         * in the DictionaryEditor and SpellChecker.
        */
        static void Application_ThreadException(object sender, System.Threading.ThreadExceptionEventArgs e)
        {
            //StreamWriter to write to the file
            StreamWriter outFile;

            //Use ToFile to append to the text file Error_Log
            outFile = File.AppendText("Error_Log.txt");
            //Write the date and exception to the4 file
            outFile.WriteLine(DateTime.Now + "    " + e.Exception.Message);
            //close the file
            outFile.Close();

            //message box displays that the program has encountered an error and gives
            //the user the option to restart the program
            DialogResult results = MessageBox.Show("The Diconary Editor has encountered a fatal error: \n "
               + e.Exception.Message + "\n Start the program over?", "Error", MessageBoxButtons.YesNo);
            //if the user chooses yes then kill the current process and start a new one
            if (results == DialogResult.Yes)
            {
                //String with the process name
                string s = Process.GetCurrentProcess().ProcessName + ".exe";

                //get the process to destory
                Process destroy = Process.GetCurrentProcess();

                //create a new process
                Process life = new Process();
                //set the new process file name to that of the old process
                life.StartInfo.FileName = s;

                //start a new instance of this process
                life.Start();
                //end the old process
                destroy.Kill();
            }
        }
    }
}