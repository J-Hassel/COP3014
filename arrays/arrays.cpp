/* Name: Jonathan Hassel 
Date: 10/21/15 
Section: 12 
Assignment: Assignment# 5 
Due Date: 10/30/15
About this project: This projects goals are to use functions and a menu loop to populate and edit arrays.
Assumptions: Assumes correct user input, assumes user enters only the size of the array(no more, no less).

All work below was performed by Jonathan Hassel */

#include <iostream>
using namespace std;


//FUNCTION PROTOTYPES
void PrintArray (const int arr[], const int size);
void FillArray(int arr[], const int size);
void Insert(int [], int, int, int);
void Delete(int [], int, int);
void Reverse(int [], int);
void TimesWhat(int [], int, int);
int SumOdds(const int [], int, int);
void menu();

int main()
{
   const int SIZE = 15;
   int array[SIZE], newValue, insertIndex, deleteIndex, multiplyBy, numOdds;										//necessary variables
   char menuSelection;

   menu();																											//prints menu

   do																												//do while loop which loops the menu selection process
   {
	   cout << "Enter your menu selection: ";
	   cin >> menuSelection;

	   switch(menuSelection)																						//switch statement that checks the user input
	   {																											//and chooses the corresponding path
		case 'P':
		case 'p':
			PrintArray(array, SIZE);		//calling PrintArray
			break;

		case 'F':
		case 'f':
			FillArray(array, SIZE);			//calling FillArray
			break;

		case 'I':
		case 'i':
			cout << "Enter a value to insert: ";																	//asks for a value to insert and at which index
			cin >> newValue;
			cout << "Enter index at which to insert: ";
			cin >> insertIndex;
			Insert(array, SIZE, newValue, insertIndex);																//then calls the insert and print functions
			PrintArray(array, SIZE);
			break;

		case 'D':
		case 'd':
			cout << "Enter index of item to delete: ";																//asks for an index to delete
			cin >> deleteIndex;
			Delete(array, SIZE, deleteIndex);																		//then calls the delete and print functions
			PrintArray(array, SIZE);
			break;

		case 'R':
		case 'r':
			Reverse(array, SIZE);																					//reverses the array, then prints it
			PrintArray(array, SIZE);
			break;

		case 'T':
		case 't':
			cout << "Enter value for multiplication of array contents: ";											//asks for a value to multiply the whole array by
			cin >> multiplyBy;
			TimesWhat(array, SIZE, multiplyBy);																		//then calls the multiply and print functions
			PrintArray(array, SIZE);
			break;

		case 'S':
		case 's':
			cout << "How many odd numbers to add: ";																//asks how many odd numbers to add up
			cin >> numOdds;
			while(numOdds > SIZE || numOdds < 0)																	//error message if value entered is out of the range of the array
			{
				cout << endl << "Error: This value is out of the range of the array. Re-enter a value" << endl;
				cout << "How many odd numbers to add: ";
				cin >> numOdds;
			}																										//if value entered is valid, then it calls the sumOdds function
			cout << "The sum of the first " << numOdds << " odd numbers is: " << SumOdds(array, SIZE, numOdds) << endl <<endl;
			break;

		case 'M':
		case 'm':
			cout << endl;																							//prints the menu
			menu();
			break;
	   }

	   if(menuSelection == 'Q' || menuSelection == 'q')																//if q is entered, then program prints the array and exits
	   {
		   PrintArray(array, SIZE);
		   break;
	   }
   }while(1);





   return 0;
}

//FUNCTION DEFENITIONS
void Insert(int arr[], int size, int newValue, int whichIndex)
{																//inserts a number into an index, then shifts everything to the right
	if(whichIndex > size - 1)
		return;
	else if(whichIndex < 0)
		return;

	for(int i = 0; i < size - whichIndex; i++)
	{
		arr[size - i - 1] = arr[size - i - 2];
	}
	arr[whichIndex] = newValue;
}

void Delete(int arr[], int size, int whichIndex)				//deletes an index, then shifts everything to the left
{
	if(whichIndex > size - 1)
		return;
	else if(whichIndex < 0)
		return;
	
	for(int i = whichIndex; i < size; i++)						
		arr[i] = arr[i + 1];

	arr[size - 1] = 0;
}

void Reverse(int arr[], int size)								//reverses the array
{
	int temp;

	for(int i = 0; i < size/2; i++)
	{
		temp = arr[i];
		arr[i] = arr[size - i - 1];
		arr[size - i - 1] = temp;
	}
}

void TimesWhat(int arr[], int size, int multiplyBy)				//multiplies the array by x
{
	for(int i = 0; i < size; i++)
		arr[i] = (arr[i] * multiplyBy);
}

int SumOdds(const int arr[], int size, int numOdds)				//adds the first x odd numbers
{
	int i = 0, count = 0, sum = 0;
	
	while(count < numOdds && i < size)
	{
		if(arr[i] % 2 == 1)
		{
			sum += arr[i];
			count++;
		}
		i++;
	}
	return sum;
}

void menu()														//prints the menu
{
	cout << "	** Given features **" << endl;
	cout << "P	Print the array contents" << endl << "F	Fill the array (user entry)" << endl << endl;
	cout << "	** Function Tests **" << endl;
	cout << "I	Insert" << endl << "D	Delete" << endl << "R	Reverse" << endl << "T	TimesWhat" << endl << "S	SumOdds" << endl << endl;
	cout << "M	Print this menu" << endl << "Q	Quit this program" << endl << endl;
}

void PrintArray(const int arr[], const int size)
// this function prints the contents of the array
{
   cout << "\nThe array:\n { ";

   for (int i = 0; i < size - 1; i++)	// print all but last item
		cout << arr[i] << ", ";

   cout << arr[size - 1] << " }\n\n";	// print last item
}

void FillArray(int arr[], const int size)
// this function loads the contents of the array with user-entered values
{
   cout << "Please enter " << size << " integers to load into the array\n> ";

   for (int i = 0; i < size; i++)
		cin >> arr[i];			// enter data into array slot
   cout << endl;
}
