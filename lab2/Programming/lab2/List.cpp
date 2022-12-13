#include <stdlib.h>
#include "List.h"

using namespace std;

Node* NodeSearch(List* list, int index)
{
	Node* node = new Node;

	if (index < list->Length / 2)
	{
		node = list->Head;

		for (int i = 0; i < index; ++i)
		{
			node = node->Next;
		}
		return node;
	}
	else
	{
		node = list->Tail;

		for (int i = list->Length - 1; i > index; i--)
		{
			node = node->Prev;
		}
		return node;
	}
}

void AddItemToList(List* list, int value)
{
	list->Length++;
	Node* node = new Node;

	node->Data = value;
	node->Prev = list->Tail;
	node->Next = nullptr;

	if (list->Tail != nullptr)
	{
		list->Tail->Next = node;
	}

	if (list->Head == nullptr)
	{
		list->Head = node;
	}

	list->Tail = node;
}

bool RemoveItemFromList(List* list, int index)
{
	if (list->Head == nullptr || list->Length - 1 < index)
	{
		return false;
	}

	Node* node = NodeSearch(list, index);

	if (node == list->Head)
	{
		list->Head = node->Next;
	}
	else
	{
		node->Prev->Next = node->Next;
	}

	if (node == list->Tail)
	{
		list->Tail = node->Prev;
	}
	else
	{
		node->Next->Prev = node->Prev;
	}

	list->Length--;
	delete node;
	return true;
}

void AddItemToFirstPositionInList(List* list, int value)
{
	list->Length++;
	Node* node = new Node();

	node->Data = value;
	node->Prev = list->Tail;
	node->Next = nullptr;

	if (list->Tail != nullptr)
	{
		list->Tail->Next = node;
	}

	if (list->Head == nullptr)
	{
		list->Head = node;
	}

	list->Tail = node;
}

bool AddItemAfter(List* list, int index, int value)
{
	if (list->Head == nullptr || list->Length - 1 < index)
	{
		return false;
	}

	Node* element = NodeSearch(list, index);
	Node* node = new Node;

	node->Data = value;

	if (element == list->Tail)
	{
		list->Tail->Next = node;
		node->Prev = list->Tail;
		node->Next = nullptr;
		list->Tail = node;
	}
	else
	{
		node->Next = element->Next;
		element->Next->Prev = node;
		element->Next = node;
		node->Prev = element;
	}
	
	list->Length++;
	return true;
}

bool AddItemBefore(List* list, int index, int value)
{
	if (list->Head == nullptr || list->Length - 1 < index)
	{
		return false;
	}

	Node* element = NodeSearch(list, index);
	Node* node = new Node;

	node->Data = value;

	if (element == list->Head)
	{
		list->Head->Prev = node;
		node->Next = list->Head;
		node->Prev = nullptr;
		list->Head = node;
	}
	else
	{
		node->Prev = element->Prev;
		element->Prev->Next = node;
		element->Prev = node;
		node->Next = element;
	}

	list->Length++;
	return true;
}

void SwapElements(List* list, Node* first, Node* second)
{
	if (first == list->Head)
	{
		list->Head = second;
	}
	else
	{
		first->Prev->Next = second;
	}

	if (second == list->Tail)
	{
		list->Tail = first;
	}
	else
	{
		second->Next->Prev = first;
	}

	first->Next = second->Next;
	second->Prev = first->Prev;
	first->Prev = second;
	second->Next = first;
}

bool InsertionSort(List* list)
{
	if (list->Head == nullptr)
	{
		return false;
	}

	for (Node* iNode = list->Head->Next; iNode != nullptr;
		iNode = iNode->Next)
	{
		Node* jNode = iNode->Prev;

		while (jNode != nullptr && jNode->Data > jNode->Next->Data)
		{
			SwapElements(list, jNode, jNode->Next);
			jNode = jNode->Prev->Prev;
		}
	}

	return true;
}

int LinearSearch(List* list, int element)
{
	int index = 0;

	for (Node* iNode = list->Head; iNode != nullptr;
		iNode = iNode->Next, index++)
	{
		if (iNode->Data == element)
		{
			return index;
		}
	}

	return -1;
}