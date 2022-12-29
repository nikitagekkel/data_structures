#include <iostream>
#include "List.h"
#include "Test.h"

using namespace std;

/**
Вывод в консоль пунктов меню
*/
void PrintMenu()
{
	system("cls");
	cout << "Doubly linked list" << endl;
	cout << "0. Exit" << endl;
	cout << "1. Show the list" << endl;
	cout << "2. Add element to the list" << endl;
	cout << "3. Remove element from the list" << endl;
	cout << "4. Add element to the first position in the list" << endl;
	cout << "5. Add element after the existing element" << endl;
	cout << "6. Add element before the existing element" << endl;
	cout << "7. Sort the list" << endl;
	cout << "8. Linear search" << endl;
	cout << "9. Measuring the working time" << endl;
}

/**
Ввод значения в переменную с валидацией
*/
int TryInput()
{
	int element;
	cin >> element;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "You entered the incorrect number";
		cout << " please, enter number again: ";
		cin >> element;
	}
	return element;
}

/**
Вывод двусвязного списка
*/
void PrintList(Node* head)
{
	if (head == nullptr)
	{
		cout << "List is empty";
	}
	else if (head->Next != nullptr)
	{
		cout << "List: ";
		do {
			printf("%d ", head->Data);
			head = head->Next;
		} while (head != nullptr);
	}
	else
	{
		cout << "List: " << head->Data;
	}
}

/**
Работа с меню и вызов его функций
*/
int main()
{;
	List* list = new List();
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
				PrintList(list->Head);
				cout << endl;
				break;
			}

			case 2:
			{
				cout << "Enter the value of the element ";
				cout << "that you want to add: ";
				int element = TryInput();

				AddItemToList(list, element);
				cout << "\nElement was was successfully added" << endl;
				break;
			}

			case 3:
			{
				cout << "Enter the index of the element";
				cout << " that you want to delete from the list: ";
				int index = TryInput();

				bool isFound = RemoveItemFromList(list, index);
				//TODO: duplication
				if (isFound == false)
				{
					cout << "\nELement under index ";
					cout << index << " not found" << endl;
				}
				else
				{
					cout << "\nElement was successfully deleted" << endl;
				}
				break;
			}

			case 4:
			{
				cout << "Enter the value of the element";
				cout << " that you want to add to the first positon";
				cout << " of the list: ";
				int element = TryInput();
				
				AddItemToFirstPositionInList(list, element);
				cout << "\nElement was successfully added to the list";
				cout << endl;
				break;
			}

			case 5:
			{
				cout << "Enter the value of the element: ";
				int element = TryInput();

				cout << "\nEnter the index of the existing element: ";
				int index = TryInput();

				bool isFound = AddItemAfter(list, index, element);
				//TODO: duplication
				if (isFound == false)
				{
					cout << "\nELement under index " << index;
					cout << " not found" << endl;
				}
				else
				{
					cout << "\nElement was was successfully added" << endl;
				}
				break;
			}

			case 6:
			{
				cout << "Enter the value of the element: ";
				int element = TryInput();

				cout << "\nEnter the index of existing the element: ";
				int index = TryInput();

				bool isFound = AddItemBefore(list, index, element);
				//TODO: duplication
				if (isFound == false)
				{
					cout << "\nELement under index " << index;
					cout << " not found" << endl;
				}
				else
				{
					cout << "\nElement was was successfully added" << endl;
				}
				break;
			}

			case 7:
			{
				bool isSorted = InsertionSort(list);
				if (isSorted == true)
				{
					cout << "List has been successfully sorted" << endl;
				}
				else
				{
					cout << "List is empty and can't be sorted" << endl;
				}
				break;
			}

			case 8:
			{
				cout << "Enter the element to find in the list: ";
				int element = TryInput();
				int index = LinearSearch(list, element);
				if (index != -1)
				{
					cout << "\nIndex of the element " << element;
					cout << " is " << index << endl;
				}
				//TODO: add output
				break;
			}

			case 9:
			{
				TestOperations();
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
}