#include "DynamicArray.h"
#include <iostream>
#include <cmath>

using namespace std;

/// <summary>
/// Реализует добавление элемента в динамический массив
/// </summary>
/// <param name="array">Динамичесикй массив</param>
/// <param name="element">Добавляемый элемент</param>
void AddElementInArray(DynamicArray* array, int element)
{
	ResizeDynamicArray(array);
	array->Length++;
	array->Array[array->Length - 1] = element;
}

/// <summary>
/// Реализует удаление элемента из массива по индексу
/// </summary>
/// <param name="array">Динамический массив</param>
/// <param name="index">Индекс удаляемого элемента</param>
void RemoveElementAtIndex(DynamicArray* array, int index)
{
	if (CheckIndexOutRange(array, index))
	{
		PrintIndexOutOfRange();
		return;
	}

	for (int i = index; i < array->Length - 1; i++)
	{
		array->Array[i] = array->Array[i + 1];
	}

	array->Length--;
}

/// <summary>
/// Реализует добавление элемента на первую позицию в массиве
/// </summary>
/// <param name="array">Динамический массив</param>
/// <param name="element">Добавляемый элемент</param>
void InsertElementToFirstPosition(DynamicArray* array, int element)
{
	ResizeDynamicArray(array);
	array->Length++;

	int* tempArray = new int[array->Capacity + 4];
	tempArray[0] = element;
	for (int i = 1; i < array->Length; i++)
	{
		tempArray[i] = array->Array[i - 1];
	}
	delete[] array->Array;
	array->Array = tempArray;
}

/// <summary>
/// Реализует добавление элемента на последнюю позицию массива
/// </summary>
/// <param name="array">Динамический массив</param>
/// <param name="element">Добавлемый элемент</param>
void InsertElementToLastPosition(DynamicArray* array, int element)
{
	ResizeDynamicArray(array);
	array->Length++;
	array->Array[array->Length - 1] = element;
}

/// <summary>
/// Реализует добавление элемента по индексу
/// </summary>
/// <param name="array">Динамический массив</param>
/// <param name="index">Индекс добавляемого элемента</param>
/// <param name="element">Добавляемый элемент</param>
void InsertElementAtIndex(DynamicArray* array, int index, int element)
{
	if (CheckIndexOutRange(array, index))
	{
		PrintIndexOutOfRange();
		return;
	}
	ResizeDynamicArray(array);
	array->Length++;
	
	int* tempArray = new int[array->Capacity + 16];
	for (int i = 0; i <= index; i++)
	{
		tempArray[i] = array->Array[i];
	}
	int tempElement;
	tempElement = array->Array[index + 1];
	tempArray[index + 1] = element;
	tempArray[index + 2] = tempElement;

	for (int i = index + 2; i < array->Length; i++)
	{
		tempArray[i + 1] = array->Array[i];
	}

	delete[] array->Array;
	array->Array = tempArray;
}

/// <summary>
/// Реализует сортировку динамического массива
/// </summary>
/// <param name="array"></param>
void ArraySort(DynamicArray* array)
{
	for (int i = 0; i < array->Length - 1; i++)
	{
		for (int j = i + 1; j < array->Length; j++)
		{
			if (array->Array[j] < array->Array[i])
			{
				swap(array->Array[j], array->Array[i]);
			}
		}
	}
}

/// <summary>
/// Реализует линейный поиск в динамическом массиве
/// </summary>
/// <param name="array">Динамический массив</param>
/// <param name="element">Элемент, который необходимо найти</param>
/// <returns></returns>
int LinearSearch(DynamicArray* array, int element)
{
	int count = 0;
	int result = 0;
	for (int i = 0; i < array->Length; i++)
	{
		if (element == array->Array[i])
		{
			result = i;
			count += 1;
		}
	}
	if (count == 0)
	{
		result = -1;
	}
	return result;
}

/// <summary>
/// Реализует бинарный поиск в динамическом массиве
/// </summary>
/// <param name="array">Динамический массив</param>
/// <param name="element">Элемент, который необходимо найти</param>
/// <returns></returns>
int BinarySearch(DynamicArray* array, int element)
{
	ArraySort(array);
	
	int middle;
	int left = 0;
	int right = array->Length;
	while (right - left > 1)
	{
		middle = (left + right) / 2;
		if (array->Array[middle] < element)
		{
			left = middle;
		}
		else
		{
			right = middle;
		}
	}
	int result = 0;
	result = right;
	if (array->Array[result] != element)
	{
		result = -1;
	}
	return result;
}

/// <summary>
/// Реализует повторную инициилизацию
/// структуру динамического массива, с нулевыми полями
/// </summary>
/// <param name="array"></param>
void ReInitializeDynamicArray(DynamicArray* array)
{
	int capacity = 8;
	array->Capacity = capacity;
	array->Length = 0;
	delete[] array->Array;
	array->Array = new int[array->Length + capacity];
}
