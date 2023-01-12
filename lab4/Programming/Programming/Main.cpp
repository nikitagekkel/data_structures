#include <iostream>
#include "Dictionary.h"
#include "HashTable.h"

using namespace std;

/**
Вывод в консоль пунктов меню
*/
void PrintMenu()
{
	system("cls");
	cout << "0. Exit" << endl;
	cout << "\nHash table based dictionary" << endl;
	cout << "1. Show the data" << endl;
	cout << "2. Add item to dictionary" << endl;
	cout << "3. Delete item from dictionary" << endl;
	cout << "4. Find element in dictionary" << endl;
	cout << "5. Delete dictionary" << endl;
}

/**
Ввод значений в переменную с валидацией
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

string IsStringEmpty()
{
	string element;
	cin >> element;
	while (element == " ")
	{
		cin.clear();
		cout << "You entered the incorrect element";
		cout << " please, enter the element again: ";
		cin >> element;
	}
	return element;
}

void PrintDictionary(Dictionary* dict)
{
	Node* current;
	for (int i = 0; i < dict->Table->Capacity; i++)
	{
		current = dict->Table->Array[i];

		if (current == nullptr)
		{
			cout << "";
			continue;
		}

		while (current != nullptr)
		{
			cout << "Key: " << current->Key << "\t Value: " << current->Value;
			current = current->Next;
			cout << endl;
		}
	}
}

void PrintHashTable(HashTable* table)
{
	cout << table->Count << endl;
	Node* current;
	for (int i = 0; i < table->Capacity; i++)
	{
		current = table->Array[i];
		if (current == nullptr)
		{
			cout << "NULL\n";
			continue;
		}
		if (current->Next == nullptr)
		{
			cout << "Key: " << current->Key << "\t Value: " << current->Value << endl;
			continue;
		}
		while (current != nullptr)
		{
			cout << "Key: " << current->Key << "\t Value: " << current->Value << " -> ";
			current = current->Next;
		}
		cout << endl;
	}
}

int main()
{
	Dictionary* dictionary = new Dictionary;
	HashTable* hashTable = new HashTable;
	hashTable = InitHashTable(4);
	dictionary->Table = InitHashTable(4);
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
				cout << "Hash Table:" << endl;
				PrintHashTable(hashTable);
				cout << "\nDictionary:" << endl;
				PrintDictionary(dictionary);
				break;
			}

			case 2:
			{
				cout << "Enter the key: ";
				string key = IsStringEmpty();
				cout << "Enter the element: ";
				string value = IsStringEmpty();

				AddItem(dictionary, value, key);
				AddElement(hashTable, value, key);

				double maxOcupationDictionary =
					dictionary->Table->Capacity *
					dictionary->Table->CoefficientOccupancy;

				if (dictionary->Table->Count >= maxOcupationDictionary)
				{
					dictionary->Table = Rehashing(dictionary->Table);
				}

				double maxOcupationTable =
					hashTable->Capacity *
					hashTable->CoefficientOccupancy;

				if (hashTable->Count >= maxOcupationTable)
				{
					hashTable = Rehashing(hashTable);
				}
				break;
			}

			case 3:
			{
				cout << "Enter the key: ";
				string key = IsStringEmpty();
				int removedItem = RemoveItem(dictionary, key);
				int removedElement = RemoveElement(hashTable, key);

				if (removedItem == -1)
				{
					cout << "\nThere is no such key in the dictionary" << endl;
				}
				if (removedElement == -1)
				{
					cout << "There is no such key in hash table" << endl;
				}
				if (removedItem != -1 || removedElement != -1)
				{
					cout << "Successfully removed" << endl;
				}
				break;
			}

			case 4:
			{
				cout << "Enter the key: ";
				string key = IsStringEmpty();

				string searchValueDictionary = FindItem(dictionary, key);

				string searchValueTable = FindElement(hashTable, key);

				cout << "\n";

				if (searchValueDictionary == "")
				{
					cout << "Value not found" << endl;
				}
				else
				{
					cout << "Found value in dictionary: ";
					cout << searchValueDictionary << endl;
				}

				if (searchValueTable == "")
				{
					cout << "Value not found in hash table" << endl;
				}
				else
				{
					cout << "Found value in hash table: ";
					cout << searchValueTable << endl;
				}
				break;
			}

			case 5:
			{
				DeleteDictionary(dictionary);
				delete dictionary;
				cout << "Dictionary is successfully deleted" << endl;
				return -1;
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