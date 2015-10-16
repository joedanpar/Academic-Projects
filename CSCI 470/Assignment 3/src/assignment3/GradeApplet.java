/*********************************************************
 * Names: Joe Dan Parker, Brandon Kesler, Michael Pagano *
 * Assignment: 3                                         *
 * Due Date: 03 March 2010                               *
 * Program Purpose: Design an applet that will serve as  *
 *                  a grade calculator.  Users will input*
 *                  their quiz grades, midterm grade, and*
 *                  final grade into the textboxes, and  *
 *                  when they hit the calculate button,  *
 *                  their grade is along with any penalty*
 *                  applied from being absent.           *
 *********************************************************/

/*********************************************************
* Names: Joe Dan Parker, Brandon Kesler, Michael Pagano *
* Assignment: 3 *
* Due Date: 03 March 2010 *
* Program Purpose: Design an applet that will serve as *
* a grade calculator. Users will input*
* their quiz grades, midterm grade, and*
* final grade into the textboxes, and *
* when they hit the calculate button, *
* their grade is along with any penalty*
* applied from being absent. *
*********************************************************/ 
package assignment3;
import java.awt.*;
import java.awt.event.*;
import java.util.Scanner;

import javax.swing.*;
import javax.swing.event.*;

public class GradeApplet extends JApplet implements ActionListener {

	JButton b = new JButton("Push Me");
	JTextField tf = new JTextField(10);
	JTextField q1 = new JTextField(10);
	JTextField q2 = new JTextField(10);
	JTextField q3 = new JTextField(10);
	JTextField q4 = new JTextField(10);
	JTextField q5 = new JTextField(10);
	JTextField q6 = new JTextField(10);
	JTextField mid_term = new JTextField(10);
	JTextField final_score = new JTextField(10);
	JTextField work_score = new JTextField(10);
	JTextField absences = new JTextField(10);
	JTextField final_average = new JTextField(10);
	JTextField work_average = new JTextField(10);
	JTextArea ta = new JTextArea();
	JPanel quizScoresPanel = new JPanel();
	JPanel quizAnswerPanel = new JPanel();
	JPanel otherScoresPanel = new JPanel();
	JPanel topPanel = new JPanel();
	JPanel resultsPanel = new JPanel();
	JButton calcScore = new JButton("Calculate"),
			clearScores = new JButton("Clear");
	JLabel title = new JLabel("CSCI 470 Grade Calculator",JLabel.CENTER);
	
	public boolean privateKey;

	public void init() {
		setSize(600,500);
		setLayout(new GridLayout(5, 1, 5, 10));
		GridLayout quiz_layout = new GridLayout(2,6,10,5);
		GridLayout otherScores_layout = new GridLayout(2,4,10,5);
		GridLayout results_layout = new GridLayout(2,4,10,5);
		GridLayout top_layout = new GridLayout(1,1);
	
		calcScore.addActionListener(this);
		clearScores.addActionListener(this);
	    
		topPanel.setLayout(top_layout);
		topPanel.add(new JLabel("Indonesian Course Grade Calculator",JLabel.CENTER));
		topPanel.setBackground(new Color(170, 201, 170));
		add(topPanel);
	
		quizScoresPanel.setLayout(quiz_layout);
		quizScoresPanel.setBorder(BorderFactory.createTitledBorder("Quizzes"));
		for (int num = 1; num < 7; num++)
			quizScoresPanel.add(new JLabel("Quiz " + num, JLabel.CENTER));
		quizScoresPanel.add(q1);
		quizScoresPanel.add(q2);
		quizScoresPanel.add(q3);
		quizScoresPanel.add(q4);
		quizScoresPanel.add(q5);
		quizScoresPanel.add(q6); 
		quizScoresPanel.setBackground(new Color(240, 120, 121));
		add(quizScoresPanel);
	
		otherScoresPanel.setLayout(otherScores_layout);
		otherScoresPanel.setBorder(BorderFactory.createTitledBorder("Other Scores"));
		otherScoresPanel.setBackground(new Color(120, 239, 119));
		otherScoresPanel.add(new JLabel("Mid-Term", JLabel.CENTER));
		otherScoresPanel.add(new JLabel("Final", JLabel.CENTER));
		otherScoresPanel.add(new JLabel("Daily Work", JLabel.CENTER));
		otherScoresPanel.add(new JLabel("Absences", JLabel.CENTER));
		otherScoresPanel.add(mid_term);
		otherScoresPanel.add(final_score);
		otherScoresPanel.add(work_score);
		otherScoresPanel.add(absences); 
		add(otherScoresPanel);

		resultsPanel.setLayout(results_layout);
		resultsPanel.setBorder(BorderFactory.createTitledBorder("Results"));
		resultsPanel.setBackground(new Color(120, 120, 240));
		resultsPanel.add(new JLabel("", JLabel.CENTER));
		resultsPanel.add(new JLabel("", JLabel.CENTER));
		resultsPanel.add(new JLabel("Work Average", JLabel.CENTER));
		resultsPanel.add(new JLabel("Final Average", JLabel.CENTER));
		resultsPanel.add(calcScore);
		resultsPanel.add(clearScores);
		work_average.setEditable(false);
		final_average.setEditable(false); 
		resultsPanel.add(work_average);
		resultsPanel.add(final_average);
		add(resultsPanel);

		ta.setEditable(false);
		add(ta);
	}

