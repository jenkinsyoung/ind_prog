#include <iostream>
#include <string>
#include "ocean.h"
#include "sea.h"
#include "bay.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    cout << "Океаны" << endl;
    Ocean ocean1("Atlantic", 8.376, 106460000);
    cout << ocean1;
    Ocean ocean2;
    cout << "Введите название, глубину, площадь океана:" << endl;
    cin >> ocean2;
    cout << endl << ocean2 << endl;

    cout << "Моря" << endl;
    Sea sea("Белое", "Северно-Ледовитый океан", 343, 90800, 9, 31);
    cout << endl << sea << endl;

    cout << "Заливы" << endl;
    Bay bay;
    cout << "Введите название, название океана, глубину, площадь, температуру, соленность и название моря для залива:"<<endl;
    cin >> bay;
    cout << endl << bay << endl;

    return 0;
}