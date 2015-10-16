//*****************************************************************************************************
//                      SUPER ANIMATOR
//
//
// Names       : Nithin kumar Gone (z1568709), Vasu Gaddam(z1569142), Ahad(z1566231) 
// Assignment  : 4
// Due Date    : 04/07/10
// Instructor  : Kurt Mcmahon
// TA          : Divya 
// Description : This program demonstrates a Java Swing application that does
//               a)a graphical "Circle" animation in one panel
//               b)a second graphical "Lines" animation in another panel.
//In addition,the application will have a menu bar and a tool bar that will allow
//quick access to selected program commands.
//******************************************************************************************************/

import java.awt.*;
import java.lang.Exception;
import java.awt.event.*;
import javax.swing.*;

//This class will hold the references to CircleControlPanel and LineControlPanel.
//It has menubar and toolbar  that will allow quick access to selected program commands.
//contain event handling code to respond to user events.

public class SuperAnimator extends JFrame implements ActionListener {

	CircleControlPanel circleAnim;
	LineControlPanel lineAnim;
	String selectedColor;
    
	
	public SuperAnimator() {

		this.setLayout(new BorderLayout());
		this.setTitle("Super Animator");
		circleAnim = new CircleControlPanel();
		lineAnim = new LineControlPanel();

		JMenuBar mBar = new JMenuBar();
		JMenu circleMenu = new JMenu("Circle");
		JMenu lineMenu = new JMenu("Line");
		JMenuItem cirStartItem = new JMenuItem("Start");
		cirStartItem.addActionListener(this);
		cirStartItem.setActionCommand("CircleStart");

		JMenuItem cirStopItem = new JMenuItem("Stop");
		cirStopItem.addActionListener(this);
		cirStopItem.setActionCommand("CircleStop");

		JMenuItem lineStartItem = new JMenuItem("Start");
		lineStartItem.addActionListener(this);
		lineStartItem.setActionCommand("LineStart");

		JMenuItem lineStopItem = new JMenuItem("Stop");
		lineStopItem.addActionListener(this);
		lineStopItem.setActionCommand("LineStop");

		circleMenu.add(cirStartItem);
		circleMenu.add(cirStopItem);
		lineMenu.add(lineStartItem);
		lineMenu.add(lineStopItem);
		mBar.add(circleMenu);
		mBar.add(lineMenu);
		this.setJMenuBar(mBar);

		// toolbar
		JToolBar toolBar = new JToolBar();
		ToolBarButton cirStartBtn = new ToolBarButton(new ImageIcon(
				"goCirc_icon.gif"));
		ToolBarButton cirStopBtn = new ToolBarButton(new ImageIcon(
				"stopCirc_icon.gif"));
		ToolBarButton lineStartBtn = new ToolBarButton(new ImageIcon(
				"goLines_icon.gif"));
		ToolBarButton lineStopBtn = new ToolBarButton(new ImageIcon(
				"stop_Lines_icon.gif"));

		cirStartBtn.setToolTipText("Start Circle Animation");
		cirStartBtn.setActionCommand("CircleStart");
		cirStartBtn.addActionListener(this);

		cirStopBtn.setToolTipText("Stop Circle Animation");
		cirStopBtn.setActionCommand("CircleStop");
		cirStopBtn.addActionListener(this);

		lineStartBtn.setToolTipText("Start Line Animation");
		lineStartBtn.setActionCommand("LineStart");
		lineStartBtn.addActionListener(this);

		lineStopBtn.setToolTipText("Stop Line Animation");
		lineStopBtn.setActionCommand("LineStop");
		lineStopBtn.addActionListener(this);

		toolBar.add(cirStartBtn);
		toolBar.add(cirStopBtn);
		toolBar.add(lineStartBtn);
		toolBar.add(lineStopBtn);

		toolBar.addSeparator();

		this.setLayout(new BorderLayout());
		this.add(toolBar, BorderLayout.NORTH);
		JPanel cirLine = new JPanel(new GridLayout(1, 2, 10, 10));
		cirLine.add(circleAnim);
		cirLine.add(lineAnim);
		this.add(cirLine, BorderLayout.CENTER);
		this.setSize(1200, 450);
		this.setVisible(true);

	}

