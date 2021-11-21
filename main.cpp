//main.cpp
/* 
************************************************************
This program will help you to implement and play Minesweeper.
Nguyen Si Minh - APCS 21 CTT 2
************************************************************
If you want to know more about how this program excecutes, please
read instruction.txt 
*/

#include"header.h"
#include"playMinesweeper.cpp"
#include"implement.cpp"
#include"console.cpp"

int main()
{
	/* Choose a level between
	--> BEGINNER = 9 * 9 Cells and 10 Mines
	--> INTERMEDIATE = 16 * 16 Cells and 40 Mines
	--> ADVANCED = 24 * 24 Cells and 99 Mines
	*/
	chooseDifficultyLevel();

	playMinesweeper();
	system("pause");
	return (0);
}
