/* Name: Jonathan Hassel 
Date: 11/18/15
Section: 12 
Assignment: Assignment# 7 
Due Date: 12/3/15 
About this project: This projects goals are to read in input from a file, and manipulate it through a menu system. 
Assumptions: Assumes the correct file is in the folder along with this .cpp file. Assumes correct user input. 

All work below was performed by Jonathan Hassel */

#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
struct teamInfo																									//Struct containing 5 variables
{
	char teamName[40];
	int numWins, numLosses, wlDifferential;
	bool playoffChance;
};

//Function Prototypes
void menu();
void sortAscending(teamInfo*, int);

int main()
{
	int arrSize, menuChoice, userWins, n = 0, k = 0;															//Variables
	char fileName[20];
	ifstream fin;

	do																											//do while loop that asks for the name of the input file
	{																											//if the incorrect file is typed, it tells the user to try again
		fin.clear();																							//you can only continue with the program when the correct file is entered						
		cout << "Please enter the name of the input file." << endl << "Filename: ";
		cin >> fileName;

		fin.open(fileName);
		if(!fin)
			cout << "That is not a valid file. Try again!" << endl;
		else
			break;
	}while(true);

	fin >> arrSize;																								//reads in the first number in the file. Used to size the array

	teamInfo* team = new teamInfo [arrSize];																	//dynamic array
	
	for(int i = 0; i < arrSize; i++)																			//for loop that reads in team name, wins, losses, and their playoff chance
	{
		fin.get();
		fin.getline(team[i].teamName, 40, ',');

		fin >> team[i].numWins;
		fin.get();

		fin >> team[i].numLosses;
		fin.get();

		fin >> team[i].playoffChance;

		if(team[i].playoffChance == 1)																			//for comma issue, counts the number of playoff teams
			n++;

		team[i].wlDifferential = team[i].numWins - team[i].numLosses;											//calculates w/l differential
	}	
	fin.close();																								//closes the file
	
	while(true)																									//menu loop that prompts user to select a menu item
	{
		menu();
		cout << "Choice: ";
		cin >> menuChoice;

		switch(menuChoice)
		{
			case 1:																								//prints teams and their w/l
				cout << endl << "Team W-L:" << endl;

				for(int i = 0; i < arrSize; i++)
					cout << team[i].teamName << " " << team[i].numWins << "-" << team[i].numLosses << endl;
				break;

			case 2:																								//prints teams with x wins
				cout << endl << "Show teams with at least how many wins? --> ";
				cin >> userWins;

				for(int i = 0; i < arrSize; i++)
				{
					if(team[i].numWins >= userWins)
						cout << team[i].teamName << endl;
				}
				break;

			case 3:																								//prints playoff teams
				cout << endl << "Playoff teams:" << endl;
				
				for(int i = 0; i < arrSize; i++)
				{
					if(team[i].playoffChance == 1)
					{
						cout << team[i].teamName;
						
						if(k < n - 1)
						{
							cout << ", ";
							k++;
						}
					}
				}
				cout << endl;
				break;

			case 4:																								//prints teams and their respective w/l differentials
				cout << endl;
				
				for(int i = 0; i < arrSize; i++)
				{
					if(team[i].wlDifferential > 0)
						cout << team[i].teamName << " +" << team[i].wlDifferential << endl;
					else
						cout << team[i].teamName << " " << team[i].wlDifferential << endl;
				}
				break;

			case 5:																							//sorts teams in ascending order by w/l differential
				cout << endl << "Win/Loss differential in ascending order:" << endl << endl;

				sortAscending(team, arrSize);

				for(int i = 0; i < arrSize; i++)
				{
					if(team[i].wlDifferential > 0)
						cout << team[i].teamName << " +" << team[i].wlDifferential << endl;
					else
						cout << team[i].teamName << " " << team[i].wlDifferential << endl;
				}
				break;

			default:																						//if menu choice != 0 prints error
				if(menuChoice != 0)
					cout << endl << "Invalid choice." << endl;
		}

		if(menuChoice == 0)																					//closes program
		{
			cout << endl << "Goodbye!" << endl;
			break;
		}

		cout << endl;
	}


	delete [] team;																							//deletes dynamic array pointed to by team
	team = 0;

	return 0;
}

void menu()																									//prints menu
{
	cout << "Select one of the following choices: " << endl;
	cout << "\t1 - View team Win/Loss records" << endl;
	cout << "\t2 - Show teams with at least x wins" << endl;
	cout << "\t3 - List teams that made the playoffs" << endl;
	cout << "\t4 - List teams and their win/loss differential" << endl;
	cout << "\t5 - Sort teams by Win/Loss differential" << endl;
	cout << "\t0 - Exit Program" << endl;
	cout << "------------------------------------------" << endl;
}

void sortAscending(teamInfo* arr, int size)																	//sorts in ascending order
{
	int temp;

	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size - 1; j++)
		{
			if(arr[j].wlDifferential > arr[j + 1].wlDifferential)
			{
				temp = arr[j].wlDifferential;
				arr[j].wlDifferential = arr[j + 1].wlDifferential;
				arr[j + 1].wlDifferential = temp;
			}
		}
	}
}