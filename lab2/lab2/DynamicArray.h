#pragma once

struct DynamicArray
{
	int* array;
	int size;
	int capacity;
};

void InitializeDynamicArray(DynamicArray* array);
void PrintArray(DynamicArray* array);
bool CheckIndexOutRange(DynamicArray* array, int index);
void ResizeDynamicArray(DynamicArray* array);