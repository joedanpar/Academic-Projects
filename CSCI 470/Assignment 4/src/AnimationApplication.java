import java.awt.*;
import java.awt.event.*;
import java.awt.geom.Line2D;
import java.awt.geom.Point2D;
import java.util.ArrayList;
import java.util.Vector;
import java.util.Queue;

import javax.swing.*;

public class AnimationApplication extends JFrame {

	 private static final long serialVersionUID = 1L;

	 AnimationPanel panel1 = new AnimationPanel();
	 //AnimationPanel panel2 = new AnimationPanel();

	 public static void main(String[] args) {
		 AnimationApplication prog = new 
			AnimationApplication("Animation Application");
		 
		 prog.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		 prog.setSize(1200, 600);
		 prog.setVisible(true);
	 }

	 AnimationApplication(String title) {
		 super(title);
		 
		 setLayout(new GridLayout(1,1));
		 
		 add(panel1);
		 //add(panel2, BorderLayout.EAST);
	 }
}

class AnimationPanel extends JPanel implements ActionListener, Runnable {

	private static final long serialVersionUID = 1L;
	
	private volatile Thread animator = null;
	private volatile Thread lineAnim = null;
	private volatile boolean animationSuspended = false;
	JMenuBar menuBar = new JMenuBar();
	JMenu menu1 = new JMenu("Circle");
	JMenu menu2 = new JMenu("Lines");
	JMenuItem  menuItem_c1 = new JMenuItem("Start Circle");
	JMenuItem  menuItem_c2 = new JMenuItem("Stop Circle");
	JMenuItem  menuItem_l1 = new JMenuItem("Start Lines");
	JMenuItem  menuItem_l2 = new JMenuItem("Stop Lines");
	JTextPane  circleDraw = new JTextPane();
	JButton b = new JButton("Push Me");
	JTextField tf = new JTextField(10);
	JTextField radiusField = new JTextField(10);
	JTextField numPoints = new JTextField(10);
	JRadioButton fastButton = new JRadioButton("Fast");
	JRadioButton mediumButton = new JRadioButton("Medium");
	JRadioButton slowButton = new JRadioButton("Slow");
	JPanel menuPanel = new JPanel();
	JPanel circlePanel = new JPanel();
	JPanel linePanel = new JPanel();
	JPanel circleMenu = new JPanel();
	TriAnimation triani = new TriAnimation();
	JPanel lineMenu = new JPanel();
	JPanel buttonPanelthings = new JPanel();
	JPanel bgPanel = new JPanel();
	
	String[] num_list = {"1","2","3","4","5","6","7","8","9","10"};
	JComboBox dx1_list = new JComboBox(num_list);
	JComboBox dx2_list = new JComboBox(num_list);
	JComboBox dy1_list = new JComboBox(num_list);
	JComboBox dy2_list = new JComboBox(num_list);
	
	String[] colors = {"Orange/Blue", "Red/Green", "Black/White", "Yellow/Green"};
	JComboBox color_list = new JComboBox(colors);
	
	String[] circleColors = {"Red","White","Black","Cyan","Purple"};
	JList circle_colors = new JList(circleColors);
  
	JButton start1 = new JButton("Start"),
			 stop1 = new JButton("Stop");
	JButton start2 = new JButton("Start"),
		stop2 = new JButton("Stop");
	JLabel title = new JLabel("CSCI 470 Super Animator",JLabel.CENTER);
	int speedvar = 100;
	DrawingPanel circledraw = new DrawingPanel();
	
	public boolean privateKey;
	
	int thing = 0,
		numPts = 0;
  	float radius = 0;
  	double pointAngle = 2*Math.PI/numPts;
		double	a = 0.0,
		x = 0.0,
		y = 0.0;
		
		Point2D.Double center = new Point2D.Double(120, 285);
		Vector<Point2D> points = new Vector<Point2D>(numPts);
		boolean cirani = false;
		boolean linani = false;
		
