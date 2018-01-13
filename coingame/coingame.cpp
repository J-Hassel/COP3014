/* Name: Jonathan Hassel
Date: 9/14/15 
Section: 12 
Assignment: Assignment# 2 Exercise 2
Due Date: 9/18/15 
About this project: This program allows the user to try to match a value they entered through them guessing how many coins it takes to reach that value. If they are off, it tells them  by how much. 
Assumptions: Assumes user does want to play the game, does not enter negative coin numbes. Also assumes coins have the appropriate value.

All work below was performed by Jonathan Hassel */

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	char userResponse;																									//All the variables for this assignment
	double dollarAmount, userTotal, difference; 
	double halfDollarAmount = 0.50, quarterAmount = 0.25, dimeAmount = 0.10, nickelAmount = 0.05, pennyAmount = 0.01;	//Assigning values to the coins
	int halfDollar, quarter, dime, nickel, penny;																		//For user input

	cout << "Welcome to the coin game!" << endl << "Would you like to play? (y or n) --> ";								//Asking user if they want to play the game
	cin >> userResponse;

	cout << fixed;																										//Setting decimals to 2 places
	cout << showpoint;
	cout << setprecision(2);
	
	if(userResponse == 'y')																								//Initiates the game
	{
		cout << "What amount of $ would you like to match? --> ";														//Asking user what amount they want to match
		cin >> dollarAmount;
		cout << "Okay! You need to match the value of $" << dollarAmount << endl;
		cout << "Enter the number of: " << endl << "	Half Dollars: ";												//Prompting them to enter the number of coins
		cin >> halfDollar;																								
		cout << "	Quarters: ";																						//"																				
		cin >> quarter;
		cout << "	Dimes: ";																							//"
		cin >> dime;
		cout << "	Nickels: ";																							//"
		cin >> nickel;
		cout << "	Pennies: ";																							//"
		cin >> penny;

		if(halfDollar < 0)																								//Error checking. Making sure they dont
			cout << "You can't enter a negative amount of coins. Aborting game." << endl;								//enter a negative value for coins
		else if(quarter < 0)
			cout << "You can't enter a negative amount of coins. Aborting game." << endl;								//"
		else if(dime < 0)
			cout << "You can't enter a negative amount of coins. Aborting game." << endl;								//"
		else if(nickel < 0)
			cout << "You can't enter a negative amount of coins. Aborting game." << endl;								//"
		else if(penny < 0)
			cout << "You can't enter a negative amount of coins. Aborting game." << endl;								//"
		else
		{
			userTotal = (halfDollar*halfDollarAmount)+(quarter*quarterAmount)+(dime*dimeAmount)+(nickel*nickelAmount)+(penny*pennyAmount);	//Calculations

			if(userTotal > dollarAmount)																				//Makes sure the value they lost by
				difference = userTotal - dollarAmount;																	//is always positive
			else if(dollarAmount > userTotal)
				difference = dollarAmount - userTotal;

			if(userTotal == dollarAmount)																				//If their coins added up to the amount
				cout << "You WIN!" << endl << "Thanks for playing!" << endl;											//they wanted to match, it tells them
			else if(userTotal != dollarAmount)																			//they won. If not, it tells them they 
				cout << "You LOST by: $" << difference << endl << "Thanks for playing!" << endl;						//lost and by how much.
		}
	}
	else if(userResponse == 'n')																						//If user does not want to play, aborts game.
		cout << "Guess you're scared! Come back when you're ready to play!" << endl;									
	else
		cout << "Invalid entry, aborting program." << endl;																//Aborts game for incorrect response																				

	return 0;
}