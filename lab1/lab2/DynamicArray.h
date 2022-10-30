#pragma once
#include <vector>
using namespace std;

//TODO: xml -> doxygen
/// <summary>
/// Структура динамического массива
/// </summary>
struct DynamicArray
{
	//TODO: rsdn 
	vector<int> Array;
	int Length;
	int Capacity;
	const int capacity = 8;
};

void InitializeDynamicArray(DynamicArray* array);
void PrintArray(DynamicArray* array);
void PrintIndexOutOfRange();
bool CheckIndexOutRange(DynamicArray* array, int index);
void ResizeDynamicArray(DynamicArray* array);
void PrintIndexOfElement(int index, int element);