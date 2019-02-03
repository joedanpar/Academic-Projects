/***********************************************************************/
/*                                                                     */
/*  Programmer:  Joe Dan Parker                   Z-ID:  158012        */
/*                                                                     */
/*  CSCI 210 - Section 4                                               */
/*                                                                     */
/*  T.A.:  Anusha Gaddam                                               */
/*                                                                     */
/*  Due Date:  09/21/07                                                */
/*                                                                     */
/*  Assignment No. 2 - Part C                                          */
/*                                                                     */
/*  Purpose:  This program prompts and gets three integers from the    */
/*            user.  These numbers represent the measurements of the   */
/*            three sides of a box (Length, Width, and Height).  The   */
/*            program then computes and prints the surface area and    */
/*            volume of the box.                                       */
/*                                                                     */
/***********************************************************************/

import java.util.Scanner;         /* Declare an object of the Scanner class
                                     to be able to get user input of integers */

public class asgn2c
{
   public static void main(String[] args)
   {
          
      int L,           // Length of the box
          W,           // Width  of the box
          H,           // Height of the box    
          Area,        // Area of the box to be calculated
          Volume;      // Volume of the box to be calculated
 
      Scanner scan = new Scanner(System.in);
 
      System.out.print("Please enter an integer for length: ");
      
      L = scan.nextInt();    // Get the length of the box

	  System.out.print("Please enter an integer for width: ");
      
      W = scan.nextInt();    // Get the width of the box

	  System.out.print("Please enter an integer for height: ");
      
      H = scan.nextInt();    // Get the height of the box

	  Volume = L * W * H;    // Calculate the volume of the box
	  
	  Area = 2* ((L * W) + (L * H) + (W * H));
                             // Calculate the surface area of the box
                             
                             /* Print program header messages */
  
      System.out.print("\n\n             CSCI 210 - Assignment No. 2 - Part C");
      System.out.print("\n             **************************************");
      System.out.print("\n               Area and Volume of a Box in Inches");
      System.out.print("\n             **************************************\n\n");
	  System.out.printf("\n                     Length of the box: %6d", L);
	  System.out.printf("\n                      Width of the box: %6d", W);
	  System.out.printf("\n                     Height of the box: %6d", H);
	  System.out.printf("\n               Surface Area of the box: %6d", Area);
	  System.out.printf("\n                     Volume of the box: %6d", Volume);
	 
      /* Print program trailer messages */
     
      System.out.print("\n\n                     End of Program Output");
      System.out.print("\n             **************************************\n\n");
   }
}