	AnimationPanel() {
		b.addActionListener(this);
		menuItem_c1.addActionListener(this);
		menuItem_c2.addActionListener(this);
		menuItem_l1.addActionListener(this);
		menuItem_l2.addActionListener(this);
		start1.addActionListener(this);
		start2.addActionListener(this);
		stop1.addActionListener(this);
		stop2.addActionListener(this);
		fastButton.addActionListener(this);
		mediumButton.addActionListener(this);
		slowButton.addActionListener(this);
		
		setSize(1200,600);
		setLayout(new BorderLayout(4, 10));
		menuPanel.setLayout(new GridLayout(1,1));
		menuBar.setPreferredSize(new Dimension(10,20));
		menuBar.add(menu1);
		menu1.add(menuItem_c1);
		menu1.add(menuItem_c2);
		menuBar.add(menu2);
		menu2.add(menuItem_l1);
		menu2.add(menuItem_l2);
		menuPanel.add(menuBar);
		add(menuPanel,BorderLayout.NORTH);
		
		circleMenu.setLayout(new BorderLayout());
		buttonPanelthings.setLayout(new GridLayout(1,2));
		buttonPanelthings.add(start1);
		buttonPanelthings.add(stop1);
		circleMenu.add(buttonPanelthings,BorderLayout.NORTH);
		
		bgPanel.setLayout(new BorderLayout());
	    bgPanel.add(new JLabel("Background Color                        "),BorderLayout.WEST);
		circle_colors.setSelectionMode(ListSelectionModel.SINGLE_INTERVAL_SELECTION);
		
		
		bgPanel.add(circle_colors,BorderLayout.CENTER);
		circleMenu.add(bgPanel,BorderLayout.CENTER);
		
		JPanel bottomstuff = new JPanel();
		bottomstuff.setLayout(new GridLayout(3,1));
		bottomstuff.add(new JLabel("Radius"));
		bottomstuff.add(radiusField);
		bottomstuff.add(new JLabel(""));
		bottomstuff.add(new JLabel("Number of Points"));
		bottomstuff.add(numPoints);
		
		bottomstuff.add(new JLabel(""));
		ButtonGroup speeds = new ButtonGroup();
		speeds.add(fastButton);
		speeds.add(mediumButton);
		speeds.add(slowButton);
		slowButton.setSelected(true);
		bottomstuff.add(fastButton);
		bottomstuff.add(mediumButton);
		bottomstuff.add(slowButton);
		circleMenu.add(bottomstuff,BorderLayout.SOUTH);
		
		
		//JPanel blah = new JPanel();
		//circleMenu.add(blah,BorderLayout.EAST);
		add(circleMenu,BorderLayout.WEST);
		
		/*circlePanel.setLayout(new GridLayout(1,1));
		circlePanel.add(ta);
		ta.setBackground(new Color(0,0,0));
		add(circlePanel,BorderLayout.CENTER);*/
		
		circledraw.setLayout(new GridLayout(1,1));
		add(circledraw,BorderLayout.CENTER);
		
		JPanel lthings = new JPanel();
		lthings.setLayout(new BorderLayout());
		triani.setLayout(new BorderLayout(1,1));
		lineMenu.setLayout(new GridLayout(2,6));
		lineMenu.add(start2);
		lineMenu.add(stop2);
		lineMenu.add(new JLabel("dx1"));
		lineMenu.add(dx1_list);
		lineMenu.add(new JLabel("dy1"));
		lineMenu.add(dy1_list);
		lineMenu.add(new JLabel("Colors"));
		lineMenu.add(color_list);
		lineMenu.add(new JLabel("dx2"));
	    lineMenu.add(dx2_list);
		lineMenu.add(new JLabel("dy2"));
		lineMenu.add(dy2_list);
		lthings.add(triani,BorderLayout.CENTER);
		lthings.add(lineMenu,BorderLayout.SOUTH);
		add(lthings,BorderLayout.EAST);
       
       

   }
   
