/****************************************
 * Names: Dan Parker and Michael Pagano *
 * Course: CSCI 470                     *
 * Assignment: 1                        *
 * Date: 31 January 2010                *
 ****************************************/

import java.text.DecimalFormat;

public class CalcScore {

	DecimalFormat df = new DecimalFormat("#.000");
	public int[] quizScore;//array of the individual quiz scores
	private int finalQuizScore;
	private int midtermScore;
	private int finalExamScore;
	private int dailyWorkScore;
	private int absence;
	private int lowestQuiz;
	private double baseAverage;
	private double finalAverage;
	private static final int ABSENT_LIMIT = 5;
	
	//Constructor method for the CalcScore Class
	//It initializes all the required data members
	public CalcScore(){
	quizScore = new int[6];
	finalQuizScore = 0;
	midtermScore = 0;
	finalExamScore = 0;
	dailyWorkScore = 0;
	absence = 0;
	lowestQuiz = 0;
	baseAverage = 0.0;
	finalAverage = 0.0;
	}

	//Returns the final quiz score
	public int getFinalQuizScore(){
	return finalQuizScore;
	}

	//Returns the midterm score
	public int getMidtermScore(){
	return midtermScore;
	}

	//Returns the final exam score
	public int getFinalExamScore(){
	return finalExamScore;
	}

	//Returns the daily work score
	public int getDailyWorkScore(){
	return dailyWorkScore;
	}

	//Returns the number of absences
	public int getAbsence(){
	return absence;
	}

	//Returns the lowest quiz score
	public int getLowestQuiz(){
	return lowestQuiz;
	}

	//Returns the base average (score before absences)
	public double getBaseAverage(){
	return baseAverage;
	}

	//Returns the final average (score after absences)
	public double getFinalAverage(){
	return finalAverage;
	}

	//Sets the final quiz score
	public void setFinalQuizScore(int finalQuizScore){
	this.finalQuizScore = finalQuizScore;
	}

	//Sets the midterm score
	public void setMidtermScore(int midtermScore){
	this.midtermScore = midtermScore;
	}

	//Sets the final exam score
	public void setFinalExamScore(int finalExamScore){
	this.finalExamScore = finalExamScore;
	}

	//Sets the daily work score
	public void setDailyWorkScore(int dailyWorkScore){
	this.dailyWorkScore = dailyWorkScore;
	}

	//Sets the number of absences
	public void setAbsence(int absence){
	this.absence = absence;
	}

	//Sets the lowest quiz score
	public void setLowestQuiz(int lowestQuiz){
	this.lowestQuiz = lowestQuiz;
	}

	//Sets the base average
	public void setBaseAverage(double baseAverage){
	this.baseAverage = baseAverage;
	}

	//Sets the final average
	public void setFinalAverage(double finalAverage){
	this.finalAverage = finalAverage;
	}

	//Finds the lowest score in an array of quiz grades and returns it
	public int getLowestScores (int[] grades){
	int temp = 90;
	for (int i = 0; i < grades.length; i++){
		if(temp > grades[i])
			temp = grades[i];
	}
	return temp;
	}

	//Returns the amount of absences that exceed the absence limit
	public int adjustAbsences (int numAbsences){
	if (numAbsences > ABSENT_LIMIT)
		return numAbsences - ABSENT_LIMIT;
	else
		return 0;
	}

	//Calculates the base average grade. It also determines if a student has taken
	//the midterm and/or final yet and adjusts the calculation
	//It then returns the calculated grade
	public double calcBaseAverage (int finalQuizScore, int midtermScore, int finalExamScore, int dailyWorkScore){
	if ((midtermScore == 0 && finalExamScore > 0)||(midtermScore>0&&finalExamScore>0)){//midterm was taken and had a zero
		return (finalQuizScore + midtermScore + finalExamScore + dailyWorkScore)/400.0;
	}
	else if (midtermScore > 0 && finalExamScore == 0){//midterm was taken, final may or may not have been taken
		return (finalQuizScore + midtermScore + dailyWorkScore)/300.0;
	}	
	else{// (midtermScore == 0 && finalExamScore == 0)//neither were taken
		return (finalQuizScore + dailyWorkScore)/200.0;
	}
	}

	//Calculates the final average grade based on the base average grade
	//and the number of exceeded absences if any
	public double calcfinalAverage (double baseAverage, int absences){
	return baseAverage - (5 * absences);
	} 
}
