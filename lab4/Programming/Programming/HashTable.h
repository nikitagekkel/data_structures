#pragma once
#include "Node.h"
#include <string>

using namespace std;

/**
������ ������ � ���-�������
*/
struct HashTable
{
	/**
	������ �����
	*/
	const int GrowthFactor = 2;

	/**
	����������� �������������
	*/
	double CoefficientOccupancy = 4.0 / 3.0;

	/**
	���������� ���������
	*/
	int Count = 0;

	/**
	������ ���-�������
	*/
	int Capacity = 0;

	/**
	������ �������� ���-�������
	*/
	Node** Array = nullptr;
};

/**
�������� ������ � ���-�������
\param capacity ������ ���-�������
\param key ����
\return ������������ �������
*/
int HashFunction(int capacity, string key);

/**
��������� �������� � ���-�������
\param Node* first ������ ����
\param Node* node ���� � ���������
\return true ���� ���� ��������
\return false ���� �������� ���
*/
bool ResolveCollisions(Node* first, Node* node);

/**
������������� ���-�������
\param capacity ������ ���-�������
\return HashTable* table ���-�������
*/
HashTable* InitHashTable(int capacity);

/**
��������� ������� � ���-�������
\param HashTable* table ���-�������
\param string key ���� ������������ ��������
\param string value ����������� ������
\return true ���� ������� ��������
\return false ���� ������� �� ��������
*/
bool AddElement(HashTable* table, string key, string value);

/**
������� ������� �� ���-�������
\param HashTable* table ���-�������
\param string key ���� ���������� ��������
\return 0 ���� ������� ������
\return -1 ���� ������� �� ������
*/
int RemoveElement(HashTable* table, string key);

/**
���� ������� � ���-�������
\param HashTable* table ���-�������
\param string key ���� �������������� ��������
\return Node* ��������� �������
*/
string FindElement(HashTable* table, string key);

/**
���������� ��������������� ���-�������
\param HashTable* table ���-�������
\return HashTable* ���-�������
*/
HashTable* Rehashing(HashTable* table);
