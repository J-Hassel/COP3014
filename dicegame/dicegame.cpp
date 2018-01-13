/* Name: Jonathan Hassel 
Date: 10/14/15 
Section: 12 
Assignment: Assignment# 4 
Due Date: 10/19/15 
About this project: This projects goals are to use functions and random number generation to create a betting game of chance. 
Assumptions: Assumes the user enters only an integer value as a bet.

All work below was performed by Jonathan Hassel */

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//FUNCTION PROTOTYPES
void welcome();
void roll(int&, int&);
bool winOrLose(int, int);

int main()
{
	const int startingMoney = 500;															//variables
	int currentMoney = 500, die1, die2, userBet;

	srand((unsigned int)time(0));															//seeding the time for RNG
	
	welcome();																				//calling the welcome function

	do
	{																						//do while loop that prompts the user, telling them how much money
		cout << "You have $" << currentMoney << " remaining" << endl;						//they have left , and asks them to place their bet
		cout << "Place your bet: ";
		cin >> userBet;

		if(userBet > currentMoney)
			cout << "You can't bet more $ than you have!" << endl << endl;					//if statements telling the user things they cant bet(more money
		else if(userBet == 0)																//than they have, 0, etc) 
			cout << "You can't bet 0!" << endl << endl;
		else if(userBet > 0)																//if the bet is valid, initiates the dice roll
		{
			currentMoney -= userBet;
			roll(die1, die2);

			cout << "You rolled " << die1 << " and " << die2 << " = " << die1 + die2 << endl;	//tells what each die rolled, and adds them

			if(winOrLose(die1, die2) == true)												//calls the win or lose function which checks if both die add up to
			{																				//7. If they do it returns the value true, else returns false 
				cout << "You Win!!" << endl << endl;

				currentMoney += (2 * userBet);												//if they win they win what they bet * 2.
			}
			else
			{
				cout << "You Lose!!" << endl << endl;

				if(currentMoney == 0)
					cout << "You're broke!" << endl << "Thanks for playing!" << endl;		//if the user has no money left, game ends
			}
		}
		else
		{
			if(currentMoney < startingMoney)												//if user leaves with less money, it tells them how much
			{
				cout << endl << "You're leaving with $" << currentMoney << endl;
				cout << "You LOST $" << startingMoney - currentMoney << "!!!" << endl;
				cout << "Thanks for playing!" << endl;
				break;
			}
			else if(currentMoney > startingMoney)											//if user leaves with more money, it tells them how much
			{
				cout << endl << "You're leaving with $" << currentMoney << endl;
				cout << "You MADE $" << currentMoney - startingMoney << "!!!" << endl;
				cout << "Thanks for playing!" << endl;
				break;
			}
		}
	}while(currentMoney > 0);

	return 0;
}


//FUNCTION DEFENITIONS
void welcome()
{
	cout << "***** Welcome to SEVENS! *****" << endl << "Wager whatever you'd like. If you roll a 7, you win whatever you bet!" << endl;
	cout << "But beware, if you don't roll a 7, you lose your wager" << endl << "Enter a negative bet to quit." << endl;
	cout << "LETS BEGIN!!!" << endl << endl;
}

void roll(int& num1, int& num2)									//function rolls 2 die 1-6
{
	num1 = (rand() % 6) + 1;
	num2 = (rand() % 6) + 1;
}

bool winOrLose(int num1, int num2)								//function that checks if the die add up to 7. if so, returns true, else false
{
	if(num1 + num2 == 7)
		return true;
	else
		return false;
}