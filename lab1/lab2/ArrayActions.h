#pragma once
#include "DynamicArray.h"

void AddElementInArray(DynamicArray* array, int element);
void RemoveElementAtIndex(DynamicArray* array, int index);
void InsertElementToFirstPosition(DynamicArray* array, int element);
void InsertElementToLastPosition(DynamicArray* array, int element);
void InsertElementAtIndex(DynamicArray* array, int index, int element);
void ArraySort(DynamicArray* array);
int LinearSearch(DynamicArray* array, int element);
int BinarySearch(DynamicArray* array, int element);
void ReInitializeDynamicArray(DynamicArray* array);