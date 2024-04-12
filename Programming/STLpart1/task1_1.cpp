// Дан набор целых чисел. Удалить все нечетные числа.

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

bool nechet(int x)
{
    return x % 2 != 0;
}

int main()
{
    setlocale(LC_ALL, "russian");

    int n; // размер вектора
    cout << "n = ";
    cin >> n;

    vector<int> vec; // создание вектора
    int x;
    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i << "] = ";
        cin >> x;
        vec.push_back(x);
    }

    cout << "Вектор: ";
    for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++) // вывод вектора
    {
        cout << *iter << " ";
    }

    vector<int>::iterator it = remove_if(vec.begin(), vec.end(), nechet); // удаление нечетных
    vec.erase(it, vec.end());

    cout << "Новый вектор: ";
    for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++) // вывод вектора
    {
        cout << *iter << " ";
    }
}