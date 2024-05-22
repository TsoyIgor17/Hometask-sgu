#include <iostream>
using namespace std;

struct list
{
    int inf;
    list *next;
    list *prev;
};

// Вставка
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

// Вывод
void print(list *h)
{
    list *p = h;
    while (p)
    {
        cout << p->inf << " ";
        p = p->next;
    }
    cout << endl;
}

int findFirst(list *h)
{
    if (h)
    {
        return h->inf;
    }
    else
    {
        cout << "List is empty";
        return -1;
    }
}

// Функция для поиска минимального числа
int findMin(list *h)
{
    int minEl = h->inf;
    list *p = h;
    while (p)
    {
        if (p->inf < minEl)
        {
            minEl = p->inf;
        }
        p = p->next;
    }
    return minEl;
}

//Ф-ция для вставки х после у числа
void insertAfter(list *&h, list *&t, int x, int y)
{
    list *p = h;
    while (p)
    {
        if (p->inf == x) //если ткущий равен х
        {
            list *current = new list; //создаем новую очередь
            current->inf = y;
            current->next = p->next; //меняем в нужном порядке связи
            current->prev = p;
            if (p->next)
            {
                p->next->prev = current;
            }
            else
            {
                t = current; // если нет следующего, то хвост - текующий
            }
            p->next = current;
            p = current;
        }
        p = p->next;
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
    int firstEl = findFirst(h);
    int minEl = findMin(h);
    cout << "Before: ";
    print(h);
    insertAfter(h, t, firstEl, minEl);
    cout << "After: ";
    print(h);
    return 0;
}