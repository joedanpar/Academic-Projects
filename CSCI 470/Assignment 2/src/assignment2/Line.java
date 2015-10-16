package assignment2;

/*****************************************************************
This program demonstrates a simple "Line" class. 
Here, a Line class is defined with its properties and
interface (i.e., its methods).  
A main class then creates instances of this Line class 
and calls on the methods to demonstrate its behavior.
*****************************************************************/
//import java.io.*;
//import java.lang.Math.*;
//****************************************************************
class Line
  {
  private int x1, y1, x2, y2;     //coordinates of the line
  private int lcolorr, lcolorg, lcolorb;
  
  //Constructor
  //Receives 4 integers which are the Line's start and end points.
  //
  public Line(int left, int top, int right, int bottom)
    {
    // each of these validates its argument - see below.
    setLeft(left);
    setTop(top);
    setRight(right);
    setBottom(bottom);
	lcolorr = 0;
	lcolorg = 0;
	lcolorb = 0;
	setColor(lcolorr,lcolorg,lcolorb);
    } // end constructor    
  //*************************************
  //Constructor
  //Receives 2 TwoDPoint classes which hold the x and y
  //values for the start and end points of the line.
  //
  public Line(TwoDPoint p1, TwoDPoint p2)
  	{
	this(p1.x, p1.y, p2.x, p2.y);
  	} // end constructor
  //*************************************
  //method draw() calls another method called drawLine(),
  //which is assumed to be a graphics primitive on the
  //system.  However, since this program will be
  //run in console mode, a text description of the Line
  //will be displayed. 
  //
  public void draw()
    {
    drawLine(x1, y1, x2, y2);
    }
  //*************************************
  //method drawLine() simulates drawing of a line for console mode.
  //It should describe all the important attributes of the line.
  //In a graphics mode program, we would delete this and use the
  //system's Graphics library drawLine().
  //
  private void drawLine(int x1, int y1, int x2, int y2)
    {
    System.out.println("Draw a line from x of " + x1 + " and y of " + y1);
    System.out.println("to x of " + x2 + " and y of " + y2 + "\n");
    }
  //*************************************
  //Method setLine() allows user to change the points of the 
  //already existing Line.
  //
  public void setLine(int left, int top, int right, int bottom)
    {
    setLeft(left);
    setTop(top);
    setRight(right);
    setBottom(bottom);    
    }  
  // -- the individual setXXXX methods that prevent
  //    any line's coordinate from being offscreen.
  //    In the event of an invalid (offscreen) value,
  //    that value is (silently) set to 0.
  //**************************
  public void setLeft(int left)
    {
    if (left < 0 || left > 639)
      x1 = 0;
    else
      x1 = left;
    }
  //**************************
  public void setTop(int top)
    {
    if (top < 0 || top > 479)
      y1 = 0;
    else
      y1 = top;
    }
  //**************************
  public void setRight(int right)
    {
    if (right > 639 || right < 0)
      x2 = 0;
    else
      x2 = right;
    }
  //**************************
  public void setBottom(int bottom)
    {
    if (bottom > 479 || bottom < 0)
      y2 = 0;
    else
      y2 = bottom;
    }
	
	
	public double getLength(){
	int xs = getRight() - getLeft();
	int ys = getTop() - getBottom();
	double ls = (double)(xs*xs + ys*ys);
	return ls;
	}
	
	public void setColor(int r, int g, int b){
	//setColor(new Color(r,g,b));
	lcolorr = r;
	lcolorg = g;
	lcolorb = b;
	}
	
	public String getColor(){
	return "(" + lcolorr + ", " + lcolorg + ", " + lcolorb + ")";
	}
	
	
  //Now for some "get" Access methods to get individual values
  //**************************
  public int getLeft()
    {
    return x1;
    }
  
  //**************************
  public int getTop()
    {
    return y1;
    }
  
  //**************************
  public int getRight()
    {
    return x2;
    }
  
  //**************************
  public int getBottom()
    {
    return y2;
    }  
} // end class Line