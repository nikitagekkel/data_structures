#include "DynamicArray.h"
#include <iostream>
#include <cmath>

using namespace std;

void AddElementInArray(DynamicArray* array)
{
	int element = 0;

	cout << "\nEnter the value of the element that you want to add to the array: ";
	cin >> element;

	ResizeDynamicArray(array);
	array->length++;
	array->array[array->length - 1] = element;

	PrintArray(array);
}

void RemoveElementAtIndex(DynamicArray* array)
{
	PrintArray(array);
	int index;
	cout << "Enter the index of the element to remove: ";
	cin >> index;

	if (CheckIndexOutRange(array, index)) return;

	for (int i = index; i < array->length - 1; i++)
	{
		array->array[i] = array->array[i + 1];
	}

	array->length--;

	PrintArray(array);
}

void InsertElementToFirstPosition(DynamicArray* array)
{
	int element;

	cout << "\nEnter the value of the element ";
	cout << "that you want to add to the first position of the array: ";
	cin >> element;

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
	PrintArray(array);
}

void InsertElementToLastPosition(DynamicArray* array)
{
	int element = 0;

	cout << "\nEnter the value of the element that you want to add to the array: ";
	cin >> element;

	ResizeDynamicArray(array);
	array->length++;
	array->array[array->length - 1] = element;

	PrintArray(array);
}

void InsertElementAtIndex(DynamicArray* array)
{
	PrintArray(array);
	int index;
	int element;
	int tempElement;
	cout << "Enter the index of the element ";
	cout << "after which the new element should be placed: ";
	cin >> index;
	if (CheckIndexOutRange(array, index)) return;

	cout << "\nEnter the value of the element that you want to add to the array: ";
	cin >> element;

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

	PrintArray(array);
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

void LinearSearch(DynamicArray* array, int count)
{
	PrintArray(array);
	int element;
	cout << "Enter the element, whose index needs to be found: ";
	cin >> element;
	for (int i = 0; i < array->length; i++)
	{
		if (element == array->array[i])
		{
			cout << "Index of " << element << " is: " << i << endl;
			count += 1;
		}
	}
	if (count == 0)
	{
		cout << "Element not found\n";
	}
}

void BinarySearch(DynamicArray* array)
{
	ArraySort(array);
	PrintArray(array);
	int element;
	int middle;
	int left = 0;
	int right = array->length;
	cout << "Enter the element, whose index needs to be found: ";
	cin >> element;
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
	if (array->array[right] != element)
	{
		cout << "Element not found" << endl;
	}
	else
	{
		cout << "Index of " << element << " is: " << right << endl;
	}
}

void ReInitializeDynamicArray(DynamicArray* array)
{
	int capacity = 8;
	array->capacity = capacity;
	array->length = 0;
	delete[] array->array;
	array->array = new int[array->length + capacity];
	cout << "The array has been successfully reinitialized" << endl;
}
