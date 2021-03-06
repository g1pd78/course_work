#include <iostream>
#include "list.hpp"
#include <fstream>
#include "EncDecClass.h"

using namespace std;


struct ExamsRecords {
	string name;
	int mark; 
	bool isEmpty;
};

class ExamsResultsClass
{
public:
	ExamsRecords data[9][10];
	int semCount, subjCount[9];
	ExamsResultsClass() {
		emptpy();
	}

	void emptpy() {
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 10; j++)
				data[i][j].isEmpty = true;
	}

	void inputSubj(){
		system("clear");
		cout << "Введите количество семестров:\n";
		cin >> semCount;
		

		for (int i = 0;i < semCount;i++)
		{
			system("clear");
			cout << "Ввод информации за " << i + 1 << " семестр:\n"; 
			cout << "Введите количество предметов:\n";
			cin >> subjCount[i];
			cout << "Введите названия предметов:\n";

			for(int j = 0;j < subjCount[i];j++)
			{
				cout << j + 1 << ":\n";

				//getline(cin, data[i][j].name);
				cin >> data[i][j].name;	
				cout << "Оценка:\n";
				cin >> data[i][j].mark;
			}
		}
	}

	void writeIntoFile(){

	}

};



class StudentClass
{	
public:

	string name;
	string surName;
	string middleName;
	string fac;
	string kaf;
	string group;
	string DateOfBirth;
	string uniqueCardNumber;
	string sex;

	string DateOfEduStart;

	int degree;

	ExamsResultsClass Exams;

	void setData() {
		cout << "Введите имя студента:\n";
		getline(cin, name);
		cout << "Введите фамилию студента:\n";
		getline(cin, surName);
		cout << "Введите отчество студента:\n";
		getline(cin, middleName);
		cout << "Введите факультет, на котором обучается студент:\n";
		getline(cin, fac);
		cout << "Введите кафедру, на которой обучается студент:\n";
		getline(cin, kaf);
		cout << "Введите группу, в которой обучается студент:\n";
		getline(cin, group);
		cout << "Введите дату рождения студента:\n";
		getline(cin, DateOfBirth);
		cout << "Введите гендер студента:\n";
		getline(cin, sex);
		cout << "Введите номер студенческого билета студента:\n";
		getline(cin, uniqueCardNumber);
		cout << "Введите дату поступления студента:\n";
		getline(cin, DateOfEduStart);

		Exams.inputSubj();
	}

	void setName(string newName){
		name = newName;
	}
};

class studentsDB
{
public:
	List <StudentClass> students;

	void printInfo(int i){
		cout << "------------------------------------\n";
		cout << "Имя студента:\n" << students.at(i).name << '\n';
		cout << "Фамилия студента:\n" << students.at(i).surName << '\n';
		cout << "Отчество студента:\n" << students.at(i).middleName << '\n';
		cout << "Кафедра:\n" << students.at(i).kaf << '\n';
		cout << "Факультет:\n" << students.at(i).fac << '\n';
		cout << "Группа:\n" << students.at(i).group << '\n';
		cout << "Дата рождения студента:\n" << students.at(i).DateOfBirth << '\n';
		cout << "Дата поступления студента:\n" << students.at(i).DateOfEduStart << '\n';
		cout << "Номер студенческого:\n" << students.at(i).uniqueCardNumber << '\n';
		cout << "Пол студента:\n" << students.at(i).sex << '\n';

		//cout << students.at(i).Exams.semCount; information 'bout exams

		int _semCount = students.at(i).Exams.semCount;

		cout << "------------------------------------\n";

		for(int k = 0;k < _semCount;k++)
		{
			int _subjCount = students.at(i).Exams.subjCount[k];
			cout << k + 1 <<" семестр:\n";
			//cout << _subjCount << '\n';
			for(int j = 0;j < _subjCount;j++)
			{
				cout << "Предмет: " << students.at(i).Exams.data[k][j].name << '\n';
				cout << "Оценка: " << students.at(i).Exams.data[k][j].mark << '\n';
			}
		}
		cout << "------------------------------------\n";
	}

	bool isInList(){
	string UNC = students.at(students.size() - 1).uniqueCardNumber;
		for(int i = 0;i < students.size() - 1;i++)
			if(students.at(i).uniqueCardNumber == UNC)
			{
				students.erase(students.begin());
				return true;
			}
		return false;
	}

	void printByName(string studentsName){
		cout << "asddddddddddddd";
		for(int i = 0;i < students.size();i++)
			if(students.at(i).name == studentsName)
				printInfo(i);
			cout << "Нажмите любую клавишу для продолжения...\n";
	}

	void printBySurName(string studentsSurName){
		for(int i = 0;i < students.size();i++)
			if(students.at(i).surName == studentsSurName)
				printInfo(i);
			cout << "Нажмите любую клавишу для продолжения...\n";
	}

