#pragma once
#include "TreeNode.h"
class BinarySearchTree
{
public:
	BinarySearchTree(); 
	~BinarySearchTree();
	void add(int value);
	int height();
	int size();
	bool isLeaf();
	bool find(int value);
	void print();
	void deleteNode(int value); //change to int return type
	bool isComplete();
	bool isBalanced();
private:
	void add(TreeNode * node, int value);
	int height(TreeNode * node);
	int size(TreeNode * node, int counter);
	bool find(TreeNode * node, int value);
	void preOrder(TreeNode * node);
	bool isLeaf(TreeNode * node);
	bool isComplete(TreeNode * node);
	bool isBalanced(TreeNode * node);
	TreeNode * createNode(int value);
	TreeNode * minValue(TreeNode * node);
	TreeNode * deleteNode(TreeNode * node, int value); //change to int return type
	TreeNode * root;
};

