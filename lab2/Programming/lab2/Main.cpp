#include <iostream>
#include "List.h"

using namespace std;

int counter = 0;

void PrintMenu()
{
	system("cls");
	cout << "0. Exit" << endl;
	cout << "1. Show the list" << endl;
	cout << "2. Add element to the list" << endl;
	cout << "3. Remove element from the list" << endl;
	cout << "4. Add element to the first position in the list" << endl;
	//cout << "5. Add element after the existing element" << endl;
	//cout << "6. Sort array" << endl;
	//cout << "7. Linear search for an element in the array" << endl;
	//cout << "8. Binary search for an element in the array" << endl;
	//cout << "9. Reinitialize array" << endl;
}

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

void PrintList(Node* list)
{
	cout << "List: ";
	struct Node* tempList;
	tempList = list;
	do {
		printf("%d ", tempList->Data); // вывод значения элемента p
		tempList = tempList->Next; // переход к следующему узлу
	} while (tempList != NULL); // условие окончания обхода
}

int main()
{
	int variant;
	Node* node = new Node;
	Node* headNode = new Node;

	while (true)
	{
		bool runnig = false;
		system("cls");
		cout << "0. Exit" << endl;
		cout << "1. Initialize new list" << endl;
		cout << "\nEnter nubmer of action: ";
		variant = TryInput();
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
			int element;
			cout << "Enter the value of root: ";
			element = TryInput();
			node = InitializeList(element);
			headNode = node;
			cout << "\nNew list was successfully created" << endl;
			runnig = true;
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
		if (runnig == true)
		{
			break;
		}
	}

	while (true)
	{
		PrintMenu();
		cout << "\nEnter nubmer of action: ";
		variant = TryInput();
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
			struct Node* tempList = new Node;
			tempList = node;
			if (tempList->Prev != NULL)
			{
				//do {
				//	tempList = tempList->Prev;
				//} while (tempList->Prev != NULL);
				PrintList(headNode);
			}
			else if (tempList->Next != NULL)
			{
				PrintList(tempList);
			}
			else
			{
				cout << "List: ";
				printf("%d ", tempList->Data);
			}
			cout << "\n";
			break;
		}
		case 2:
		{
			int element;
			cout << "Enter the value of the element that you want to add: ";
			element = TryInput();
			node = AddItemToList(node, element);
			break;
		}
		case 3:
		{
			struct Node* tempList = new Node;
			tempList = node;
			int element;
			cout << "Enter the value of the element that you want to delete from the list: ";
			element = TryInput();
			tempList = RemoveItemFromList(node, element);
			if (tempList == NULL)
			{
				cout << "\nError, you can't delete the only one value in the list or value is not found" << endl;
			}
			else
			{
				node = tempList;
			}
			break;
		}
		case 4:
		{
			int element;
			cout << "Enter the value of the element that you want to add: ";
			element = TryInput();
			node = AddItemToFirstPositionInList(node, element);
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