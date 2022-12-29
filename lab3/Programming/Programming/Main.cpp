#include <iostream>
#include "Stack.h"

using namespace std;

/**
Вывод в консоль пунктов меню
*/
void PrintMenu()
{
	system("cls");
	cout << "Abstract data structures" << endl;
	cout << "0. Exit" << endl;
	cout << "1. Show the stack" << endl;
	cout << "2. Add element to the stack" << endl;
	cout << "3. Delete element from the stack" << endl;
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

void PrintStack(Node* head, Node* top)
{
	if (head == nullptr)
	{
		cout << "Stack is empty";
	}
	else if (top != nullptr)
	{
		cout << "Stack: ";
		cout << top->Data << " ";
		do {
			top = top->Next;
			printf("%d ", top->Data);
		} while (top->Next != nullptr);
	}
	else
	{
		cout << "Stack: " << head->Data;
	}
}

int main()
{
	Stack* stack = new Stack();
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
				PrintStack(stack->Head, stack->Top);
				cout << endl;
				break;
			}

			case 2:
			{
				cout << "Enter the element to push to stack: ";
				int element = TryInput();
				Push(stack, element);
				cout << "\nElement was was successfully added" << endl;
				break;
			}

			case 3:
			{
				bool isDeleted = Pop(stack);
				if (isDeleted == false)
				{
					cout << "Stack is empty" << endl;
				}
				else
				{
					cout << "Last element in stack was successfully deleted"
						<< endl;
				}
				break;
			}

			case 4:
			{
				bool isEmpty = DeleteStack(stack);
				if (isEmpty == false)
				{
					cout << "Stack is empty alredy" << endl;
				}
				else
				{
					cout << "Stack successfully deleted" << endl;
				}
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