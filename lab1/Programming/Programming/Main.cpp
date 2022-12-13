#include <iostream>
#include "DynamicArray.h"
#include "ArrayActions.h"

using namespace std;

/**
Функция, выводящая в консоль пункты меню
*/
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

/**
Функция, выводящая в консоль динамический массив
\param array Динамический массив
*/
void PrintArray(DynamicArray* array)
{
	cout << "Array: ";

	for (int i = 0; i < array->Length; i++)
	{
		cout << "[" << i << "]" << array->Array[i] << " ";
	}
	cout << endl;
}

/**
Функция, выводящая ошибку выхода за границу массива
*/
void PrintIndexOutOfRange()
{
	cout << "\nThe index is a negative number,";
	cout << " or it goes beyond the borders of the array" << endl;
}

/**
Функция, выводящая индекс элемента в массиве
\param index Индекс элемента
\param element Элемент
*/
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

/**
Функция, проверяющая корректность ввода значений в консоль
\return Вводимый элемент
*/
int TryInput()
{
	int element;
	cin >> element;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "\nYou entered the incorrect number";
		cout << " please, enter number again: ";
		cin >> element;
	}
	return element;
}
/**
Функция, вызывающая все методы работы с массивом
*/
int main()
{
	DynamicArray* array = new DynamicArray;
	while (true)
	{
		PrintMenu();
		cout << "\nEnter nubmer of action: ";
		int variant = TryInput();
		system("cls");
		switch (variant)
		{
			case 0:
			{
				cout << "Program finished" << "\n";
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
				cout << "Enter the value of the element that you want to add to the array: ";
				int element = TryInput();
				AddElementToArray(array, element);
				cout << "\n";
				PrintArray(array);
				break;
			}
			case 3:
			{
				PrintArray(array);
				cout << "Enter the index of the element to remove: ";
				int index = TryInput();
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
				cout << "Enter the value of the element ";
				cout << "that you want to add to the ";
				cout << "first position of the array: ";
				int element = TryInput();
				InsertElement(array, element, 0);
				cout << "\n";
				PrintArray(array);
				break;
			}
			case 5:
			{
				PrintArray(array);
				cout << "\nEnter the index of the element ";
				cout << "after which the new element should be placed: ";
				int index = TryInput();
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				if (CheckIndexOutRange(array, index))
				{
					PrintIndexOutOfRange();
					break;
				}
				cout << "\nEnter the value of the element";
				cout << " that you want to add to the array: ";
				int element = TryInput();
				InsertElement(array, element, index);
				cout << "\n";
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
				PrintArray(array);
				cout << "\nEnter the element,";
				cout << " whose index needs to be found : ";
				int element = TryInput();
				int result = LinearSearch(array, element);
				PrintIndexOfElement(result, element);
				break;
			}
			case 8:
			{
				ArraySort(array);
				cout << "Array was successfully sorted" << endl << "\n";
				PrintArray(array);
				cout << "\nEnter the element,";
				cout <<	" whose index needs to be found : ";
				int element = TryInput();
				int result = BinarySearch(array, element);
				PrintIndexOfElement(result, element);

				break;
			}
			case 9:
			{
				ReInitializeDynamicArray(array);
				cout << "The array has been successfully";
				cout << " reinitialized" << endl;
				break;
			}
			default:
			{
				cout << "You entered the incorrect number" << endl;
			}
		}
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "\n";
		system("pause");
	}
	delete[] array->Array;
	delete array;
}
