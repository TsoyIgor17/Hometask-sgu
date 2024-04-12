#include <iostream>
#include <numeric>
#include <functional>
#include <vector>
using namespace std;

int main()
{
    int n; // Количество степеней
    cout << "n = ";
    cin >> n;
    int x; // Число, степени которого нужно найти
    cout << "x = ";
    cin >> x;

    // Создаем вектор степеней
    vector<int> vec; // создание вектора
    for (int i = 0; i < n; i++)
    {
        vec.push_back(x);
    }
    partial_sum(vec.begin(), vec.end(), vec.begin(), multiplies<int>()); // Ф-ция для вычисления степеней

    // Выводим степени числа x
    for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++)
    {
        cout << *iter << " ";
    }

    return 0;
}