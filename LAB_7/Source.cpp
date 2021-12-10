#include <iostream>
#include <ctime>
#include <string>
#include <windows.h>
#include <algorithm>
#include <fstream>
using namespace std;

int getint()
{
	while (true)
	{
		cout << "Please input integer vallue";
		cout << '\n';
		int a;
		cin >> a;
		cout << '\n';
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
		}
		else return a;
	}
}

double getdouble()
{
	while (true)
	{
		cout << "Please input double or integer vallue";
		cout << '\n';
		double a;
		cin >> a;
		cout << '\n';
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
		}
		else return a;
	}

}

struct date
{
	int day;
	string month;
	int year;
};

struct tovar
{
	date info;
	int section;
	string name;
	double price;
	int vallue;
};

void save(string file, tovar store)
{
	ofstream fout;
	fout.open(file, ofstream::app);
	fout << store.name << " " << store.section << " " << store.price << " " << store.vallue << " ";
	fout << store.info.day << " " << store.info.month << " " << store.info.year << endl;
	fout.close();
}

void add(tovar* store, int* store_info, string file)
{
	int n;
	ofstream fout;
	fout.open(file);
	fout.close();
	fout.open("Key.txt");
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
	if (store_info[0] == 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
		cout << "There if noone product, input at least one" << endl;
		Sleep(800);
		system("cls");
		cout << "Add name" << endl;
		cin >> store[0].name;
		cout << "Add section" << endl;
		store[0].section = getint();
		cout << "Add price" << endl;
		store[0].price = getdouble();
		cout << "Add vallue" << endl;
		store[0].vallue = getint();
		cout << "Add day" << endl;
		store[0].info.day = getint();
		cout << "Add month" << endl;
		cin >> store[0].info.month;
		cout << "Add year" << endl;
		store[0].info.year = getint();
		save(file, store[store_info[1]]);
		store_info[1]++;
		system("cls");
		store_info[0]++;
	}
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		cout << "How much products do you want to put?" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		n = getint();
		tovar* store_tmp = new tovar[n];
		for (int i = 0; i < n; i++)
		{
			cout << "Add name" << endl;
			cin >> store_tmp[i].name;
			cout << "Add section" << endl;
			store_tmp[i].section = getint();
			cout << "Add price" << endl;
			store_tmp[i].price = getdouble();
			cout << "Add vallue" << endl;
			store_tmp[i].vallue = getint();
			cout << "Add day" << endl;
			store_tmp[i].info.day = getint();
			cout << "Add month" << endl;
			cin >> store_tmp[i].info.month;
			cout << "Add year" << endl;
			store_tmp[i].info.year = getint();
			system("cls");
		}
		for (int i = 0; i < n; i++)
		{
			int k = 0;
			for (int j = 0; j < store_info[1]; j++)
			{
				if ((store_tmp[i].name == store[j].name) && (store_tmp[i].price == store[j].price))
				{
					store[j].vallue += store_tmp[i].vallue;
					k++;
				}					
			}
			if (k == 0)
			{
				store[store_info[1]] = store_tmp[i];
				store_info[1]++;
			}
		}
	}
	for (int i = 0; i < store_info[1]; i++)
	{
		save(file, store[i]);
	}
	fout << store_info[0] << endl;
	fout << store_info[1];
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void load(tovar* store, string file, int* store_info)
{
	ifstream fin, fkey;
	fin.open(file);
	int i = 0;
	if (!fin.is_open())
	{
		cout << "Empty file" << endl;
		Sleep(700);//Отсутствие файла
		add(store, store_info, file);
	}
	else
	{
		cout << "Succesfull" << endl;
		Sleep(500);
		fkey.open("Key.txt");
		//Считываем файл
		fkey >> store_info[0];
		fkey >> store_info[1];
		fkey.clear();
		int j = 0;
		while (!fin.eof())
		{

			int ost = i % 7;
			switch (ost)
			{
				case (0):
				{
					fin >> store[j].name;
					i++;
					break;
				}
				case (1):
				{
					string d;
					fin >> d;
					store[j].section = stoi(d);
					i++;
					break;
				}
				case (2):
				{
					string d;
					fin >> d;
					store[j].price = stod(d);
					i++;
					break;
				}
				case (3):
				{
					string d;
					fin >> d;
					store[j].vallue = stoi(d);
					i++;
					break;
				}
				case (4):
				{
					string d;
					fin >> d;
					store[j].info.day = stoi(d);
					i++;
					break;
				}
				case (5):
				{
					fin >> store[j].info.month;
					i++;
					break;
				}
				case (6):
				{
					string d;
					fin >> d;
					store[j].info.year = stoi(d);
					i++;
					j++;
					break;
				}
			}
		}

	}
}