   public void actionPerformed(ActionEvent e) {
       
	   if (e.getSource() == start1 || e.getSource() == menuItem_c1) {
			cirani = true;
			buildCircle();
			int tempInt;
			float tempFloat;
			int tempColor;
			
			tempColor = circle_colors.getSelectedIndex();
			if(tempColor == 0){
				circledraw.setBackground(new Color(255,0,0));
			}
			else if(tempColor == 1){
				circledraw.setBackground(new Color(255,255,255));
			}
			else if(tempColor == 2){
				circledraw.setBackground(new Color(0,0,0));
			}
			else if(tempColor == 3){
				circledraw.setBackground(new Color(0,255,255));
			}
			else if(tempColor == 4){
				circledraw.setBackground(new Color(160,32,240));
			}
			if (animator == null) {
				// If not, start the animation
				animator = new Thread(this);
				animationSuspended = false;
				animator.start();
			}
			//circleani.repaint();
		}
		
		if(e.getSource() == fastButton){
			speedvar = 50;
		}
		if(e.getSource() == mediumButton){
			speedvar = 100;
		}
		if(e.getSource() == slowButton){
			speedvar = 150;
		}
		
		
		if (e.getSource() == stop1 || e.getSource() == menuItem_c2) {
			cirani = false;
			stop();
		}
		if (e.getSource() == start2 || e.getSource() == menuItem_l1) {
			if (lineAnim == null) {
				//triani.makeTri();
				linani = true;
				lineAnim = new Thread(this);
				//animationSuspended = false;
				lineAnim.start();
			}
			//TriThread t = new TriThread(triani);
		    //new Thread(t).start();
		}
		if(e.getSource() == stop2){
			linani = false;
			stop();
		}
       /*if (e.getSource() == startB) {
           
           
           
           // Check if no animation thread exists
           if (animator == null) {
               
               // If not, start the animation
               start();
    
          
           } else {
               // If animation is paused, resume it
               if (animationSuspended) {
                   resume();
               }
           }
           
       } else if (e.getSource() == pauseB) {
           
           // Check if animation thread exists
           if (animator != null) {
               
               // If so, suspend the animation thread
               animationSuspended = true;
           }
           
       } else if (e.getSource() == stopB) {
           stop();
           clear();
       }*/

   }

   public void run() {
		Thread thisThread = Thread.currentThread();
		while (animator == thisThread) {

			if (thing < numPts) {
				this.repaint();
				try {
					Thread.sleep(speedvar);
				}
				catch (InterruptedException e){
				}
				if(cirani){
					thing++;
				}
				if(linani){
					;
				}
			}
			else {
				try {
					Thread.sleep(speedvar*2);
				}
				catch (InterruptedException e){
				}
				this.repaint();
				thing = 0;
			}
		}
		
		while (lineAnim == thisThread) {
			try {
			triani.lineSet1.addLine();
			triani.lineSet1.displayAllLines();
			} catch (Exception e) {
				triani.lineSet1.queue.add(new Line2D.Double(Math.random()*500,Math.random()*500,Math.random()*500,Math.random()*500));
			}
			
			if (triani.lineSet2 == null) {
			triani.lineSet2.addLine();
			triani.lineSet2.displayAllLines();
			}
		}
	}

	public void start() {
		// Create a new animation thread and start it
	}

	public synchronized void stop() {
		animator = null;
		notify();
		thing = 0;
		repaint();
	}
   
	public synchronized void resume() {
		animationSuspended = false;
		notify();
	}

	/*public void clear() {
		DrawingPanel.clear();
	}*/
	
