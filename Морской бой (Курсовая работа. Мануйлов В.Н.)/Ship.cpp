#include <iostream>
#include<string>
#include<vector>
#include<ctime>
#include "windows.h"

using namespace std;

//Класс поля игрока
class PlayingTable
{
public:
	PlayingTable()
	{
		// Создаем пустое поле игрока
		table = {
			{" ", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10"},
			{"a", ".", ".", ".", ".", ".", ".", ".", ".", ".", "."},
			{"b", ".", ".", ".", ".", ".", ".", ".", ".", ".", "."},
			{"c", ".", ".", ".", ".", ".", ".", ".", ".", ".", "."},
			{"d", ".", ".", ".", ".", ".", ".", ".", ".", ".", "."},
			{"e", ".", ".", ".", ".", ".", ".", ".", ".", ".", "."},
			{"f", ".", ".", ".", ".", ".", ".", ".", ".", ".", "."},
			{"g", ".", ".", ".", ".", ".", ".", ".", ".", ".", "."},
			{"h", ".", ".", ".", ".", ".", ".", ".", ".", ".", "."},
			{"i", ".", ".", ".", ".", ".", ".", ".", ".", ".", "."},
			{"j", ".", ".", ".", ".", ".", ".", ".", ".", ".", "."},
		};
	}

	//Метод создающий коробли горизонтально
	bool ShowShipGor(int x, int y, int size)
	{
		if (size == 1)
		{
			if (table[y][x] == ".")
			{
				table[y][x] = "#";
				return true;
			}
			else
			{
				return false;
			}
		}
		if (size == 2)
		{
			if (table[y][x] == "." && table[y][x + 1] == ".")
			{
				table[y][x] = "#";
				table[y][x + 1] = "#";
				return true;
			}
			else
			{
				return false;
			}
		}
		if (size == 3)
		{
			if (table[y][x] == "." && table[y][x + 1] == "." && table[y][x + 2] == ".")
			{
				table[y][x] = "#";
				table[y][x + 1] = "#";
				table[y][x + 2] = "#";
				return true;
			}
			else
			{
				return false;
			}
		}
		if (size == 4)
		{
			if (table[y][x] == "." && table[y][x + 1] == "." && table[y][x + 2] == "." && table[y][x + 3] == ".")
			{
				table[y][x] = "#";
				table[y][x + 1] = "#";
				table[y][x + 2] = "#";
				table[y][x + 3] = "#";
				return true;
			}
			else
			{
				return false;
			}
		}

	}
	//Метод создающий коробли вертикально
	bool ShowShipVer(int x, int y, int size)
	{
		if (size == 1)
		{
			if (table[y][x] == ".")
			{
				table[y][x] = "#";
				return true;
			}
			else
			{
				return false;
			}
		}
		if (size == 2)
		{
			if (table[y][x] == "." && table[y - 1][x] == ".")
			{
				table[y][x] = "#";
				table[y - 1][x] = "#";
				return true;
			}
			else
			{
				return false;
			}
		}
		if (size == 3)
		{
			if (table[y][x] == "." && table[y - 1][x] == "." && table[y - 2][x] == ".")
			{
				table[y][x] = "#";
				table[y - 1][x] = "#";
				table[y - 2][x] = "#";
				return true;
			}
			else
			{
				return false;
			}
		}
		if (size == 4)
		{
			if (table[y][x] == "." && table[y - 1][x] == "." && table[y - 2][x] == "." && table[y - 3][x] == ".")
			{
				table[y][x] = "#";
				table[y - 1][x] = "#";
				table[y - 2][x] = "#";
				table[y - 3][x] = "#";
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	//Метод выводит поле игрока
	void ShowTable()
	{
		for (int i = 0; i < 11; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				cout << table[i][j] << " ";
			}
			cout << endl;
		}
	}
	//Метод регестрирует попадания по игроку
	bool RegShoot(int x, int y)
	{
		//Если в этой точке палуба, то отмечаем попадание
		if (table[y][x] == "#")
		{
			table[y][x] = "X";
			return true;
		}
		else
		{
			table[y][x] = " ";
			return false;
		}
	}



private:
	vector<vector<string>> table;
};

//Класс поля компьютера
class PlayingTablePc
{
public:
	PlayingTablePc()
	{
		// Создаем пустое поле компьютера
		table = {
			{" ", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10"},
			{"a", ".", ".", ".", ".", ".", ".", ".", ".", ".", "."},
			{"b", ".", ".", ".", ".", ".", ".", ".", ".", ".", "."},
			{"c", ".", ".", ".", ".", ".", ".", ".", ".", ".", "."},
			{"d", ".", ".", ".", ".", ".", ".", ".", ".", ".", "."},
			{"e", ".", ".", ".", ".", ".", ".", ".", ".", ".", "."},
			{"f", ".", ".", ".", ".", ".", ".", ".", ".", ".", "."},
			{"g", ".", ".", ".", ".", ".", ".", ".", ".", ".", "."},
			{"h", ".", ".", ".", ".", ".", ".", ".", ".", ".", "."},
			{"i", ".", ".", ".", ".", ".", ".", ".", ".", ".", "."},
			{"j", ".", ".", ".", ".", ".", ".", ".", ".", ".", "."},
		};

		// Создаем пустое поле компьютера, которое будем отображать игроку
		tableShow = {
			{" ", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10"},
			{"a", ".", ".", ".", ".", ".", ".", ".", ".", ".", "."},
			{"b", ".", ".", ".", ".", ".", ".", ".", ".", ".", "."},
			{"c", ".", ".", ".", ".", ".", ".", ".", ".", ".", "."},
			{"d", ".", ".", ".", ".", ".", ".", ".", ".", ".", "."},
			{"e", ".", ".", ".", ".", ".", ".", ".", ".", ".", "."},
			{"f", ".", ".", ".", ".", ".", ".", ".", ".", ".", "."},
			{"g", ".", ".", ".", ".", ".", ".", ".", ".", ".", "."},
			{"h", ".", ".", ".", ".", ".", ".", ".", ".", ".", "."},
			{"i", ".", ".", ".", ".", ".", ".", ".", ".", ".", "."},
			{"j", ".", ".", ".", ".", ".", ".", ".", ".", ".", "."},
		};
		//Переменная подсчитывает попадания компютера
		count_shoot = 0;
	}

	
	//Метод генерирующий коробли вертикально
	void ShowShipVer(int size)
	{
		
		if (size == 1)
		{
			//Генерируем случайные значения х и у
			l:
			int x = 1 + rand() % (10 - 1 + 1);
			int y = 1 + rand() % (10 - 1 + 1);

			//Проверяем возможность установки коробля в полученные координаты
			if (table[y][x] == ".")
			{
				table[y][x] = "#";
			}
			else
			{
				Sleep(10);
				srand(time(NULL));
				goto l;
			}
		}
		if (size == 2)
		{
			l1:
			int x = 1 + rand() % (10 - 1 + 1);
			int y = 1 + rand() % (10 - 1 + 1);

			if (table[y][x] == "." && table[y - 1][x] == ".")
			{
				table[y][x] = "#";
				table[y - 1][x] = "#";
			}
			else
			{
				Sleep(10);
				srand(time(NULL));
				goto l1;
			}
		}
		if (size == 3)
		{
			l2:
			int x = 1 + rand() % (10 - 1 + 1);
			int y = 1 + rand() % (10 - 1 + 1);

			if (table[y][x] == "." && table[y - 1][x] == "." && table[y - 2][x] == ".")
			{
				table[y][x] = "#";
				table[y - 1][x] = "#";
				table[y - 2][x] = "#";
			}
			else
			{
				Sleep(10);
				srand(time(NULL));
				goto l2;
			}
		}
		if (size == 4)
		{
			l3:
			int x = 1 + rand() % (10 - 1 + 1);
			int y = 1 + rand() % (10 - 1 + 1);

			if (table[y][x] == "." && table[y - 1][x] == "." && table[y - 2][x] == "." && table[y - 3][x] == ".")
			{
				table[y][x] = "#";
				table[y - 1][x] = "#";
				table[y - 2][x] = "#";
				table[y - 3][x] = "#";
			}
			else
			{
				Sleep(10);
				srand(time(NULL));
				goto l3;
			}
		}
	}
	//Метод выводит поле компьютера
	void ShowTable()
	{
		for (int i = 0; i < 11; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				cout << table[i][j] << " ";
			}
			cout << endl;
		}
	}
	//Метод выводит поле комьютера для игрока
	void ShowTablePC()
	{
		for (int i = 0; i < 11; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				cout << tableShow[i][j] << " ";
			}
			cout << endl;
		}
	}
	//Метод регестрирует попадания по компьютеру
	bool RegShoot(int x, int y)
	{
		//Если в этой точке палуба, то отмечаем попадание
		if (table[y][x] == "#")
		{
			table[y][x] = "X";
			tableShow[y][x] = "X";
			return true;
		}
		else
		{
			tableShow[y][x] = " ";
			return false;
		}
	}
	//Метод выстрела компьютера
	void ShootPC(PlayingTable& table)
	{
		//Генерируем координаты выстрела компьютера
		bool reg = false;
		Sleep(10);
		int x = 1 + rand() % (10 - 1 + 1);
		Sleep(10);
		int y = 1 + rand() % (10 - 1 + 1);
		reg = table.RegShoot(x, y);
		if (reg)
		{
			cout << "------------------" << endl;
			cout << "КОМПЬЮТЕР ПОПАЛ!!!" << endl;
			cout << "------------------" << endl;
			count_shoot++;
		}
		else 
		{
			cout << "------------------------" << endl;
			cout << "КОМПЬЮТЕР ПРОМАХНУЛСЯ!!!" << endl;
			cout << "------------------------" << endl;
		}


	}
	//Геттер выводит кол-во попаданий компьютера
	int GetCount()
	{
		return count_shoot;
	}



private:
	vector<vector<string>> tableShow;
	vector<vector<string>> table;
	int count_shoot;
};

//Класс создающий корабли игрока
class Ship
{
public:
	Ship(int s, PlayingTable& table) : size(s)
	{
		//Буквенная координата коробля
		int y = 0;
		//Числовая координата коробля
		int x = 0;
		//Переменная выбора в меню
		int res;
		char word;
		//Регестрируем возможность поставить корабль по заданным координатам
		bool res_in = false;
		link:
		cout << "Введите буквенную координату: ";
		cin >> word;
		//Переводим букву в цифру для удобной работы с полем игрока
		switch (word)
		{
		case 'a': {
			y = 1;
			break;
		}
		case 'b': {
			y = 2;
			break;
		}
		case 'c': {
			y = 3;
			break;
		}
		case 'd': {
			y = 4;
			break;
		}
		case 'e': {
			y = 5;
			break;
		}
		case 'f': {
			y = 6;
			break;
		}
		case 'g': {
			y = 7;
			break;
		}
		case 'h': {
			y = 8;
			break;
		}
		case 'i': {
			y = 9;
			break;
		}
		case 'j': {
			y = 10;
			break;
		}
		default: {
			cout << "Вы ввели некорректное расположение коробля! Попробуйте еще раз" << endl;
			goto link;
		}
		}
		link1:
		cout << "Введите числовую координату: ";
		cin >> x;
		//Проверяем входит ли числовая координата в область поля
		if (x < 1 || 10 < x)
		{
			cout << "Вы ввели некорректное расположение коробля! Попробуйте еще раз" << endl;
			goto link1;
		}
		cout << "Выберите корабль установится по горизотали вправо или по вертикали вверх:" << endl;
		cout << "1.) Вертикально вверх" << endl;
		cout << "2.) Горизонтально вправо" << endl;
		cout << "Введите номер варианта: ";
		cin >> res;
		//Меню выбора установки коробля по вертикали или горизонтали
		switch (res)
		{
		case 1: {
			res_in = table.ShowShipVer(x, y, size);
			break;
		}
		case 2: {

			res_in = table.ShowShipGor(x, y, size);
			break;
		}
		}
		if (res_in == false)
		{
			cout << "Вы ввели некорректное расположение коробля! Попробуйте еще раз" << endl;
			goto link;
		}
	}
private:
	int size;
};

class Player
{
public:
	Player() { count_shoot = 0; }
	//Метод выстрела игрока
	void Shoot(PlayingTablePc& table)
	{
		//Числовая координата выстрела
		int x = 0;
		//Буквенная координата выстрела
		int y = 0;
		//Переменная хранит в себе попал игрок или нет
		bool reg = false;
		char word;
		d:
		cout << "---------------------------------------" << endl;
		cout << "ВВЕДИТЕ БУКВЕННУЮ КООРДИНАТУ ВЫСТРЕЛА: ";
		cin >> word;
		//Переводим буквы в цифры для удобной работы с полем компьютера
		switch (word)
		{
		case 'a': {
			y = 1;
			break;
		}
		case 'b': {
			y = 2;
			break;
		}
		case 'c': {
			y = 3;
			break;
		}
		case 'd': {
			y = 4;
			break;
		}
		case 'e': {
			y = 5;
			break;
		}
		case 'f': {
			y = 6;
			break;
		}
		case 'g': {
			y = 7;
			break;
		}
		case 'h': {
			y = 8;
			break;
		}
		case 'i': {
			y = 9;
			break;
		}
		case 'j': {
			y = 10;
			break;
		}
		default: {
			cout << "Вы ввели некорректное расположение коробля! Попробуйте еще раз" << endl;
			goto d;
		}
		}
		cout << "--------------------------------------" << endl;
		cout << "ВВЕДИТЕ ЧИСЛОВУЮ КООРДИНАТУ ВЫСТРЕЛА: ";
		i:
		cin >> x;
		//Проверяем границы выстрела по числовой координате
		if (x < 1 || 10 < x)
		{
			cout << "Вы ввели некорректное расположение коробля! Попробуйте еще раз" << endl;
			goto i;
		}
		//Получаем результат выстрела игрока
		reg = table.RegShoot(x, y);
		if (reg)
		{
			cout << "\n----------------" << endl;
			cout << "  ВЫ ПОПАЛИ!!!"<<endl;
			cout << "----------------" << endl;
			count_shoot++;

		}
		else
		{
			cout << "\n------------------" << endl;
			cout << "ВЫ ПРОМАХНУЛИСЬ!!!" << endl;
			cout << "------------------" << endl;
		}

	}
	//Геттер выводит кол-во попаданий игрока
	int GetCount()
	{
		return count_shoot;
	}
private:
	int count_shoot;
};