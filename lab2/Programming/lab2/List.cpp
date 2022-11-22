#include <stdlib.h>
#include "List.h"

using namespace std;

#pragma warning(push)
#pragma warning(disable:6011)
struct Node* InitializeList(int firstNodeData)
{
	struct Node* root = new Node;
	root->Data = firstNodeData;
	root->Next = NULL;
	root->Prev = NULL;
	return(root);
}

struct Node* AddItemToList(Node* node, int value)
{
	struct Node* tempNode = new Node;
	tempNode->Prev = node;
	tempNode->Next = NULL;
	tempNode->Data = value;
	node->Next = tempNode;
	return tempNode;
}
#pragma warning(pop)

struct Node* RemoveItemFromList(Node* node, int element)
{
	struct Node* tempNode = new Node;
	bool flag = false;
	tempNode = node;
	if (tempNode->Next != NULL)
	{
		do {
			if (tempNode->Data == element)
			{
				flag = true;
				break;
			}
			tempNode = tempNode->Next;
		} while (tempNode->Next != NULL);
	}

	if (flag = true)
	{
		if (tempNode->Prev != NULL)
		{
			tempNode->Prev->Next = tempNode->Next;
		}
		if (tempNode->Next != NULL)
		{
			tempNode->Next->Prev = tempNode->Prev;
		}
	}

	if (tempNode->Prev != NULL)
	{
		do {
			tempNode = tempNode->Prev;
		} while (tempNode->Prev != NULL);
	}
	return tempNode;
}

struct Node* AddItemToFirstPositionInList(Node* node, int value)
{
	struct Node* tempNode = new Node;
	struct Node* firstNode = new Node;
	tempNode = node;
	if (tempNode->Prev != 0)
	{
		do {
			tempNode = tempNode->Prev;
		} while (tempNode->Prev != NULL);
	}
	firstNode->Data = value;
	firstNode->Next = tempNode;
	firstNode->Prev = NULL;
	return(firstNode);
}