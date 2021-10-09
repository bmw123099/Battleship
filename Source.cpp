//Brett Wolff Lab 9, Battleship
//With help from Jesse

#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

//sets all the prototypes for functions used inside main

void Fire(char board[26][26], char Game[26][26]);

void Game(char Game[26][26], int& fS);

void fillBoard(char board[26][26]);

void displayBoard(char board[26][26]);

bool shipsdestroyed(char board[26][26], char Game[26][26]);

int main()
{
	char board[26][26];		// Create a 26 x 26 array for gameboard
	char Game[26][26];		//creates empty board.
	
	 // get oceanboard.txt and get ready to assign the value to the board
	ifstream infile;
	infile.open("Oceanboard.txt");

	if (!infile) {				//check file 
		cout << "Can not open file." << endl;
	}

	// nested for loops to assign chars in the text file to spaces in an array.
	for (int i = 0; i < 26; i++) {			// goes through each row
		for (int j = 0; j < 26; j++) {	//goes through each column
			char bS = 0;					// bS is the character given that is being assigned to a space on the board	
			infile.get(bS);					// get character from the board 				
			board[i][j] = bS;        //assign that character to board[i][j]
		}
	}
	int fS = 0;					// Create an int variable to determine when to exit loop 	

	fillBoard(Game);

	//function to play the game

	do {

		Fire(board, Game);
		displayBoard(Game);

	} while (!shipsdestroyed(board, Game));

	//line indicating the game is over

	cout << "Game over! All ships sunk!" << endl;

	system("pause");
	return 0;
}

// The Fire function takes in board[] and uses it for the fire function 
void Fire(char board[26][26], char Game[26][26])
{
	int row = 0;			//initializes the int x and y that will represent row and column respectively
	int col = 0;

	cout << "Enter the Row and Column that you would like to try and hit between 1 and 25, seperated by a space: ";
	cin >> row;  
	cin >> col;

	//failcheck on what is input

	while (cin.fail() || (row < 1) || (row > 25) || (col < 1) || (col > 25))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Please enter 2 valid integers: ";
		cin >> row;
		cin >> col;
	}

	//since there is 26 rows and col, there has to be one subtracted. 

	row--;
	col--;

	//switch statement to determine hit or miss

	switch (board[row][col])
	{
	case '~':
		{
			cout << "MISS" << endl;
			break;
		}
	case '#':
	{
		if (Game [row][col] == 'H')

			cout << "Hit Again." << endl;

		else
		{
			cout << "Hit." << endl;
			Game [row][col] = 'H';
		}
		break;
	}
	default:
		cout << "error with shot" << endl;
		break;
	}	
}

//function for the board displayed

void Game(char Game[26][26], int& fS)
{
	for (int x = 0; x < 25; x++)
	{
		for (int y = 0; y < 25; y++)
		{
			Game[x][y] = '~';
		}
	}
}

//funtion that places the ocean tiles

void fillBoard(char board[26][26])
{
	for (int x = 0; x < 25; x++)
	{
		for (int y = 0; y < 25; y++)
		{
			board[x][y] = '~';
		}
	}
	return;
}

//function that outputs the board

void displayBoard(char board[26][26])
{
	for (int x = 0; x < 25; x++)
	{
		for (int y = 0; y < 25; y++)
		{
			cout << board[x][y];
		}
		cout << endl;
	}
	return;
}

//checks to see if all ships have been destroyed.

bool shipsdestroyed(char board[26][26], char Game[26][26])
{
	bool gameover{ true };

	for (int x = 0; x < 25; x++)
	{
		for (int y = 0; y < 25; y++)
		{
			if (board[x][y] == Game[x][y]) {}

			else if ((board[x][y] == '#') && (Game[x][y] == 'H')) {}

			else
			{
				gameover = false;
			}
		}
	}
	return gameover;
}