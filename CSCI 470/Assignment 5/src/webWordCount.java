/*********************************************************
 * Names: Joe Dan Parker, Brandon Kesler, Michael Pagano *
 * Assignment: 5                                         *
 * Due Date: 02 April 2010                               *
 * Program Purpose:  The Purpose of this Program is to   *
 *   establish a connection with a website and calculate *
 *   word counts.	                                     *
 *  URL: http://students.cs.niu.edu/~z157694/index8.html *
 *********************************************************/

//package assignment5;

import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.net.*;
import java.util.*;

import javax.swing.*;

	public class webWordCount extends JApplet  implements ActionListener {
		Socket s = new Socket();
		ArrayList<String> lineList = new ArrayList<String>();
		String[] addrList = null,
				tempList = null;
		int numLines = 0,
			numChars = 0,
			shortestLine = 1000,
			longestLine = 0,
			numSpaces = 0,
			numJPEGs = 0,
			numGIFs = 0;
		
		double avgNumChars = 0.0;
	
		//Creates all the buttons and such for the application
		JPanel thing = new JPanel();
		JButton enter = new JButton("Enter");
		JTextField address = new JTextField("Enter Web Address Here");
		JTextArea results = new JTextArea();
		JScrollPane scrollingArea = new JScrollPane(results);
		JPanel buttonPanel = new JPanel();
		JPanel resultsPanel = new JPanel();

		//Adds all the buttons and such for the application
		public void init(){
			setSize(800, 600);
			setVisible(true);
			thing.setLayout(new BorderLayout(2,1));
			enter.addActionListener(this);
			buttonPanel.setLayout(new GridLayout(1,2));
			buttonPanel.add(address);
			buttonPanel.add(enter);
			thing.add(buttonPanel,BorderLayout.NORTH);
			resultsPanel.setLayout(new GridLayout(1,1));
			results.setEditable(false);
			resultsPanel.add(scrollingArea);
			thing.add(resultsPanel);
			add(thing);
		}
		
	public void actionPerformed(ActionEvent e) {
		if (e.getSource() == enter) {
			try {
				//After pressing enter, tries to get the host name from the text box
				//and split it
				results.setText("");
				String line = null,
					addr = new String(address.getText()),
					hostName = new String(),
					pagePathAndName = new String("");
				addrList = addr.split("/");
		   
				hostName = addrList[0];
		   
				for (int i = 1; i < addrList.length; i++) {
					pagePathAndName = pagePathAndName + "/" + addrList[i];
				}
				
				//Connects to the server and reads the site
				s.connect(new InetSocketAddress(hostName, 80));
				OutputStreamWriter out = new OutputStreamWriter(s.getOutputStream());
				InputStreamReader in = new InputStreamReader(s.getInputStream());
				BufferedReader bufReader = new BufferedReader(in);
			   
			   
				out.write("GET " + pagePathAndName + "\r\nHTTP/1.1\r\nHost: " + hostName + "\r\n\r\n");
				out.flush();
			   
				//Writes out each line of the site until there's nothing left
				while (true) {
					line = bufReader.readLine();
			    	if (line == null) {
						System.out.println("Connection closed by server");
						break;
			    	}
			    	lineList.add(line);
			    	results.setText(results.getText() + line + "\r\n");
				}
				
				//Finds the shortest line, longest line, number of space, images and instances of "the"
		    	numLines = lineList.size();
		    	for (int x = 0; x < numLines; x++) {
		    		tempList = lineList.get(x).split(" ");
		    		numChars += lineList.get(x).length();
		    		if (lineList.get(x).length() < shortestLine)
		    			shortestLine = lineList.get(x).length();
		    		if (lineList.get(x).length() > longestLine)
		    			longestLine = lineList.get(x).length();
		    		for (int y = 0; y < tempList.length; y++) {
		    			if (tempList[y].contains(".jpg")) {
		    				numJPEGs ++;
		    			}
		    			if (tempList[y].contains("the")) {
		    				numGIFs ++;
		    			}
		    			if (tempList[y].contains("&nbsp")) {
		    				numSpaces ++;
		    			}
		    		}
		    	}
		    	
		    	avgNumChars = numChars/numLines;
				//Prints out all the results for the read data
		    	results.setText(results.getText() + "\nNumber of lines:  " + numLines + "\n");
		    	results.setText(results.getText() + "Number of characters:  " + numChars + "\n");
		    	results.setText(results.getText() + "Shortest line:  " + shortestLine + " characters" + "\n");
		    	results.setText(results.getText() + "Longest line:  " + longestLine + " characters" + "\n");
		    	results.setText(results.getText() + "Average number of characters per line:  " + avgNumChars + "\n");
		    	results.setText(results.getText() + "Number of spaces (&nbsp):  " + numSpaces + "\n");
		    	results.setText(results.getText() + "Number of '.jpeg' files:  " + numJPEGs + "\n");
		    	results.setText(results.getText() + "Number of occurences of the word 'The':  " + numGIFs + "\n");
			} catch (IOException e1) {
				System.out.println("HOSTNAME NOT FOUND");
				e1.printStackTrace();
			}
			
			finally {
				try {
					if (s != null)
					//Closes the connection
						s.close();
					
					s = new Socket();
					lineList = new ArrayList<String>();
					addrList = null;
					tempList = null;
					numLines = 0;
					numChars = 0;
					shortestLine = 1000;
					longestLine = 0;
					numSpaces = 0;
					numJPEGs = 0;
					numGIFs = 0;
				} 
				catch (IOException e2) {
				}
			}
		}	
	}
}