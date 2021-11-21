#include"console.h"
#include<iostream>
using namespace std;
#include"console.cpp"

int main(){


  for (int i = 1; i < 100; i++) {
    setColor(i);
    cout << i;}
  clrscr;
  gotoXY(5, 10);
  
  system("pause");
  return 0;
}