#include <algorithm>
#include <iostream>
#include "BinaryTree.h"

BinaryTree::BinaryTree()
{
}

BinaryTree::~BinaryTree()
{
}


/*-------- public facing methods -----------*/
void BinaryTree::add(int toAdd)
{
	if (root == nullptr) {
		root = new TreeNode;		//
		root->data = toAdd;			//
		root->left = nullptr;		//
		root->right = nullptr;		// SAME AS A CREATE FUNCTION
	}
	else {
		add(toAdd, root);
	}
}

int BinaryTree::height()
{
	return height(root);
}

bool BinaryTree::hasPathSum(int in) {

	return hasPathSum(root, in);
}

void BinaryTree::printPaths() {
	int path[500];
	printPaths(root, path, 0);    // recursion of the private method
}


/*-------- private facing methods -----------*/
void BinaryTree::add(int toAdd, TreeNode * node)
{
	if (toAdd < node->data) {
		if (node->left == nullptr) {
			node->left = new TreeNode;		//
			node->left->data = toAdd;		//
			node->left->left = nullptr;		//
			node->left->right = nullptr;	// same as a create method
		} else {
			add(toAdd, node->left);
		}
	}
	else if (toAdd > node->data) {
		if (node->right == nullptr) {
			node->right = new TreeNode;
			node->right->data = toAdd;
			node->right->left = nullptr;
			node->right->right = nullptr;
		}
		else {
			add(toAdd, node->right);
		}
	}
}

int BinaryTree::height(TreeNode * root)
{
	if (root == nullptr) {
		return -1;
	}

	int left = height(root->left);
	int right = height(root->right);

	return 1+std::max(left,right);
}

bool BinaryTree::hasPathSum(TreeNode *node, int sum) {
	/* return true if we run out of tree and sum==0 */
	if (node == nullptr && sum == 0) return true;
	else {
		bool hasSum = false;
		/* otherwise check both subtrees */
		int runningSum = sum - node->data;

		//if leaf and running sum - 0, then true
		if (runningSum == 0 && node->left == nullptr && node->right == nullptr) return true;

		if (node->left)
			hasSum = hasSum || hasPathSum(node->left, runningSum);
		if (node->right)
			hasSum = hasSum || hasPathSum(node->right, runningSum);
		return hasSum;
	}
}

void BinaryTree::printPaths(TreeNode *node, int *arr, int len) {
	if (node != nullptr) {

		//add data to path, increment size
		arr[len] = node->data;
		len++;
		// if leaf, print this and path
		if (node->left == nullptr && node->right == nullptr) {
			printArray(arr, len);   // calls the array method.
		}
		else {
			printPaths(node->left, arr, len);
			printPaths(node->right, arr, len);
		}
	}
	else {
		return;
	}
}

void BinaryTree::printArray(int *arr, int len) {
	for (int i = 0; i < len; ++i) {
		std::cout << arr[i];
		if (i != len-1)
			std::cout << ", ";
	}
	std::cout << "\n\n";
}