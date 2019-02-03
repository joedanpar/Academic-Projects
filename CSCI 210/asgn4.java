/***********************************************************************/
/*                                                                     */
/*  Programmer:  Joe Daniel Parker             Z-ID:  Z-158012         */
/*                                                                     */
/*  CSCI 210 - Section 4                                               */
/*                                                                     */
/*  T.A.:  Anusha Gaddam                                               */
/*                                                                     */
/*  Due Date:  05 October  , 2007                                      */
/*                                                                     */
/*  Assignment No. 4                                                   */
/*                                                                     */
/*  Purpose:  This program prompts and gets two integers from the      */
/*            user.  These numbers represent the measurements of the   */
/*            length and width of a room (Length and Width).  The      */
/*            program then computes and prints the cost of carpeting   */
/*            for the room, including tax.  If the area is large       */
/*            enough, add in a discount as well as the tax rate.       */
/*                                                                     */
/***********************************************************************/

import java.util.Scanner;    /* Import the Java Scanner class to get input entered at the keyboard. */

public class asgn4

{
       
        public static void main(String[] args)                
       
        	{                        
              
               final double TAX_RATE = 0.075;  /* This declares a constant for computing tax amount. */	       
              
               final double DISCOUNT_RATE = 0.08;  /* This declares the constant for discount rate.  */
              
               int Length, Width;   /* These are the dimensions of the room.         */
                                    /* carpeting.                                    */
              
               int AreaFeet;        /* Area of the room in square feet.              */
             
               double AreaYards;    /* Area of the room in square yards.             */
             
               double CarpetCost;   /* This is the cost of the carpeting itself.     */               
             
               double Cost;         /* This is the cost per square yard of carpeting */               
             
               double Discount;     /* Discount amount if there is one.              */               
             
               double SalesTax;     /* Sales tax amount.                             */
             
               Scanner scan = new Scanner(System.in);   /* Declare a new instance of the scanner class. */ 
               
               /* <1> Prompt for and get the room's length. */
               
               System.out.print("\nPlease enter the length of the room in whole feet: ");
               
               Length = scan.nextInt();              
               
               /* <2> Prompt for and get the room's width. */ 
               
               System.out.print("\nPlease enter the width of the room in whole feet: ");
               
               Width = scan.nextInt();
               
               /* <3> Prompt for and get the cost per square yard of carpeting. */                  
               
               System.out.print("\nPlease enter the cost per square yard of carpeting: $");
               
               Cost = scan.nextDouble();
               	
               /* <4> Compute the area in square feet of the room. */

			   AreaFeet = Length * Width;
			   
               /* <5> Compute the area in square yards of the room */
 
 			   AreaYards = AreaFeet / 9.0;
 			   
               /* <6> Compute the cost to carpet the room. */                    
               
               CarpetCost = AreaYards * Cost;
               	
               /* <7> Compute the discount if there is one using an if statement. */

			   Discount = 0;
			   	
			   if ( AreaFeet > 500 )
			   {
			   	Discount = CarpetCost * DISCOUNT_RATE;
			   }
			   
               /* <8> Compute the sales tax amount based on the cost after discount if there is one. */
 
 			   SalesTax = (CarpetCost - Discount) * TAX_RATE;
 			   
               /* <9> Print program header message. */
              
               System.out.print("\n\n    CSCI 210  -  Java Assignment 4");               
              
               System.out.print("\n  **********************************");               
              
               System.out.print("\n       Cost of Carpeting a Room");               
              
               System.out.print("\n  **********************************\n"); 
               
               /* <10> Print the report lines. */
 			   
 			   System.out.printf("\nLength of the room   =%7d    feet", Length);
 			   System.out.printf("\nWidth of the room    =%7d    feet", Width);
 			   System.out.printf("\nCost per square yard =%10.2f dollars", Cost);
 			   System.out.printf("\nArea in square feet  =%7d", AreaFeet);
 			   System.out.printf("\nArea in square yards =%10.2f", AreaYards);
 			   System.out.printf("\nCost of carpeting    =%10.2f dollars", CarpetCost);
 			   System.out.printf("\nDiscount             =%10.2f dollars", Discount);
 			   System.out.printf("\nSales Tax            =%10.2f dollars", SalesTax);
 			   System.out.printf("\nTotal Cost           =%10.2f dollars", CarpetCost - Discount + SalesTax);
 			   
               /* <11> Print the program ending message. */
               
               System.out.print("\n\n      End of Carpet Cost Report");
               System.out.print("\n  **********************************\n\n");
        }
}        
