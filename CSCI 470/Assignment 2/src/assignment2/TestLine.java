package assignment2;

/***************************************************************
 Now we will define a class with main() where execution will begin. It is this
 class, and this code, that will create instances of the Line and call its
 methods.
***************************************************************/

public class TestLine
  {
  public static void main(String args[])
    {
    Line l1 = null;
    Line l2 = null;
    Line l3 = null;           //declare 3 instances of Line class
    
    TwoDPoint p1 = new TwoDPoint(5,5);
    TwoDPoint p2 = new TwoDPoint(10,10);
    
    //create 1 Line object
    try
    	{
    	l1 = new Line (10, 10, 100, 100);
    	} catch (Exception e) {
    		System.err.println("Error: " +
    				e.getMessage());
    	}
    //draw it
    l1.draw();    
    //change start point with valid values
    try
    	{
    	l1.setLine(5, 5, l1.getRight(), l1.getBottom());
    	} catch (Exception e) {
    		System.err.println("Error: " +
    				e.getMessage());
    	}
    //draw it again with new start point
    l1.draw();    
    //try to change left (x1) to an illegal value
    try
    	{
    	l1.setLeft(3000);    
    	} catch (Exception e) {
    		System.err.println("Error: " +
    				e.getMessage());
    	}
    //draw the line...x1 should now be zero
    l1.draw();    
    //create a second Line instance, or object
    try
    	{
    	l2 = new Line(100, 100, 400, 400);    
    	} catch (Exception e) {
    		System.err.println("Error: " +
    				e.getMessage());
    	}
    //draw 2nd line
    l2.draw();    
    //set a new valid bottom for line 2
    try
    	{
    	l2.setBottom(479);    
    	} catch (Exception e) {
    		System.err.println("Error: " +
    				e.getMessage());
    	}
    //draw 2nd line again
    l2.draw();    
    
    //create a third Line instance, or object
    l3 = new Line(p1, p2);
    
    //draw 3rd line
    l3.draw();
    
    } // end of main
  }  // end class TestLine