	public static void main(String[] args) {
		new SuperAnimator();
	}

	public void actionPerformed(ActionEvent e) {

		if (e.getActionCommand().equals("CircleStart")) {
			circleAnim.actionPerformed(e);
		} else if (e.getActionCommand().equals("CircleStop")) {
			circleAnim.actionPerformed(e);
		} else if (e.getActionCommand().equals("LineStart")) {
			lineAnim.actionPerformed(e);
		} else if (e.getActionCommand().equals("LineStop")) {
			lineAnim.actionPerformed(e);
		}
	}

}

class ToolBarButton extends JButton {
	public ToolBarButton(Icon icon) {
		super(icon);
		setMargin(new Insets(0, 0, 0, 0));
	}

}

//This class will hold ComponentPanel.It will also hold the reference to the Display Panel
//(CircleCanvas) and any other variables necessary to its functoning.This panel will also
//contain event handling code to respond to user events such as button clicks.

class CircleControlPanel extends JPanel implements ActionListener {

	
	int numberPoints = 6;
	double radius = 100;
	int speedRate;
	JButton start, stop;
	JTextField txtRadius = new JTextField(20);
	JTextField txtNumOfPoints = new JTextField(20);
	String[] colors = { "Red", "White", "Black", "Cyan" };
	JList listBgcolor = new JList(colors);
	ButtonGroup bg = new ButtonGroup();
	JRadioButton radioBtnFast = new JRadioButton("Fast", false);
	JRadioButton radioBtnMed = new JRadioButton("Medium", true);
	JRadioButton radioBtnSlow = new JRadioButton("Slow", false);
	String selectedColor;
	CircleCanvas cirCanvas;

	public CircleControlPanel() {

		JPanel componentPanel = new JPanel();
		start = new JButton("Start");
		start.setActionCommand("CircleStart");
		start.addActionListener(this);
		stop = new JButton("Stop");
		stop.setActionCommand("CircleStop");
		stop.addActionListener(this);

		componentPanel.setLayout(new BorderLayout());
		JPanel northPanel = new JPanel(new GridLayout(1, 2));
		northPanel.add(start);
		northPanel.add(stop);
		componentPanel.add(BorderLayout.NORTH, northPanel);

		JPanel southPanel = new JPanel(new GridLayout(3, 2));
		southPanel.add(new JLabel("Radius"));
		southPanel.add(txtRadius);
		southPanel.add(new JLabel("Number of points"));
		southPanel.add(txtNumOfPoints);
		southPanel.add(new JLabel("Speed"));

		JPanel speedPanel = new JPanel(new GridLayout(1, 3));
		bg.add(radioBtnFast);
		bg.add(radioBtnMed);
		bg.add(radioBtnSlow);
		speedPanel.add(radioBtnFast);
		speedPanel.add(radioBtnMed);
		speedPanel.add(radioBtnSlow);
		southPanel.add(speedPanel);
		componentPanel.add(BorderLayout.SOUTH, southPanel);
		radioBtnFast.addActionListener(this);
		radioBtnMed.addActionListener(this);
		radioBtnSlow.addActionListener(this);

		JPanel colorList = new JPanel(new GridLayout(1, 2));
		colorList.add(new JLabel("Background Color"));
		colorList.add(listBgcolor);
		componentPanel.add(BorderLayout.CENTER, colorList);
		this.setLayout(new GridLayout(1, 2));
		this.add(componentPanel);
		listBgcolor.setSelectedIndex(2);
		cirCanvas = new CircleCanvas();
		cirCanvas.setBackground(Color.BLACK);
		this.add(cirCanvas);

	} // end of Constructor

