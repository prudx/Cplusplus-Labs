#pragma once
#include "TreeNode.h"
class BinarySearchTree
{
public:
	BinarySearchTree();
	~BinarySearchTree();
	void add(int value);
	int height();
	bool search(int searchInt);
	void print();
	void deleteNode(int value);
private:
	void add(TreeNode *node, int value);
	int height(TreeNode *node);
	bool search(TreeNode *node, int searchInt);
	void printPreOrder(TreeNode *node);
	TreeNode * createNode(int value);
	TreeNode * deleteNode(TreeNode *node, int value);
	TreeNode * minNodeValue(TreeNode *node);
	TreeNode *root;
};

