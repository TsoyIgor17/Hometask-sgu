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

//Сортировка пузырьком
void BubbleSort(vector<people>& x) 
{
    int n = x.size();

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (x[j].job > x[j + 1].job) // Сначала сортируем по должности
            {
                swap(x[j], x[j + 1]);
            }
            else if (x[j].job == x[j + 1].job && x[j].staj > x[j + 1].staj) //по стажу
            {
                swap(x[j], x[j + 1]);
            }
            else if (x[j].job == x[j + 1].job && x[j].staj == x[j + 1].staj && x[j].salary > x[j + 1].salary) //по зарплате
            {
                swap(x[j], x[j + 1]);
            }
        }
    }
}

int main()
{
    vector<people> x;
    x = inFile();
    
    // Сортировка
    BubbleSort(x);
    
    // Вывод результатов
    for (int i = 0; i < x.size(); i++)
    {
        print(x[i]);
    }
    
    in.close();
    out.close();
}