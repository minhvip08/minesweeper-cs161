#include"header.h"
// A Function to cheat by revealing where the mines are
// placed.
void cheatMinesweeper(char realBoard[][MAXSIDE])
{
	printf("The mines locations are-\n");
	printBoard(realBoard);
	return;
}
