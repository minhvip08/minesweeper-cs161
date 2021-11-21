#include<iostream>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<cstring>
using namespace std;

//Define level
#define BEGINNER 0
#define INTERMEDIATE 1
#define ADVANCED 2

//Define size of game
#define MAXSIDE 25
#define MAXMINES 99
#define MOVESIZE 526 // (25 * 25 - 99)

//These variables include in playMinesweeper.cpp
extern int SIDE;
extern int MINE;



// A Utility Function to check whether given cell (row, col)
// is a valid cell or not
bool isValid(int row, int col);

// A Utility Function to check whether given cell (row, col)
// has a mine or not.
bool isMine(int row, int col, char board[][MAXSIDE]);

// A Function to get the user's move
void makeMove(int* x, int* y);

// A Function to print the current gameplay board
void printBoard(char myBoard[][MAXSIDE]);

// A Function to count the number of
// mines in the adjacent cells
int countAdjacentMines(int row, int col, int mines[][2],
	char realBoard[][MAXSIDE]);

// A Recursive Function to play the Minesweeper Game
bool playMinesweeperUtil(char myBoard[][MAXSIDE], char realBoard[][MAXSIDE],
	int mines[][2], int row, int col, int* movesLeft);

// A Function to place the mines randomly
// on the board
void placeMines(int mines[][2], char realBoard[][MAXSIDE]);

// A Function to initialise the game
void initialise(char realBoard[][MAXSIDE], char myBoard[][MAXSIDE]);

// A function to replace the mine from (row, col) and put
// it to a vacant space
void replaceMine(int row, int col, char board[][MAXSIDE]);

// A Function to play Minesweeper game
void playMinesweeper();

// A Function to choose the difficulty level
// of the game
void chooseDifficultyLevel();
