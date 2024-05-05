#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>

using namespace std;

int main()
{
    string word = "quenn"; // Загаданное слово

    vector<char> alphabet; // Создание алфавита
    for (char letter = 'a'; letter <= 'z'; ++letter)
    {
        alphabet.push_back(letter);
    }
    printf("\e[1;1H\e[2J");

    vector<string> guessWord(word.length(), "_"); // Создание угадываемого слова

    int attempts = 0; // Создание попыток и максимального числа попыток
    int maxAttempts = 17;

    while (attempts < maxAttempts)
    {
        cout << "Слово: ";
        for (auto &letter : guessWord) // Вывод спрятанного слово
        {
            cout << letter << " ";
        }
        cout << endl;
        cout << "Введите букву: "; // Ввод буквы
        char guess;
        cin >> guess;

        if (find(alphabet.begin(), alphabet.end(), guess) != alphabet.end()) // если буква есть в алфавите
        {
            bool correctGuess = false;
            for (int i = 0; i < word.length(); i++)
            {
                if (word[i] == guess) // если буква есть в загаданном слове
                {
                    guessWord[i] = guess;
                    correctGuess = true;
                }
            }

            if (correctGuess) // проверка на догадку
            {
                cout << "Вы угадали!" << endl;
            }
            else
            {
                cout << "Не повезло:(" << endl;
            }

            alphabet.erase(remove(alphabet.begin(), alphabet.end(), guess), alphabet.end());

            if (word == accumulate(guessWord.begin(), guessWord.end(), string(""))) // проверка угадал ли слово полностью
            {
                cout << "Вы угадали слово " << word << "!" << endl;
                break;
            }
        }
        else
        {
            cout << "Эта буква уже использовалась или не является буквой алфавита" << endl;
        }

        attempts++;
    }

    if (attempts >= maxAttempts) // если попытки закончились
    {
        cout << "Вы не смогли угадать слово:( " << endl;
    }

    return 0;
}