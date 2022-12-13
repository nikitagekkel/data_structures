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
	int left = 0;
	int right = array->Length - 1;
	int index = 0;
	int result = -1;

	while (left <= right)
	{
		index = (right + left) / 2;
		if (array->Array[index] == element)
		{
			result = index;
			break;
		}
		if (array->Array[index] < element)
		{
			left = index + 1;
		}
		else
		{
			right = index - 1;
		}
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
