#include <iostream>
#include "DynamicArray.h"
#include "ArrayActions.h"

using namespace std;

/// <summary>
/// Выводит в консоль список команд для выполнения
/// </summary>
void PrintMenu()
{
	system("cls");
	cout << "0. Exit" << endl;
	cout << "1. Show the array" << endl;
	cout << "2. Add element to the array" << endl;
	cout << "3. Remove element from the array" << endl;
	cout << "4. Add element to the first position in the array" << endl;
	cout << "5. Add element after the existing element" << endl;
	cout << "6. Sort array" << endl;
	cout << "7. Linear search for an element in the array" << endl;
	cout << "8. Binary search for an element in the array" << endl;
	cout << "9. Reinitialize array" << endl;
}

/// <summary>
/// Реализует вывод динамического массива в консоль
/// </summary>
/// <param name="array">Динамический массив</param>
void PrintArray(DynamicArray* array)
{
	cout << "\nArray: ";

	for (int i = 0; i < array->Length; i++)
	{
		cout << "[" << i << "]" << array->Array[i] << " ";
	}
	cout << endl;
}

/// <summary>
/// Реализует вывод ошибки о превышении индекса в консоль
/// </summary>
void PrintIndexOutOfRange()
{
	cout << "\nThe index is a negative number,";
	cout << " or it goes beyond the borders of the array" << endl;
	cout << "\n";
}

void PrintIndexOfElement(int index, int element)
{
	if (index >= 0)
	{
		cout << "\nIndex of " << element << " is: " << index << endl;
	}
	else
	{
		cout << "\nElement not found" << endl;
	}
}

/// <summary>
/// Реализует обработку консольных команд
/// </summary>
/// <returns>Вовзращает выход из функции</returns>
int main()
{
	int variant;
	DynamicArray* array = new DynamicArray;

	while (true)
	{
		PrintMenu();
		cout << "\nEnter nubmer of action: ";
		cin >> variant;
		switch (variant)
		{
		case 0:
		{
			return -1;
			break;
		}
		case 1:
		{
			PrintArray(array);
			break;
		}
		case 2:
		{
			int element;

			cout << "\nEnter the value of the element that you want to add to the array: ";
			cin >> element;
			AddElementInArray(array, element);
			PrintArray(array);
			break;
		}
		case 3:
		{
			int index;

			PrintArray(array);
			cout << "\nEnter the index of the element to remove: ";
			cin >> index;
			if (CheckIndexOutRange(array, index))
			{
				PrintIndexOutOfRange();
				break;
			}
			RemoveElementAtIndex(array, index);
			PrintArray(array);
			break;
		}
		case 4:
		{
			int element;

			cout << "\nEnter the value of the element ";
			cout << "that you want to add to the first position of the array: ";
			cin >> element;
			InsertElementToFirstPosition(array, element);
			PrintArray(array);
			break;
		}
		case 5:
		{
			int index;
			int element;

			PrintArray(array);
			cout << "\nEnter the index of the element ";
			cout << "after which the new element should be placed: ";
			cin >> index;
			if (CheckIndexOutRange(array, index))
			{
				PrintIndexOutOfRange();
				break;
			}
			cout << "\nEnter the value of the element that you want to add to the array: ";
			cin >> element;
			InsertElementAtIndex(array, index, element);
			PrintArray(array);
			break;
		}
		case 6:
		{
			ArraySort(array);
			PrintArray(array);
			break;
		}
		case 7:
		{
			int element;
			int result;
			PrintArray(array);
			cout << "\nEnter the element, whose index needs to be found: ";
			cin >> element;
			result = LinearSearch(array, element);
			//TODO:дубль
			PrintIndexOfElement(result, element);

			break;
		}
		case 8:
		{
			int element;
			int result;

			PrintArray(array);
			cout << "\nEnter the element, whose index needs to be found: ";
			cin >> element;
			result = BinarySearch(array, element);
			//TODO:дубль
			PrintIndexOfElement(result, element);

			break;
		}
		case 9:
		{
			ReInitializeDynamicArray(array);
			cout << "\nThe array has been successfully reinitialized" << endl;
			break;
		}
		default:
		{
			cout << "\nYou entered the incorrect number" << endl;
		}
		}
		cout << "\n";
		system("pause");
	}
	delete[] array->Array;
	delete array;
}