	public void actionPerformed(ActionEvent e) {

		if (e.getSource() == radioBtnFast) {
			speedRate = 50;
			cirCanvas.setSpeed(speedRate);

		}
		if (e.getSource() == radioBtnMed) {
			speedRate = 200;
			cirCanvas.setSpeed(speedRate);
		}
		if (e.getSource() == radioBtnSlow) {
			speedRate = 500;
			cirCanvas.setSpeed(speedRate);
		}

		if (e.getActionCommand().equals("CircleStart")) {
			try {
				numberPoints = Integer.parseInt(txtNumOfPoints.getText());
				radius = Double.parseDouble(txtRadius.getText());
			} catch (Exception ex) {
				ex.getMessage();
			}
			selectedColor = (String) listBgcolor.getSelectedValue();
			
			cirCanvas.startAnim(selectedColor, numberPoints, radius);
			
		}

		if (e.getActionCommand().equals("CircleStop")) {
			cirCanvas.stopAnim();
		}

	}

} // End of CircleControlPanel class

//This class will present a display of a graphical circle animation.

class CircleCanvas extends Canvas implements Runnable {

	Thread runner = null;
	int x1 = 10, y1 = 10, x2 = 200, y2 = 200;
	int speed = 200;
	double initialAngle = 0;
	double x[], y[];
	double circleRadius;
	boolean keepDrawing;
	double lineAngle;
	int numberOfPoints;

	public CircleCanvas() {
		super();
	}

	public void setSpeed(int speedRate) {
		speed = speedRate;
	}

	public void startAnim(String bgColor, int numberPoints,
			Double radius) {
		if (bgColor.equals("Red")) {
			this.setBackground(Color.RED);
		} else if (bgColor.equals("Cyan")) {
			this.setBackground(Color.CYAN);
		} else if (bgColor.equals("White")) {
			this.setBackground(Color.WHITE);
		} else {
			this.setBackground(Color.BLACK);
		}
		numberOfPoints = numberPoints;
		
		circleRadius = radius;

		keepDrawing = true;
		if (runner == null) {
			runner = new Thread(this);
			runner.start();
		}
	}

	public void stopAnim() {
		if (runner != null) {
			keepDrawing = false;
			runner = null;

		}
	}

	public void run() {
		Graphics g = getGraphics();
		x = new double[40];
		y = new double[40];

		while (keepDrawing) {

			float Y = this.getHeight();
			float X = this.getWidth();

			if (numberOfPoints > 40) {
				numberOfPoints = 40;
			}
			if (X > Y) {
				if (circleRadius > Y) {
					circleRadius = Y / 2;
				}
			} else {
				if (circleRadius > X) {
					circleRadius = X / 2;
				}

			}

			lineAngle = 360 / numberOfPoints;
			for (int i = 0; i < numberOfPoints; i++) {
				double angle = Math.toRadians(initialAngle);
				x[i] = circleRadius * Math.sin(angle) + (X / 2);
				y[i] = circleRadius * Math.cos(angle) + (Y / 2);
				initialAngle = initialAngle + lineAngle;
			}
			int R = (int) (Math.random() * 256);
			int G = (int) (Math.random() * 256);
			int B = (int) (Math.random() * 256);
			Color randomColor = new Color(R, G, B);
			g.setColor(randomColor);

			try {
				for (int i = 0; i < numberOfPoints; i++) {
					for (int j = 0; j < numberOfPoints; j++) {
						g.drawLine((int) x[i], (int) y[i], (int) x[j],
								(int) y[j]);
						runner.sleep(speed);
						if (!keepDrawing)
							break;
					}

					runner.sleep(speed);

				}
				runner.sleep(500);
				repaint();
			} catch (Exception e) {
				e.getMessage();
			}

		}
	} // end of run
} // end of class


//
class LineControlPanel extends JPanel implements ActionListener {
	JButton lineStart, lineStop; // stop and start the animation
	JComboBox dx1, dx2, dy1, dy2, color;
	static String[] objectArray = { "4", "3", "2", "1", "0", "-1", "-2", "-3",
			"-4" };
	static String[] colorArray = { "Blue/Orange", "Cyan/Green", "Red/Magenta" };
	JPanel lineComponentPanel;
	xLineCanvas lineCan;
	Color set1color, set2color;

