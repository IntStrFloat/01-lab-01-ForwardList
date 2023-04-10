# Лабораторная работа 10

## Задание 1

Реализуйте односвязный список `ForwardList` и функции для работы с ним. Элементы списка - целочисленные значения.

```cc
struct ForwardList {
  struct Node {
    Node* Next;
    int Data;
  };

  // Указатель на первый элемент списка.
  Node* Head;
};

// Инициализирует список.
void Construct(ForwardList& list);

// Разрушает список и осводождает выделенную память.
void Destruct(ForwardList& list);

// Добавляет элемент в начало списка.
void PushFront(ForwardList& list, int value);

// Удаляет элемент из начала списка.
// Освобождает память удаленного элемента.
void PopFront(ForwardList& list);

// Удаляет элемент после элемента, на который указывает |node|.
// Освобождает память удаленного элемента.
void RemoveAfter(ForwardList::Node* node);

// Вставляет новый элемент после элемента, на который указывает |node|.
ForwardList::Node* InsertAfter(ForwardList::Node* node, int value);

// Возвращает размер списка.
size_t Size(const ForwardList& list);

// Разворачивает список.
// Т.е изменяет список A -> B -> C -> D
// и превращает его в D -> C -> B -> A.
// Требования:
// * по времени - O(N);
// * по памяти - O(1).
void Reverse(ForwardList& list);

```


## Задание 2

Реализуйте очередь `Queue`.

```cc
struct Queue {
  struct Node {
    Node* Next;
    int Data;
  };

  // Указатель на первый элемент очереди.
  Node* Head;

  // Указатель на последний элемент очереди.
  Node* Tail;
};

// Инициализация очереди.
void Construct(Queue& queue);

// Освобождение памяти.
void Destruct(Queue& queue);

// Добавление нового элемента |value| в конец очереди |queue|.
void Push(Queue& queue, int value);

// Удаляет элемент из очереди. Возвращает значение первого в очереди элемента.
// Освобождает память удаленного элемента.
int Pop(Queue& queue);

// Проверяет, пуста ли очередь.
bool Empty(const Queue& queue);
```

## Задание 3

Реализуйте стек `Stack`.

```cc
struct Stack {
  struct Node {
    Node* Next;
    int Data;
  };

  // Указатель на вверхний элемент стека.
  Node* Top;
};

// Инициализация стека.
void Construct(Stack& stack);

// Освобождение памяти.
void Destruct(Stack& stack);

// Добавление нового элемента |value| наверх стека |stack|.
void Push(Stack& stack, int value);

// Снимает элемент с верхушки стека. Возвращает значение верхнего элемента.
// Освобождает память удаленного элемента.
int Pop(Stack& stack);

// Проверяет, пуст ли стек.
bool Empty(const Stack& stack);
```
