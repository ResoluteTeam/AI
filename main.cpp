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

unsigned int arrow = 0; // ���� ����� ���� �� ���� ��������� ��������
unsigned int last_arrow = 5; //������� ��������

const char* arrow_icon = ""; //���� �������
const char* free_space = "  "; // ������ � ���������
inline void RaiseArrow() { arrow > 0 ? arrow-- : arrow = last_arrow; }
inline void LowerArrow() { arrow < last_arrow ? arrow++ : arrow = 0; }

std::vector<Auto*> cars;

inline void ShowMainMenu()
{
    system("CLS");

    printf("%s ������ ���i\n",  arrow == 0 ? arrow_icon : free_space);
    printf("%s ����-i���\n",  arrow == 1 ? arrow_icon : free_space);
    printf("%s ��������� �� ������� ������ �������\n",  arrow == 2 ? arrow_icon : free_space);
    printf("%s ����i��� ����������� ��i�� ���� �� ����� ����\n",  arrow == 3 ? arrow_icon : free_space);
    printf("%s ����i��� ������ ������� �� �������\n",  arrow == 4 ? arrow_icon : free_space);
    printf("%s ����� ���� � ����i����� �����������\n",  arrow == 5 ? arrow_icon : free_space);

    printf("\n\n");
    printf("%s Esc - ���i�\n",free_space);
}

void fuelCountPerWeek() {
    //-----------------TEST
    Auto *car = new Auto("SS", "A95", 4.0);
    cars.push_back(car);
    //-----------------TEST


    for (int i = 0; i < cars.size(); i++) {
        float fCount = 0;
        fCount = cars.at(i)->getFuelCount() * 6;

        std::cout << "�����: " << cars.at(i)->getNumber() << "  �i���i��� ������, ����������� ������� �� �������:" << fCount;
    }

}

void fuelCostAllAutosOnEveryDay() {
    float fuelCost = 0;
    for (int i = 0; i < cars.size(); i++) {
        fuelCost += cars.at(i)->getFuelCount();

        std::cout << i + 1 << " �����(�) ���������� " << fuelCost << " �i���(i�) �� ����";
    }
}

float getFuelPrice(std::string _fuelType) {
    if (_fuelType == "A80") {
        return 17.49;
    } if (_fuelType == "A92") {
        return 20.47;
    } if (_fuelType == "A95") {
        return 21.22;
    } if (_fuelType == "A98") {
        return 25.95;
    } else {
        return 1;
    }
}

void fuelCostPerWeek() {
    float fuelCost = 0;
    for (int i = 0; i < cars.size(); i++) {
        fuelCost += getFuelPrice(cars.at(i)->getFuelType()) * 6;
    }

    std::cout << "����i��� ������ ������, ����������� �� �������: " << fuelCost;
}

std::string autoNumberWithHighestFuel() {

}


int main()
{
    setlocale(LC_CTYPE, "ukr");
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
//                    ������ ���� ����
                }; break;

            }
        }
    }
    return 0;
}
