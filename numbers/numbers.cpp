/* Name: Jonathan Hassel 
Date: 9/19/15 
Section: 12 
Assignment: 3 Exercise 1 
Due Date: 10/2/15
About this project: The goal of this project is to look at a list of numbers, determin how many are positive/negative, get the sum of all the numbers and the average. 
Assumptions: Assumes user enters only integers.

All work below was performed by Jonathan Hassel */

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int number, sum = 0, numPositive = 0, numNegative = 0;						//declaring/initializing variables
	double  i = -1, average;

	do
	{
		cout << "Input integer (0 to stop): ";									//prompting user to enter a number
		cin >> number;

		if(number > 0)															//if a positive number is entered, then +1 is added to numPositive
			numPositive++;
		else if(number < 0)														//if a negative number is entered, then +1 is added to numNegative
			numNegative++;

		sum = sum + number;														//running total sum of the numbers entered

		i++;

	}while(number != 0);														//this loop runs once, and continues to run until number == 0

	cout << showpoint;															//allows for decimals to 2 places
	cout << fixed;
	cout << setprecision(2);

	if(sum == 0)																//if sum == 0, the average shows as 0 instead of -1.#J
		average = 0;
	else																		//gets the average
		average = sum / i;												

	cout << endl << "# of positives = " << numPositive << endl;					//tells the user all of the information about the  numbers they entered
	cout << "# of negatives = " << numNegative << endl;
	cout << "Sum = " << sum << endl;
	cout << "Average = " << average << endl;

	return 0;
}