#include <iostream>
#include <Windows.h>
#include <fstream>
using namespace std;
double func_y(double n, double x)
{
    if (x < 0)
    {
        int y = 1;
        int i;
        for (i = 0; i < (n - 1); i++)
        {
            y *= (i * i * i) + x;
        }
        return y;
    }
    else
    {
        double sum = 0;
        double y = 0;
        for (int i = 1; i <= n - 1; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                sum += x / (i + j);
            }
            return y;
            y += sum;
            sum = 0;
        }

    }

}
void checkValidInput() {
    if (cin.fail())
    {
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
        throw "Помилка";
    }
}
void checkParamn(double n) {
    if (n <= 0)
    {
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
        throw "Неправильно, n > 0 .";
    }
}
void checkParamsminmax(double xmin, double xmax) {
    if (xmin < xmax)
    {
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
        throw "Неправильно, Xmin < Xmax";
    }
}
void checkParamxarg(double xarg) {
    if (xarg <= 0)
    {
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
        throw "Неправильно, хarg > 0";
    }
}
void read(double& xmax, double& n, double& xmin, double& xarg)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Введіть xmin ";
    cin >> xmin;
    checkValidInput();
    cout << "Введіть xmax ";
    cin >> xmax;
    checkValidInput();
    checkParamsminmax(xmax, xmin);
    cout << "Введіть n: ";
    cin >> n;
    checkParamn(n);
    checkValidInput();
    cout << "Введіть xarg: ";
    cin >> xarg;
    checkParamxarg(xarg);
    checkValidInput();
}
int main()
{
    try
    {
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
        double xmax, n, xmin, xarg;
        read(xmax, n, xmin, xarg);
        double x = xmin;

        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
        string path = "results.txt";
        ofstream fout;
        fout.open("results.txt");
        fout.is_open();
        if (!fout.is_open()) {
            cout << "Файл не відчиняється" << endl;
        }
        else
            for (x; x <= xmax; x += xarg)
            {
                double y = func_y(n, x);
                fout << "x = " << x << "\t y = " << y << endl;
            }
        fout.close();

    }

    catch (const char* ex)
    {
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
        cout << "\n";
        cout << ex << endl;
        cerr << "Помилка." << endl;
        return 1;
    }
    catch (...)
    {
        cout << "\n";
        cout << "Помилка." << endl;
        return 1;
    }
}