#pragma once
//TODO: comments
/**
��������� ���� ����������� ������
*/
struct Node {
	/**
	���� ������
	*/
	int Data = 0;

	/**
	��������� �� ��������� ����
	*/
	Node *Next = nullptr;

	/**
	��������� �� ���������� ����
	*/
	Node *Prev = nullptr;
};

//TODO: comments
/**
��������� ����������� ������
*/
struct List
{
	/**
	���������� ��������� � ���������� ������
	*/
	int Length = 0;

	/**
	��������� �� ������ ������� ����������� ������
	*/
	Node* Head = nullptr;

	/**
	��������� �� ��������� ������� ����������� ������
	*/
	Node* Tail = nullptr;
};

/**
�������, ����������� ������� � ���������� ������
\param list ���������� ������
\param value ����������� ��������
*/
void AddItemToList(List* list, int value);

/**
�������, ��������� ������� �� ����������� ������
\param list ���������� ������
\param index ������ ���������� ��������
\return ������� �������� �� ��� ��� - ������� �� ��������� �������
*/
bool RemoveItemFromList(List* list, int index);

/**
�������, ����������� ������� � ������ ����������� ������
\param list ���������� ������
\param value ����������� ��������
*/
void AddItemToFirstPositionInList(List* list, int value);

/**
�������, ����������� ������� ����� ������������� �������� � ���������� ������
\param list ���������� ������
\param index ������ ������������� ��������
\param value ����������� ��������
\return ������� �������� �� ��� ��� - ������� �� ��������� �������
*/
bool AddItemAfter(List* list, int index, int value);

/**
�������, ����������� ������� �� ������������� �������� � ���������� ������
\param list ���������� ������
\param index ������ ������������� ��������
\param value ����������� ��������
\return ������� �������� �� ��� ��� - ������� �� ��������� �������
*/
bool AddItemBefore(List* list, int index, int value);

/**
�������, ����������� ���������� ������
\param list ���������� ������
\return ������� �������� �� ��� ��� - ������� �� ��������� �������
*/
bool InsertionSort(List* list);

/**
�������, ����������� �������� ����� � ���������� ������
\param list ���������� ������
\param list �������, ������� ���������� �����
\return ������ �������������� �������� (-1, ���� ������� �� ������)
*/
int LinearSearch(List* list, int element);