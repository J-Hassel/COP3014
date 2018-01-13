/* Name: Jonathan Hassel
Date: 9/15/15 
Section: 12 
Assignment: 2 
Due Date: 9/18/15 
About this project: This program lets the user choose a medium they want a sound wave to trave through, and calculates how long it takes depending on the users entered distance. 
Assumptions: Assumes user enters capital or lowercase A, W, or S. Also assume user does not enter a negative distance.

All work below was performed by Jonathan Hassel */

#include <iostream>
#include <iomanip>
using namespace std;


int main()
{
	char medium;																									//All the variables
	double distance, time;
	int airSpeed = 343, waterSpeed = 1433, steelSpeed = 5790;

	cout << "Welcome to Sound Wave Calculator" << endl << endl;														//Welcoming the user
	cout << "Select the medium the sound wave will travel through." << endl;										//Prompting the user to choose a medium the wave will travel through
	cout << "	A	Air" << endl << "	W	Water" << endl << "	S	Steel" << endl << endl << ">";
	cin >> medium;

	if(medium != 'a' && medium != 'A' && medium != 'w' && medium != 'W' && medium != 's' && medium != 'S')			//If user enters an incorrect value, programs ends.
		cout << "Illegal entry. Aborting program." << endl << "Goodbye" << endl;
	else																											//Prompts the user to enter the distance it will travel
	{
		cout << endl << "How far will the sound wave travel (in meters)? ";
		cin >> distance;

		if(distance < 0)																							//Aborts the program if distance is negative
			cout << "Distance cannot be negative. Aborting program." << endl << "Goodbye" << endl;
		else
		{
			cout << fixed;																							//Making it so decimals go to 4 places
			cout << showpoint;
			cout << setprecision(4);

			switch(medium)																							
			{
				case 'A':																							//If the user entered 'a' or 'A', it uses the airSpeed equation
				case 'a':
					time = distance / airSpeed;
					break;

				case 'W':																							//"
				case 'w':
					time = distance / waterSpeed;
					break;

				case 'S':																							//"
				case 's':
					time = distance / steelSpeed;
					break;
			}

			cout << "The sound wave will travel " << time << " seconds" << endl << "Goodbye" << endl;				//Tells the user how long it will take for the sound wave to travel through the medium
		}
	}
	
	return 0;
}
