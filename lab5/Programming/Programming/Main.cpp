#include <iostream>
#include "BinarySearchTree.h"
#include "Treap.h"

using namespace std;

/**
¬ывод в консоль пунктов меню
*/
void PrintMenu()
{
	system("cls");
	cout << "0. Exit" << endl;
	cout << "\nBinary search tree" << endl;
	cout << "1. Initialize tree" << endl;
	cout << "2. Print tree" << endl;
	cout << "3. Add node" << endl;
	cout << "4. Delete node from the tree" << endl;
	cout << "5. Search node" << endl;
	cout << "6. Find minimum element" << endl;
	cout << "7. Find maximum element" << endl;
	cout << "8. Delete tree" << endl;
	cout << "\nTreap" << endl;
	cout << "9. Initialize treap" << endl;
	cout << "10. Print treap" << endl;
	cout << "11. Search element" << endl;
	cout << "12. Unoptimized adding" << endl;
	cout << "13. Omptimized adding" << endl;
	cout << "14. Unomptimized deliting" << endl;
	cout << "15. Optimized deliting" << endl;
	cout << "16. Delete treap" << endl;
}

/**
¬вод значений в переменную с валидацией
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
¬ывод ключей дерева в пор€дке возрастани€ в консоль
\param BinaryTreeNode* root корень дерева
*/
void PrintTree(BinaryTreeNode* root)
{
	if (root != nullptr)
	{
		PrintTree(root->Left);
		cout << root->Value << " -> ";
		PrintTree(root->Right);
	}
}

/**
ѕроверка, иницилизировано ли бинарное дерево
\param BinaryTreeNode* root корень дерева
\return true если дерево иницилизировано
\return false если дерево неиницилизировано
*/
bool IsInitialized(BinaryTreeNode* root)
{
	if (root == nullptr)
	{
		cout << "Tree is not initialized yet" << endl;
		return false;
	}
	else
	{
		return true;
	}
}

/**
ѕроверка, иницилизировано ли дерево
\param BinaryTreeNode* root корень дерева
\return true если дерево иницилизировано
\return false если дерево неиницилизировано
*/
bool IsInitialized(Treap* treap)
{
	if (treap == nullptr)
	{
		cout << "Treap is not initialized yet" << endl;
		return false;
	}
	else
	{
		return true;
	}
}

/**
ѕроизводит вызов функции SearchNode()
и вывод ее результата
\param BinaryTreeNode* root корень дерева
\param int value разыскиваемый элемент
\return BinaryTreeNode* найденный элемент
*/
BinaryTreeNode* FindNode(BinaryTreeNode* root, int value)
{
	BinaryTreeNode* foundNode = SearchNode(root, value);
	if (foundNode == nullptr)
	{
		cout << "\nNode not found" << endl;
	}
	return foundNode;
}

/**
ѕроизводит вывод декартового дерева в консоль
\param TreapNode* current корневой узел
\param int level уровень вывода
*/
void PrintTreap(TreapNode* current, int level)
{
	if (current)
	{
		PrintTreap(current->Right, level + 1);

		for (int i = 0; i < level; i++)
		{
			cout << "   ";
		}
		cout << current->Priority << " : " << current->Data << endl;
		PrintTreap(current->Left, level + 1);
	}
}

int main()
{
	BinaryTreeNode* root = nullptr;
	Treap* treap = nullptr;
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
			if (root != nullptr)
			{
				cout << "Tree is alredy initialized" << endl;
				break;
			}

			cout << "Enter the value of the root of the tree: ";
			int value = TryInput();
			root = InitializeBinaryTree(value);
			cout << "\nTree successfully created" << endl;
			break;
		}

		case 2:
		{
			if (!IsInitialized(root))
			{
				break;
			}

			cout << "Tree: " << endl;
			PrintTree(root);
			break;
		}

		case 3:
		{
			if (!IsInitialized(root))
			{
				break;
			}

			cout << "Enter the value of the node to add to the tree: ";
			int value = TryInput();
			root = AddNode(root, value);
			cout << "\nNode successfully created" << endl;
			break;
		}

		case 4:
		{
			if (!IsInitialized(root))
			{
				break;
			}

			cout << "Enter the key of the node to delete from the tree: ";
			int value = TryInput();
			if (FindNode(root, value) == nullptr)
			{
				break;
			}
			else
			{
				root = DeleteNode(root, value);
				cout << "\nNode successfully deleted" << endl;
			}
			break;
		}

		case 5:
		{
			if (!IsInitialized(root))
			{
				break;
			}

			cout << "Enter the key of the node to find in the tree: ";
			int value = TryInput();
			if (FindNode(root, value) == nullptr)
			{
				break;
			}
			else
			{
				cout << "\nNode found" << endl;
			}
			break;
		}

		case 6:
		{
			if (!IsInitialized(root))
			{
				break;
			}

			BinaryTreeNode* minNode = root;
			minNode = SearchMinElement(minNode);
			cout << "Minimum element is: " << minNode->Value;
			break;
		}

		case 7:
		{
			if (!IsInitialized(root))
			{
				break;
			}

			BinaryTreeNode* maxNode = root;
			maxNode = SearchMaxElement(maxNode);
			cout << "Minimum element is: " << maxNode->Value;
			break;
		}

		case 8:
		{
			if (!IsInitialized(root))
			{
				break;
			}

			DeleteTree(root);
			root = nullptr;
			cout << "Tree was successfully deleted" << endl;
			break;
		}

		case 9:
		{
			if (treap != nullptr)
			{
				cout << "Treap is alredy initialized" << endl;

			}

			cout << "Enter the value of the root of the treap: ";
			int value = TryInput();
			treap = InitializeTreap(value);
			cout << "\nTreap successfully created" << endl;
			break;
		}

		case 10:
		{
			if (!IsInitialized(treap))
			{
				break;
			}

			PrintTreap(treap->Root, 0);
			break;
		}

		case 11:
		{
			if (!IsInitialized(treap))
			{
				break;
			}

			cout << "Enter the value of the element to find in the treap: ";
			int value = TryInput();
			TreapNode* element = SearchElementByValue(treap->Root, value);
			cout << "Element found: " << element;
			break;
		}

		case 12:
		{
			if (!IsInitialized(treap))
			{
				break;
			}

			cout << "Enter the value of the node to add to the tree: ";
			int value = TryInput();
			InsertNotOpt(treap->Root, value);
			cout << "\nNode successfully added" << endl;
			break;
		}

		case 13:
		{
			if (!IsInitialized(treap))
			{
				break;
			}

			cout << "Enter the value of the node to add to the tree: ";
			int value = TryInput();
			InsertOpt(value, rand() % treap->MaxPriority, treap->Root);
			cout << "\nNode successfully added" << endl;
			break;
		}

		case 14:
		{
			if (!IsInitialized(treap))
			{
				break;
			}

			cout << "Enter the value of the node to delete from the tree: ";
			int value = TryInput();
			DeleteNotOpt(treap->Root, value);
			cout << "\nNode successfully deleted" << endl;
			break;
		}

		case 15:
		{
			if (!IsInitialized(treap))
			{
				break;
			}

			cout << "Enter the value of the node to delete from the tree: ";
			int value = TryInput();
			DeleteOpt(treap->Root, value);
			cout << "\nNode successfully deleted" << endl;
			break;
		}

		case 16:
		{
			if (!IsInitialized(treap))
			{
				break;
			}

			DeleteTreap(treap->Root);
			treap = nullptr;
			cout << "Treap was successfully deleted" << endl;
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