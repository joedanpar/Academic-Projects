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
/*  Assignment No. 6                                                   */
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
import java.io.*;

public class asgn6

{
       
        public static void main(String[] args) throws IOException
       
        	{                        
              
			   String RoomName = null,  // name of room being processed
			   		  Record;    // current line of record being processed
			   		  
			   Scanner fileScan,   // instance of the scanner class, reads each line of input file
			   		   RecordScan; // another instance, manipulates the input read by fileScan
			   		  
               final double TAX_RATE = 0.075;      /* This declares a constant for computing tax amount.  */	       
              
               final double DISCOUNT_RATE = 0.08;  /* This declares the constant for discount rate.       */
              
               int Length, Width,   			   /* These are the total dimensions of the room.         */
               	   TotalLength = 0, TotalWidth = 0;        /* These are the total dimensions of the room.         */
                                 		  		   /* carpeting.                                          */
              
               int RoomNumber = 0;				   /* Total Number of rooms so far.                       */
              
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
             
               fileScan = new Scanner (new File("carpet.txt"));   /* Declare a new instance of the scanner class. */ 
               
               System.out.print("\n\n     CSCI 210  -  Java Assignment 6");            
               System.out.print("\n   **********************************");                        
               System.out.print("\n    Cost of Carpeting multiple Rooms");               
               System.out.print("\n   **********************************\n");
               
			   while (fileScan.hasNext())
               {
               
                 Record = fileScan.nextLine();
                 
                 RecordScan = new Scanner (Record); 
                 
                 RoomName = RecordScan.next();
                 
                 Length = RecordScan.nextInt();
                 TotalLength = TotalLength + Length;              
                
                 Width = RecordScan.nextInt();
                 TotalWidth = TotalWidth + Width;
               
                 Cost = RecordScan.nextDouble();
                 TotalCost = TotalCost + Cost;
               	
               	 AreaFeet = Length * Width;
			     TotalAreaFeet = TotalAreaFeet + AreaFeet;
			    
			     AreaYards = AreaFeet / 9.0;
 			     TotalAreaYards = TotalAreaYards + AreaYards;
 			    
 			     CarpetCost = AreaYards * Cost;
                 TotalCarpetCost = TotalCarpetCost + CarpetCost;
               
               	 Discount = 0;
			   	
			   if ( AreaFeet > 500 )
			   {
			   	Discount = CarpetCost * DISCOUNT_RATE;
			   }
			   
			   TotalDiscount = TotalDiscount + Discount;
			   
			   SalesTax = (CarpetCost - Discount) * TAX_RATE;
 			   TotalSalesTax = TotalSalesTax + SalesTax; 
               
               System.out.printf("\nName of the Room      = %s", RoomName);
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
               
               RoomNumber ++;
               System.out.println("");
               }
               
               System.out.printf("\n      Number of rooms =%7d", RoomNumber);
 			   System.out.printf("\n       Total Discount =%10.2f dollars", TotalDiscount);
 			   System.out.printf("\n      Total Sales Tax =%10.2f dollars", TotalSalesTax);
 			   System.out.printf("\n           Total Cost =%10.2f dollars", TotalCarpetCost - TotalDiscount + TotalSalesTax);
 			   System.out.printf("\nAverage Cost per Room =%10.2f dollars", (TotalCarpetCost - TotalDiscount + TotalSalesTax) / RoomNumber);
               System.out.print("\n\n       End of Carpet Cost Report");
               System.out.print("\n   **********************************\n\n");
        }
}        
