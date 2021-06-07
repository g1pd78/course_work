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
	int frame = 1, index = 1;
 	
	string firstLine = "Добавить студента";
	string secondLine = "Вывод информации о студенте";
	string changeInfo = "Изменить информацию о студенте";
	string intoFile = "Записать дб в файл";
	string fromFile = "Загрузить из дб";
	
	string exitLine = "Выход";
	
	string additionalMessage = "Для начала работы добавьте студентов вручную или загрузите из базы данных!";

	string searchByName = "Поиск по имени";
	string searchBySurName = "Поиск по фамилии";
	string searchByMiddleName = "Поиск по отчеству";
	string searchByUCN = "Поиск по номеру зачетки";
	string searchByKaf = "Поиск по кафедре";
	string searchByFac = "Поиск по факультету";

	string changeName = "Изменить именя";
	string changeSurName = "Изменитьфамилию";
	string changeMiddleName = "Изменить отчество";
	string changeGroup = "Изменить группу";
	string changeKaf = "Изменить кафедру";
	string changeFac = "Изменить факультет";
	string changeDateOfEduStart = "Изменить день поступления";
	string changeDateOfBirth = "Изменить день рождения";
	string changeSex = "Изменить пол";



	studentsDB *mirea = new studentsDB();



	void printLine(string line, bool prm){
		if(prm)
			cout << "\x1B[34m" + line + "\x1B[0m" << '\n';
		else
			cout << line << '\n';
	}
	void paint(){
		system("clear");

		switch(frame){
			case 1:
			{
				if(index == 1)printLine(firstLine, 1); else printLine(firstLine, 0); 
				if(index == 2)printLine(secondLine, 1); else printLine(secondLine, 0);
				if(index == 3)printLine(changeInfo, 1); else printLine(changeInfo, 0);
				if(index == 4)printLine(intoFile, 1); else printLine(intoFile, 0);
				if(index == 5)printLine(fromFile, 1); else printLine(fromFile, 0);
				if(index == 6)printLine(exitLine, 1); else printLine(exitLine, 0);
				if(!additionalMessage.empty())printLine(additionalMessage, 1), additionalMessage = "";
				break;
			}
			case 11:
			{
				system("clear");
				StudentClass stud;

				stud.setData();
				mirea->students.push_back(stud);
				//cout << db.at(1).name;
				additionalMessage = "Запись прошла успешно!\n";
				frame = 1;
				break;
			}
			case 12:
			{
				if(index == 1)printLine(searchByName, 1); else printLine(searchByName, 0);
				if(index == 2)printLine(searchBySurName, 1); else printLine(searchBySurName, 0);
				if(index == 3)printLine(searchByMiddleName, 1); else printLine(searchByMiddleName, 0);
				if(index == 4)printLine(searchByUCN, 1); else printLine(searchByUCN, 0);
				if(index == 5)printLine(searchByKaf, 1); else printLine(searchByKaf, 0);
				if(index == 6)printLine(searchByFac, 1); else printLine(searchByFac, 0);
				if(index == 7)printLine(exitLine, 1); else printLine(exitLine, 0);
				break;
			}
			case 121:
			{
				cout << "Input:\n";
				string _name;
				cin >> _name;
				mirea->printByName(_name);
				mygetch();
				frame = 12;
				break;
			}
			case 122:
			{
				cout << "Input:\n";
				string _surName;
				cin >> _surName;
				mirea->printBySurName(_surName);
				mygetch();
				frame = 12;
				break;
			}
			case 123:
			{
				cout << "Input:\n";
				string _middleName;
				cin >> _middleName;
				mirea->printByMiddleName(_middleName);
				mygetch();
				frame = 12;
				break;
			}
			case 124:
			{
				cout << "Input:\n";
				string _UCN;
				cin >> _UCN;
				mirea->printByUniqueCardNumber(_UCN);
				mygetch();
				frame = 12;
				break;
			}
			case 125:
			{
				cout << "Input:\n";
				string _kaf;
				cin >> _kaf;
				mirea->printByKaf(_kaf);
				mygetch();
				frame = 12;
				break;
			}
			case 126:
			{
				cout << "Input:\n";
				string _fac;
				cin >> _fac;
				mirea->printByFac(_fac);
				mygetch();
				frame = 12;
				break;
			}
			case 13:
			{
				if(index == 1)printLine(changeName, 1); else printLine(changeName, 0);
				if(index == 2)printLine(changeSurName, 1); else printLine(changeSurName, 0);
				if(index == 3)printLine(changeMiddleName, 1); else printLine(changeMiddleName, 0);
				if(index == 4)printLine(changeGroup, 1); else printLine(changeGroup, 0);
				if(index == 5)printLine(changeKaf, 1); else printLine(changeKaf, 0);
				if(index == 6)printLine(changeFac, 1); else printLine(changeFac, 0);
				if(index == 7)printLine(changeSex, 1); else printLine(changeSex, 0);
				if(index == 8)printLine(changeDateOfBirth, 1); else printLine(changeDateOfBirth, 0);
				if(index == 9)printLine(changeDateOfEduStart, 1); else printLine(changeDateOfEduStart, 0);
				if(index == 10)printLine(exitLine, 1); else printLine(exitLine, 0);
				break;
			}
			case 131:
			{
				cout << "Введите номер студенческого:\n";
				string UCN;
				cin >> UCN;
				mirea->editPrm(UCN, 0);
				mygetch();
				cout << "Для продолжения нажмите любую клавишу...\n";
				frame = 13;
				break;
			}
			case 14:
			{
				mirea->loadIntoFile();
				frame = 1;
				break;
			}
			case 15:
			{
				mirea->loadFromFile();
				mygetch();
				frame = 1;
				break;
			}
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
				if(frame == 12 && index > 8)index = 8;
				if(frame == 13 && index > 10)index = 10;
				break;
			case 67:	
				switch(frame){
					case 1:
					{
						switch(index){
							case 1:
							{
								frame = 11;
								break;
							}
							case 2:
							{
								frame = 12; 
								index = 1;
								break;
							}
							case 3:
							{
								frame = 13;
								break;
							}
							case 4:
							{
								frame = 14;
								break;	
							}
							case 5:
							{
								frame = 15;
								break;
							}
							case 6:
							{
								isRun = false;
								break;
							}
						}
						break;
					}
					case 12:
					{
						switch(index){
							case 1:
							{
								frame = 121;
								break;
							}
							case 2:
							{
								frame = 122;
								break;
							}
							case 3:
							{
								frame = 123;
								break;
							}
							case 4:
							{
								frame = 124;
								break;
							}
							case 5:
							{
								frame = 125;
								break;
							}
							case 6:
							{
								frame = 126;
								break;
							}
							case 7:
							{
								frame = 1; 
								index = 1;
								break;
							}
						}
						break;
					}
					case 13:
					{
						switch(index){
							case 1:
							{
								frame = 131;
								break;
							}
							case 2:
							{
								frame = 132;
								break;
							}
							case 3:
							{
								frame = 133;
								break;
							}
							case 4:
							{
								frame = 134;
								break;
							}
							case 5:
							{
								frame = 135;
								break;
							}
							case 6:
							{
								frame = 136;
								break;
							}
							case 7:
							{
								frame = 1; 
								index = 1;
								break;
							}
						}
						break;
					}
				}			
				/*if(index == 1 && frame == 1)frame = 11;
				else if(index == 2 && frame == 1)frame = 12, index = 1;
				else if(index == 1 && frame == 12)frame = 121;
				else if(index == 4 && frame == 12)frame = 1, index = 1;
				else if(index == 6 && frame == 1)isRun = false;
				else if(index == 3 && frame == 1)frame = 131;
				else if(index == 4 && frame == 1)frame = 14;
				else if(index == 5 && frame == 1)frame = 15;
				//if(frame == 2 && index == 1)frame = 3;*/
			break;
		}
	}
};
