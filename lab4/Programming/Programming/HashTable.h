#pragma once
#include "Node.h"
#include <string>

using namespace std;

/**
Хранит данные о хеш-таблице
*/
struct HashTable
{
	/**
	Фактор роста
	*/
	const int GrowthFactor = 2;

	/**
	Коэффициент заполняемости
	*/
	double CoefficientOccupancy = 4.0 / 3.0;

	/**
	Количество элементов
	*/
	int Count = 0;

	/**
	Размер хеш-таблицы
	*/
	int Capacity = 0;

	/**
	Хранит элементы хеш-таблицы
	*/
	Node** Array = nullptr;
};

/**
Хеширует данные в хеш-таблице
\param capacity размер хеш-таблицы
\param key ключ
\return хешированный элемент
*/
int HashFunction(int capacity, string key);

/**
Разрешает коллизии в хеш-таблице
\param Node* first первый узел
\param Node* node узел с коллизией
\return true если есть коллизия
\return false если коллизии нет
*/
bool ResolveCollisions(Node* first, Node* node);

/**
Инициализация хеш-таблицы
\param capacity размер хеш-таблицы
\return HashTable* table хеш-таблица
*/
HashTable* InitHashTable(int capacity);

/**
Добавляет элемент в хеш-таблицу
\param HashTable* table хеш-таблица
\param string key ключ добавляемого элемента
\param string value добавляемый элемен
\return true если элемент добавлен
\return false если элемент не добавлен
*/
bool AddElement(HashTable* table, string key, string value);

/**
Удаляет элемент из хеш-таблицы
\param HashTable* table хеш-таблица
\param string key ключ удаляемого элемента
\return 0 если элемент удален
\return -1 если элемент не найден
*/
int RemoveElement(HashTable* table, string key);

/**
Ищет элемент в хеш-таблице
\param HashTable* table хеш-таблица
\param string key ключ разыскиваемого элемента
\return Node* найденный элемент
*/
string FindElement(HashTable* table, string key);

/**
Производит перехеширование хеш-таблицы
\param HashTable* table хеш-таблица
\return HashTable* хеш-таблица
*/
HashTable* Rehashing(HashTable* table);
