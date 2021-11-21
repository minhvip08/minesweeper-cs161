#include"header.h"
extern int SIDE;
extern int MINE;
// A Utility Function to check whether given cell (row, col)
// is a valid cell or not
bool isValid(int row, int col)
{
	// Returns true if row number and column number
	// is in range
	return (row >= 0) && (row < SIDE) &&
		(col >= 0) && (col < SIDE);
}

// A Utility Function to check whether given cell (row, col)
// has a mine or not.
bool isMine(int row, int col, char board[][MAXSIDE])
{
	if (board[row][col] == '*')
		return (true);
	else
		return (false);
}


void putFlag (int x, int y, char myBoard[][MAXSIDE]){
	makeMove(&x, &y);
	if (myBoard[x][y] == 'P')
		myBoard[x][y] = '-';
	else myBoard[x][y] = 'P';
	printBoard(myBoard);
	return;
}

// A Function to get the user's move
void makeMove(int* x, int* y)
{
	// Take the input move
	printf("Enter your move, (row, column) -> ");
	scanf("%d %d", x, y);
	return;
}


// A Function to print the current gameplay board
void printBoard(char myBoard[][MAXSIDE])
{
	int i, j;

	printf("  ");

	for (i = 0; i < SIDE; i++){
		setColor(12);
		printf("%d ", i);
	}


	printf("\n");

	for (i = 0; i < SIDE; i++)
	{	setColor(12);
		printf("%d ", i);
		setColor(7);
		for (j = 0; j < SIDE; j++)
			printf("%c ", myBoard[i][j]);
		printf("\n");
	}
	return;
}

// A Function to count the number of
// mines in the adjacent cells
int countAdjacentMines(int row, int col, int mines[][2],
	char realBoard[][MAXSIDE])
{

	int i;
	int count = 0;

	/*
		Count all the mines in the 8 adjacent
		cells

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
		if (isMine(row - 1, col, realBoard) == true)
			count++;
	}

	//----------- 2nd Neighbour (South) ------------

		// Only process this cell if this is a valid one
	if (isValid(row + 1, col) == true)
	{
		if (isMine(row + 1, col, realBoard) == true)
			count++;
	}

	//----------- 3rd Neighbour (East) ------------

		// Only process this cell if this is a valid one
	if (isValid(row, col + 1) == true)
	{
		if (isMine(row, col + 1, realBoard) == true)
			count++;
	}

	//----------- 4th Neighbour (West) ------------

		// Only process this cell if this is a valid one
	if (isValid(row, col - 1) == true)
	{
		if (isMine(row, col - 1, realBoard) == true)
			count++;
	}

	//----------- 5th Neighbour (North-East) ------------

		// Only process this cell if this is a valid one
	if (isValid(row - 1, col + 1) == true)
	{
		if (isMine(row - 1, col + 1, realBoard) == true)
			count++;
	}

	//----------- 6th Neighbour (North-West) ------------

		// Only process this cell if this is a valid one
	if (isValid(row - 1, col - 1) == true)
	{
		if (isMine(row - 1, col - 1, realBoard) == true)
			count++;
	}

	//----------- 7th Neighbour (South-East) ------------

		// Only process this cell if this is a valid one
	if (isValid(row + 1, col + 1) == true)
	{
		if (isMine(row + 1, col + 1, realBoard) == true)
			count++;
	}

	//----------- 8th Neighbour (South-West) ------------

		// Only process this cell if this is a valid one
	if (isValid(row + 1, col - 1) == true)
	{
		if (isMine(row + 1, col - 1, realBoard) == true)
			count++;
	}

	return (count);
}

// A Function to place the mines randomly
// on the board
void placeMines(int mines[][2], char realBoard[][MAXSIDE])
{
	bool mark[MAXSIDE * MAXSIDE];

	memset(mark, false, sizeof(mark));

	// Continue until all random mines have been created.
	for (int i = 0; i < MINES; )
	{
		int random = rand() % (SIDE * SIDE);
		int x = random / SIDE;
		int y = random % SIDE;

		// Add the mine if no mine is placed at this
		// position on the board
		if (mark[random] == false)
		{
			// Row Index of the Mine
			mines[i][0] = x;
			// Column Index of the Mine
			mines[i][1] = y;

			// Place the mine
			realBoard[mines[i][0]][mines[i][1]] = '*';
			mark[random] = true;
			i++;
		}
	}

	return;
}


// A function to replace the mine from (row, col) and put
// it to a vacant space
void replaceMine(int row, int col, char board[][MAXSIDE])
{
	for (int i = 0; i < SIDE; i++)
	{
		for (int j = 0; j < SIDE; j++)
		{
			// Find the first location in the board
			// which is not having a mine and put a mine
			// there.
			if (board[i][j] != '*')
			{
				board[i][j] = '*';
				board[row][col] = '-';
				return;
			}
		}
	}
	return;
}

void initialise(char realBoard[][MAXSIDE], char myBoard[][MAXSIDE])
{
	// Initiate the random number generator so that
	// the same configuration doesn't arises
	srand(time(NULL));

	// Assign all the cells as mine-free
	for (int i = 0; i < SIDE; i++)
	{
		for (int j = 0; j < SIDE; j++)
		{
			myBoard[i][j] = realBoard[i][j] = '-';
		}
	}

	return;
}
