/* Name: Jonathan Hassel 
Date: 9/3/2015 
Section: 12 
Assignment: Assignment# 1 
Due Date: 9/10/2015 
About this project: The goal of this project was to practice the basic input/output features along with arithmetic operations.
Assumptions: I assume that the user will input the correct type of value, know to press enter to move to next section, and inputs the correct number of people.

All work below was performed by Jonathan Hassel */

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	const double priceAdult = 28.50;										//All the variables
	const double priceChild = 12.50;
	const double priceSenior = 16.50;
	const double taxRate = 0.07;
	double adultTotal, childTotal, seniorTotal;
	double totalBeforeTax, tax, totalAfterTax;
	int numAdult, numChild, numSenior;
	adultTotal = childTotal = seniorTotal = 0.0;

	cout << "Welcome to the FSU Football ticket system!" << endl;			//Printing a welcome message to the screen
	cout << "Please enter the number of: " <<  endl << "	Adults" << endl << "	Children(up to age of 12)" << endl;			//Prompting a user to input numbers
	cout << "	Seniors(60+)" << endl;
	cout << "Adults--> "; 
	cin >> numAdult;														//Using cin to get the users input, then storing their input into a variable
	cout << "Children--> "; 
	cin >> numChild;			
	cout << "Senior--> "; 
	cin >> numSenior;
	cout << "-------------------------------" << endl;

	adultTotal = numAdult * priceAdult;										//Calculating the total price of each category: adult, child and senior
	childTotal = numChild * priceChild;										
	seniorTotal = numSenior * priceSenior;									
	totalBeforeTax = adultTotal + childTotal + seniorTotal;					//Adding all the totals for the total before tax
	tax = totalBeforeTax * taxRate;											//Finding the tax
	totalAfterTax = totalBeforeTax + tax;									//Adding everything together to get price after tax

	cout << fixed;															//Making it so decimals go to 2 places
	cout << showpoint;
	cout << setprecision(2);
	cout << "TOTAL (before tax) = $" << totalBeforeTax << endl;				//Telling the user how much the tickets costed before tax using the variable that stores the calculated value
	cout << "Tax = $" << totalBeforeTax * taxRate << endl;					//The cost of the tax using the variable that stores the calculated value
	cout << "TOTAL COST (after tax) = $" << totalAfterTax << endl;			//Total cost after tax using the variable that stores the calculated value
	cout << endl << "Thanks for using the ticket system!" << endl;

	return 0;
}