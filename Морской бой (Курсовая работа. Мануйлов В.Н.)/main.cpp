#include <iostream>
#include<string>
#include<vector>
#include"Ship.cpp"
#include<ctime>
#include "windows.h"

using namespace std;

class PlayingTable;
class Ship;
class Player;
class PlayingTablePc;
//Функция создает объекты кораблей игрока и выводит его поле с расположенными кораблями
void InstShip(PlayingTable& table_player)
{
    cout << "\nВВЕДИТЕ КООРДИНАТЫ ОДОПАЛУБНИКА" << endl;
    Ship ship1_1(1, table_player);
    cout << "----------------" << endl;
    cout << "   ВАША КАРТА" << endl;
    cout << "----------------" << endl;
    table_player.ShowTable();
    cout << "\nВВЕДИТЕ КООРДИНАТЫ ОДОПАЛУБНИКА" << endl;
    Ship ship1_2(1, table_player);
    cout << "----------------" << endl;
    cout << "   ВАША КАРТА" << endl;
    cout << "----------------" << endl;
    table_player.ShowTable();
    cout << "\nВВЕДИТЕ КООРДИНАТЫ ОДОПАЛУБНИКА" << endl;
    Ship ship1_3(1, table_player);
    cout << "----------------" << endl;
    cout << "   ВАША КАРТА" << endl;
    cout << "----------------" << endl;
    table_player.ShowTable();
    cout << "\nВВЕДИТЕ КООРДИНАТЫ ОДОПАЛУБНИКА" << endl;
    Ship ship1_4(1, table_player);
    cout << "----------------" << endl;
    cout << "   ВАША КАРТА" << endl;
    cout << "----------------" << endl;
    table_player.ShowTable();

    cout << "\nВВЕДИТЕ КООРДИНАТЫ ДВУХПАЛУБНИКА" << endl;
    Ship ship2_1(2, table_player);
    cout << "----------------" << endl;
    cout << "   ВАША КАРТА" << endl;
    cout << "----------------" << endl;
    table_player.ShowTable();
    cout << "\nВВЕДИТЕ КООРДИНАТЫ ДВУХПАЛУБНИКА" << endl;
    Ship ship2_2(2, table_player);
    cout << "----------------" << endl;
    cout << "   ВАША КАРТА" << endl;
    cout << "----------------" << endl;
    table_player.ShowTable();
    cout << "\nВВЕДИТЕ КООРДИНАТЫ ДВУХПАЛУБНИКА" << endl;
    Ship ship2_3(2, table_player);
    cout << "----------------" << endl;
    cout << "   ВАША КАРТА" << endl;
    cout << "----------------" << endl;
    table_player.ShowTable();

    cout << "\nВВЕДИТЕ КООРДИНАТЫ ТРЕХПАЛУБНИКА" << endl;
    Ship ship3_1(3, table_player);
    cout << "----------------" << endl;
    cout << "   ВАША КАРТА" << endl;
    cout << "----------------" << endl;
    table_player.ShowTable();
    cout << "\nВВЕДИТЕ КООРДИНАТЫ ТРЕХПАЛУБНИКА" << endl;
    Ship ship3_2(3, table_player);
    cout << "----------------" << endl;
    cout << "   ВАША КАРТА" << endl;
    cout << "----------------" << endl;
    table_player.ShowTable();

    cout << "\nВВЕДИТЕ КООРДИНАТЫ ЧЕТЫРЕХПАЛУБНИКА" << endl;
    Ship ship4_1(4, table_player);
    cout << "----------------" << endl;
    cout << "   ВАША КАРТА" << endl;
    cout << "----------------" << endl;
    table_player.ShowTable();
}

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "\t\t\t\t\t\t\"МОРСКОЙ БОЙ\"" << endl << endl;
    //Меню игры
    while (true)
    {
        int item;
        cout << "    *МЕНЮ*" << endl;
        cout << "----------------" << endl;
        cout << "1.) НАЧАТЬ ИГРУ" << endl;
        cout << "2.) ВЫХОД" << endl;
        cout << "----------------" << endl;
        cout << "Выбор пункта меню: ";
        cin >> item;

        switch (item)
        {
            case 1:
            {
                //Объект поля игрока.
                PlayingTable table_player;
                //Объект поля компьютера
                PlayingTablePc table_comp;
                //Объект игрока
                Player player;
                cout << "----------------" << endl;
                cout << "КАРТА КОМПЬЮТЕРА" << endl;
                cout << "----------------" << endl;
                // Метод класса выводит поле компьютера в консоль
                table_comp.ShowTablePC();
                //В цикле случайно расставляются корабли компьютера
                for (int i = 0; i < 10; i++)
                {
                    if (i < 4)
                    {
                        //Задерживаем выполнение программы, чтобы обновить генерируемые значения
                        Sleep(10);
                        //Метод класса генерирует однопалубные корабли компьютера
                        table_comp.ShowShipVer(1);
                    }
                    else if (3 < i && i < 7)
                    {
                        //Задерживаем выполнение программы, чтобы обновить генерируемые значения
                        Sleep(10);
                        //Метод класса генерирует двухпалубные корабли компьютера
                        table_comp.ShowShipVer(2);
                    }
                    else if (6 < i && i < 9)
                    {
                        //Задерживаем выполнение программы, чтобы обновить генерируемые значения
                        Sleep(10);
                        //Метод класса генерирует трехпалубные корабли компьютера
                        table_comp.ShowShipVer(3);
                    }
                    else
                    {
                        //Задерживаем выполнение программы, чтобы обновить генерируемые значения
                        Sleep(10);
                        //Метод класса генерирует четрырехпалубные корабли компьютера
                        table_comp.ShowShipVer(4);
                    }
                }
                cout << endl;
                cout << "----------------" << endl;
                cout << "   ВАША КАРТА" << endl;
                cout << "----------------" << endl;
                table_player.ShowTable();
                //Вызываем функцию создающая объекты короблей игрока
                InstShip(table_player);
                int a = 0;
                int b = 0;
                // Ходим по циклу пока кто-либо не победит
                while (true)
                {
                    //Метод отвечающий за выстрел игрока
                    player.Shoot(table_comp);
                    //Метод отвечающий за выстрел компьютера
                    table_comp.ShootPC(table_player);
                    cout << "\n----------------" << endl;
                    cout << "КАРТА КОМПЬЮТЕРА" << endl;
                    cout << "----------------" << endl;
                    // Отображаем поле компьютера
                    table_comp.ShowTablePC();
                    cout << "\n----------------" << endl;
                    cout << "   ВАША КАРТА" << endl;
                    cout << "----------------" << endl;
                    //Отображаем поле игрока
                    table_player.ShowTable();
                    //Получаем кол-во уничтоженных палуб игроком
                    a = player.GetCount();
                    //Получаем кол-во уничтоженных палуб компьютером
                    b = table_comp.GetCount();
                    if (a == 20)
                    {
                        cout << "\n----------------" << endl;
                        cout << " ВЫ ПОБЕДИЛИ!!!" << endl;
                        cout << "----------------" << endl;
                        break;
                    }
                    if (b == 20)
                    {
                        cout << "\n----------------" << endl;
                        cout << " ВЫ ПРОИГРАЛИ!!!" << endl;
                        cout << "----------------" << endl;
                        break;
                    }


                }

                break;
            }
            case 2: default:
            {
                break;
            }
        }
        cout << "\n----------------" << endl;
        cout << "\nКОНЕЦ ИГРЫ!!!\n";
        cout << "----------------" << endl;
        break;
    }
}
