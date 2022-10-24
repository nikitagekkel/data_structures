#include "DynamicArray.h"
#include <iostream>
#include <cmath>

using namespace std;

void AddElementInArray(DynamicArray* array, int element)
{
	ResizeDynamicArray(array);
	array->length++;
	array->array[array->length - 1] = element;
}

void RemoveElementAtIndex(DynamicArray* array, int index)
{
	if (CheckIndexOutRange(array, index))
	{
		PrintIndexOutOfRange();
		return;
	}

	for (int i = index; i < array->length - 1; i++)
	{
		array->array[i] = array->array[i + 1];
	}

	array->length--;
}

void InsertElementToFirstPosition(DynamicArray* array, int element)
{
	ResizeDynamicArray(array);
	array->length++;

	int* tempArray = new int[array->capacity + 4];
	tempArray[0] = element;
	for (int i = 1; i < array->length; i++)
	{
		tempArray[i] = array->array[i - 1];
	}
	delete[] array->array;
	array->array = tempArray;
}

void InsertElementToLastPosition(DynamicArray* array, int element)
{
	ResizeDynamicArray(array);
	array->length++;
	array->array[array->length - 1] = element;
}

void InsertElementAtIndex(DynamicArray* array, int index, int element)
{
	int tempElement;

	if (CheckIndexOutRange(array, index))
	{
		PrintIndexOutOfRange();
		return;
	}
	ResizeDynamicArray(array);
	array->length++;
	
	int* tempArray = new int[array->capacity + 16];
	for (int i = 0; i <= index; i++)
	{
		tempArray[i] = array->array[i];
	}
	tempElement = array->array[index + 1];
	tempArray[index + 1] = element;
	tempArray[index + 2] = tempElement;

	for (int i = index + 2; i < array->length; i++)
	{
		tempArray[i + 1] = array->array[i];
	}

	delete[] array->array;
	array->array = tempArray;
}

void ArraySort(DynamicArray* array)
{
	for (int i = 0; i < array->length - 1; i++)
	{
		for (int j = i + 1; j < array->length; j++)
		{
			if (array->array[j] < array->array[i])
			{
				swap(array->array[j], array->array[i]);
			}
		}
	}
}

int LinearSearch(DynamicArray* array, int element)
{
	int count = 0;
	int result = 0;
	for (int i = 0; i < array->length; i++)
	{
		if (element == array->array[i])
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
	int right = array->length;
	int result = 0;
	while (right - left > 1)
	{
		middle = (left + right) / 2;
		if (array->array[middle] < element)
		{
			left = middle;
		}
		else
		{
			right = middle;
		}
	}
	result = right;
	if (array->array[result] != element)
	{
		result = -1;
	}
	return result;
}

void ReInitializeDynamicArray(DynamicArray* array)
{
	int capacity = 8;
	array->capacity = capacity;
	array->length = 0;
	delete[] array->array;
	array->array = new int[array->length + capacity];
}
