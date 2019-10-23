#include <iostream>
#include <algorithm>
#include "BinarySearchTree.h"
//Daniel maguire - x00127907

/*-------public methods---------*/
// all public methods will call their private counterparts
BinarySearchTree::BinarySearchTree()
{
	root = new TreeNode();
	root->data = NULL;
	root->left = nullptr;
	root->right = nullptr;
}

BinarySearchTree::~BinarySearchTree()
{
	free(root->left);
	free(root->right);
	free(root);

}

void BinarySearchTree::add(int value)
{
	//if there isn't a root yet, create one
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

int BinarySearchTree::size()
{
	int counter = 0;
	return size(root, counter);
}

bool BinarySearchTree::isLeaf()
{
	return isLeaf();	//come back to this
}

bool BinarySearchTree::find(int value)
{
	return find(root, value);
}

void BinarySearchTree::print()
{
	preOrder(root);
}

void BinarySearchTree::deleteNode(int value)
{
	deleteNode(root, value);
}

bool BinarySearchTree::isComplete()
{
	return isComplete(root);
}

bool BinarySearchTree::isBalanced()
{
	return isBalanced(root);
}


/*---------- private methods ---------*/
void BinarySearchTree::add(TreeNode * node, int value)
{
	//if value lower, go left
	if (value < node->data) {
		if (node->left == nullptr) {
			node->left = createNode(value);
		}
		else {
			add(node->left, value);
		}
	}
	//if value higher, go right
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
	//empty root, -1 height
	if (node == nullptr)
		return -1;

	int left = height(node->left);
	int right = height(node->right);

	//max value of both heights + 1
	return 1 + std::max(left,right);
}

//COME BACK TO THIS
int BinarySearchTree::size(TreeNode * node, int counter)
{
	counter++;
	if (node != nullptr) {
		size(node->left, counter);
		size(node->right, counter);
	}
	return counter;
}

bool  BinarySearchTree::find(TreeNode * node, int value)
{
	//base cases
	if (node == nullptr) {
		return false;
	}
	else if (value == node->data) {
		return true;
	}
	//if base cases fail, search more
	else if (value < node->data) {	
		find(node->left, value);
	}
	else if (value > node->data) {
		find(node->right, value);
	}
	else {
		return false;
	}
}

void BinarySearchTree::preOrder(TreeNode * node)
{
	if (node != nullptr) {
		std::cout << node->data << ", ";
		preOrder(node->left);
		preOrder(node->right);
	}
}

//COME BACK TO THIS
bool BinarySearchTree::isLeaf(TreeNode * node)
{
	return false;
}

//COME BACK TO THIS
bool BinarySearchTree::isComplete(TreeNode * node)
{
	if (node == nullptr) {
		return false; //empty so false
	}
	else if (node->left == nullptr && node->right != nullptr) {
		return false; //incomplete as there is an empty node
	}
	else if (node->left != nullptr && node->right == nullptr) {
		return false; //incomplete as there is an empty node
	}
	else {
		isComplete(node->left);
		isComplete(node->right);
	}
	return true;
}

bool BinarySearchTree::isBalanced(TreeNode * node)
{
	if (node == nullptr) {
		return true; //empty trees are balanced
	}
	//trees equal or withen 1 height of eachother are balanced
	else if (height(node->left) == height(node->right)) {
		return true;
	}
	else if (height(node->left) == height(node->right) + 1) {
		return true;
	}
	else if (height(node->left) + 1 == height(node->right)) {
		return true;
	}
	else {
		return false;
	}
}

//using this instead of calling constructor for TreeNode
TreeNode * BinarySearchTree::createNode(int value)
{
	TreeNode *temp = new TreeNode();
	temp->data = value;
	temp->left = nullptr;
	temp->right = nullptr;
	return temp;
}

// CHANGE TO RETURN INT
TreeNode * BinarySearchTree::minValue(TreeNode * node)
{
	TreeNode *current = node;

	//traverse all the way left
	while (current->left != nullptr) {
		current = current->left;
	}
	return current;
}

// CHANGE TO RETURN INT
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

		//one or no children | ALL MEMORY MANAGMENT DONE HERE
		if (node->left == nullptr) {
			TreeNode *temp = node->right;
			free(node);		//deallocated memory
			return temp;
		}
		else if (node->right == nullptr) {
			TreeNode *temp = node->left;
			free(node);		
			return temp;
		}

		//two children
		TreeNode *temp = minValue(node->right);
		temp->data = node->data;
		node->right = deleteNode(node->right, value);
	}
	return node;
}
