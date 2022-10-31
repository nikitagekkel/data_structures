#include "DynamicArray.h"
#include <iostream>
#include <cmath>

using namespace std;

void AddElementInArray(DynamicArray* array, int element)
{
	IncreaseDynamicArray(array);
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
	DecreaseDynamicArray(array);
}

void InsertElementToFirstPosition(DynamicArray* array, int element)
{
	IncreaseDynamicArray(array);
	array->Length++;

	int* tempArray = new int[array->Length];
	tempArray[0] = element;
	for (int i = 1; i < array->Length; i++)
	{
		tempArray[i] = array->Array[i - 1];
	}
	delete[] array->Array;
	array->Array = tempArray;
}

#pragma warning(push)
#pragma warning(disable:6386)
void InsertElementAtIndex(DynamicArray* array, int index, int element)
{
	IncreaseDynamicArray(array);
	array->Length++;

	index += 1;
	int* tempArray = new int[array->Length];
	tempArray[index] = element;
	for (int i = 0; i < index; i++)
	{
		tempArray[i] = array->Array[i];
	}
	for (int i = index; i < array->Length - 1; i++)
	{
		tempArray[i + 1] = array->Array[i];
	}
	delete[] array->Array;
	array->Array = tempArray;
}
#pragma warning(pop)


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

void ReInitializeDynamicArray(DynamicArray* array)
{
	array->Capacity = array->ConstCapacity;
	array->Length = 0;
	delete[] array->Array;
	array->Array = new int[array->Length + array->ConstCapacity];
}
