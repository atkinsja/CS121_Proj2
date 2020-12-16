//***********************************************************
//
// Programmer:		Jeremy Atkins
// Instructor		Professor Mackay
// Course:			CS 121
// Date:			4/11/2018
// Program Name:	Project_2
// Program file:	Project_2.cpp
// Input files:		None
// Output Files:	None
// Included files:	Project_2.cpp
// Purpose:			Provides a menu for the user to choose
//					a pattern, asks for a size, and then
//					displays the chosen pattern on the 
//					console. Includes input validation
//					for all user inputs
//
//***********************************************************
#include <iostream>

using namespace std;

//function declarations
void diag_left_to_right(int);
void diag_right_to_left(int);
void fill_left_to_right(int);
void fill_right_to_left(int);
bool validate_input(int&, int);
int get_size();

//***********************************************************
// Function Name:			main
// Purpose:					Driver to print the menu and
//							call functions according to
//							the user input
// Parameters:				none
// 	Input:					none
// 	Output:					Menu options and the pattern
//							selected
// Return Value:			int 0 when exit is selected
// Functions Called:		validate_input
//							get_size
//							diag_left_to_right
//							diag_right_to_left
//							fill_left_to_right
//							fill_right_to_left
//***********************************************************
int main()
{
	const int size_of_menu = 5;		//size of main menu
	int selection, size;
	
	//start main function do-while loop
	do
	{
		//start main menu do-while loop
		do 
		{
			//menu options
			cout << "Your options are:" << endl;
			cout << "1: A square with a left to right diagonal" << endl;
			cout << "2: A square with a right to left diagonal" << endl;
			cout << "3: A square that fills left to right" << endl;
			cout << "4: A square that fills right to left" << endl;
			cout << "5: Exit" << endl;

			cout << "\nChoose an option: ";
		} while (!validate_input(selection, size_of_menu));		//end do-while for input validation
			
		//switch for the main menu
		switch (selection)
		{
		case 1:
			//square with a left to right diagonal
			system("cls");
			size = get_size();
			diag_left_to_right(size);
			break;
		case 2:
			//square with a right to left diagonal
			system("cls");
			size = get_size();
			diag_right_to_left(size);
			break;
		case 3:
			//square that fills left to right
			system("cls");
			size = get_size();
			fill_left_to_right(size);
			break;
		case 4:
			//square that fills right to left
			system("cls");
			size = get_size();
			fill_right_to_left(size);
			break;
		case 5:
			//exit option
			system("cls");
			cout << "Exitting" << endl;
			return 0;
		default:
			//default option that should never be accessed
			system("cls");
			cout << "Invalid selection. Please enter an integer 1 - 5" << endl;
		}
	} while (selection != 5);	//end do-while
}

//***********************************************************
// Function Name:		validate_input
// Purpose:				Checks if a user input is a valid
//						integer. If the input is valid, sends
//						back the calling function by reference.
//						If not, forces the user to reenter the
//						input.
// Parameters:			int & input, int highest_input
// 	Input:				reference to user input, highest
//						value of the menu
// 	Output:				Error message and reprompt if input
//						is invalid.
// Return Value:		bool valid
//***********************************************************

bool validate_input(int &input, int highest_input)
{
	bool valid;
	cin >> input;			//user input

	//if input is valid
	if (cin.good() && input > 0 && input <= highest_input && cin.peek() == '\n')		
	{
		valid = true;
	}

	//if input is invalid
	else
	{
		valid = false;
		cin.clear();
		cin.ignore(100, '\n');
		system("cls");
		cout << "Invalid input. Please enter an integer 1 - " << highest_input << endl;
	}
	return valid;
}

//***********************************************************
// Function Name:		get_size
// Purpose:				Prompts the user for the size
//						of the pattern to be output
// Parameters:			None
// 	Input:				None
// 	Output:				User prompt
// Return Value:		int size
// Functions Called:	validate_input
//***********************************************************

int get_size()
{
	const int max_size = 9;							//maximum size of the square
	int size;
	do 
	{
		cout << "Please choose a size from 1 - 9: ";
	} while (!validate_input(size, max_size));		//validates size of square
	
	return size;
}

//***********************************************************
// Function Name:		diag_left_to_right
// Purpose:				Prints a rectangle with a user input
//						size made of '#'s and a diagonal line
//						left to right made of the number input
//						for the size
// Parameters:			int size
// 	Input:				Size entered by the user
// 	Output:				Rectangle with the diagonal left to right
// Return Value:		None
//***********************************************************

void diag_left_to_right(int size)
{
	//square with a left to right diagonal
	cout << "\nLeft to right diagonal:\n";
	for (int i = 0; i < size; i++)		//begin outer loop
	{
		for (int j = 0; j < size; j++)	//begin inner loop
		{
			if (i == j)
				cout << size;
			else
				cout << "#";
		}								//end inner loop
		cout << "\n";
	}									//end outer loop
	cout << "\n";
}

//***********************************************************
// Function Name:		diag_right_to_left
// Purpose:				Prints a rectangle with a user input
//						size made of '#'s and a diagonal line
//						right to left made of the number input
//						for the size
// Parameters:			int size
// 	Input:				Size entered by the user
// 	Output:				Rectangle with the diagonal right to left
// Return Value:		None
//***********************************************************


void diag_right_to_left(int size)
{
	//square with a right to left diagonal
	cout << "\nRight to left diagonal:\n";
	for (int i = 0; i < size; i++)		//begin outer loop
	{
		for (int j = 0; j < size; j++)	//begin inner loop
		{
			if (j == size - (i+1))
				cout << size;
			else
				cout << "#";
		}								//end inner loop
		cout << "\n";
	}									//end outer loop
	cout << "\n";
}

//***********************************************************
// Function Name:		fill_left_to_right
// Purpose:				Prints a rectangle with a user input
//						size made of '#'s filled left to right
//						with the number input for the size
// Parameters:			int size
// 	Input:				Size entered by the user
// 	Output:				Rectangle filled left to right
// Return Value:		None
//***********************************************************


void fill_left_to_right(int size)
{
	//square that fills left to right
	cout << "\nLeft to right fill:\n";
	for (int i = 0; i < size; i++)		//begin outer loop
	{
		for (int j = 0; j < size; j++)	//begin inner loop
		{
			if (i >= j)
				cout << size;
			else
				cout << "#";
		}								//end inner loop
		cout << "\n";
	}									//end outer loop
	cout << "\n";
}

//***********************************************************
// Function Name:		fill_right_to_left
// Purpose:				Prints a rectangle with a user input
//						size made of '#'s filled right to left
//						with the number input for the size
// Parameters:			int size
// 	Input:				Size entered by the user
// 	Output:				Rectangle filled right to left
// Return Value:		None
//***********************************************************

void fill_right_to_left(int size)
{
	//square that fills right to left
	cout << "\nRight to left fill:\n";
	for (int i = 0; i < size; i++)		//begin outer loop
	{
		for (int j = 0; j < size; j++)	//begin inner loop
		{
			if (i <= j)
				cout << size;
			else
				cout << "#";
		}								//end inner loop
		cout << "\n";
	}									//end outer loop
	cout << "\n";
}