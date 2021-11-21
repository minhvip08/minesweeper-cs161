
#include"header.h"
int SIDE; // side length of the board
int MINES; // number of mines on the board


void chooseDifficultyLevel()
{
	/*
	--> BEGINNER = 9 * 9 Cells and 10 Mines
	--> INTERMEDIATE = 16 * 16 Cells and 40 Mines
	--> ADVANCED = 24 * 24 Cells and 99 Mines
	*/

	int level;

	printf("Enter the Difficulty Level\n");
	printf("Press 0 for BEGINNER (9 * 9 Cells and 10 Mines)\n");
	printf("Press 1 for INTERMEDIATE (16 * 16 Cells and 40 Mines)\n");
	printf("Press 2 for ADVANCED (24 * 24 Cells and 99 Mines)\n");

	scanf("%d", &level);

	if (level == BEGINNER)
	{
		SIDE = 9;
		MINES = 10;
	}

	if (level == INTERMEDIATE)
	{
		SIDE = 16;
		MINES = 40;
	}

	if (level == ADVANCED)
	{
		SIDE = 24;
		MINES = 99;
	}

	return;
}
// A Function to play Minesweeper game
void playMinesweeper()
{
	// Initially the game is not over
	bool gameOver = false;

	// Actual Board and My Board
	char realBoard[MAXSIDE][MAXSIDE], myBoard[MAXSIDE][MAXSIDE];

	int movesLeft = SIDE * SIDE - MINES, x, y;
	int mines[MAXMINES][2]; // stores (x,y) coordinates of all mines.

	initialise(realBoard, myBoard);

	// Place the Mines randomly
	placeMines(mines, realBoard);

	/*
	If you want to cheat and know
	where mines are before playing the game
	then uncomment this part

	cheatMinesweeper(realBoard);
	*/

	// You are in the game until you have not opened a mine
	// So keep playing

	int currentMoveIndex = 0;
	while (gameOver == false)
	{	
		system("cls");
		char put;

		printf("Current Status of Board : \n");
		printBoard(myBoard);

		cout << "If you want to put flag, press P, no press X: ";
		cin >> put;
		if (put == 'P'){
			putFlag(x, y, myBoard);
			continue;		
		}

		makeMove(&x, &y);

		// This is to guarantee that the first move is
		// always safe
		// If it is the first move of the game
		if (currentMoveIndex == 0)
		{
			// If the first move itself is a mine
			// then we remove the mine from that location
			if (isMine(x, y, realBoard) == true)
				replaceMine(x, y, realBoard);
		}

		currentMoveIndex++;

		gameOver = playMinesweeperUtil(myBoard, realBoard, mines, x, y, &movesLeft);

		if ((gameOver == false) && (movesLeft == 0))
		{
			printf("\nYou won !\n");
			gameOver = true;
		}
	}
	return;
}

// A Recursive Function to play the Minesweeper Game
bool playMinesweeperUtil(char myBoard[][MAXSIDE], char realBoard[][MAXSIDE],
	int mines[][2], int row, int col, int* movesLeft)
{

	// Base Case of Recursion
	if (myBoard[row][col] != '-')
		return (false);

	int i, j;

	// You opened a mine
	// You are going to lose
	if (realBoard[row][col] == '*')
	{
		myBoard[row][col] = '*';

		for (i = 0; i < MINES; i++)
			{	

				
				if (myBoard[mines[i][0]][mines[i][1]] == 'P' 
						&& realBoard[mines[i][0]][mines[i][1]] == '*')
					continue;
				myBoard[mines[i][0]][mines[i][1]] = '*';
			}
			
		for (int i=0; i < 8; i++){
			for (int j=0; j <8; j++){
					if (myBoard[i][j] == 'P' 
						&& realBoard[i][j] != '*')
					myBoard[i][j] = 'X';
			}
		}
		printBoard(myBoard);
		printf("\nYou lost!\n");
		return (true);
	}

	else
	{
		// Calculate the number of adjacent mines and put it
		// on the board
		int count = countAdjacentMines(row, col, mines, realBoard);
		(*movesLeft)--;

		myBoard[row][col] = count + '0';
		realBoard[row][col] = myBoard[row][col];

		if (!count)
		{
			/*
			Recur for all 8 adjacent cells

				N.W N N.E
				\ | /
					\ | /
				W----Cell----E
					/ | \
				/ | \
				S.W S S.E

			Cell-->Current Cell (row, col)
			N --> North	 (row-1, col)
			S --> South	 (row+1, col)
			E --> East		 (row, col+1)
			W --> West		 (row, col-1)
			N.E--> North-East (row-1, col+1)
			N.W--> North-West (row-1, col-1)
			S.E--> South-East (row+1, col+1)
			S.W--> South-West (row+1, col-1)
			*/

			//----------- 1st Neighbour (North) ------------

		// Only process this cell if this is a valid one
			if (isValid(row - 1, col) == true)
			{
				if (isMine(row - 1, col, realBoard) == false)
					playMinesweeperUtil(myBoard, realBoard, mines, row - 1, col, movesLeft);
			}

			//----------- 2nd Neighbour (South) ------------

			// Only process this cell if this is a valid one
			if (isValid(row + 1, col) == true)
			{
				if (isMine(row + 1, col, realBoard) == false)
					playMinesweeperUtil(myBoard, realBoard, mines, row + 1, col, movesLeft);
			}

			//----------- 3rd Neighbour (East) ------------

			// Only process this cell if this is a valid one
			if (isValid(row, col + 1) == true)
			{
				if (isMine(row, col + 1, realBoard) == false)
					playMinesweeperUtil(myBoard, realBoard, mines, row, col + 1, movesLeft);
			}

			//----------- 4th Neighbour (West) ------------

			// Only process this cell if this is a valid one
			if (isValid(row, col - 1) == true)
			{
				if (isMine(row, col - 1, realBoard) == false)
					playMinesweeperUtil(myBoard, realBoard, mines, row, col - 1, movesLeft);
			}

			//----------- 5th Neighbour (North-East) ------------

			// Only process this cell if this is a valid one
			if (isValid(row - 1, col + 1) == true)
			{
				if (isMine(row - 1, col + 1, realBoard) == false)
					playMinesweeperUtil(myBoard, realBoard, mines, row - 1, col + 1, movesLeft);
			}

			//----------- 6th Neighbour (North-West) ------------

			// Only process this cell if this is a valid one
			if (isValid(row - 1, col - 1) == true)
			{
				if (isMine(row - 1, col - 1, realBoard) == false)
					playMinesweeperUtil(myBoard, realBoard, mines, row - 1, col - 1, movesLeft);
			}

			//----------- 7th Neighbour (South-East) ------------

			// Only process this cell if this is a valid one
			if (isValid(row + 1, col + 1) == true)
			{
				if (isMine(row + 1, col + 1, realBoard) == false)
					playMinesweeperUtil(myBoard, realBoard, mines, row + 1, col + 1, movesLeft);
			}

			//----------- 8th Neighbour (South-West) ------------

			// Only process this cell if this is a valid one
			if (isValid(row + 1, col - 1) == true)
			{
				if (isMine(row + 1, col - 1, realBoard) == false)
					playMinesweeperUtil(myBoard, realBoard, mines, row + 1, col - 1, movesLeft);
			}
		}

		return (false);
	}
}