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


inline void ShowStorageMenu()
{
    system("CLS");

    ShowMainMenu();

    printf("%s �����\n",              arrow == 1 ? arrow_icon : free_space);
    printf("%s ���� �����\n",         arrow == 2 ? arrow_icon : free_space);
    printf("%s Գ����\n",             arrow == 3 ? arrow_icon : free_space);
    printf("\n\n");
    printf("%s ����� - Back",free_space);
}

void fuelCountPerWeek() {
    //-----------------TEST
    Auto *car = new Auto("SS", "A95", 4.0);
    cars.push_back(car);
    //-----------------TEST


    for (int i = 0; i < cars.size(); i++) {
        float fCount = 0;
        fCount = cars.at(i)->getFuelCount() * 7;

        std::cout << "�����: " << cars.at(i)->getNumber() << "�i���i��� ������, ����������� ������� �� �������:" << fCount;
    }
}

float fuelCostAllAutosOnEveryDay() {

}

float fuelCostPerWeek() {

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
//                    ������ ����
                }; break;

                case 4:
                {
//                    ������ ����
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
