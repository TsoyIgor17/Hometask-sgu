#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool isWord(string s) // Ф-ция, проверяющая является ли словом
{
    for (int i = 0; i < s.length(); i++)
    {
        if (!isalpha(s[i]))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int k; // Ввод данных
    cout << "Enter k: ";
    cin >> k;

    string word;
    map<string, int> wordCount;
    ifstream in("text.txt");

    while (in >> word)
    {
        if (isWord(word))
        {
            wordCount[word]++; // Добавление если слово
        }
    }

    vector<string> RareWords; // Вектор, в которые буду добавлять редкие слова

    for (int i = 0; i < k; i++)
    {
        int minCount = 999999;
        string minWord;
        for (const auto &pair : wordCount)
        {
            if (pair.second < minCount)
            {
                minCount = pair.second;
                minWord = pair.first;
            }
        }
        RareWords.push_back(minWord);
        wordCount.erase(minWord);
    }

    cout << "Самые редкие слова: " << endl;
    for (const auto &word : RareWords)
    {
        cout << word << endl;
    }
}
