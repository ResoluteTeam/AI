#include <stdio.h>
#include <windows.h>
#include <clocale>
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
inline void RaiseArrow() { arrow > 1 ? arrow-- : arrow = last_arrow; }
inline void LowerArrow() { arrow < last_arrow ? arrow++ : arrow = 1; }


inline void ShowMainMenu()
{
    system("CLS");

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

float fuelCountPerWeek() {

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
                case 1:
                  {

                  }; break;

                case 2:
                {
                  //  методи сюда

                };break;

                case 3:
                {
//                    методи сюда
                }; break;

                case 4:
                {
//                    методи сюда
                }; break;

                case 5:
                {
//                    методи сюда
                }; break;

            }
        }
    }
    return 0;
}
