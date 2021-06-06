#include <iostream>
#include "list.hpp"
#include <fstream>
#include "studentClass.h"
#include "menuClass.h"
#include "EncDecClass.h"

using namespace CryptoPP;
using namespace std;


//Дописать цвета
#define RST  "\x1B[0m"
#define KBLU  "\x1B[34m"
#define FBLU(x) KBLU x RST
#define KWHT  "\x1B[37m"


/*
Запись отдельных данных в файл
Удаление отдельных записей из файла
Обновить данные в файле



*/




int main(){

	_rsa *r = new _rsa();

	cout << r->encrypt("Hello") << '\n';
	cout << r->decrypt(r->encrypt("Hello")) << '\n';

	/*
	cout << blow->Encrypt("Hello World!", key, iv) << '\n';
	cout << blow->Decrypt(blow->Encrypt("Hello World!", key, iv));*/
	mygetch();

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
	delete mainMenu;
}