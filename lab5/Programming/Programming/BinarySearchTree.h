#pragma once
#include <stddef.h>

/**
’ранит данные об узле бинарного дерева
*/
struct BinaryTreeNode {
    /**
    «начение ключа узла
    */
    int Value = NULL;

    /**
    ”казатель на следующий левый узел
    */
    BinaryTreeNode* Left = nullptr;

    /**
    ”казатель на следующий правый узел
    */
    BinaryTreeNode* Right = nullptr;
};

/**
ѕроизводит инициализацию бинарного дерева поиска
\param int key значение ключа корневого узла
\return BinaryTreeNode* корень дерева
*/
BinaryTreeNode* InitializeBinaryTree(int key);

/**
ѕроизводит добавление элемента в бинарное дерево
\param BinaryTreeNode* node корень бинарного дерева
\param int key значение ключа добавл€емого узла
\return BinaryTreeNode* корень дерева
*/
BinaryTreeNode* AddNode(BinaryTreeNode* node, int key);

/**
ѕроизводит удаление узла дерева по ключу
\param BinaryTreeNode* node корень бинарного дерева
\param int key значение ключа удал€емого узла
\return BinaryTreeNode* корень дерева
*/
BinaryTreeNode* DeleteNode(BinaryTreeNode* node, int key);

/**
ѕроизводит поиска узла дерева по ключу
\param BinaryTreeNode* node корень бинарного дерева
\param int key значение ключа разыскиваемого узла
\return BinaryTreeNode* корень дерева
*/
BinaryTreeNode* SearchNode(BinaryTreeNode* node, int key);

/**
ѕроизводит поиск узла с минимальным ключом в дереве
\param BinaryTreeNode* node корень бинарного дерева
\return BinaryTreeNode* найденный узел дерева
*/
BinaryTreeNode* SearchMinElement(BinaryTreeNode* node);

/**
ѕроизводит поиск узла с максимальным ключом в дереве
\param BinaryTreeNode* node корень бинарного дерева
\return BinaryTreeNode* найденный узел дерева
*/
BinaryTreeNode* SearchMaxElement(BinaryTreeNode* node);

/**
ѕроизводит удаление бинарного дерева
\param BinaryTreeNode* node корень бинарного дерева
*/
void DeleteTree(BinaryTreeNode* root);