	public void buildCircle () {
		numPts = Integer.parseInt(numPoints.getText());
		radius = Float.parseFloat(radiusField.getText());
		pointAngle = 2*Math.PI/numPts;
		points.clear();
		//this.setBackground(new Color(0, 0, 0));
		
		/*red = (int)(Math.random()*255);
		blue = (int)(Math.random()*255);
		green = (int)(Math.random()*255);*/
		//circle.setColor(new Color(red, green, blue));
		//displayPanel.paint(circle);
		for (int i = 0; i < numPts; i++) {
			a = i*pointAngle;
			x = radius*Math.cos(a)+center.getX();
			y = radius*Math.sin(a)+center.getY();
			//tempPt.setLocation(radius*Math.cos(a)+center.getX(), radius*Math.sin(a)+center.getY());	
			points.add(new Point2D.Double(radius*Math.cos(a)+center.getX(), radius*Math.sin(a)+center.getY()));
		}
	}
	public class DrawingPanel extends JPanel {
	
		private static final long serialVersionUID = 1L;
		//int numPts = 0;
		//int thing = 0;
		Point2D.Double tempPt = new Point2D.Double();
		Line2D.Double tempLn = new Line2D.Double();
		boolean isDrawing = false;
		int red = 0,
			green = 0,
			blue = 0,
			paintcount = 0;
   
			protected void paintComponent(Graphics g) {
       
				// Call superclass version of method
				super.paintComponent(g);
				if (animator != null) {

				//this.setBackground(Color.WHITE);

				//clear the background

				// Draw points
				for (int i = 0; i < thing; i++) {
					for (int j = i+1; j < numPts; j++) {
						//tempLn.setLine(points.get(i), points.get(j));
						//lines.add(new Line2D.Double(points.get(i), points.get(j)));
						int xa = (int) points.get(i).getX();
						int xb = (int) points.get(j).getX();
						int y1 = (int) points.get(i).getY();
						int y2 = (int) points.get(j).getY();
						g.drawLine(xa,y1,xb,y2);
					}
				}
			}
			/*for (int i = 0; i < pointList.size()-1; i++) {
				g.drawLine(pointList.get(i).x, pointList.get(i).y, 
				pointList.get(i+1).x, pointList.get(i+1).y);
			}*/
		}
		public void clear() {
			points.clear();
			repaint();
		}
	}
	
	
	public class TriAnimation extends JPanel {
	//public JPanel displayPanel = new JPanel();
		
	public LineQueue lineSet1, lineSet2;
	//int numPts = 0;
	//int red1 = (int)(Math.random()*255);
	//int blue1 = (int)(Math.random()*255);
	//int green1 = (int)(Math.random()*255);
	//Point2D.Double center = new Point2D.Double(, );
	//Vector<Point2D> points = new Vector<Point2D>();
	//Point2D.Double tempPt = new Point2D.Double();
	Line2D tempLn = new Line2D.Double();
	boolean isDrawing = false;
	//Vector<Line2D> lines = new Vector<Line2D>();
	Graphics g1;
	
	TriAnimation() {
	}
	
