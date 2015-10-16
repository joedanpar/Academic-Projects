/*********************************************************
 * Names: Joe Dan Parker, Brandon Kesler, Michael Pagano *
 * Assignment: 6                                         *
 * Due Date: 30 April 2010                               *
 * Program Purpose:	                                     *
 *********************************************************/
 import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

import java.io.*;
import java.net.*;
import java.sql.*;

public class DBApplet extends JApplet implements ActionListener {
	
	JTextField			name = new JTextField(),
						ssn = new JTextField(),
						address = new JTextField(),
						code = new JTextField("0");
	JLabel				nameLabel = new JLabel("Name"),
						ssnLabel = new JLabel("SSN"),
						addressLabel = new JLabel("Address"),
						codeLabel = new JLabel("Code");
	JButton				addButton = new JButton("Add Data"),
						updateButton = new JButton("Update Data"),
						deleteButton = new JButton("Delete Data"),
						searchButton = new JButton("Search Data"),
						getAllButton = new JButton("Get all Data");
	JTextArea			infoArea = new JTextArea();
	JScrollPane 		scrollArea = new JScrollPane(infoArea);
	JPanel				appPanel = new JPanel(),
						buttonPanel = new JPanel(),
						inputPanel = new JPanel(),
						resultsPanel = new JPanel();
	Socket				s = null;
	ObjectOutputStream	out;
	ObjectInputStream	in;
	ResultSet			rs = null;
	
	public void init() {
		
		setSize(800, 600);
		addButton.addActionListener(this);
		updateButton.addActionListener(this);
		deleteButton.addActionListener(this);
		searchButton.addActionListener(this);
		getAllButton.addActionListener(this);

		appPanel.setLayout(new BorderLayout(2,1));
		buttonPanel.setLayout(new GridLayout(1,5));
		inputPanel.setLayout(new GridLayout(2,4));
		resultsPanel.setLayout(new GridLayout(1,1));

		infoArea.setEditable(false);
		resultsPanel.add(scrollArea);
		
		buttonPanel.add(addButton);
		buttonPanel.add(updateButton);
		buttonPanel.add(searchButton);
		buttonPanel.add(deleteButton);
		buttonPanel.add(getAllButton);
		
		inputPanel.add(nameLabel);
		inputPanel.add(ssnLabel);
		inputPanel.add(addressLabel);
		inputPanel.add(codeLabel);
		inputPanel.add(name);
		inputPanel.add(ssn);
		inputPanel.add(address);
		inputPanel.add(code);
		
		appPanel.add(resultsPanel, BorderLayout.CENTER);
		appPanel.add(inputPanel, BorderLayout.NORTH);
		appPanel.add(buttonPanel, BorderLayout.SOUTH);
		add(appPanel);
		
		try {
			s = new Socket("turing.cs.niu.edu", 9722);
			out = new ObjectOutputStream(s.getOutputStream());
			in = new ObjectInputStream(s.getInputStream());
		} catch (IOException e) {
			System.err.println("IOException " + e);
		}
		
	}

	public void actionPerformed(ActionEvent e) {
		if(e.getSource()==addButton){
			doStuff(name.getText(), ssn.getText(), address.getText(), Integer.parseInt(code.getText()),"ADD");
		}
		if(e.getSource()==deleteButton){
			doStuff(name.getText(), ssn.getText(), address.getText(), Integer.parseInt(code.getText()),"DELETE");
		}
		if(e.getSource()==updateButton){
			doStuff(name.getText(), ssn.getText(), address.getText(), Integer.parseInt(code.getText()),"UPDATE");
		}
		if(e.getSource()==getAllButton){
			doStuff(name.getText(), ssn.getText(), address.getText(), Integer.parseInt(code.getText()),"GETALL");
		}
		if(e.getSource()==searchButton){
			doStuff(name.getText(), ssn.getText(), address.getText(), Integer.parseInt(code.getText()),"SEARCH");
		}
		
		try {
			rs = (ResultSet) in.readObject();
		} catch (IOException e1) {
			System.err.println("IOException " + e);
		} catch (ClassNotFoundException e1) {
			System.err.println("ClassNotFoundException " + e);
		}
		
		System.out.println(rs);
	}
	public void doStuff(String name, String ssn, String address, int code, String doing){
		if(doing.equals("ADD")){
			if(name.equals("") || ssn.equals("") || address.equals("")){
				//set error field - "you forgot a field"
				return;
			}
		}
		else if(doing.equals("DELETE")||doing.equals("SEARCH")){
			if(ssn.equals("")){
				return;
			}
		}
		
		MessageObject thingsnsuch = new MessageObject(name,ssn,address,code);
		thingsnsuch.setTransType(doing);
		try {
			out.writeObject(thingsnsuch);
			out.flush();
			out.reset();
		} catch (IOException e) {
			System.err.println("IOException " + e);
		}
	}
}
