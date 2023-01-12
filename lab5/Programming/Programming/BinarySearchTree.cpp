#include "BinarySearchTree.h"

using namespace std;

BinaryTreeNode* InitializeBinaryTree(int key)
{
    BinaryTreeNode* root = new BinaryTreeNode;

    root->Value = key;
    root->Left = root->Right = nullptr;
    return root;
}

BinaryTreeNode* AddNode(BinaryTreeNode* node, int key)
{
    if (node == nullptr)
    {
        BinaryTreeNode* newNode = new BinaryTreeNode;
        newNode->Value = key;
        newNode->Left = newNode->Right = nullptr;
        return newNode;
    }
    if (key < node->Value)
    {
        node->Left = AddNode(node->Left, key);
    }
    else
    {
        node->Right = AddNode(node->Right, key);
    }
    return node;
}

BinaryTreeNode* DeleteNode(BinaryTreeNode* node, int key)
{
    if (node == nullptr) return node;

    if (key == node->Value)
    {
        BinaryTreeNode* leftNode = nullptr;
        if (node->Right == nullptr)
        {
            leftNode = node->Left;
        }
        else
        {
            BinaryTreeNode* rightNode = node->Right;
            if (rightNode->Left == nullptr) {
                rightNode->Left = node->Left;
                leftNode = rightNode;
            }
            else
            {

                BinaryTreeNode* tempNode = rightNode->Left;
                while (tempNode->Left != nullptr) {
                    rightNode = tempNode;
                    tempNode = rightNode->Left;
                }
                rightNode->Left = tempNode->Right;
                tempNode->Left = node->Left;
                tempNode->Right = node->Right;
                leftNode = tempNode;
            }
        }
        delete node;
        return leftNode;
    }
    else if (key < node->Value)
    {
        node->Left = DeleteNode(node->Left, key);
    }
    else
    {
        node->Right = DeleteNode(node->Right, key);
    }
    return node;
}

BinaryTreeNode* SearchNode(BinaryTreeNode* node, int key)
{
    if (node == nullptr) return nullptr;

    if (node->Value == key) return node;

    if (key < node->Value) return SearchNode(node->Left, key);
    else
    {
        return SearchNode(node->Right, key);
    }
}

BinaryTreeNode* SearchMinElement(BinaryTreeNode* node)
{
    if (node->Left != nullptr)
    {
        node = SearchMinElement(node->Left);
    }
    else
    {
        return node;
    }
}

BinaryTreeNode* SearchMaxElement(BinaryTreeNode* node)
{
    if (node->Right != nullptr)
    {
        node = SearchMaxElement(node->Right);
    }
    else
    {
        return node;
    }
}

void DeleteTree(BinaryTreeNode* root)
{
    if (root != nullptr) {
        DeleteTree(root->Left);
        DeleteTree(root->Right);
        delete(root);
    }
}