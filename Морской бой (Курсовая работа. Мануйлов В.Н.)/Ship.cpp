#include <iostream>
#include<string>
#include<vector>
#include<ctime>
#include "windows.h"

using namespace std;

//����� ���� ������
class PlayingTable
{
public:
	PlayingTable()
	{
		// ������� ������ ���� ������
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

	//����� ��������� ������� �������������
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
	//����� ��������� ������� �����������
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
	//����� ������� ���� ������
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
	//����� ������������ ��������� �� ������
	bool RegShoot(int x, int y)
	{
		//���� � ���� ����� ������, �� �������� ���������
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

//����� ���� ����������
class PlayingTablePc
{
public:
	PlayingTablePc()
	{
		// ������� ������ ���� ����������
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

		// ������� ������ ���� ����������, ������� ����� ���������� ������
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
		//���������� ������������ ��������� ���������
		count_shoot = 0;
	}

	
	//����� ������������ ������� �����������
	void ShowShipVer(int size)
	{
		
		if (size == 1)
		{
			//���������� ��������� �������� � � �
			l:
			int x = 1 + rand() % (10 - 1 + 1);
			int y = 1 + rand() % (10 - 1 + 1);

			//��������� ����������� ��������� ������� � ���������� ����������
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
	//����� ������� ���� ����������
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
	//����� ������� ���� ��������� ��� ������
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
	//����� ������������ ��������� �� ����������
	bool RegShoot(int x, int y)
	{
		//���� � ���� ����� ������, �� �������� ���������
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
	//����� �������� ����������
	void ShootPC(PlayingTable& table)
	{
		//���������� ���������� �������� ����������
		bool reg = false;
		Sleep(10);
		int x = 1 + rand() % (10 - 1 + 1);
		Sleep(10);
		int y = 1 + rand() % (10 - 1 + 1);
		reg = table.RegShoot(x, y);
		if (reg)
		{
			cout << "------------------" << endl;
			cout << "��������� �����!!!" << endl;
			cout << "------------------" << endl;
			count_shoot++;
		}
		else 
		{
			cout << "------------------------" << endl;
			cout << "��������� �����������!!!" << endl;
			cout << "------------------------" << endl;
		}


	}
	//������ ������� ���-�� ��������� ����������
	int GetCount()
	{
		return count_shoot;
	}



private:
	vector<vector<string>> tableShow;
	vector<vector<string>> table;
	int count_shoot;
};

//����� ��������� ������� ������
class Ship
{
public:
	Ship(int s, PlayingTable& table) : size(s)
	{
		//��������� ���������� �������
		int y = 0;
		//�������� ���������� �������
		int x = 0;
		//���������� ������ � ����
		int res;
		char word;
		//������������ ����������� ��������� ������� �� �������� �����������
		bool res_in = false;
		link:
		cout << "������� ��������� ����������: ";
		cin >> word;
		//��������� ����� � ����� ��� ������� ������ � ����� ������
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
			cout << "�� ����� ������������ ������������ �������! ���������� ��� ���" << endl;
			goto link;
		}
		}
		link1:
		cout << "������� �������� ����������: ";
		cin >> x;
		//��������� ������ �� �������� ���������� � ������� ����
		if (x < 1 || 10 < x)
		{
			cout << "�� ����� ������������ ������������ �������! ���������� ��� ���" << endl;
			goto link1;
		}
		cout << "�������� ������� ����������� �� ���������� ������ ��� �� ��������� �����:" << endl;
		cout << "1.) ����������� �����" << endl;
		cout << "2.) ������������� ������" << endl;
		cout << "������� ����� ��������: ";
		cin >> res;
		//���� ������ ��������� ������� �� ��������� ��� �����������
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
			cout << "�� ����� ������������ ������������ �������! ���������� ��� ���" << endl;
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
	//����� �������� ������
	void Shoot(PlayingTablePc& table)
	{
		//�������� ���������� ��������
		int x = 0;
		//��������� ���������� ��������
		int y = 0;
		//���������� ������ � ���� ����� ����� ��� ���
		bool reg = false;
		char word;
		d:
		cout << "---------------------------------------" << endl;
		cout << "������� ��������� ���������� ��������: ";
		cin >> word;
		//��������� ����� � ����� ��� ������� ������ � ����� ����������
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
			cout << "�� ����� ������������ ������������ �������! ���������� ��� ���" << endl;
			goto d;
		}
		}
		cout << "--------------------------------------" << endl;
		cout << "������� �������� ���������� ��������: ";
		i:
		cin >> x;
		//��������� ������� �������� �� �������� ����������
		if (x < 1 || 10 < x)
		{
			cout << "�� ����� ������������ ������������ �������! ���������� ��� ���" << endl;
			goto i;
		}
		//�������� ��������� �������� ������
		reg = table.RegShoot(x, y);
		if (reg)
		{
			cout << "\n----------------" << endl;
			cout << "  �� ������!!!"<<endl;
			cout << "----------------" << endl;
			count_shoot++;

		}
		else
		{
			cout << "\n------------------" << endl;
			cout << "�� ������������!!!" << endl;
			cout << "------------------" << endl;
		}

	}
	//������ ������� ���-�� ��������� ������
	int GetCount()
	{
		return count_shoot;
	}
private:
	int count_shoot;
};