	void printByMiddleName(string studentsMiddleName){
		for(int i = 0;i < students.size();i++)
			if(students.at(i).middleName == studentsMiddleName)
				printInfo(i);
			cout << "Нажмите любую клавишу для продолжения...\n";
	}

	void printByUniqueCardNumber(string studentsUniqueCardNumber){
		for(int i = 0;i < students.size();i++)
			if(students.at(i).uniqueCardNumber == studentsUniqueCardNumber)
				printInfo(i);
			cout << "Нажмите любую клавишу для продолжения...\n";
	}

	void printByKaf(string studentsKaf){
		for(int i = 0;i < students.size();i++)
			if(students.at(i).kaf == studentsKaf)
				printInfo(i);
			cout << "Нажмите любую клавишу для продолжения...\n";
	}

	void printByFac(string studentsFac){
		for(int i = 0;i < students.size();i++)
			if(students.at(i).fac == studentsFac)
				printInfo(i);
			cout << "Нажмите любую клавишу для продолжения...\n";
	}

	void editPrm(string UCN, int prm){
		bool wasChanged = false;
		for(int i = 0;i < students.size();i++)
			/*if(students.at(i).uniqueCardNumber == UCN)
			{
				cout << "Введите новое имя:\n";
				string newName;
				cin >> newName;
				students.at(i).setName(newName);
				cout << "Имя изменено!\n";
			}*/
			if(students.at(i).uniqueCardNumber == UCN)
			{
				switch(prm)
				{
					case 0:
					{
						cout << "Введите новое имя:\n";
						string newName;
						cin >> newName;
						students.at(i).setName(newName);
						cout << "Имя изменено!\n";
						break;
					}
					case 1:
					{
						cout << "Введите новую фамилию:\n";
						string newSurName;
						cin >> newSurName;
						students.at(i).setName(newSurName);
						cout << "Фамилия изменено!\n";
						break;
					}
					case 2:
					{
						cout << "Введите новое отчество:\n";
						string newMiddleName;
						cin >> newMiddleName;
						students.at(i).setName(newMiddleName);
						cout << "Отчество изменено!\n";
						break;
					}
					case 3:
					{
						cout << "Введите новый пол:\n";
						string newSexName;
						cin >> newSexName;
						students.at(i).setName(newSexName);
						cout << "Пол изменено!\n";
						break;
					}
					case 4:
					{
						cout << "Введите новый факультет:\n";
						string newFac;
						cin >> newFac;
						students.at(i).setName(newFac);
						cout << "Факультет изменен!\n";
						break;
					}
					case 5:
					{
						cout << "Введите новую кафедру:\n";
						string newKaf;
						cin >> newKaf;
						students.at(i).setName(newKaf);
						cout << "Кафедра изменена!\n";
						break;
					}
					case 6:
					{
						cout << "Введите новый день рождения:\n";
						string newDateOfBirth;
						cin >> newDateOfBirth;
						students.at(i).setName(newDateOfBirth);
						cout << "День рождения изменен!\n";
						break;
					}
					case 7:
					{
						cout << "Введите новый день поступления:\n";
						string newDateOfEduStart;
						cin >> newDateOfEduStart;
						students.at(i).setName(newDateOfEduStart);
						cout << "День поступления изменен!\n";
						break;
					}
					case 8:
					{
						cout << "Введите новую группу:\n";
						string newGroup;
						cin >> newGroup;
						students.at(i).setName(newGroup);
						cout << "Группа изменена!\n";
						break;
					}
				}
				wasChanged = true;
			}
			if(!wasChanged)cout<<"Ошибка!\n";
	}

