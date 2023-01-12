#pragma once
#include "HashTable.h"
#include <string>

using namespace std;

/**
������ ������ � �������
*/
struct Dictionary
{
	/**
	��������� �� ���-�������
	*/
	HashTable* Table = new HashTable;
};

/**
��������� ������� � �������
\param Dictionary* dict �������
\param string value ����������� �������
\param string key ���� ������������ ��������
\return AddElement()
*/
bool AddItem(Dictionary* dict, string value, string key);

/**
������� ������� �� �������
\param Dictionary* dict �������
\param string key ���� ���������� ��������
\return RemoveElement()
*/
int RemoveItem(Dictionary* dict, string key);

/**
����� �������� � �������
\param Dictionary* dict �������
\param string key ���� �������������� ��������
\return FindElement()
*/
string FindItem(Dictionary* dict, string key);

/**
�������� �������
\param Dictionary* dict �������
*/
void DeleteDictionary(Dictionary* dict);
