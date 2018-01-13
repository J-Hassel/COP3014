/* Name: Jonathan Hassel
Date: 11/6/15 
Section: 12 
Assignment: Assignment# 6 
Due Date: 11/10/15 
About this project: The goal of this project is to create a password program that requires at least one lowercase, uppercase and digit. The password must also be 6 characters long. 
Assumptions: Assumes the user satifies all requirements and then verifies the password.

All work below was performed by Jonathan Hassel */

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
	string password, verification;

	while(true)
	{
		int lower = 0, upper = 0, digit = 0, error = 0;

		cout << "Enter your password: ";															//prompts user to enter a password
		getline(cin, password);

		//checks if length is less than 6
		if(password.size() < 6)
		{
			cout << "Password needs to have 6 or more characters" << endl;
			error++;
		}

		//checks for a lowercase
		for(int i = 0; i < password.size(); i++)
		{
			if(islower(password[i]))
				lower++;
		}
		if(lower == 0)
		{
			cout << "Password needs to contain at least one lowercase letter" << endl;
			error++;
		}

		//checks for an uppercase
		for(int i = 0; i < password.size(); i++)
		{
			if(isupper(password[i]))
				upper++;
		}
		if(upper == 0)
		{
			cout << "Password needs to contain at least one uppercase letter" << endl;
			error++;
		}

		//checks for a digit
		for(int i = 0; i < password.size(); i++)
		{
			if(isdigit(password[i]))
				digit++;
		}
		if(digit == 0)
		{
			cout << "Password needs to contain at least one digit" << endl;
			error++;
		}

		//checks that password meets all requirements
		if(error == 0)
		{
			cout << "Now re-enter your password for verification: ";								//prompts user to verify the password
			getline(cin, verification);

			if(password == verification)															//if the passwords match it tells the user and breaks the loop
			{
				cout << endl << "You have now entered a valid password" << endl;
				break;
			}
			else																					//if the password does not match the loop starts over
				cout << "Password does not match. Start over" << endl;
		}

		cout << endl;
	}

	return 0;
}