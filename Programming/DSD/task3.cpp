#include <iostream>
using namespace std;

// создаем структуру очередь
struct queue
{
    int inf;
    queue *next;
};

// функция добавления элемента x в конец очереди
void push(queue *&h, queue *&t, int x)
{
    queue *r = new queue;
    r->inf = x;
    r->next = NULL;
    if (!h && !t)
    {
        h = t = r;
    }
    else
    {
        t->next = r;
        t = r;
    }
}

// удаляет первый элемент из очереди и возвращает его значение
int pop(queue *&h, queue *&t)
{
    int i = h->inf;
    queue *r = h;
    h = h->next;
    if (!h)
        t = NULL;
    delete r;
    return i;
}

// пройтись по очереди и найти первый четный элемент
int findFirstCh(queue *h)
{
    int firstCh = 0;
    queue *temp = h;
    while (temp)
    {
        if (temp->inf % 2 == 0)
        {
            firstCh = temp->inf;
            return firstCh;
        }
        temp = temp->next;
    }
    return 0; // возвращаем 0, если первый четный элемент не найден
}

// выполнить циклический сдвиг очереди так, чтобы на первом месте был первый четный элемент
void result(queue *&h, queue *&t)
{
    int firstCh = findFirstCh(h);
    queue *newQueueBefore = NULL; // создаем новую очередь
    queue *newQueueBeforeEnd = NULL;
    queue *newQueueAfter = NULL; // создаем новую очередь
    queue *newQueueEndAfter = NULL;

    bool found = false; // переменная для пометки, что первый четный элемент уже найден
    while (!found)
    { // выполняем циклический сдвиг до тех пор, пока не найдем первый четный элемент
        int x = pop(h, t);
        if (x == firstCh)
        {
            found = true; // помечаем, что первый четный элемент найден
            push(newQueueAfter, newQueueEndAfter, x);
            break;
        }
        push(newQueueBefore, newQueueBeforeEnd, x); // добавляем элемент в новую очередь
    }

    while (h)
    { // добавляем оставшиеся элементы в новую очередь
        int x = pop(h, t);
        push(newQueueAfter, newQueueEndAfter, x);
    }

    while (newQueueBefore)
    {
        int temp = pop(newQueueBefore, newQueueBeforeEnd);
        push(newQueueAfter, newQueueEndAfter, temp);
    }

    h = newQueueAfter; // заменяем начальную очередь на новую
    t = newQueueEndAfter;
}

int main()
{
    queue *h = NULL; // создание очереди
    queue *t = NULL;
    int n, x;
    cout << "n=";
    cin >> n;
    cout << "Input element\n";
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        push(h, t, x);
    }
    cout << "Old queue\n"; // вывод данных
    queue *temp = h;
    while (temp)
    {
        cout << temp->inf << " ";
        temp = temp->next;
    }
    result(h, t);
    cout << "\nNew queue\n";
    while (h)
    {
        cout << pop(h, t) << " ";
    }
    return 0;
}