	void loadIntoFile(){
		ofstream out;
		out.open("db.rsa", std::ios::app);
		if (out.is_open())
    	{
    		_rsa *r = new _rsa();
    		for(int i = 0;i < students.size();i++)
    		{
				string output = "{\n";
				output = output +
				"Name:" + students.at(i).name + '\n' +
				"surName:" + students.at(i).surName + '\n' +
				"middleName:" + students.at(i).middleName + '\n' +
				"fac:" + students.at(i).fac + '\n' +
				"kaf:" + students.at(i).kaf + '\n' +
				"group:" + students.at(i).group + '\n' +
				"sex:" + students.at(i).sex + '\n' +
				"uniqueCardNumber:" + students.at(i).uniqueCardNumber + '\n' +
				"DateOfBirth:" + students.at(i).DateOfBirth + '\n' +
				"DateOfEduStart:" + students.at(i).DateOfEduStart + '\n';

				int _semCount = students.at(i).Exams.semCount;

				output = output + "semCount:" + to_string(_semCount) + '\n';

				for(int k = 0;k < _semCount;k++)
				{
					//out << "[\n";
					int _subjCount = students.at(i).Exams.subjCount[k];
					output = output + "subjCount:" + to_string(_subjCount) + '\n';
					for(int j = 0;j < _subjCount;j++)
					{
						output = output + "subj:" + students.at(i).Exams.data[k][j].name + '\n';
						output = output + "mark:" + to_string(students.at(i).Exams.data[k][j].mark) + '\n';
					}
					//out << "]\n";
				}
				output = output + "}\n";
				for(long long int i = 0;i < output.size();i++)
					out << r->encrypt(to_string(output[i])) << '\n';

    		}
    	}
    	out.close();
    	cout << "Запись прошла успешно!\nНажмите любую клавишу для продолжения...\n";
	}
	void loadFromFile(){
		ifstream in("db.rsa");

		int j = 0, k = 0;

		string line, line1;
		int count = 0;
		
    	if (in.is_open())
    	{
    		StudentClass st;
			_rsa *r = new _rsa();
			bool enc = true;
        	while (enc)
        	{
        		getline(in, line1);
        		if(line1.empty())break;
        		char str = char(stoi(r->decrypt(line1)));
        		line = line + str;

        		if(line == "{\n")line = "";
        		if(line == "}\n")
            	{
            		students.push_back(st);
            		line = "";
            		//enc = false;
            	}
            	if(str == '\n')
            	{

            		if(line.substr(0, 4) == "Name")st.name = line.substr(5, line.size()-6), line = "";
            		if(line.substr(0, 7) == "surName")st.surName = line.substr(8, line.size()-9), line = "";
            		if(line.substr(0, 10) == "middleName")st.middleName = line.substr(11, line.size()-12), line = "";
            		if(line.substr(0, 3) == "fac")st.fac = line.substr(4, line.size()-5), line = "";
            		if(line.substr(0, 3) == "kaf")st.kaf = line.substr(4, line.size()-5), line = "";
            		if(line.substr(0, 5) == "group")st.group = line.substr(6, line.size()-7), line = "";
            		if(line.substr(0, 3) == "sex")st.sex = line.substr(4, line.size()-5), line = "";
            		if(line.substr(0, 16) == "uniqueCardNumber")st.uniqueCardNumber = line.substr(17, line.size()-18), line = "";
            		if(line.substr(0, 11) == "DateOfBirth")st.DateOfBirth = line.substr(12, line.size()-19), line = "";
            		if(line.substr(0, 14) == "DateOfEduStart")st.DateOfEduStart = line.substr(15, line.size()-16), line = "";
            		if(line.substr(0, 8) == "semCount")st.Exams.semCount = stoi(line.substr(9, line.size() - 10)), line = "", k = 0, j = 0;
            		if(line.substr(0, 9) == "subjCount")st.Exams.subjCount[k] = stoi(line.substr(10, line.size() - 11)), line = "";
            		if(line.substr(0, 4) == "subj")st.Exams.data[k][j].name = line.substr(5, line.size()-6), line = "";
            		if(line.substr(0, 4) == "mark"){
            			st.Exams.data[k][j].mark = stoi(line.substr(5, line.size()-6));
            			j++;
            			//cout << j << '\n';
            			line = "";
            			if(j == st.Exams.subjCount[k]){
            				k++;
            				j = 0;
            			}
            		}	
            	}
        	}
    	}
    	in.close(); 
    	
    	cout << "Загрузка из ДБ закончена!\nНажмите любую клавишу для продолжения...\n";
	}

	void calculateDegree(){
		for(int i = 0;i < students.size();i++){
			int _five = 0, _four = 0, _three = 0, _two = 0, sum = 0;
			for(int j = 0;j < students.at(i).Exams.semCount;j++){
				for(int k = 0;k < students.at(i).Exams.subjCount[j];k++){
					if(students.at(i).Exams.data[j][k].mark == 5)_five++;
					if(students.at(i).Exams.data[j][k].mark == 4)_four++;
					if(students.at(i).Exams.data[j][k].mark == 3)_three++;
					if(students.at(i).Exams.data[j][k].mark == 3)_two++;

					sum++;
				}
			}
			if(sum == _five)students.at(i).degree = 5;
			else if(_three + _two == 0)students.at(i).degree = 4;
			else if(_two == 0)students.at(i).degree = 3;
		}
	}

	void var46(int x){
		string str;
		calculateDegree();

		cout << "Какой пол интересует?!\n";
		cin >> str;

		for(int i = 0;i < students.size();i++){
			if(str == students.at(i).sex){
				if(students.at(i).degree == x){
					cout << students.at(i).name << '\n';
					cout << students.at(i).uniqueCardNumber << '\n';
					cout << "------------------------------\n";
				}
			}
		}
	}
}; 	
