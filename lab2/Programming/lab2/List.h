#pragma once
//TODO: comments
/**
Структура узла двусвязного списка
*/
struct Node {
	/**
	Поле данных
	*/
	int Data = 0;

	/**
	Указатель на следующий узел
	*/
	Node *Next = nullptr;

	/**
	Указатель на предыдущий узел
	*/
	Node *Prev = nullptr;
};

//TODO: comments
/**
Структура двусвязного списка
*/
struct List
{
	/**
	Количество элементов в двусвязном списке
	*/
	int Length = 0;

	/**
	Указатель на первый элемент двусвязного списка
	*/
	Node* Head = nullptr;

	/**
	Указатель на последний элемент двусвязного списка
	*/
	Node* Tail = nullptr;
};

/**
Функция, добавляющая элемент в двусвязный список
\param list Двусвязный список
\param value Добавляемое значение
*/
void AddItemToList(List* list, int value);

/**
Функция, удаляющая элемент из двусвязного списка
\param list Двусвязный список
\param index Индекс удаляемого элемента
\return Булевое значение да или нет - удалось ли выполнить функцию
*/
bool RemoveItemFromList(List* list, int index);

/**
Функция, добавляющая элемент в начало двусвязного списка
\param list Двусвязный список
\param value Добавляемое значение
*/
void AddItemToFirstPositionInList(List* list, int value);

/**
Функция, добавляющая элемент после существующего элемента в двусвязном списке
\param list Двусвязный список
\param index Индекс существующего элемента
\param value Добавляемое значение
\return Булевое значение да или нет - удалось ли выполнить функцию
*/
bool AddItemAfter(List* list, int index, int value);

/**
Функция, добавляющая элемент до существующего элемента в двусвязном списке
\param list Двусвязный список
\param index Индекс существующего элемента
\param value Добавляемое значение
\return Булевое значение да или нет - удалось ли выполнить функцию
*/
bool AddItemBefore(List* list, int index, int value);

/**
Функция, сортирующая двусвязный список
\param list Двусвязный список
\return Булевое значение да или нет - удалось ли выполнить функцию
*/
bool InsertionSort(List* list);

/**
Функция, реализуюшая линейный поиск в двусвязном списке
\param list Двусвязный список
\param list Элемент, который необходимо найти
\return Индекс разыскиваемого элемента (-1, если элемент не найден)
*/
int LinearSearch(List* list, int element);