	// ************************************************
	public LineControlPanel() {
		lineComponentPanel = new JPanel(new GridLayout(3, 3));
		lineStart = new JButton("Start");
		lineStart.setActionCommand("LineStart");
		lineStart.addActionListener(this);
		lineStop = new JButton("Stop");
		lineStop.setActionCommand("LineStop");
		lineStop.addActionListener(this);

		dx1 = new JComboBox(objectArray);
		dy1 = new JComboBox(objectArray);
		dx2 = new JComboBox(objectArray);
		dy2 = new JComboBox(objectArray);
		color = new JComboBox(colorArray);
		lineCan = new xLineCanvas();
		lineCan.setBackground(Color.black);

		lineComponentPanel.add(lineStart);
		lineComponentPanel.add(lineStop);
		lineComponentPanel.add(new JLabel("dx1", JLabel.CENTER));
		lineComponentPanel.add(dx1);
		lineComponentPanel.add(new JLabel("dy1", JLabel.CENTER));
		lineComponentPanel.add(dy1);
		lineComponentPanel.add(new JLabel("dx2", JLabel.CENTER));
		lineComponentPanel.add(dx2);
		lineComponentPanel.add(new JLabel("dy2", JLabel.CENTER));
		lineComponentPanel.add(dy2);
		lineComponentPanel.add(new JLabel("color", JLabel.CENTER));
		lineComponentPanel.add(color);
		this.setLayout(new BorderLayout());
		this.add(BorderLayout.SOUTH, lineComponentPanel);
		this.add(BorderLayout.CENTER, lineCan);

	} // end of Constructor

	public void actionPerformed(ActionEvent e) {

		if (e.getActionCommand().equals("LineStart")) {
			String dx1value = (String) dx1.getSelectedItem();
			int dx1 = Integer.parseInt(dx1value.trim());
			String dy1value = (String) dy1.getSelectedItem();
			int dy1 = Integer.parseInt(dy1value.trim());
			String dx2value = (String) dx2.getSelectedItem();
			int dx2 = Integer.parseInt(dx2value.trim());
			String dy2value = (String) dy2.getSelectedItem();
			int dy2 = Integer.parseInt(dy2value.trim());
			String colorNames = (String) color.getSelectedItem();

			if (colorNames.equals("Blue/Orange")) {
				set1color = Color.BLUE;
				set2color = Color.ORANGE;
			} else if (colorNames.equals("Cyan/Green")) {
				set1color = Color.CYAN;
				set2color = Color.GREEN;
			} else {
				set1color = Color.RED;
				set2color = Color.MAGENTA;
			}

			lineCan.startAnim(dx1, dy1, dx2, dy2, set1color, set2color);
		}

		if (e.getActionCommand().equals("LineStop")) {

			lineCan.stopAnim();
		}

	}

}//End of LineControlPanel class

//This class will animate a design consisting of two sets of lines  
//that move around the screen.
class xLineCanvas extends Canvas implements Runnable {
	Thread runner = null;
	int x1;
	int y1;
	int x2;
	int y2;
	boolean keepDrawing; // for controlling run loop
	LineSet l1;
	LineSet l2;
	int setdx1, setdx2, setdy1, setdy2;
	Color set1color, set2color;

	public xLineCanvas() {

		super();

	}

	public void startAnim(int dx1, int dy1, int dx2, int dy2, Color set1,
			Color set2) {
		setdx1 = dx1;
		setdy1 = dy1;
		setdx2 = dx2;
		setdy2 = dy2;
		set1color = set1;
		set2color = set2;

		if (runner == null) {
			runner = new Thread(this);
			keepDrawing = true;
			runner.start();
		}

	}

	public void stopAnim() {
		if (runner != null) {
			keepDrawing = false;
			runner = null;
		}
	}

	public void run() {
		Graphics g = getGraphics();
		Dimension d = getSize();
		l1 = new LineSet(g, d, setdx1, setdy1, setdx2, setdy2, set1color);
		l2 = new LineSet(g, d, 2 * setdx1, 2 * setdy1, 2 * setdx2, 2 * setdy2,
				set2color);
		this.setBackground(Color.BLACK);

		while (keepDrawing) {
			try {
				runner.sleep(100);
			} catch (InterruptedException ie) {

			}
			g.clearRect(0, 0, getSize().width - 1, getSize().height - 1);
			l1.addLine();
			l1.displayAllLines(g);
			l2.addLine();
			l2.displayAllLines(g);

		}

	} // end of run

}

