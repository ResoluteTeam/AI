#include <stdio.h>
#include <windows.h>
#include <clocale>
#include <vector>
#include <iostream>
#include "include/Auto.h"

#define BackPressed GetAsyncKeyState(VK_BACK)
#define BackPickUp keybd_event(VK_BACK, 0, KEYEVENTF_KEYUP, 0)

#define UpPressed GetAsyncKeyState(VK_UP)
#define UpPickUp keybd_event(VK_UP, 0, KEYEVENTF_KEYUP, 0)

#define DownPressed GetAsyncKeyState(VK_DOWN)
#define DownPickUp keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0)

#define EscapePressed GetAsyncKeyState(VK_ESCAPE)
#define EscapePickUp keybd_event(VK_ESCAPE, 0, KEYEVENTF_KEYUP, 0)

#define EnterPressed GetAsyncKeyState(VK_RETURN)
#define EnterPickUp keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0)

#define BackPressed GetAsyncKeyState(VK_BACK)
#define BackPickUp keybd_event(VK_BACK, 0, KEYEVENTF_KEYUP, 0)

const int Color = system("color F1");

unsigned int arrow = 1; // вибір номер меню на який ставеться позначка
unsigned int last_arrow = 5; //кількість категорій

const char* arrow_icon = ""; //знак категорії
const char* free_space = "  "; // відступ в категоріях
inline void RaiseArrow() { arrow > 0 ? arrow-- : arrow = last_arrow; }
inline void LowerArrow() { arrow < last_arrow ? arrow++ : arrow = 0; }

std::vector<Auto*> cars;

inline void ShowMainMenu()
{
    system("CLS");

    //printf("%s Ввести данi\n",  arrow == 0 ? arrow_icon : free_space);
    printf("%s Авто-iнфо\n",  arrow == 1 ? arrow_icon : free_space);
    printf("%s Витрачено за тиждень кожною машиною\n",  arrow == 2 ? arrow_icon : free_space);
    printf("%s Вартiсть витраченого всiма авто за кожен день\n",  arrow == 3 ? arrow_icon : free_space);
    printf("%s Вартiсть всього бензину за тиждень\n",  arrow == 4 ? arrow_icon : free_space);
    printf("%s Номер авто з найбiльшим споживанням\n",  arrow == 5 ? arrow_icon : free_space);

    printf("\n\n");
    printf("%s Esc - Вихiд\n",free_space);
}

inline void ShowStorageMenu()
{
    system("CLS");

    ShowMainMenu();

    printf("%s Пошук\n",              arrow == 1 ? arrow_icon : free_space);
    printf("%s Весь товар\n",         arrow == 2 ? arrow_icon : free_space);
    printf("%s Фільтр\n",             arrow == 3 ? arrow_icon : free_space);
    printf("\n\n");
    printf("%s Назад - Back",free_space);
}

void fillTable()
{
    bool exit = false;
    char answer;
    std::string number;
    int fuel;
    std::string fuelType;
    float fuelAmt;

    while(exit == false)
    {
        fuel = 0;
        std::cout << "\nВведiть номер машини: ";
        std::cin >> number;

        std::cout << "\nВиберiть тип пального(1 - A80, 2 - A92, 3 - A95, 4 - A98): ";
        std::cin >> fuel;



        while(fuel != 1 && fuel != 2 && fuel != 3 && fuel != 4)
        {
            fflush(stdin);
            std::cin.clear();
            std::cout << "Ви ввели неправильний тип пального.\n";
            std::cout << "\nВиберiть тип пального(1 - A80, 2 - A92, 3 - A95, 4 - A98): ";
            std::cin >> fuel;
        }

        switch(fuel)
        {
            case 1:{
                fuelType = "A80";
            }; break;
            case 2:{
                fuelType = "A92";
            }; break;
            case 3:{
                fuelType = "A95";
            }; break;
            case 4:{
                fuelType = "A98";
            }; break;
        }

        std::cout << "\nВведiть кiлькiсть пального, яке витрачається за один день:";
        std::cin >> fuelAmt;

        std::cout << "\nДодати ще один автомобiль? (т/н)";
        std::cin >> answer;

        Auto *car = new Auto(number, fuelType, fuelAmt);
        cars.push_back(car);

        std::cout << answer;
        if(answer == 'н' || answer == 'y' || answer == 'н')
        {
            exit = true;
        }
    }
}

void fuelCountPerWeek() {
    for (int i = 0; i < cars.size(); i++) {
        float fCount = 0;
        std::cout.flush();
        fCount = cars.at(i)->getFuelCount() * 6;

        std::cout << "\nНомер: " << cars.at(i)->getNumber() << "  Кiлькiсть палива, витраченого машиною за тиждень:" << fCount;
    }
}


void fuelCostAllAutosOnEveryDay() {
    float fuelCost = 0;
    std::cout.flush();
    for (int i = 0; i < cars.size(); i++) {
        fuelCost += cars.at(i)->getFuelCount();
    }
    std::cout << "\n" << cars.size() + 1 << " машин(а/и) витрачають " << fuelCost << " лiтра(iв) палива кожного дня";
}

float getFuelPrice(std::string _fuelType) {
    if (_fuelType == "A80" || _fuelType == "А80") {
        return 17.49;
    } if (_fuelType == "A92" || _fuelType == "А92") {
        return 20.47;
    } if (_fuelType == "A95" || _fuelType == "А95") {
        return 21.22;
    } if (_fuelType == "A98" || _fuelType == "А98") {
        return 25.95;
    } else {
        return 1;
    }
}

void fuelCostPerWeek() {
    float fuelCost = 0;
    std::cout.flush();
    for (int i = 0; i < cars.size(); i++) {
        fuelCost += getFuelPrice(cars.at(i)->getFuelType()) * 6;
    }

    std::cout << "Вартiсть палива за тиждень: " << fuelCost;
}

void autoNumberWithHighestFuel() {
    float fuelCost = 0;
    float temp  = 0;
    std::string carNumber;
    for (int i = 0; i < cars.size(); i++) {
        fuelCost = getFuelPrice(cars.at(i)->getFuelType()) * cars.at(i)->getFuelCount();
        if (fuelCost > temp) {
            carNumber = cars.at(i)->getNumber();
            temp = fuelCost;
        }
    }
    std::cout.flush();
    std::cout << "Номер: " << carNumber << "    (" << temp << ")";
}

void saveToFile() {

}
int main()
{
    setlocale(LC_CTYPE, "Russian");
    fillTable();
    ShowMainMenu();

    while(TRUE){

        if(DownPressed)   { DownPickUp; LowerArrow(); ShowMainMenu(); }
        if(UpPressed)     { UpPickUp;   RaiseArrow(); ShowMainMenu(); }
        if(EscapePressed) { EscapePickUp; exit(1); }
        if(BackPressed)   { BackPickUp; }

        if(EnterPressed)
        {
            EnterPickUp;

            switch(arrow)
            {
                case 0:
                {
                }; break;

                case 1:
                {

                }; break;

                case 2:
                {
                  fuelCountPerWeek();
                };break;

                case 3:
                {

                    fuelCostAllAutosOnEveryDay();
                }; break;

                case 4:
                {
                    fuelCostPerWeek();
                }; break;

                case 5:
                {
                    autoNumberWithHighestFuel();
                }; break;

            }
        }
    }
    return 0;
}