	public void actionPerformed(ActionEvent e) {
		String tempStr = "";
		int[] quizScores = new int[6];
		int quizTotal = 0,
			lowest = 21,
			maxQuiz = 20,
			midtermGrade = 0,
			finalGrade = 0,
			dailyGrade = 0,
			absencesGrade = 0,
			penalty = 0,
			temp = 0;
		double finalAvg = 0.0,
		       workAvg = 0.0,
		       quizavg = 0.0;
		
		if (e.getSource() == calcScore) {
			boolean[] boolscores = new boolean[6];
			for(int i = 0; i<6; i++)
				boolscores[i]=true;
			tempStr = q1.getText();
			try{
				if(Integer.parseInt(tempStr) <= maxQuiz){
					quizScores[0] = Integer.parseInt(tempStr);
					if(Integer.parseInt(tempStr) < lowest)
						lowest = Integer.parseInt(tempStr); // stored the lowest quiz score into lowest variable
				} else {
					quizScores[0] = 20;
					if(Integer.parseInt(tempStr) < lowest)
						lowest = Integer.parseInt(tempStr); // stored the lowest quiz score into lowest variable
				}
			}
			catch(Exception e2){
				boolscores[0] = false;
				quizScores[0] = 0;
				lowest = 0;
			}

			tempStr = q2.getText();
			try{
			if(Integer.parseInt(tempStr) <= maxQuiz){
				quizScores[1] = Integer.parseInt(tempStr);
				if(Integer.parseInt(tempStr) < lowest)
					lowest = Integer.parseInt(tempStr); // stored the lowest quiz score into lowest variable
			} else {
				quizScores[1] = 20;
				if(Integer.parseInt(tempStr) < lowest)
					lowest = Integer.parseInt(tempStr); // stored the lowest quiz score into lowest variable
			}
			}
			catch(Exception e2){
				boolscores[1] = false;
				quizScores[1] = 0;
				lowest = 0;
			}
			tempStr = q3.getText();
			try{
			if(Integer.parseInt(tempStr) <= maxQuiz){
				quizScores[2] = Integer.parseInt(tempStr);
				if(Integer.parseInt(tempStr) < lowest)
					lowest = Integer.parseInt(tempStr); // stored the lowest quiz score into lowest variable
			} else {
				quizScores[2] = 20;
				if(Integer.parseInt(tempStr) < lowest)
					lowest = Integer.parseInt(tempStr); // stored the lowest quiz score into lowest variable
			}
			}
			catch(Exception e2){
				boolscores[2] = false;
				quizScores[2] = 0;
				lowest = 0;
			}
			tempStr = q4.getText();
			try{
			if(Integer.parseInt(tempStr) <= maxQuiz){
				quizScores[3] = Integer.parseInt(tempStr);
				if(Integer.parseInt(tempStr) < lowest)
					lowest = Integer.parseInt(tempStr); // stored the lowest quiz score into lowest variable
			} else {
				quizScores[3] = 20;
				if(Integer.parseInt(tempStr) < lowest)
					lowest = Integer.parseInt(tempStr); // stored the lowest quiz score into lowest variable
			}
			}
			catch(Exception e2){
				boolscores[3] = false;
				quizScores[3] = 0;
				lowest = 0;
			}
			tempStr = q5.getText();
			try{
			if(Integer.parseInt(tempStr) <= maxQuiz){
				quizScores[4] = Integer.parseInt(tempStr);
				if(Integer.parseInt(tempStr) < lowest)
					lowest = Integer.parseInt(tempStr); // stored the lowest quiz score into lowest variable
			} else {
				quizScores[4] = 20;
				if(Integer.parseInt(tempStr) < lowest)
					lowest = Integer.parseInt(tempStr); // stored the lowest quiz score into lowest variable
			}
			}
			catch(Exception e2){
				boolscores[4] = false;
				quizScores[4] = 0;
				lowest = 0;
			}
			tempStr = q6.getText();
			try{
			if(Integer.parseInt(tempStr) <= maxQuiz){
				quizScores[5] = Integer.parseInt(tempStr);
				if(Integer.parseInt(tempStr) < lowest)
					lowest = Integer.parseInt(tempStr); // stored the lowest quiz score into lowest variable
			} else {
				quizScores[5] = 20;
				if(Integer.parseInt(tempStr) < lowest)
					lowest = Integer.parseInt(tempStr); // stored the lowest quiz score into lowest variable
			}
			}
			catch(Exception e2){
				boolscores[5] = false;
				quizScores[5] = 0;
				lowest = 0;
			}
			boolean blanks = false;
			for(int i = 0; i < 6; i++) {
				if(boolscores[i]) {
					quizTotal += quizScores[i];
					temp++;
				}
				else if(!boolscores[i]) {
					for(int j = 1; j < 6; j++) {
						if (boolscores[j] && j > i){
							quizScores[i] = 0;
							temp++;
							boolscores[i] = true;
						}
					}
				}
			}
			/*for(int i = 0; i<5; i++){
				if(!boolscores[i]&&boolscores[i+1])
				{	
					blanks = true;
					for(int j = 0; j<i+1; j++)
						boolscores[j] = true;
				}
			}*/
			//System.out.println(blanks);

			/*for(int i = 0; i < 6; i++){
				if(boolscores[i]){
					temp++;
					quizTotal += quizScores[i];
				}
			}*/
			if(temp==6&&!blanks){
			quizTotal-=lowest;
			temp--;// subtracts the lowest quiz score from the total
			}
			quizavg = (double)quizTotal/(20*temp);
			//quizTotal = (int) (quizavg *5);
						
			boolean calcthings = true;
			try{
			tempStr = mid_term.getText();
			midtermGrade = Integer.parseInt(tempStr);
			}
			catch(Exception e1){
			calcthings = false;
			ta.setText("Invalid input for midterm grade");
			}
			
			try{
			tempStr = final_score.getText();
			finalGrade = Integer.parseInt(tempStr);
			}
			catch(Exception e1){
			calcthings = false;
			ta.setText("Invalid input for final grade");
			}
			
			try{
			tempStr = work_score.getText();
			dailyGrade = Integer.parseInt(tempStr);
			}
			catch(Exception e1){
			calcthings = false;
			ta.setText("Invalid input for Daily work");
			}
			
			try{
			tempStr = absences.getText();
			absencesGrade = Integer.parseInt(tempStr);
			}
			catch(Exception e1){
			absencesGrade = 0;
			ta.setText("Invalid input for absences. Using default value of 0.");
			}
			
			if(calcthings){
				
			if(midtermGrade <= 0 && finalGrade > 0 ){ // missing a midterm grade
		    	finalAvg += quizTotal;
		    	finalAvg += midtermGrade;
		    	finalAvg += finalGrade;
		    	finalAvg += dailyGrade;
		    	finalAvg = (finalAvg/400)*100; // calculates average with all 4 scores
		    }
		    else if(finalGrade <=0 && midtermGrade >0){ // missing a final exam grade
		    	finalAvg += quizTotal;
		    	finalAvg += midtermGrade;
		    	finalAvg += dailyGrade;
		    	finalAvg = (finalAvg/300)*100; // calculated average without a final exam score
		    }
		    else if(finalGrade <=0 && midtermGrade <=0){ // missing both midterm and final exam grade
		    	finalAvg += quizTotal;
		    	finalAvg += dailyGrade;
		    	finalAvg = (finalAvg/200)*100; // calculates average without midterm and final exam grades
		    }
		    else{ // all grades inputed
		    	finalAvg += quizTotal;
		    	finalAvg += midtermGrade;
		    	finalAvg += finalGrade;
		    	finalAvg += dailyGrade;
		    	finalAvg = (finalAvg/400)*100; // calculates average with all scores
		    }
			
			if(absencesGrade <= 5){
				work_average.setText(Double.toString(finalAvg) + "%");
				final_average.setText(Double.toString(finalAvg) + "%");
			}
		    else{  // Print out the average with a penalty
				work_average.setText(Double.toString(finalAvg) + "%");
		    	absencesGrade -= 5;
		    	penalty = absencesGrade *5;
		    	finalAvg -= penalty;
		    	final_average.setText(Double.toString(finalAvg) + "%");
		    }
			}
		}
		
		if (e.getSource() == clearScores) {
			q1.setText("");
			q2.setText("");
			q3.setText("");
			q4.setText("");
			q5.setText("");
			q6.setText("");
			mid_term.setText("");
			final_score.setText("");
			work_score.setText("");
			absences.setText("");
			final_average.setText("");
			work_average.setText("");
		}
		//tf.setText("Button pushed!");
	}

