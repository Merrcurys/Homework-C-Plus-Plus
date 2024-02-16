#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    setlocale(0, "");

    const int rows = 3, columns = 5;
    double numbers[rows][columns];

    cout << "СРЕДНЕЕ АРИФМЕТИЧЕСКОЕ СТРОК В МАССИВЕ\n";

    for (int i = 0; i < rows; i++) {
        cout << "Введите цифры для " + to_string(i + 1) + " строки:\n";
        for (int j = 0; j < columns; j++) {
            cin >> numbers[i][j];
        }
    }

    cout << endl;

    double sum_number = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            sum_number += numbers[i][j];
        }
        cout << "Ср.знач. строки №" + to_string(i + 1) + " - ";
        cout << sum_number / columns << endl;
        sum_number = 0;
    }
}