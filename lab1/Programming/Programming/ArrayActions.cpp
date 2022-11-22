#include "DynamicArray.h"
#include <cmath>
#include <iostream>

using namespace std;

void AddElementToArray(DynamicArray* array, int element)
{
	CheckLengthDynamicArray(array);
	array->Length++;
	array->Array[array->Length - 1] = element;
}

void RemoveElementAtIndex(DynamicArray* array, int index)
{
	for (int i = index; i < array->Length - 1; i++)
	{
		array->Array[i] = array->Array[i + 1];
	}

	array->Length--;
	CheckLengthDynamicArray(array);
}

void InsertElement(DynamicArray* array, int element, int index)
{
	//TODO: Дублирование
	CheckLengthDynamicArray(array);
	array->Length++;

	for (int i = 0; i < array->Length - index; i++)
	{
		array->Array[array->Length - i] = array->Array[array->Length - i - 1];
	}
	array->Array[index] = element;
}


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

int BinarySearch(DynamicArray* array, int element)
{
	ArraySort(array);

	int middle = 0;
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

void ReInitializeDynamicArray(DynamicArray* array)
{
	array->Capacity = array->ConstCapacity;
	array->Length = 0;
	delete[] array->Array;
	array->Array = new int[array->Length + array->ConstCapacity];
}
