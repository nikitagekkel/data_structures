#pragma once
#include <cstddef>

/**
������ ���������� �� ���� ������
*/
struct TreapNode
{
	/**
	��������� �� ��������� ����� ����
	*/
	TreapNode* Left = nullptr;

	/**
	��������� �� ��������� ������ ����
	*/
	TreapNode* Right = nullptr;

	/**
	�������� ����� ����
	*/
	int Data = NULL;

	/**
	�������� ����������
	*/
	int Priority = NULL;
};

/**
������ ���������� � ���������� ������
*/
struct Treap
{
	/**
	����������� ��������� ���������
	*/
	const int MaxPriority = 100;

	/**
	��������� �� ������ ������
	*/
	TreapNode* Root = nullptr;

	/**
	������� ������
	*/
	Treap()
	{
		Root = nullptr;
	}
};

/**
���������� ������������� ����������� ������
\param int key �������� ����� ��������� ����
\return Treap* ��������� ������
*/
Treap* InitializeTreap(int key);

/**
���������� ���������� ���� � ������
\param Treap* treap ��������� ������
\param TreapNode* ����������� ����
*/
void InsertElement(Treap* treap, TreapNode* element);

/**
���������� ����� ������������� ���� � ������
\param Treap* treap ��������� ������
\param int data ������ ����� �������������� ����
\return TreapNode* �������� ����
*/
TreapNode* SearchParentElement(TreapNode* currentElement, int data);

/**
���������� �������� ���������� ����������� ������
\param TreapNode tree �������� ���� ������
\param int key ����
\param TreapNode*& left ��������� ����� ������
\param TreapNide*& right �������� ������ ������
*/
void Split(TreapNode* tree, int key, TreapNode*& left, TreapNode*& right);

/**
���������� �������� �������
\param TreapNode*& tree �������� ���� 
\param TreapNode* left ��������� ����� ������
\param TreapNide* right �������� ������ ������
*/
void Merge(TreapNode*& tree, TreapNode* left, TreapNode* right);

/**
���������� �������� ������ �������� � ������
\param TreapNode* current �������� ����
\param int value ������������� �������
\return TreapNode* �������� ����
*/
TreapNode* SearchElementByValue(TreapNode* current, int value);

/**
���������� ������������������ �������� �������
\param TreapNode*& root �������� ����
\param int value ����������� �������
*/
void InsertNotOpt(TreapNode*& root, int value);

/**
���������� ���������������� �������� �������
\param int value ����������� �������
\param int priority �������� ����������
\param TreapNode*& current �������� ����
*/
void InsertOpt(int value, int priority, TreapNode*& current);

/**
���������� ������������������ �������� �������
\param TreapNode*& root �������� ����
\param int value �������� ���������� ��������
*/
void DeleteNotOpt(TreapNode*& root, int value);

/**
���������� ���������������� �������� �������
\param TreapNode*& current �������� ����
\param int value �������� ���������� ��������
*/
void DeleteOpt(TreapNode*& current, int value);

/**
���������� �������� ����������� ������
\param TreapNode* current �������� ����
*/
void DeleteTreap(TreapNode* current);