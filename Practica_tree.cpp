#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");
    int choice, num1, num2;
    cout << "КАЛЬКУЛЯТОР\n1. Сложение\n2. Вычитание\n3. Умножение\n4. Деление\n5. Степень\n6. Корень\n7. 1% от числа\n8. Факториал\n9. Выход";
    while (true) {
        cout << "\n\nВведите цифру желаемой операции: ";
        cin >> choice;
        if (choice <= 5)
        {
            cout << "Введите первое число: ";
            cin >> num1;
            cout << "Введите второе число: ";
            cin >> num2;
        }
        else if (choice <= 8)
        {
            cout << "Введите первое число: ";
            cin >> num1;
        }
        else if (choice == 9)
            break;
        else
        {
            cout << "Вы ввели неправильное значение операции!";
            continue;
        }
        switch (choice)
        {
        case 1: cout << "Результат сложения: " << num1 + num2; goto exit_goto;
        case 2: cout << "Результат вычитания: " << num1 - num2; goto exit_goto;
        case 3: cout << "Результат умножения: " << num1 * num2; goto exit_goto;
        case 4:
        {
            if (num2 != 0) {
                cout << "Результат деления: " << num1 / num2; goto exit_goto;
            }
            cout << "На ноль делить нельзя, bro!"; break;
        }
        case 5: cout << "Результат возведения в степень: " << pow(num1, num2); goto exit_goto;
        case 6:
        {
            if (num1 >= 0)
            {
                cout << "Результат корня: " << sqrt(num1); goto exit_goto;
            }
            cout << "Отрицательного корня не бывает, bro!"; break;
        }
        

        case 7: cout << "Результат 1%: " << num1 / 100; goto exit_goto;
        case 8:
        {
            if (num1 >= 0) {
                long int f = 1;
                for (int i = 1; i <= num1; i++)
                {
                    f *= i;
                }
                cout << "Результат факториала: " << f; goto exit_goto;
            }
            cout << "Отрицательного факториала не бывает, bro!"; break;
        }
        }
    }
    exit_goto:
    return 0;
}