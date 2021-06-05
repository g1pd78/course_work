#include <iostream>
#include "list.hpp"
#include <fstream>
#include "studentClass.h"
#include "menuClass.h"



using namespace std;


//Дописать цвета
#define RST  "\x1B[0m"
#define KBLU  "\x1B[34m"
#define FBLU(x) KBLU x RST
#define KWHT  "\x1B[37m"





int main(){


	Menu *mainMenu = new Menu();
	mainMenu->isRun = true;
	mainMenu->paint();
	while(mainMenu->isRun){
		int currentKey = mygetch();

		mainMenu->calculateIndex(currentKey);

		mainMenu->paint();
		//cout << a;

	}
	cout << mainMenu->mirea->students.size();
}