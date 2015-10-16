/****************************************
 * Names: Dan Parker and Michael Pagano *
 * Course: CSCI 470                     *
 * Assignment: 1                        *
 * Date: 31 January 2010                *
 ****************************************/

import java.util.Scanner;
import java.text.DecimalFormat;

public class Calcerthing {

	public static void main(String[] args) {
		CalcScore calcings = new CalcScore();
		DecimalFormat df = new DecimalFormat("#.00");
		Scanner scan = new Scanner(System.in);
		System.out.println("Welcome to the CSCI 470 automatic grade calculator. Please enter correct numeric values for each of the following:");
		String tempS;
		int tempI;
		//Reads in the individual quiz scores
		//converts them into the data type int
		//and puts them into the array quizScore
		for(int i = 1; i < 7; i++){
		System.out.println("Quiz " + i + ": ");
		tempS = scan.next();
		tempI = Integer.parseInt(tempS);
		calcings.quizScore[i-1] = tempI;
		}

		System.out.println("Mid-term exam: ");
		tempS = scan.next();
		tempI = Integer.parseInt(tempS);
		calcings.setMidtermScore(tempI);
		System.out.println("Final exam: ");
		tempS = scan.next();
		tempI = Integer.parseInt(tempS);
		calcings.setFinalExamScore(tempI);
		System.out.println("Total daily assignments: ");
		tempS = scan.next();
		tempI = Integer.parseInt(tempS);
		calcings.setDailyWorkScore(tempI);
		System.out.println("Total unexcused absences: ");
		tempS = scan.next();
		tempI = Integer.parseInt(tempS);
		calcings.setAbsence(tempI);
		
		calcings.setLowestQuiz(calcings.getLowestScores(calcings.quizScore));
		calcings.setAbsence(calcings.adjustAbsences(calcings.getAbsence()));
		int temp = 0;
		for (int i = 0; i < calcings.quizScore.length; i++){
		temp += calcings.quizScore[i];
		}
		temp -= calcings.getLowestQuiz();
		calcings.setFinalQuizScore(temp);
		calcings.setBaseAverage((calcings.calcBaseAverage(calcings.getFinalQuizScore(),calcings.getMidtermScore(),calcings.getFinalExamScore(),calcings.getDailyWorkScore())));
		calcings.setFinalAverage(calcings.calcfinalAverage(calcings.getBaseAverage(), calcings.getAbsence()));
		System.out.println("Thank you for your input. Computing scores...");//Omnomnoming scores...

		System.out.println("Final quiz grade: " + calcings.getFinalQuizScore());
		System.out.println("Mid-term grade: " + calcings.getMidtermScore());
		System.out.println("Final exam grade: " + calcings.getFinalExamScore());
		System.out.println("Total daily assignments: " + calcings.getDailyWorkScore());
		System.out.println("Total affected absences: " + calcings.getAbsence());
		System.out.println("Course Average: " + df.format(calcings.getBaseAverage()));
		System.out.println("Final Grade: " + df.format(calcings.getFinalAverage())); 
	}

}
