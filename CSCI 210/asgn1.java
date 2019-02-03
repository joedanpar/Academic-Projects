/******************************************************/
/*                                                    */ 
/*  Name:  Dan Parker                                 */
/*  CSCI 210 – Section 4                              */
/*  Date:  09/06/07                                   */
/*  Assignment No. 1                                  */
/*                                                    */
/******************************************************/

import java.util.Scanner;     // Import the Java Scanner class. 
                              // Do not flowchart this as it is Java specific.
public class asgn1
{
   public static void main (String[] args)
   {
      int    A, B = 9, C;     // Declare three integer variables setting B to 9.  
                              // These will be in process rectangles on a flowchart.
      double X = 12.5,        // Declare three double floating point variables setting X to 12.5.
             Y,               // Use another process box for these three declarations. 
             Z;
 
      /* Create a new object of the Scanner class to   */
      /* read date entered by the user at the keyboard */          

      Scanner scan = new Scanner(System.in);   // This does not show up in a flowchart either.

      /* Print program header message */

      System.out.println("***********************************");    // Combine these four outputs into one
      System.out.println("   CSCI 210 - Assignment No. 1     ");    // parallelogram in the flowchart with
      System.out.println("  written by Dan Parker    ");            // "DISPLAY GREETING" or "DISPLAY REPORT
      System.out.println("***********************************\n");  // HEADER" inside it.

      /* Perform computations and print the results */

      System.out.print("Please enter an integer: ");   // This is output: "PROMPT USER TO ENTER AN INTEGER"     

      A = scan.nextInt();                        // This is input to get the integer entered by the user:
                                                 // "GET USER'S INTEGER INTO VARIABLE A"
      
      System.out.printf("\nThe integer you entered was %d.\n", A);  // Output: "DISPLAY USER'S INTEGER" 
      
      Y = 5.75;           // An assignment statement.  Should get its own process box or can be combined
                          // with the two arithmetic statements that follow.
      C = A / B;          // Two arithmetic statements.  Combine into a single process box.
      Z = X / Y;

      // The following should each get their own output parallelograms in a flowchart 
      // as some do calculations.  All are output.  They can be combined into a single output 
      // parallelogram too.  Note in the third and fourth of these next five statements that
      // C and Z hold the results of the two arithmetic statements above and they are being used
      // in the output instead of doing the arithmetic in the output statement itself.
                  
      System.out.printf("\nThe sum of %d and %d is %d.", A, B, A + B);
      System.out.printf("\nThe difference of %d and %d is %d.", B, A, B - A);
      System.out.printf("\nThe quotient of %d divided by %d is %d.", A, B, C);
      System.out.printf("\nThe quotient of %f divided by %f is %f.", X, Y, Z);
      System.out.printf("\nThe product of %d and %f is %f.", B, X, B * X);
 
      /* Print program trailer message.  Should get its own output parallelogram.  */

      System.out.println("\n\nEnd of Program Execution\n");
 
      }
}
