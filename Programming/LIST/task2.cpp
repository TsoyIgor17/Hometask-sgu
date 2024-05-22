#include <iostream>
using namespace std;

// структура списка
struct list
{
    int inf;
    list *next;
    list *prev;
};

// вставка элемента в конец списка
void push(list *&h, list *&t, int x)
{
    list *r = new list;
    r->inf = x;
    r->next = NULL;
    if (!h && !t)
    {
        r->prev = NULL;
        h = r;
    }
    else
    {
        t->next = r;
        r->prev = t;
    }
    t = r;
}

// вывод элементов списка
void print(list *h)
{
    list *p = h;
    while (p)
    {
        cout << p->inf << " ";
        p = p->next;
    }
}

// перенос четных чисел в начало
void moveEvenToFront(list *&h, list *&t)
{
    list *current = h;
    list *lastOdd = NULL; // список четных чисел
    while (current != NULL)
    {
        list *nextNode = current->next; // запоминаем следующий элемент перед изменением связей
        if (current->inf % 2 == 0)
        {
            if (current == h)
            {
                lastOdd = current;
            }
            else
            {
                if (current == t)
                {
                    t = current->prev;
                    t->next = NULL;
                }
                else
                {
                    current->next->prev = current->prev; // предыдущий для следующего теперь указывает на предыдущий от текущего
                    current->prev->next = current->next; // следующий для предыдущего теперь указывает на следующий от текущего
                }

                if (lastOdd == NULL)
                {
                    lastOdd = current;
                }

                // вставляем текущий элемент в начало
                current->next = h;
                current->prev = NULL;
                h->prev = current;
                h = current;
            }
        }
        else
        {
            lastOdd = current;
        }
        current = nextNode;
    }
}

int main()
{
    int n, x;
    cout << "Enter n: ";
    cin >> n;
    list *h = NULL;
    list *t = NULL;
    cout << "Input elements\n";
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        push(h, t, x);
    }

    cout << "Before: ";
    print(h);
    moveEvenToFront(h, t);
    cout << "\nAfter: ";
    print(h);
    cout << endl;
    return 0;
}