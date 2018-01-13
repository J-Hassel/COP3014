/* Name: Jonathan Hassel
Date: 9/21/15
Section: 12
Assignment: 3 Exercise 2 
Due Date: 10/2/15 
About this project: This program adds each number value in a string of numbers to find their total value. 
Assumptions: Assumes user enters an integer value between -2147483647 and 2147483647. 

All work below was performed by Jonathan Hassel */

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;



int SumDigits(int);																										//function prototype


int main()
{
	int number;																											//variables

	cout << "Please enter an integer (0 to quit): ";																	//prompting  user to enter an integer value
	cin >> number;

	while(number != 0)																									//loop to continue the program unless user enters 0
	{
		cout << endl << "The sum of the digits of " << number << " is " << SumDigits(number) << endl << endl;			//calls the function and prints its return value
		cout << "Please enter an integer (0 to quit): ";																
		cin >> number;
	}

	cout << endl << "Goodbye" << endl;

	return 0;
}

int SumDigits(int num)																									//function defenition
{
	int sum = 0;																										//variable only alive in SumDigits function

	while(num != 0)																										//loop that gets the last number in the string, then
	{																													//divides the number by 10, to get the next number in
		sum = sum + num % 10;																							//string. This loop continues until number is 0
		num = num / 10;
	}

	if(sum < 0)																											//if the sum is < 0 it returns the absolute value of the sum
		sum = abs(sum);

	return sum;																											//returns sum to where the function was called
}