#include <iostream>
#include <algorithm>
#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree()
{
}

BinarySearchTree::~BinarySearchTree()
{
}

/*----- public methods -------*/
void BinarySearchTree::add(int value)
{
	if (root == nullptr) {
		root = createNode(value);
	}
	else {
		add(root, value);
	}
}

int BinarySearchTree::height()
{
	return height(root);
}

bool BinarySearchTree::search(int searchInt)
{
	return search(root, searchInt);
}

void BinarySearchTree::print()
{
	printPreOrder(root);
}

void BinarySearchTree::deleteNode(int value)
{
	deleteNode(root, value);
}


/*---- private methods --------*/
void BinarySearchTree::add(TreeNode * node, int value)
{
	if (value < node->data) {
		if (node->left == nullptr) {
			node->left = createNode(value);
		}
		else {
			add(node->left, value);
		}
	}
	else if (value > node->data) {
		if (node->right == nullptr) {
			node->right = createNode(value);
		}
		else {
			add(node->right, value);
		}
	}
}

int BinarySearchTree::height(TreeNode * node)
{
	if (node == nullptr) {
		return -1;
	}
	
	int left = height(node->left);
	int right = height(node->right);

	return 1 + std::max(left, right);
}

bool BinarySearchTree::search(TreeNode * node, int searchInt)
{
	if (node == nullptr) {
		return false;
	}
	else if (searchInt == node->data) {
		return true;
	}
	else if (searchInt < node->data) {
		search(node->left, searchInt);
	}
	else if (searchInt > node->data) {
		search(node->right, searchInt);
	}
	else {
		return false; 
	}
}

void BinarySearchTree::printPreOrder(TreeNode * node)
{
	if (node != nullptr) {
		std::cout << node->data << ", ";
		printPreOrder(node->left);
		printPreOrder(node->right);
	}
}

TreeNode * BinarySearchTree::createNode(int value)
{
	TreeNode *temp = new TreeNode();
	temp->data = value;
	temp->left = nullptr;
	temp->right = nullptr;
	return temp;
}

TreeNode * BinarySearchTree::deleteNode(TreeNode * node, int value)
{
	if (node == nullptr) {
		return node;
	}
	else if (value < node->data) {
		node->left = deleteNode(node->left, value);
	}
	else if (value > node->data) {
		node->right = deleteNode(node->right, value);
	}
	else {

		//one or none child
		if (node->left == nullptr) {
			TreeNode *temp = node->right;
			free(node);
			return temp;
		} 
		else if (node->right == nullptr) { 
			TreeNode *temp = node->left;
			free(node);
			return temp;
		}

		TreeNode *temp = minNodeValue(node->right);
		node->data = temp->data;
		node->right = deleteNode(node->right, value);
	}
	return node;
}

TreeNode * BinarySearchTree::minNodeValue(TreeNode * node)
{
	TreeNode *current = node;

	while (current->left != nullptr) {
		current = current->left;
	}

	return current;
}
