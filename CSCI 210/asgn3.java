/***********************************************************************/
/*                                                                     */
/*  Programmer:  Joe Daniel Parker             Z-ID:  Z-158012         */
/*                                                                     */
/*  CSCI 210 - Section 4                                               */
/*                                                                     */
/*  T.A.:  Anusha Gaddam                                               */
/*                                                                     */
/*  Due Date:  28 September, 2007                                      */
/*                                                                     */
/*  Assignment No. 3                                                   */
/*                                                                     */
/*  Purpose:  This program prompts and gets two integers from the      */
/*            user.  These numbers represent the measurements of the   */
/*            length and width of a room (Length and Width).  The      */
/*            program then computes and prints the cost of carpeting   */
/*            for the room.                                            */
/*                                                                     */
/***********************************************************************/
 
import java.util.Scanner;   /* Import the Java Scanner class to get input entered at the keyboard. */
      
public class asgn3
{
        public static void main(String[] args)        
        {      
               int Length, Width;   /* These are the dimensions of the room.       */
               double Cost;         /* This is the cost per square yard of         */
                                    /* carpeting.                                  */
               int AreaFeet;        /* Area of the room in square feet.            */
               double AreaYards;    /* Area of the room in square yards.           */
               double CarpetCost;   /* This is the cost of the carpeting itself.   */
  
               Scanner scan = new Scanner(System.in);   /* Declare a new instance of the Scanner class. */ 
    
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
   			   	
               /* <7> Print program header message. */
   
               System.out.print("\n\n                 CSCI 210  -  Java Assignment 3");
               System.out.print("\n               **********************************");
               System.out.print("\n                    Cost of Carpeting a Room");
               System.out.print("\n               **********************************\n"); 
     
               /* <8> Print the report lines. */
    
               System.out.printf("\n               Length of the room   =%6d feet", Length);
			   System.out.printf("\n               Width of the room    =%6d feet", Width);
			   System.out.printf("\n               Cost per square yard =%9.2f dollars", Cost);
			   System.out.printf("\n               Area in square feet  =%6d square feet", AreaFeet);
			   System.out.printf("\n               Area in square yards =%9.2f square yards", AreaYards);
			   System.out.printf("\n               Cost of carpeting    =%9.2f dollars", CarpetCost);

               /* <9> Print the program ending message. */
   
			   System.out.print("\n\n                   End of Carpet Cost Report");
			   System.out.print("\n               **********************************\n\n");
			   
        }   
}