	public void makeTri(){
		lineSet1.addLine();
		lineSet2.addLine();
		
		lineSet1.dx11 = Integer.parseInt((String) dx1_list.getSelectedItem());
		lineSet1.dx21 = Integer.parseInt((String) dx2_list.getSelectedItem());
		lineSet1.dy11 = Integer.parseInt((String) dy1_list.getSelectedItem());
		lineSet1.dy21 = Integer.parseInt((String) dy2_list.getSelectedItem());
		
		lineSet2.dx11 = Integer.parseInt((String) dx1_list.getSelectedItem());
		lineSet2.dx21 = Integer.parseInt((String) dx2_list.getSelectedItem());
		lineSet2.dy11 = Integer.parseInt((String) dy1_list.getSelectedItem());
		lineSet2.dy21 = Integer.parseInt((String) dy2_list.getSelectedItem());
	}
	
	
		

		
	public void paintComponent(Graphics g1) {
        super.paintComponent(g1);
        
		//double a1 = 0.0;
		//double x1 = 0.0;
		//double y1 = 0.0;
		this.setBackground(new Color(0, 0, 0));
		g1.setColor(new Color(127, 127, 127));
		//lineSet1.clear();
		//lineSet2.clear();
		
		//this.add(displayPanel);
        
        //isDrawing = true;
        /*for (int i = 0; i < numPts; i++) {
			for (int j = i+1; j < numPts; j++) {
				lineSet1.add(new Line2D.Double(points.get(i), points.get(j)));
			}
			
		}*/
        
        //displayAllLines(lineSet1);
        /*for (int i = 0; i < lines.size(); i++) {
        	System.out.println(lines.get(i).getP1() + " " + lines.get(i).getP2());
        }
        System.out.println(lines.size());        
		if (isDrawing == true) {
			for (int x1 = 0; x1 < lines.size(); x1++) {
				if (isDrawing == true){
					int xa = (int) lines.get(x1).getX1();
					int xb = (int) lines.get(x1).getX2();
					int y1 = (int) lines.get(x1).getY1();
					int y2 = (int) lines.get(x1).getY2();
					g.drawLine(xa,y1,xb,y2);
				}
				else
					break;
			}
		}
	}

	public void stopDrawing() {
		isDrawing = false;
	}*/
		}
	}
	
	public class LineQueue {
		int maxQueueSize = 20;
		Vector<Line2D.Double> queue = new Vector<Line2D.Double>();
		Line2D oldestLine = queue.elementAt(0);
		int xa1 = 0,
			xb1 = 0,
			y11 = 0,
			y21 = 0,
			dx11 = 0,
			dy11 = 0,
			dx21 = 0,
			dy21 = 0;
		Line2D.Double tempLn;
		Graphics g1;
		
		public LineQueue () {
			maxQueueSize = 20;
			queue = new Vector<Line2D.Double>();
			oldestLine = queue.elementAt(0);
		}
		
		public boolean addLine () {
			if (queue.size() >= maxQueueSize) {
				deleteOldestLine();
				tempLn = new Line2D.Double(oldestLine.getP1(), oldestLine.getP2());
				tempLn.setLine(tempLn.getP1().getX() + dx11, tempLn.getP1().getY() + dy11, tempLn.getP2().getX() + dx21, tempLn.getP2().getY() + dy21);
				queue.add(tempLn);
				return true;
			}
			else if (queue.isEmpty()) {
				System.out.println("yay");
				xa1 = (int) Math.random()*500;
				xb1 = (int) Math.random()*500;
				y11 = (int) Math.random()*500;
				y21 = (int) Math.random()*500;
				tempLn = new Line2D.Double(xa1, y11, xb1, y21);
				queue.add(tempLn);
				return true;
			}
			else if (!queue.isEmpty() && queue.size() < maxQueueSize) {
				tempLn = new Line2D.Double(oldestLine.getP1(), oldestLine.getP2());
				tempLn.setLine(tempLn.getP1().getX() + dx11, tempLn.getP1().getY() + dy11, tempLn.getP2().getX() + dx21, tempLn.getP2().getY() + dy21);
				queue.add(tempLn);
				return true;
			}
			else
				return false;
		}
		
		public void deleteOldestLine() {
			queue.remove(oldestLine);
		}
		
		public void displayAllLines() {
			Line2D.Double[] tempLineSet = (Line2D.Double[])queue.toArray();
			for (int i = 0; i < maxQueueSize; i++) {
				//if (isDrawing == true){
					tempLn = tempLineSet[i];
					xa1 = (int) tempLn.getX1();
					xb1 = (int) tempLn.getX2();
					y11 = (int) tempLn.getY1();
					y21 = (int) tempLn.getY2();
					g1.drawLine(xa1,y11,xb1,y21);
				//}
				//else
					//break;
			}
		}
	}
}