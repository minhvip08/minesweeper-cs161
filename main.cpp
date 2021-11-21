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

int main()
{

	chooseDifficultyLevel();

	playMinesweeper();
	system("pause");
	return (0);
}
