#pragma once
#include "HashTable.h"
#include <string>

using namespace std;

/**
Хранит данные о словаре
*/
struct Dictionary
{
	/**
	Указатель на хеш-таблицу
	*/
	HashTable* Table = new HashTable;
};

/**
Добавляет элемент в словарь
\param Dictionary* dict словарь
\param string value добавляемый элемент
\param string key ключ добавляемого элемента
\return AddElement()
*/
bool AddItem(Dictionary* dict, string value, string key);

/**
Удаляет элемент из словаря
\param Dictionary* dict словарь
\param string key ключ удаляемого элемента
\return RemoveElement()
*/
int RemoveItem(Dictionary* dict, string key);

/**
Поиск элемента в словаре
\param Dictionary* dict словарь
\param string key ключ разыскиваемого элемента
\return FindElement()
*/
string FindItem(Dictionary* dict, string key);

/**
Удаление словаря
\param Dictionary* dict словарь
*/
void DeleteDictionary(Dictionary* dict);
