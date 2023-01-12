#include "Treap.h"
#include <cstdlib>

Treap* InitializeTreap(int key)
{
	Treap* treap = new Treap;
	treap->Root = new TreapNode;

	treap->Root->Data = key;
	treap->Root->Left = treap->Root->Right = nullptr;
	treap->Root->Priority = rand() % Treap().MaxPriority;

	return treap;
}

void InsertElement(Treap* treap, TreapNode* element)
{
	if (treap->Root == nullptr)
	{
		treap->Root = element;
		return;
	}
	TreapNode* elementPrev = SearchParentElement(treap->Root, element->Data);
	if (elementPrev->Data > element->Data)
	{
		elementPrev->Left = element;
	}
	else if (elementPrev->Data == element->Data)
	{
		if (elementPrev->Left)
		{
			element->Left = elementPrev->Left;
			elementPrev->Left = nullptr;
		}
		if (elementPrev->Right)
		{
			element->Right = elementPrev->Right;
		}
		elementPrev->Right = element;
		if (elementPrev == treap->Root)
		{
			elementPrev->Left = element->Left;
			element->Left = nullptr;
		}
	}
	else
	{
		elementPrev->Right = element;
	}
}

TreapNode* SearchParentElement(TreapNode* currentElement, int data)
{
	if ((currentElement->Data < data) && (currentElement->Right == nullptr)
		|| (currentElement->Data >= data) && (currentElement->Left == nullptr))
	{
		return currentElement;
	}

	if (currentElement->Data < data)
	{
		SearchParentElement(currentElement->Right, data);
	}
	else if (currentElement->Data > data)
	{
		SearchParentElement(currentElement->Left, data);
	}
}

void Split(TreapNode* tree, int key, TreapNode*& left, TreapNode*& right)
{
	if (tree == nullptr)
		left = right = nullptr;
	else
	{
		if (tree->Data > key)
		{
			Split(tree->Left, key, left, tree->Left);
			right = tree;
		}
		else
		{
			Split(tree->Right, key, tree->Right, right);
			left = tree;
		}
	}
}

void Merge(TreapNode*& tree, TreapNode* left, TreapNode* right)
{
	if (left == nullptr || right == nullptr)
	{
		tree = left ? left : right;
	}
	else if (left->Priority > right->Priority)
	{
		Merge(left->Right, left->Right, right);
		tree = left;
	}
	else
	{
		Merge(right->Left, left, right->Left);
		tree = right;
	}
}

void InsertNotOpt(TreapNode*& root, int value)
{
	TreapNode* left;
	TreapNode* right;
	Split(root, value, left, right);
	TreapNode* newElement = new TreapNode;
	newElement->Left = nullptr;
	newElement->Right = nullptr;
	newElement->Data = value;
	newElement->Priority = rand() % Treap().MaxPriority;
	Merge(root, left, newElement);
	Merge(root, root, right);
}

void InsertOpt(int value, int priority, TreapNode*& current)
{
	if (current == nullptr)
	{
		current = new TreapNode;
		current->Left = nullptr;
		current->Right = nullptr;
		current->Data = value;
		current->Priority = priority;
		return;
	}

	if (priority >= current->Priority)
	{
		TreapNode* left;
		TreapNode* right;
		Split(current, value, left, right);
		TreapNode* newElement = new TreapNode;
		newElement->Left = left;
		newElement->Right = right;
		newElement->Data = value;
		newElement->Priority = priority;
		current = newElement;
	}
	else if (value < current->Data)
	{
		InsertOpt(value, priority, current->Left);
	}
	else
	{
		InsertOpt(value, priority, current->Right);
	}
}

void DeleteNotOpt(TreapNode*& root, int value)
{
	TreapNode* left;
	TreapNode* right;
	TreapNode* element;
	Split(root, value - 1, left, right);
	Split(right, value, element, right);
	Merge(root, left, right);
	delete element;
}

void DeleteOpt(TreapNode*& current, int value)
{
	if (current == nullptr)
	{
		return;
	}
	if (value == current->Data)
	{
		TreapNode* element = current;
		Merge(current, current->Left, current->Right);
		delete element;
	}
	else if (value < current->Data)
	{
		DeleteOpt(current->Left, value);
	}
	else
	{
		DeleteOpt(current->Right, value);
	}
}

TreapNode* SearchElementByValue(TreapNode* current, int value)
{
	if (current->Data == value)
	{
		return current;
	}
	if ((current->Data < value) && (current->Right != nullptr))
	{
		SearchElementByValue(current->Right, value);
	}
	else if ((current->Data > value) && (current->Left != nullptr))
	{
		SearchElementByValue(current->Left, value);
	}
	else
	{
		return nullptr;
	}
}

void DeleteTreap(TreapNode* current)
{
	if (current == nullptr)
	{
		return;
	}
	DeleteTreap(current->Left);
	DeleteTreap(current->Right);
	delete current;
}
