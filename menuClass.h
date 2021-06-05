#include <iostream>
#include "list.hpp"
#include <fstream>

#include <stdio.h>///
#include <termios.h>////Для mygetch()
#include <unistd.h>///

int mygetch( ) {
	struct termios oldt, newt;
	int ch;
	tcgetattr( STDIN_FILENO, &oldt );
	newt = oldt;
	newt.c_lflag &= ~( ICANON | ECHO );
	tcsetattr( STDIN_FILENO, TCSANOW, &newt );
	ch = getchar();
	tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
	return ch;//get char from keyboard
}


class Menu
{
public:
	bool isRun; 
	int frame = 1, selected = 1, index = 1;
	bool isSelected = false; 	
	int readerIndex = 0;
	string firstLine = "Добавить студента";
	string secondLine = "Вывод информации о студенте";
	string changeInfo = "Изменить информацию о студенте";
	string intoFile = "Записать дб в файл";
	string fromFile = "Загрузить из дб";
	string thirdLine = "Выход";
	string additionalMessage = "";

	string searchByName = "Поиск по имени";
	string searchBySurName = "Поиск по фамилии";
	string searchByUC = "Поиск по номеру зачетки";

	studentsDB *mirea = new studentsDB();



	void printLine(string line, bool prm){
		if(prm)
			cout << "\x1B[34m" + line + "\x1B[0m" << '\n';
		else
			cout << line << '\n';
	}
	void paint(){
		system("clear");
		if(frame == 1)
		{
			if(index == 1)printLine(firstLine, 1); else printLine(firstLine, 0); 
			if(index == 2)printLine(secondLine, 1); else printLine(secondLine, 0);
			if(index == 3)printLine(changeInfo, 1); else printLine(changeInfo, 0);
			if(index == 4)printLine(intoFile, 1); else printLine(intoFile, 0);
			if(index == 5)printLine(fromFile, 1); else printLine(fromFile, 0);
			if(index == 6)printLine(thirdLine, 1); else printLine(thirdLine, 0);
			if(!additionalMessage.empty())printLine(additionalMessage, 1), additionalMessage = "";
		}
		
		if(frame == 2)
		{
			system("clear");
			StudentClass stud;

			stud.setData();
			mirea->students.push_back(stud);
			//cout << db.at(1).name;
			additionalMessage = "Запись прошла успешно!\n";
			frame = 1;
			isSelected = false;
		}
		if(frame == 3)
		{

			if(index == 1)printLine(searchByName, 1); else printLine(searchByName, 0);
			if(index == 2)printLine(searchBySurName, 1); else printLine(searchBySurName, 0);
			if(index == 3)printLine(searchByUC, 1); else printLine(searchByUC, 0);
			if(index == 4)printLine(thirdLine, 1); else printLine(thirdLine, 0);
			
		}
		if(frame == 4){
			cout << "Input:\n";
			string _name;
			cin >> _name;
			mirea->printByName(_name);
			mygetch();
			frame = 3;
		}
		if(frame == 5){
			mirea->loadIntoFile();
			frame = 1;
		}
		if(frame == 6){
			mirea->loadFromFile();
			frame = 1;
		}
		if(frame == 7){
			cout << "Введите имя студента, которое нужно сменить:\n";
			string curName;
			cin >> curName;
			mirea->editName(curName);
			frame = 1;
		}
	}
	void calculateIndex(int code){

		switch(code){
			case 65:
				index--;
				if(index < 1)index = 1;
			break;
			case 66:
				index++; 
				if(frame == 1 && index > 6)index = 6;
				if(frame == 3 && index > 4)index = 4;
				break;
			case 67:				
				if(index == 1 && frame == 1)frame = 2;
				else if(index == 2 && frame == 1)frame = 3, index = 1;
				else if(index == 1 && frame == 3)frame = 4;
				else if(index == 4 && frame == 3)frame = 1, index = 1;
				else if(index == 6 && frame == 1)isRun = false;
				else if(index == 3 && frame == 1)frame = 7;
				else if(index == 4 && frame == 1)frame = 5;
				else if(index == 5 && frame == 1)frame = 6;
				//if(frame == 2 && index == 1)frame = 3;
			break;
		}
	}
};
