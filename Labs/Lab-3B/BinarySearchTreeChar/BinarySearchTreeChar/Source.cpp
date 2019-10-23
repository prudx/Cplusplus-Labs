#include <iostream>
#include "BinarySearchTree.h"

int main() {
	BinarySearchTree *tree = new BinarySearchTree();

	tree->add('b');
	tree->add('a');
	tree->add('c');
	tree->add('d');
	tree->add('e');
	tree->add('f');
	tree->add('g');

	std::cout << "Height of tree: " << tree->height() << "\n";

	std::cout << "Find 'g': " << tree->search('g') << "\n";

	std::cout << "Print tree inOrder traversal: ";
	tree->print();
	
	std::cout << "\nPrint tree preOrder traversal: ";
	tree->printPreOrder();

	std::cout << "\nPrint tree postOrder traversal: ";
	tree->printPostOrder();
	std::cout << std::endl;

	std::cout << "\nDelete 'g': ";
	tree->deleteNode('g');
	tree->print();
	std::cout << std::endl;

	delete tree;
	system("pause");
	return 0;
}