//This class implements the idea of a queue.
class LineSet {
	Line queueHead, queueTail;//head and tail references
	Line current;
	int qlength = 0;
	static final int maxsize = 50;
	Color color;
	int a = 0;
	int dx1, dy1, dx2, dy2;
	double WIDTH, HEIGHT;
	int x1, x2, y1, y2;

	//This constructor stores queue's dx1,dy1,etc. and it's color, and which initializes the queue reference to null
	//This sets first line in the line set to a random positions on the screen.
	public LineSet(Graphics g, Dimension d, int dx1, int dy1, int dx2, int dy2,
			Color cr) {
		WIDTH = d.getWidth();
		HEIGHT = d.getHeight();
		this.color = cr;
		this.dx1 = dx1;
		this.dy1 = dy1;
		this.dx2 = dx2;
		this.dy2 = dy2;

		x1 = (int) (WIDTH * Math.random());
		x2 = (int) (HEIGHT * Math.random());
		y1 = (int) (WIDTH * Math.random());
		y2 = (int) (HEIGHT * Math.random());

		queueHead = null;
		queueTail = queueHead;
	}

	public boolean isEmpty() {
		return queueHead == null;
	}

	//This method is to add a new line.It should also change the signs of dx1 and dy1,etc.
	//It detects that the new line would be moving off the edge of the screen.
	public void addLine() {
		x1 = x1 + dx1;
		y1 = y1 + dy1;
		x2 = x2 + dx2;
		y2 = y2 + dy2;

		if (x1 >= WIDTH) {
			x1 = (int) WIDTH - 1;
			dx1 = -dx1;
		}
		if (x1 <= 0) {
			dx1 = -dx1;
		}

		if (y1 >= HEIGHT) {
			y1 = (int) HEIGHT - 1;
			dy1 = -dy1;
		}
		if (y1 <= 0) {
			dy1 = -dy1;

		}
		if (x2 >= WIDTH) {
			x2 = (int) WIDTH - 1;
			dx2 = -dx2;

		}
		if (x2 <= 0) {
			dx2 = -dx2;
		}
		if (y2 >= HEIGHT) {
			y2 = (int) HEIGHT - 1;
			dy2 = -dy2;
		}
		if (y2 <= 0) {

			dy2 = -dy2;
		}

		if (isEmpty()) {// Make queue of one element
			queueTail = new Line(x1, y1, x2, y2);
			queueHead = queueTail;
		}

		else {
			qlength++;
			queueTail = queueTail.nextLine = new Line(x1, y1, x2, y2);
			// Regular case
			if (qlength > 50)
				deleteOldestLine();

		}

	}

	//This method deletes the oldest line in the queue
	public void deleteOldestLine() {

		queueHead = queueHead.nextLine;
		qlength--;

	}
    //This method is to paint all the lines on a graphics context.
	public void displayAllLines(Graphics g) {
		current = queueHead;
		while (current.nextLine != null) {
			g.setColor(color);
			g.drawLine(current.getx1(), current.gety1(), current.gety1(),
					current.gety2());

			current = current.nextLine;

		}// End of while

	}// End of displayAllLine method

} // End of LineSet Class

//This Line class defined with its properties.
class Line {

	private int x1, y1, x2, y2;
	public Line nextLine;

	// Line class constructor
	public Line(int x1, int y1, int x2, int y2) {
		this.x1 = x1;
		this.y1 = y1;
		this.x2 = x2;
		this.y2 = y2;
		nextLine = null;
	}//End of Line class constructor

	//Getter methods
	public int getx1() {
		return x1;
	}

	public int gety1() {
		return y1;
	}

	public int getx2() {
		return x2;
	}

	public int gety2() {
		return y2;
	}
}
