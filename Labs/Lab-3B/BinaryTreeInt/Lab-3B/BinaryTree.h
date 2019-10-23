#pragma once
#include "TreeNode.h"

class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();
	void add(int toAdd);
	int height();
	bool hasPathSum(int in);
	void printPaths();
	void printArray(int *arr, int len);
private:
	void add(int toAdd, TreeNode *root);
	int  height(TreeNode *root);
	TreeNode *root;
	bool hasPathSum(TreeNode *root, int in);
	void printPaths(TreeNode *root, int *arr, int sum);
};

