#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

// Структура даты
struct date
{
    int dd, mm, yy;
};

// Структура людей
struct people
{
    string surname;
    string job;
    date dateOfBirth;
    int staj;
    int salary;
};

// Из строки в дату
date Str_to_Date(string str)
{
    date x;
    string temp = str.substr(0, 2); // день
    x.dd = stoi(temp);
    temp = str.substr(3, 2); // месяц
    x.mm = stoi(temp);
    temp = str.substr(6, 4); // год
    x.yy = stoi(temp);
    return x;
};

// Ввод из файла
vector<people> inFile()
{
    vector<people> x;
    people temp;
    string tmp;
    while (in >> temp.surname >> temp.job >> tmp >> temp.staj >> temp.salary)
    {
        temp.dateOfBirth = Str_to_Date(tmp);
        x.push_back(temp);
    }
    return x;
};

// Вывод в файл
void print(people x)
{
    out << setw(30) << left << x.surname;
    out << setw(30) << left << x.job;
    out << setfill('0') << setw(2) << x.dateOfBirth.dd << ".";
    out << setw(2) << x.dateOfBirth.mm << ".";
    out << setw(4) << x.dateOfBirth.yy << setfill(' ') << " ";
    out << setw(30) << x.staj;
    out << setw(30) << x.salary << endl;
}

// Сортировка LSD
void LSDsort(vector<people> &x)
{
    int n = x.size(); // размер
    int p = 10;       // основание системы счисления
    int k = 0;        // максимальное количество разрядов

    for (int i = 0; i < n; i++)
    {
        if (to_string(x[i].salary).length() > k)
        {
            k = to_string(x[i].salary).length();
        }
    }

    vector<vector<people> > addPeople(p); // создание P дополнительных векторов

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int digit = (x[j].salary / static_cast<int>(pow(10, i))) % p;
            addPeople[digit].push_back(x[j]);
        }

        // Восстановление отсортированного массива
        int index = 0;
        for (int i = 0; i < p; i++)
        {
            for (people person : addPeople[i])
            {
                x[index++] = person;
            }
        }

        // Очистка дополнительных векторов
        for (int i = 0; i < p; i++)
        {
            addPeople[i].clear();
        }
    }
}

int main()
{
    vector<people> x;
    x = inFile();
    LSDsort(x);
    for (int i = 0; i < x.size(); i++)
    {
        print(x[i]);
    }
    in.close();
    out.close();
}