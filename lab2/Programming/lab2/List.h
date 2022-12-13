#pragma once

struct Node {	
	int Data = 0;
	Node *Next = nullptr;
	Node *Prev = nullptr;
};

struct List
{
	int Length = 0;
	Node* Head = nullptr;
	Node* Tail = nullptr;
};


void AddItemToList(List* list, int value);
bool RemoveItemFromList(List* list, int index);
void AddItemToFirstPositionInList(List* list, int value);
bool AddItemAfter(List* list, int index, int value);
bool AddItemBefore(List* list, int index, int value);
bool InsertionSort(List* list);
int LinearSearch(List* list, int element);