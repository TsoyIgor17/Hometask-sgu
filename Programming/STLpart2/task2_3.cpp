#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <iterator>
#include <string>
using namespace std;
string lower(string s) // функция преобразует строку s в нижний регистр
{
    for (int i = 0; i < s.length(); i++)
        s[i] = tolower(s[i]);
    return s;
}
set<string> set_word(string s) // функция возвращает множество из слов нижнего регистра предложения s
{
    set<string> set_s;
    if (s[s.length() - 1] != ' ')
        s += " ";
    while (s != "")
    {
        set_s.insert(lower(s.substr(0, s.find(' '))));
        s.erase(0, s.find(' ') + 1);
    }
    return set_s;
}
int main()
{
    string stroka, temp;
    cout << "Введите текст: \n";
    getline(cin, stroka);
    set<string> res, res1, pov, voskl, vopr, s0;

    while (stroka != "")
    {
        int pos = stroka.find_first_of(".!?"); // Добавление слова в set, в зависимости от предложений
        temp = stroka.substr(0, pos);
        s0 = set_word(temp);
        if (stroka[pos] == '.')
            pov.insert(s0.begin(), s0.end());
        if (stroka[pos] == '!')
            voskl.insert(s0.begin(), s0.end());
        if (stroka[pos] == '?')
            vopr.insert(s0.begin(), s0.end());
        stroka.erase(0, pos + 1);
    }
    // Только в восклицательных
    set_difference(voskl.begin(), voskl.end(), vopr.begin(), vopr.end(), inserter(res1, res1.begin()));
    set_difference(res1.begin(), res1.end(), pov.begin(), pov.end(), inserter(res, res.begin()));
    for (set<string>::iterator i = res.begin(); i != res.end(); i++)
        cout << *i << " ";
}