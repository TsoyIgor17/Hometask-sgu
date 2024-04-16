
// Дана последовательность целых чисел. Найти все такие цифры, которые встречаются только в трехзначных числах.
// Работать только с цифрами, которые встречаются в данной последовательности, а не со всеми цифрами от 0 до 9.
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <iterator>
using namespace std;

set<int> set_n(int n)
{
    // Функция которая возвращает множество из цифр числа n
    set<int> s;
    while (n != 0)
    {
        s.insert(n % 10);
        n /= 10;
    }
    return s;
}

int main()
{
    int n; // Количество чисел
    cout << "n = ";
    cin >> n; // Ввод n - количество чисел
    int a;
    set<int> s3, s, anothers, res;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        s = set_n(a);

        // в множество s3 добавляем цифры трехзначных чисел
        if (a >= 100 && a <= 999)
            s3.insert(s.begin(), s.end());
        // в множество anothers добавляем цифры не трехзначных чисел
        if (a <= 100 || a >= 999)
            anothers.insert(s.begin(), s.end());
    }

    set_difference(s3.begin(), s3.end(),anothers.begin(), anothers.end(), inserter(res, res.begin()));

    cout << "Массив цифр трехзначных цифр: ";
    for (set<int>::iterator iter = res.begin(); iter != res.end(); iter++)
    {
        cout << *iter << " ";
    }
}