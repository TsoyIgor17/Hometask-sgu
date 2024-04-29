#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include <algorithm>
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

// Сортировка расчесткой по году, потом по стажу
void CombSort(vector<people>& x)
{
    int n = x.size();
    int gap = n;
    const double shrink = 1.3;
    bool sorted = false;
    
    while (!sorted)
    {
        gap = floor(gap / shrink);
        if (gap <= 1)
        {
            gap = 1;
            sorted = true;
        }

        for (int i = 0; i + gap < n; ++i)
        {
            if (x[i].dateOfBirth.yy > x[i + gap].dateOfBirth.yy || 
                (x[i].dateOfBirth.yy == x[i + gap].dateOfBirth.yy && x[i].staj > x[i + gap].staj))
            {
                // Swap
                swap(x[i], x[i + gap]);
                sorted = false;
            }
        }
    }
}

int main()
{
    vector<people> x;
    x = inFile();
    
    // Сортировка
    CombSort(x);
    
    // Вывод результатов
    for (int i = 0; i < x.size(); i++)
    {
        print(x[i]);
    }
    
    in.close();
    out.close();
}