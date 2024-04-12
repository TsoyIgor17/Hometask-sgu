#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int X;
bool del(int x)
{
    return x % X == 0;
};

int main()
{
    setlocale(LC_ALL, "russian");

    // В первой последовательности удалить все элементы, кратные 𝑋.
    int n; // размер вектора
    cout << "n = ";
    cin >> n;
    cout << "X = "; // кратное число
    cin >> X;

    vector<int> vec, vec2; // создание первого вектора
    int x;
    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i << "] = ";
        cin >> x;
        vec.push_back(x);
    }

    cout << "Певрый вектор: ";
    for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++) // вывод первого вектора
    {
        cout << *iter << " ";
    }

    vector<int>::iterator it = remove_if(vec.begin(), vec.end(), del); // удаление кратных Х
    vec.erase(it, vec.end());

    cout << "Первый измененный вектор: ";
    for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++) // вывод первого измененного вектора
    {
        cout << *iter << " ";
    }

    // Отсортировать данные последовательности.
    sort(vec.begin(), vec.end());

    cout << "Первый измененный отсортированный вектор: ";
    for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++) // вывод первого измененного отсортированный вектора
    {
        cout << *iter << " ";
    }

    // Во второй — заменить элементы, попадающие в интервал [𝑎, 𝑏] числом 𝑌
    int n1; // размер вектора
    cout << endl
         << "n1 = ";
    cin >> n1;
    int Y; // число, на которую заменить
    cout << "Y = ";
    cin >> Y;
    cout << "[a,b] = "; // Ввод интервала
    int a, b;
    cin >> a >> b;

    vector<int> vec1; // создание второго вектора
    int x1;
    for (int i = 0; i < n1; i++)
    {
        cout << "a[" << i << "] = ";
        cin >> x1;
        vec1.push_back(x1);
    }

    cout << "Второй вектор: ";
    for (vector<int>::iterator iter = vec1.begin(); iter != vec1.end(); iter++) // вывод второго вектора
    {
        cout << *iter << " ";
    }

    for (int i = a; i <= b; i++)
    {
        replace( // замена
            vec1.begin(), vec1.end(), vec1[i], Y);
    }

    cout << "Второй измененный вектор: ";
    for (vector<int>::iterator iter = vec1.begin(); iter != vec1.end(); iter++) // вывод второго измененного вектора
    {
        cout << *iter << " ";
    }

    sort(vec1.begin(), vec1.end());

    cout << "Второй измененный отсортированный вектор: ";
    for (vector<int>::iterator iter = vec1.begin(); iter != vec1.end(); iter++) // вывод второго измененного отсортированный вектора
    {
        cout << *iter << " ";
    }

    // Объединить их в одну отсортированную последовательность.
    merge(vec.begin(), vec.end(), vec1.begin(), vec1.end(), inserter(vec2, vec2.end()));

    cout << "Финальный вектор: ";
    for (vector<int>::iterator iter = vec2.begin(); iter != vec2.end(); iter++) // вывод финального вектора
    {
        cout << *iter << " ";
    }
}