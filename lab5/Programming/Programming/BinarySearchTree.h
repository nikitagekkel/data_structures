#pragma once
#include <stddef.h>

/**
������ ������ �� ���� ��������� ������
*/
struct BinaryTreeNode {
    /**
    �������� ����� ����
    */
    int Value = NULL;

    /**
    ��������� �� ��������� ����� ����
    */
    BinaryTreeNode* Left = nullptr;

    /**
    ��������� �� ��������� ������ ����
    */
    BinaryTreeNode* Right = nullptr;
};

/**
���������� ������������� ��������� ������ ������
\param int key �������� ����� ��������� ����
\return BinaryTreeNode* ������ ������
*/
BinaryTreeNode* InitializeBinaryTree(int key);

/**
���������� ���������� �������� � �������� ������
\param BinaryTreeNode* node ������ ��������� ������
\param int key �������� ����� ������������ ����
\return BinaryTreeNode* ������ ������
*/
BinaryTreeNode* AddNode(BinaryTreeNode* node, int key);

/**
���������� �������� ���� ������ �� �����
\param BinaryTreeNode* node ������ ��������� ������
\param int key �������� ����� ���������� ����
\return BinaryTreeNode* ������ ������
*/
BinaryTreeNode* DeleteNode(BinaryTreeNode* node, int key);

/**
���������� ������ ���� ������ �� �����
\param BinaryTreeNode* node ������ ��������� ������
\param int key �������� ����� �������������� ����
\return BinaryTreeNode* ������ ������
*/
BinaryTreeNode* SearchNode(BinaryTreeNode* node, int key);

/**
���������� ����� ���� � ����������� ������ � ������
\param BinaryTreeNode* node ������ ��������� ������
\return BinaryTreeNode* ��������� ���� ������
*/
BinaryTreeNode* SearchMinElement(BinaryTreeNode* node);

/**
���������� ����� ���� � ������������ ������ � ������
\param BinaryTreeNode* node ������ ��������� ������
\return BinaryTreeNode* ��������� ���� ������
*/
BinaryTreeNode* SearchMaxElement(BinaryTreeNode* node);

/**
���������� �������� ��������� ������
\param BinaryTreeNode* node ������ ��������� ������
*/
void DeleteTree(BinaryTreeNode* root);