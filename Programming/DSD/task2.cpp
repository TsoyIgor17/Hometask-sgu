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

// функция возвращает значение минимального элемента в стеке h
int stack_min(stack *h)
{
    stack *temp = NULL;  // инициализация вспомогательного стека
    int min = pop(h), x; // в min кладем первый элемент стека h
    push(temp, min);     // первый элемент стека h перекладываем в стек temp
    while (h)
    {                  // пока стек не пуст
        x = pop(h);    // извлекаем первый элемент из стека h в переменную x
        if (x < min)   // если этот элемент x меньше min,
            min = x;   // то запомним его в min
        push(temp, x); // кладем извлеченный элемент в temp
    }
    reverse(temp); // меняем порядок элементов в стеке temp
    h = temp;      // h будет указывать на temp
    return min;
}

// функция возвращает значение максимального элемента в стеке h
int stack_max(stack *h)
{
    stack *temp = NULL;  // инициализация вспомогательного стека
    int max = pop(h), x; // в max кладем первый элемент стека h
    push(temp, max);     // первый элемент стека h перекладываем в стек temp
    while (h)
    {                  // пока стек не пуст
        x = pop(h);    // извлекаем первый элемент из стека h в переменную h
        if (x > max)   // если этот элемент x больше max,
            max = x;   // то запомним его в max
        push(temp, x); // кладем извлеченный элемент в temp
    }
    reverse(temp); // меняем порядок элементов в стеке temp
    h = temp;      // h будет указывать на temp
    return max;
}

// функция, которая будет выполнять задание
stack *result(stack *h)
// после максимального вставляет новый элемент
{
    int min = stack_min(h); // ищем минимальный элемент
    int max = stack_max(h); // ищем максимальный элемент
    stack *temp = NULL;     // инициализация вспомогательного стека
    int x;

    while (h)
    {                        // пока стек не пуст
        x = pop(h);          // извлекаем первый элемент из стека h в переменную h
        if (x == min)        // если этот элемент x равен max
            push(temp, max); // то добавляем max в стек temp
        push(temp, x);       // добавляем х в стек temp
    }

    return (temp); // возвращаем temp как результат функции
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