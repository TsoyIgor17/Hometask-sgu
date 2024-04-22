#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

void merge(vector<int> &arr, int l, int m, int r) // Сортировка двух отсортированных файлов
{
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> left(n1), right(n2);
    for (int i = 0; i < n1; i++)
    {
        left[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++)
    {
        right[j] = arr[m + 1 + j];
    }

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int> &arr, int l, int r) //сортировка одного массива
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main()
{
    ifstream inputFile("input.txt");
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
        mergeSort(row, 0, row.size() - 1);
        arr.push_back(row);
    }

    for (int i = 0; i < arr.size(); i++) //вывод данных в файл при доп условии
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            if ((i+1) % 3 == 0){
                outputFile << arr[i][arr[i].size()-j-1] << " ";
            }
            else {
                outputFile << arr[i][j] << " ";
            }
        }
        outputFile << endl;
    }

    return 0;
}