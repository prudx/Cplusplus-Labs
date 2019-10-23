#include <algorithm>
#include <iostream>
#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree()
{
}

BinarySearchTree::~BinarySearchTree()
{
}

/*-------- public facing methods -----------*/

void BinarySearchTree::add(char toAdd)
{
	if (root == nullptr) {
		root = new TreeNode;
		root->data = toAdd;
		root->left = nullptr;
		root->right = nullptr;
	}
	else {
		add(toAdd, root);
	}
}

int BinarySearchTree::height()
{
	return height(root);
}

bool BinarySearchTree::search(char searchChar)
{
	return search(searchChar, root);
}

void BinarySearchTree::print() {
	printInOrder(root);		//Printing InOrder traversal type
}

//LAB 4A -- DO THE OTHER TRAVERSALS
void BinarySearchTree::printPostOrder() {
	printPostOrder(root);	//Printing PostOrder traversal type
}

void BinarySearchTree::printPreOrder() {
	printPreOrder(root);	//Printing PreOrder traversal type
}

void BinarySearchTree::deleteNode(char data) {
	deleteNode(root, data);
}

/*-------- private facing methods -----------*/
void BinarySearchTree::add(char toAdd, TreeNode * node)
{
	if (toAdd < node->data) {
		if (node->left == nullptr) {
			node->left = new TreeNode;
			node->left->data = toAdd;
			node->left->left = nullptr;
			node->left->right = nullptr;
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

int BinarySearchTree::height(TreeNode * root)
{
	if (root == nullptr) {
		return -1;
	}

	int left = height(root->left);
	int right = height(root->right);

	return 1+std::max(left,right);
}

bool BinarySearchTree::search(char searchChar, TreeNode * node)
{
	if (node == nullptr) {	//empty tree
		return false;
	}
	else if (searchChar == node->data) {	//char = node data
		return true;
	}
	else if (searchChar < node->data) {
		search(searchChar, node->left);
	}
	else if (searchChar > node->data) {
		search(searchChar, node->right);
	}
	else {						//fallback
		return false;
	}
}

//i believe this is an in order traversal
void BinarySearchTree::printInOrder(TreeNode *node) {
	if (node != nullptr) {
		printInOrder(node->left);						//LEFT
		std::cout.put(node->data) << ", ";				//ROOT
		printInOrder(node->right);						//RIGHT
	}
}

//LAB 4A -- DO THE OTHER TRAVERSALS
void BinarySearchTree::printPostOrder(TreeNode *node) {
	if (node != nullptr) {
		printPostOrder(node->left);						//LEFT
		printPostOrder(node->right);					//RIGHT
		std::cout << node->data << ", ";				//NODE
	}
}



void BinarySearchTree::printPreOrder(TreeNode *node) {
	if (node != nullptr) {
		std::cout << node->data << ", ";				//ROOT
		printPreOrder(node->left);						//LEFT
		printPreOrder(node->right);						//RIGHT
	}
}

// DELETE (uses minValueNode)
TreeNode * BinarySearchTree::minValueNode(TreeNode * node)
{
	TreeNode* current = node;

	/* loop down to find the leftmost leaf */
	while (current->left != nullptr)
		current = current->left;

	return current;
}

TreeNode * BinarySearchTree::deleteNode(TreeNode *root, char data)
{
	// base case 
	if (root == nullptr) return root;

	// If the data to be deleted is smaller than the root's data, 
	// then it lies in left subtree 
	if (data < root->data)
		root->left = deleteNode(root->left, data);

	// If the data to be deleted is greater than the root's data, 
	// then it lies in right subtree 
	else if (data > root->data)
		root->right = deleteNode(root->right, data);

	// if data is same as root's data, then This is the node 
	// to be deleted 
	else
	{
		// node with only one child or no child 
		if (root->left == nullptr)
		{
			TreeNode *temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == nullptr)
		{
			TreeNode *temp = root->left;
			free(root);
			return temp;
		}

		// node with two children: Get the inorder successor (smallest 
		// in the right subtree) 
		TreeNode* temp = minValueNode(root->right);

		// Copy the inorder successor's content to this node 
		root->data = temp->data;

		// Delete the inorder successor 
		root->right = deleteNode(root->right, temp->data);
	}
	return root;
}
