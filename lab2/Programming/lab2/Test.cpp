#include <iostream>
#include <chrono>
#include <iomanip>
#include "List.h"

using namespace std;

/**
Очистка двусвязного списка
\param list Двусвязный список
*/
void RemoveList(List* list)
{
	if (list->Head == nullptr)
	{
		return;
	}

	int index = 0;
	Node* temp = list->Head->Next;

	while (temp != nullptr)
	{
		delete temp->Prev;
		list->Length--;
		temp = temp->Next;
	}

	delete temp;
	list->Length--;
	list->Head = nullptr;
	list->Tail = nullptr;
}

/**
Заполнение двусвязного списка случайными элементами
\param list Двусвязный список
\param count Количество элементов
*/
void RandomValues(List* list, int count)
{
	srand(time(nullptr));

	for (int i = 0; i < count; i++)
	{
		AddItemToList(list, rand() % 100);
	}
}

void TestOperations()
{
	List* list = new List();

	for (int step = 10000; step <= 1000000; step += 10000)
	{
		RemoveList(list);
		int testValue = 10;
		RandomValues(list, step);
		auto start = chrono::steady_clock::now();
		//AddItemToFirstPositionInList(list, testValue);
		AddItemBefore(list, list->Length / 2, testValue);
		//RemoveItemFromList(list, list->Length / 2);
		auto end = chrono::steady_clock::now();

		cout << chrono::duration_cast<std::chrono::microseconds>(end - start).count()
			/*<< ", " << step*/ << endl;
	}
}