	/*private double calcFinalAvg() {
	
		double finalGrade = 0.0;
		
		return finalGrade;
	}*/
}

/*package assignment3;

import java.awt.*;
import java.awt.event.*;
import java.text.NumberFormat;

import javax.swing.*;
import javax.swing.event.*;

public class GradeApplet extends JApplet implements ActionListener {

	JButton b = new JButton("Push Me");
	JTextField tf = new JTextField(10);
	JFormattedTextField q1 = new JFormattedTextField(NumberFormat.getInstance());
	JFormattedTextField q2 = new JFormattedTextField(NumberFormat.getInstance());
	JFormattedTextField q3 = new JFormattedTextField(NumberFormat.getInstance());
	JFormattedTextField q4 = new JFormattedTextField(NumberFormat.getInstance());
	JFormattedTextField q5 = new JFormattedTextField(NumberFormat.getInstance());
	JFormattedTextField q6 = new JFormattedTextField(NumberFormat.getInstance());
	JFormattedTextField mid_term = new JFormattedTextField(NumberFormat.getInstance());
	JFormattedTextField final_score = new JFormattedTextField(NumberFormat.getInstance());
	JFormattedTextField work_score = new JFormattedTextField(NumberFormat.getInstance());
	JFormattedTextField absences = new JFormattedTextField(NumberFormat.getInstance());
	JTextField final_average = new JTextField(10);
	JTextField work_average = new JTextField(10);
	JTextArea ta = new JTextArea();
	JPanel quizScoresPanel = new JPanel();
	JPanel quizAnswerPanel = new JPanel();
	JPanel otherScoresPanel = new JPanel();
	JPanel topPanel = new JPanel();
	JPanel resultsPanel = new JPanel();
	JButton calcScore = new JButton("Calculate"),
			clearScores = new JButton("Clear");
	JLabel title = new JLabel("CSCI 470 Grade Calculator",JLabel.CENTER);
	
	public boolean privateKey;

	public void init() {
		setSize(600,500);
		setLayout(new GridLayout(5, 1, 5, 10));
		GridLayout quiz_layout = new GridLayout(2,6,10,5);
		GridLayout otherScores_layout = new GridLayout(2,4,10,5);
		GridLayout results_layout = new GridLayout(2,4,10,5);
		GridLayout top_layout = new GridLayout(1,1);
	
		calcScore.addActionListener(this);
		clearScores.addActionListener(this);
	    
		topPanel.setLayout(top_layout);
		topPanel.add(new JLabel("Indonesian Course Grade Calculator",JLabel.CENTER));
		topPanel.setBackground(new Color(170, 201, 170));
		add(topPanel);
	
		quizScoresPanel.setLayout(quiz_layout);
		quizScoresPanel.setBorder(BorderFactory.createTitledBorder("Quizzes"));
		for (int num = 1; num < 7; num++)
			quizScoresPanel.add(new JLabel("Quiz " + num, JLabel.CENTER));
		quizScoresPanel.add(q1);
		quizScoresPanel.add(q2);
		quizScoresPanel.add(q3);
		quizScoresPanel.add(q4);
		quizScoresPanel.add(q5);
		quizScoresPanel.add(q6); 
		quizScoresPanel.setBackground(new Color(240, 120, 121));
		add(quizScoresPanel);
	
		otherScoresPanel.setLayout(otherScores_layout);
		otherScoresPanel.setBorder(BorderFactory.createTitledBorder("Other Scores"));
		otherScoresPanel.setBackground(new Color(120, 239, 119));
		otherScoresPanel.add(new JLabel("Mid-Term", JLabel.CENTER));
		otherScoresPanel.add(new JLabel("Final", JLabel.CENTER));
		otherScoresPanel.add(new JLabel("Daily Work", JLabel.CENTER));
		otherScoresPanel.add(new JLabel("Absences", JLabel.CENTER));
		otherScoresPanel.add(mid_term);
		otherScoresPanel.add(final_score);
		otherScoresPanel.add(work_score);
		otherScoresPanel.add(absences); 
		add(otherScoresPanel);

		resultsPanel.setLayout(results_layout);
		resultsPanel.setBorder(BorderFactory.createTitledBorder("Results"));
		resultsPanel.setBackground(new Color(120, 120, 240));
		resultsPanel.add(new JLabel("", JLabel.CENTER));
		resultsPanel.add(new JLabel("", JLabel.CENTER));
		resultsPanel.add(new JLabel("Work Average", JLabel.CENTER));
		resultsPanel.add(new JLabel("Final Average", JLabel.CENTER));
		resultsPanel.add(calcScore);
		resultsPanel.add(clearScores);
		work_average.setEditable(false);
		final_average.setEditable(false); 
		resultsPanel.add(work_average);
		resultsPanel.add(final_average);
		add(resultsPanel);

		ta.setEditable(false);
		add(ta);
	}

	public void actionPerformed(ActionEvent e) {
		String tempStr = "";
		int[] quizScores = new int[6];
		int quizTotal = 0,
			totalQuizzes = 0,
			lowest = 21,
			maxQuiz = 20,
			midtermGrade = 0,
			finalGrade = 0,
			dailyGrade = 0,
			absencesGrade = 0,
			penalty = 0;
		double finalAvg = 0.0;
		
		if (e.getSource() == calcScore) {
			tempStr = q1.getText();
			if(Integer.parseInt(tempStr) <= maxQuiz){
				quizScores[0] = Integer.parseInt(tempStr);
				if(Integer.parseInt(tempStr) < lowest)
					lowest = Integer.parseInt(tempStr); // stored the lowest quiz score into lowest variable
			} else {
				quizScores[0] = 20;
				if(Integer.parseInt(tempStr) < lowest)
					lowest = Integer.parseInt(tempStr); // stored the lowest quiz score into lowest variable
			}
			tempStr = q2.getText();
			if(Integer.parseInt(tempStr) <= maxQuiz){
				quizScores[1] = Integer.parseInt(tempStr);
				if(Integer.parseInt(tempStr) < lowest)
					lowest = Integer.parseInt(tempStr); // stored the lowest quiz score into lowest variable
			} else {
				quizScores[1] = 20;
				if(Integer.parseInt(tempStr) < lowest)
					lowest = Integer.parseInt(tempStr); // stored the lowest quiz score into lowest variable
			}
			tempStr = q3.getText();
			if(Integer.parseInt(tempStr) <= maxQuiz){
				quizScores[2] = Integer.parseInt(tempStr);
				if(Integer.parseInt(tempStr) < lowest)
					lowest = Integer.parseInt(tempStr); // stored the lowest quiz score into lowest variable
			} else {
				quizScores[2] = 20;
				if(Integer.parseInt(tempStr) < lowest)
					lowest = Integer.parseInt(tempStr); // stored the lowest quiz score into lowest variable
			}
			tempStr = q4.getText();
			if(Integer.parseInt(tempStr) <= maxQuiz){
				quizScores[3] = Integer.parseInt(tempStr);
				if(Integer.parseInt(tempStr) < lowest)
					lowest = Integer.parseInt(tempStr); // stored the lowest quiz score into lowest variable
			} else {
				quizScores[3] = 20;
				if(Integer.parseInt(tempStr) < lowest)
					lowest = Integer.parseInt(tempStr); // stored the lowest quiz score into lowest variable
			}
			tempStr = q5.getText();
			if(Integer.parseInt(tempStr) <= maxQuiz){
				quizScores[4] = Integer.parseInt(tempStr);
				if(Integer.parseInt(tempStr) < lowest)
					lowest = Integer.parseInt(tempStr); // stored the lowest quiz score into lowest variable
			} else {
				quizScores[4] = 20;
				if(Integer.parseInt(tempStr) < lowest)
					lowest = Integer.parseInt(tempStr); // stored the lowest quiz score into lowest variable
			}
			tempStr = q6.getText();
			if(Integer.parseInt(tempStr) <= maxQuiz){
				quizScores[5] = Integer.parseInt(tempStr);
				if(Integer.parseInt(tempStr) < lowest)
					lowest = Integer.parseInt(tempStr); // stored the lowest quiz score into lowest variable
			} else {
				quizScores[5] = 20;
				if(Integer.parseInt(tempStr) < lowest)
					lowest = Integer.parseInt(tempStr); // stored the lowest quiz score into lowest variable
			}
			
			/*for(int i = 0; i < 6; i++) {
				if(quizPanelArray[i].getText() != ""){
					quizTotal += quizScores[i];
					totalQuizzes++;
				}
				else if(quizPanelArray[i].getText() == ""){
					for(int j = 1; j < 6; j++) {
						if (quizPanelArray[j] != "" && j > i){
							quizScores[i] = 0;
							totalQuizzes++;
						}
					}
				}
			}
			
			for(int i = 0; i < 6; i++) {
				quizTotal += quizScores[i];
				totalQuizzes++;
			}
			
			quizTotal -= lowest; // subtracts the lowest quiz score from the total
			
			tempStr = mid_term.getText();
			midtermGrade = Integer.parseInt(tempStr);
			
			tempStr = final_score.getText();
			finalGrade = Integer.parseInt(tempStr);
			
			tempStr = work_score.getText();
			dailyGrade = Integer.parseInt(tempStr);
			
			tempStr = absences.getText();
			absencesGrade = Integer.parseInt(tempStr);
			
			if(midtermGrade <= 0 && finalGrade > 0 ){ // missing a midterm grade
		    	finalAvg += quizTotal;
		    	finalAvg += midtermGrade;
		    	finalAvg += finalGrade;
		    	finalAvg += dailyGrade;
		    	finalAvg = (finalAvg/400)*100; // calculates average with all 4 scores
		    }
		    else if(finalGrade <=0 && midtermGrade >0){ // missing a final exam grade
		    	finalAvg += quizTotal;
		    	finalAvg += midtermGrade;
		    	finalAvg += dailyGrade;
		    	finalAvg = (finalAvg/300)*100; // calculated average without a final exam score
		    }
		    else if(finalGrade <=0 && midtermGrade <=0){ // missing both midterm and final exam grade
		    	finalAvg += quizTotal;
		    	finalAvg += dailyGrade;
		    	finalAvg = (finalAvg/200)*100; // calculates average without midterm and final exam grades
		    }
		    else{ // all grades inputed
		    	finalAvg += quizTotal;
		    	finalAvg += midtermGrade;
		    	finalAvg += finalGrade;
		    	finalAvg += dailyGrade;
		    	finalAvg = (finalAvg/400)*100; // calculates average with all scores
		    }
			
			if(absencesGrade <= 5){
				work_average.setText(Double.toString(finalAvg) + "%");
				final_average.setText(Double.toString(finalAvg) + "%");
			}
			else{ // Print out the average with a penalty
				work_average.setText(Double.toString(finalAvg) + "%");
				absencesGrade -= 5;
				penalty = absencesGrade *5;
				finalAvg -= penalty;
				final_average.setText(Double.toString(finalAvg) + "%");
			} 
		}
		
		if (e.getSource() == clearScores) {
			q1.setText("");
			q2.setText("");
			q3.setText("");
			q4.setText("");
			q5.setText("");
			q6.setText("");
			mid_term.setText("");
			final_score.setText("");
			work_score.setText("");
			absences.setText("");
			final_average.setText("");
			work_average.setText("");
		}
		//tf.setText("Button pushed!");
	}

	/*private double calcFinalAvg() {
	
		double finalGrade = 0.0;
		
		return finalGrade;
	}
}*/