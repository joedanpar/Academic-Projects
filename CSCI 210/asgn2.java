/******************************************************/
/*                                                    */ 
/*  Name:  Dan Parker                                 */
/*  CSCI 210 – Section 4                              */
/*  Date:  09/19/07                                   */
/*  Assignment No. 2                                  */
/*                                                    */
/******************************************************/

import java.util.Scanner;

public class asgn2
{
	public static void main (String[] args)
	{
      int    L,     // length of box.
      		 W,     // width of box.
      		 H,     // height of box.  
             A,     // surface area of box.
             V;     // volume of box.
      Scanner scan = new Scanner(System.in);

      System.out.println("***********************************");
      System.out.println("    CSCI 210 - Assignment No. 2    ");
      System.out.println("       written by Dan Parker       ");        
      System.out.println("***********************************\n");

      System.out.print("Please enter an integer for the length of a box: ");     

      L = scan.nextInt();
      
      System.out.printf("\nThe integer you entered was %d, please enter another integer fo the width of the box: ", L); 
      
      W = scan.nextInt();
      
      System.out.printf("\nThe integer you entered was %d, please enter another integer fo the height of the box: ", W);

	  H = scan.nextInt();

      System.out.printf("\nThe integer you entered was %d.  Now calculating...", H);
      
      A = 2*((L*W)+(L*H)+(W*H));
      V = L*W*H;
      	
      System.out.printf("\n\nThe box's dimensions are: %d x %d x %d.", L, W, H);
      System.out.printf("\nThe box's total surface area is: %d.", A);
      System.out.printf("\nThe box's volume is: %d.", V);
 
      System.out.println("\n\nEnd of Program.\n");
 
      }
}
