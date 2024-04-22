#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

void countingSort(vector<int> &arr, int n)
{
    vector<int> counts(101); // Инициализация вектора для подсчета
    for (int i = 0; i < n; i++)
    {
        counts[arr[i]]++; // Подсчитываем количество каждого элемента в строке
    }
    int index = 0;
    for (int i = 0; i < 101; i++)
    {
        for (int k = 0; k < counts[i]; k++)
        {
            arr[index++] = i; // Заполняем отсортированный массив
        }
    }
}

int main()
{
    ifstream inputFile("input.txt"); // Потоки для файлов
    ofstream outputFile("output.txt");

    vector<vector<int> > arr;
    string line;
    while (getline(inputFile, line))
    {
        istringstream iss(line);
        vector<int> row;
        int num;
        while (iss >> num)
        {
            row.push_back(num);
        }
        countingSort(row, row.size());
        arr.push_back(row);
    }

    for (int i = 0; i < arr.size(); i++) //вывод в файл
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            outputFile << arr[i][j] << " ";
        }
        outputFile << endl;
    }

    return 0;
}