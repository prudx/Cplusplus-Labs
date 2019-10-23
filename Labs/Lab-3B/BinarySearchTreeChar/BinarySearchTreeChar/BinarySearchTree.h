#pragma once
#include "TreeNode.h"

class BinarySearchTree
{
public:
	BinarySearchTree();
	~BinarySearchTree();
	void add(char toAdd);
	int height();
	bool search(char searchChar);
	void print();
	void printPostOrder();
	void printPreOrder();
	void deleteNode(char ch);
private:
	void add(char toAdd, TreeNode *root);
	int  height(TreeNode *root);
	bool search(char searchChar, TreeNode *root);
	void printInOrder(TreeNode *root);
	void printPreOrder(TreeNode *root);
	void printPostOrder(TreeNode *root);
	TreeNode * deleteNode(TreeNode *root, char ch);
	TreeNode * minValueNode(TreeNode *node);
	TreeNode *root;
};

