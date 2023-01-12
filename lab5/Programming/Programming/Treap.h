#pragma once
#include <cstddef>

/**
Хранит информацию об узле дерева
*/
struct TreapNode
{
	/**
	Указатель на следующий левый узел
	*/
	TreapNode* Left = nullptr;

	/**
	Указатель на следующий правый узел
	*/
	TreapNode* Right = nullptr;

	/**
	Значение ключа узла
	*/
	int Data = NULL;

	/**
	Значение приоритета
	*/
	int Priority = NULL;
};

/**
Хранит информацию о декартовом дереве
*/
struct Treap
{
	/**
	Максимально возможный приоритет
	*/
	const int MaxPriority = 100;

	/**
	Укзаатель на корень дерева
	*/
	TreapNode* Root = nullptr;

	/**
	Функция дерева
	*/
	Treap()
	{
		Root = nullptr;
	}
};

/**
Производит инициализацию декартового дерева
\param int key значение ключа корневого узла
\return Treap* декартово дерево
*/
Treap* InitializeTreap(int key);

/**
Производит добавление узла в дерево
\param Treap* treap декартово дерево
\param TreapNode* добавляемый узел
*/
void InsertElement(Treap* treap, TreapNode* element);

/**
Производит поиск родительского узла в дереве
\param Treap* treap декартово дерево
\param int data данные ключа разыскиваемого узел
\return TreapNode* корневой узел
*/
TreapNode* SearchParentElement(TreapNode* currentElement, int data);

/**
Производит операцию разделения декартового дерева
\param TreapNode tree корневой узел дерева
\param int key ключ
\param TreapNode*& left следующее левое дерево
\param TreapNide*& right следющее правое дерево
*/
void Split(TreapNode* tree, int key, TreapNode*& left, TreapNode*& right);

/**
Производит операцию слияния
\param TreapNode*& tree корневой узел 
\param TreapNode* left следующее левое дерево
\param TreapNide* right следющее правое дерево
*/
void Merge(TreapNode*& tree, TreapNode* left, TreapNode* right);

/**
Производит операцию поиска элемента в дереве
\param TreapNode* current корневой узел
\param int value разыскиваемый элемент
\return TreapNode* корневой узел
*/
TreapNode* SearchElementByValue(TreapNode* current, int value);

/**
Производит неоптимизированную операцию вставки
\param TreapNode*& root корневой узел
\param int value добавляемый элемент
*/
void InsertNotOpt(TreapNode*& root, int value);

/**
Производит оптимизированную операцию вставки
\param int value добавляемый элемент
\param int priority значение приоритета
\param TreapNode*& current корневой узел
*/
void InsertOpt(int value, int priority, TreapNode*& current);

/**
Производит неоптимизированную операцию деления
\param TreapNode*& root корневой узел
\param int value значение удаляемого элемента
*/
void DeleteNotOpt(TreapNode*& root, int value);

/**
Производит оптимизированную операцию деления
\param TreapNode*& current корневой узел
\param int value значение удаляемого элемента
*/
void DeleteOpt(TreapNode*& current, int value);

/**
Производит удаление декартового дерева
\param TreapNode* current корневой узел
*/
void DeleteTreap(TreapNode* current);