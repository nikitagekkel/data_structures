#include "DynamicArray.h"
#include <iostream>

using namespace std;

void AddElementInArray(DynamicArray* array)
{
	int element = 0;

	cout << "\nEnter the value of the element that you want to add to the array: ";
	cin >> element;

	if (array->size >= array->capacity)
	{
		ResizeDynamicArray(array);
	}
	array->size++;
	array->array[array->size - 1] = element;

	PrintArray(array);
}

void RemoveElementAtIndex(DynamicArray* array)
{
	PrintArray(array);
	int index;
	cout << "Enter the index of the element to remove: ";
	cin >> index;

	if (CheckIndexOutRange(array, index)) return;

	for (int i = index; i < array->size - 1; i++)
	{
		array->array[i] = array->array[i + 1];
	}

	array->size--;

	PrintArray(array);
}

void InsertElementToFirstPosition(DynamicArray* array)
{
	int element;

	cout << "\nEnter the value of the element ";
	cout << "that you want to add to the first position of the array: ";
	cin >> element;

	if (array->size >= array->capacity)
	{
		ResizeDynamicArray(array);
	}
	array->size++;

	int* tempArray = new int[array->capacity];
	tempArray[0] = element;
	for (int i = 1; i < array->size; i++)
	{
		tempArray[i] = array->array[i - 1];
	}
	delete[] array->array;
	array->array = tempArray;

	PrintArray(array);
}

void InsertElementToLastPosition(DynamicArray* array)
{
	int element;

	cout << "\nEnter the value of the element ";
	cout << "that you want to add to the last position of the array: ";
	cin >> element;

	if (array->size >= array->capacity)
	{
		ResizeDynamicArray(array);
	}
	array->size++;

	int* tempArray = new int[array->capacity];
	for (int i = 0; i < array->size; i++)
	{
		tempArray[i] = array->array[i];
	}
	tempArray[array->size-1] = element;
	delete[] array->array;
	array->array = tempArray;

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

	if (array->size >= array->capacity)
	{
		ResizeDynamicArray(array);
	}
	array->size++;
	
	tempElement = array->array[index + 1];
	array->array[index + 1] = element;
	for (int i = index + 2; i < array->size + 1; i++)
	{
		array->array[i - 1] = array->array[i];
	}

	PrintArray(array);
}