void print(tovar* store, int* store_info)
{
	system("cls");
	string name;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	cout << "Input product name:" << endl;
	cin >> name;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	int k = 0;
	for (int i = 0; i < store_info[1]; i++)
	{
		if (store[i].name == name)
		{
			cout << "_____________________________________ Information ___________________________________" << endl;
			cout << "Name:\t" << store[i].name << endl;
			cout << "Price:\t" << store[i].price << endl;
			cout << "Section: " << store[i].section << endl;
			cout << "Vallue:\t" << store[i].vallue << endl;
			cout << "Date:\t" << store[i].info.day << " / " << store[i].info.month << " / " << store[i].info.year << endl;
			cout << "=====================================================================================" << endl;
			k = 1;
		}
	}
	if (k == 0)
	{
		cout << "Not founded" << endl;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	system("pause");
	system("cls");
}

void find_section(tovar* store, int* store_info)
{
	system("cls");
	cout << "Input section number" << endl;
	int number = getint();
	int k = 0;
	system("cls");
	for (int i = 0; i < store_info[1]; i++)
	{
		if (store[i].section == number)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
			cout << "__________________________ Information __________________________" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			cout << "Name: " << store[i].name << endl;
			cout << "Price: " << store[i].price << endl;
			cout << "Vallue: " << store[i].vallue << endl;
			cout << "Date: " << store[i].info.day << " / " << store[i].info.month << " / " << store[i].info.year << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
			cout << "=================================================================" << "\n" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			k++;
		}
	}
	if (k == 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		cout << "This section is empty" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
	system("pause");
}

void find_vallue(tovar* store, int* store_info)
{
	system("cls");
	tovar* store_tmp = new tovar[store_info[1]];
	cout << "Input necessary vallue: " << endl;
	int vallue = getint(), k = 0;
	for (int i = 0; i < store_info[1]; i++)
	{
		if (store[i].vallue <= vallue)
		{
			store_tmp[k] = store[i];
			k++;
		}
	}
	if (k == 0)
	{
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		cout << "Don't find anything" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
	else
	{
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		cout << "______________ Found these products ________________" << endl;
		for (int i = 0; i < k; i++)
		{
			cout << store_tmp[i].name << endl;
		}
		cout << "====================================================" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
	system("pause");
}

int main()
{
	ofstream fout;
	tovar* store = new tovar[10000];
	string file = "Save.txt", key = "Key.txt";
	int* store_info = new int[2];
	store_info[0] = 0; // Количество вызовов функции
	store_info[1] = 0; // Количество разных товаров
	load(store, file, store_info);
	int solution = 0;
	while (solution != 6)
	{
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
		cout << "______________________M.E.N.U______________________" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		cout << "===================================================" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
		cout << "Add new object...................................1" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		cout << "===================================================" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
		cout << "Print base objects...............................2" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		cout << "===================================================" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
		cout << "Find objects for section.........................3" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		cout << "===================================================" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
		cout << "Find objects with vallue smaller then keep.......4 " << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		cout << "===================================================" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
		cout << "Clear datebase...................................5" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		cout << "===================================================" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
		cout << "Exit with program................................6" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		cout << "===================================================" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
		cout << "Wait your answer" << endl;
		solution = getint();
		switch (solution)
		{
			case 1:
			{
				add(store, store_info, file);
				break;
			}
			case 2:
			{
				print(store, store_info);
				break;
			}
			case 3:
			{
				find_section(store, store_info);
				break;
			}
			case 4:
			{
				find_vallue(store, store_info);
				break;
			}
			case 5:
			{
				fout.open(file);
				fout.close();
				fout.open(key);
				fout.close();
				system("cls");
				break;
			}
			case 6:
			{
				solution = 6;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				break;
			}
		}
	}
}
