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
}

int main()
{
	int number;
	DynamicArray* array = new DynamicArray;
	InitDynamicArray(array);

	while (true)
	{
		PrintMenu();
		cout << "Enter nubmer of action: ";
		cin >> number;
		switch (number)
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
			AddElementInArray(array);
			break;
		}
		case 3:
		{
			RemoveElementAtIndex(array);
			break;
		}
		case 4:
		{
			InsertElementToFirstPosition(array);
			break;
		}
		case 5:
		{
			InsertElementToLastPosition(array);
			break;
		}
		case 6:
		{
			InsertElementAtIndex(array);
			break;
		}
		default:
		{
			cout << "You entered the incorrect number" << endl;
			system("pause");
		}
		}
		system("pause");
	}
	delete[] array->array;
	delete array;
}
