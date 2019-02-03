/***********************************************************************/
/*                                                                     */
/*  Programmer:  Joe Daniel Parker             Z-ID:  Z-158012         */
/*                                                                     */
/*  CSCI 210 - Section 4                                               */
/*                                                                     */
/*  T.A.:  Anusha Gaddam                                               */
/*                                                                     */
/*  Due Date:  11 October  , 2007                                      */
/*                                                                     */
/*  Assignment No. 5                                                   */
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

public class asgn5

{
       
        public static void main(String[] args)                
       
        	{                        
              
               final double TAX_RATE = 0.075;      /* This declares a constant for computing tax amount.  */	       
              
               final double DISCOUNT_RATE = 0.08;  /* This declares the constant for discount rate.       */
              
               int Length, Width,   			   /* These are the total dimensions of the room.         */
               	   TotalLength = 0, TotalWidth = 0;        /* These are the total dimensions of the room.         */
                                 		  		   /* carpeting.                                          */
              
               int choice,						   /* Choice for extra room(s) - 1 equals "yes"           */
               	   RoomNumber = 0;					   /* Total Number of rooms so far.                       */
              
               int AreaFeet,					   /* Area of the room in square feet.                    */
               	   TotalAreaFeet = 0; 				   /* Total Area of the room in square feet.              */
             
               double AreaYards,   				   /* Area of the room in square yards.                   */
             		  TotalAreaYards = 0; 		       /* Total Area of the room in square yards.             */
             
               double CarpetCost, 				   /* This is the cost of the carpeting itself.           */ 
               		  TotalCarpetCost = 0;  		   /* This is the Total cost of the carpeting itself.     */               
             
               double Cost,       				   /* This is the cost per square yard of carpeting       */
               		  TotalCost = 0;        		   /* This is the Total cost per square yard of carpeting */               
             
               double Discount,					   /* Discount amount if there is one.                    */
               		  TotalDiscount = 0;    		   /* Total Discount amount if there is one.              */               
             
               double SalesTax, 		   		   /* Sales tax amount.                                   */
               		  TotalSalesTax = 0;   			   /* Total Sales tax amount.                             */
             
               Scanner scan = new Scanner(System.in);   /* Declare a new instance of the scanner class. */ 
               
               /* <1> Prompt for and get the room's length. */
               
               do
               {
               System.out.print("\nPlease enter the length of the room in whole feet: ");
               
               Length = scan.nextInt();
               TotalLength = TotalLength + Length;              
               
               /* <2> Prompt for and get the room's width. */ 
               
               System.out.print("\nPlease enter the width of the room in whole feet: ");
               
               Width = scan.nextInt();
               TotalWidth = TotalWidth + Width;
               
               /* <3> Prompt for and get the cost per square yard of carpeting. */                  
               
               System.out.print("\nPlease enter the cost per square yard of carpeting: $");
               
               Cost = scan.nextDouble();
               TotalCost = TotalCost + Cost;
               	
               /* <4> Compute the area in square feet of the room. */

			   AreaFeet = Length * Width;
			   TotalAreaFeet = TotalAreaFeet + AreaFeet;
			   
               /* <5> Compute the area in square yards of the room */
 
 			   AreaYards = AreaFeet / 9.0;
 			   TotalAreaYards = TotalAreaYards + AreaYards;
 			   
               /* <6> Compute the cost to carpet the room. */                    
               
               CarpetCost = AreaYards * Cost;
               TotalCarpetCost = TotalCarpetCost + CarpetCost;
               	
               /* <7> Compute the discount if there is one using an if statement. */

			   Discount = 0;
			   	
			   if ( AreaFeet > 500 )
			   {
			   	Discount = CarpetCost * DISCOUNT_RATE;
			   }
			   
			   TotalDiscount = TotalDiscount + Discount;
			   
               /* <8> Compute the sales tax amount based on the cost after discount if there is one. */
 
 			   SalesTax = (CarpetCost - Discount) * TAX_RATE;
 			   TotalSalesTax = TotalSalesTax + SalesTax;
 			   
               /* <9> Print program header message. */
              
               System.out.print("\n\n     CSCI 210  -  Java Assignment 5");            
               System.out.print("\n   **********************************");                        
               System.out.print("\n        Cost of Carpeting a Room");               
               System.out.print("\n   **********************************\n"); 
               
               /* <10> Print the report lines. */
 			   
 			   System.out.printf("\nLength of the room    =%7d    feet", Length);
 			   System.out.printf("\nWidth of the room     =%7d    feet", Width);
 			   System.out.printf("\nCost per square yard  =%10.2f dollars", Cost);
 			   System.out.printf("\nArea in square feet   =%7d", AreaFeet);
 			   System.out.printf("\nArea in square yards  =%10.2f", AreaYards);
 			   System.out.printf("\nCost of carpeting     =%10.2f dollars", CarpetCost);
 			   System.out.printf("\nDiscount              =%10.2f dollars", Discount);
 			   System.out.printf("\nSales Tax             =%10.2f dollars", SalesTax);
 			   System.out.printf("\nTotal Cost            =%10.2f dollars", CarpetCost - Discount + SalesTax);
 			   
               /* <11> Print the program ending message. */
               
               System.out.print ("\n\nWould you like to enter another room? ");
               
               choice = scan.nextInt();
               RoomNumber ++;
               }
               while(choice == 1);
               
               System.out.printf("\n      Number of rooms =%7d", RoomNumber);
 			   System.out.printf("\n       Total Discount =%10.2f dollars", TotalDiscount);
 			   System.out.printf("\n      Total Sales Tax =%10.2f dollars", TotalSalesTax);
 			   System.out.printf("\n           Total Cost =%10.2f dollars", TotalCarpetCost - TotalDiscount + TotalSalesTax);
 			   System.out.printf("\nAverage Cost per Room =%10.2f dollars", (TotalCarpetCost - TotalDiscount + TotalSalesTax) / RoomNumber);
               System.out.print("\n\n       End of Carpet Cost Report");
               System.out.print("\n   **********************************\n\n");
        }
}        
