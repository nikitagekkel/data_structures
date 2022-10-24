#include <iostream>
#include "DynamicArray.h"
#include "ArrayActions.h"

using namespace std;

void PrintMenu()
{
	system("cls");
	cout << "0. Exit" << endl;
	cout << "1. Show the array" << endl;
	cout << "2. Add element to the array" << endl;
	cout << "3. Remove element from the array" << endl;
	cout << "4. Add element to the first position in the array" << endl;
	cout << "5. Add element to the last position in the array" << endl;
	cout << "6. Add element after the existing element" << endl;
	cout << "7. Sort array" << endl;
	cout << "8. Linear search for an element in the array" << endl;
	cout << "9. Binary search for an element in the array" << endl;
	cout << "10. Reinitialize array" << endl;
}

int main()
{
	int variant;
	DynamicArray* array = new DynamicArray;
	InitializeDynamicArray(array);

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
			RemoveElementAtIndex(array, index);
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
			int element = 0;

			cout << "\nEnter the value of the element that you want to add to the array: ";
			cin >> element;
			InsertElementToLastPosition(array, element);
			PrintArray(array);
			break;
		}
		case 6:
		{
			int index;
			int element;

			PrintArray(array);
			cout << "\nEnter the index of the element ";
			cout << "after which the new element should be placed: ";
			cin >> index;
			cout << "\nEnter the value of the element that you want to add to the array: ";
			cin >> element;
			InsertElementAtIndex(array, index, element);
			PrintArray(array);
			break;
		}
		case 7:
		{
			ArraySort(array);
			PrintArray(array);
			break;
		}
		case 8:
		{
			int element;
			int result;
			PrintArray(array);
			cout << "\nEnter the element, whose index needs to be found: ";
			cin >> element;
			result = LinearSearch(array, element);
			if (result >= 0)
			{
				cout << "\nIndex of " << element << " is: " << result << endl;
			}
			else
			{
				cout << "\nElement not found" << endl;
			}

			break;
		}
		case 9:
		{
			int element;
			int result;

			PrintArray(array);
			cout << "\nEnter the element, whose index needs to be found: ";
			cin >> element;
			result = BinarySearch(array, element);
			if (result >= 0)
			{
				cout << "\nIndex of " << element << " is: " << result << endl;
			}
			else
			{
				cout << "\nElement not found" << endl;
			}

			break;
		}
		case 10:
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
		system("pause");
	}
	delete[] array->array;
	delete array;
}
