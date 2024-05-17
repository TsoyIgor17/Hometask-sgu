#include <iostream>
using namespace std;

// описание структуры стек
struct stack
{
    int inf;
    stack *next;
};

// функция вставки элемента х в стек h
void push(stack *&h, int x)
{
    stack *r = new stack;
    r->inf = x;
    r->next = h;
    h = r;
}

// функция извлекает из стека h первый элемент и возвращает его в качестве результата
int pop(stack *&h)
{
    int i = h->inf;
    stack *r = h;
    h = h->next;
    delete r;
    return i;
}

void reverse(stack *h)
{
    stack *head1 = NULL;     // инициализация буферного стека
    while (h)                // пока стек не пуст
        push(head1, pop(h)); // переписываем элементы из одного стека в другой
    h = head1;               // переобозначаем указатели
}

// функция которая ищет последнее четное число
int findCh(stack *h)
{
    stack *temp = NULL;   // инициализация вспомогательного стека
    int chet = pop(h), x; // в max кладем первый элемент стека h
    push(temp, chet);     // первый элемент стека h перекладываем в стек temp
    while (h)
    {               // пока стек не пуст
        x = pop(h); // извлекаем первый элемент из стека h в переменную h
        if (x % 2 == 0)
        {
            chet = x;
            push(temp, x);
            break;
        }
        push(temp, x);
    }
    while (h)
    {
        x = pop(h);
        push(temp, x);
    }
    reverse(temp); // меняем порядок элементов в стеке temp
    h = temp;      // h будет указывать на temp
    return chet;
}

// функция, которая будет выполнять задание
stack *result(stack *h)
// после максимального вставляет новый элемент
{
    stack *temp = NULL; // инициализация вспомогательного стека
    int x;
    int chet = findCh(h);

    cout << "Enter new element: "; // ввод данных
    int newEl;
    cin >> newEl;

    while (h)
    {
        x = pop(h);
        if (x == chet) // если встретили, то вставляем новый элемент и заканчиваем эту часть
        {
            push(temp, newEl);
            push(temp, x);
            break;
        }
        push(temp, x);
    }
    while (h) // дозакидываем оставшиеся элементы
    {
        x = pop(h);
        push(temp, x);
    }

    return (temp);
}

int main()
{
    stack *h = NULL;
    int n, x;
    cout << "n=";
    cin >> n; // вводим n количество элементов в стеке
    cout << "Input element\n";
    for (int i = 0; i < n; i++)
    {
        cin >> x;   // вводим число
        push(h, x); // добавляем число в стек h
    }
    h = result(h); // вызываем функцию result
    while (h)
    {
        cout << pop(h) << " "; // выводим элементы из стека на экран
    }
    return 0;
}