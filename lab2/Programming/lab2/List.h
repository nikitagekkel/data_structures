#pragma once


struct Node {
	int Data;
	struct Node *Next;
	struct Node *Prev;
};

struct Node* InitializeList(int firstNodeData);
struct Node* AddItemToList(Node* node, int value);
struct Node* RemoveItemFromList(Node* node, int element);
struct Node* AddItemToFirstPositionInList(Node* node, int value);
//struct Node* DeleteRoot(Node* root);
