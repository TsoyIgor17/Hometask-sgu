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
    list *r = new list; // создаем новый элемент
    r->inf = x;
    r->next = NULL;
    r->prev = t; // предыдущий указатель нового элемента указывает на текущий хвост списка (t)
    if (t) 
    {
        t->next = r; // если хвост списка существует, обновляем указатель следующего элемента текущего хвоста
    }
    else
    {
        h = r; // если хвоста нет, то это первый элемент и мы обновляем указатель головы списка
    }
    t = r; // обновляем хвост списка
};

// вывод элементов списка
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

//ф-ция для подсчета среднеарифметического
float calculateAverage(list *current) {
    int sum = 0;
    int count = 0;
    
    list *temp = current->next;
    while (temp != NULL) {
        sum += temp->inf;
        count++;
        temp = temp->next;
    }

    return (float) sum / count;
}

//ф-ция для удаления лишних элементов
void removeExtraElements(list *&h) {
    list *current = h;
    while (current->next != NULL) {
        if (current->inf < calculateAverage(current)) { //если текущий меньше среднего
            if (current->prev == NULL) { //если этот элемент голова, то меняем указатель на след
                h = current->next;
                h->prev = NULL;
            } else { //Перескакиваем на след элемент, для правильной связи элементов
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            list *tmp = current;
            current = current->next;
            delete tmp; // освобождаем память элемента, который нужно удалить
        } else {
            current = current->next;
        }
    }
}

int main()
{
    int n,x;
    cout << "Enter n: ";
    cin >> n;

    list *h = NULL;
    list *t = NULL;

    cout << "Input elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        push(h, t, x);
    }

    cout << "Before: ";
    print(h); //вывод до

    removeExtraElements(h); // вызов ф-ции для изменения

    cout << "After: ";
    print(h); //вывод после

    return 0;
}