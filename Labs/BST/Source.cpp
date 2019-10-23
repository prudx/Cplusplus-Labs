#include <iostream>
#include "BinarySearchTree.h"

int main() {
	BinarySearchTree *tree = new BinarySearchTree();

	tree->add(5);
	tree->add(3);
	tree->add(7); 
	tree->add(2);
	tree->add(4);
	tree->add(6);
	tree->add(8);


	std::cout << "Height of tree: " << tree->height() << "\n";

	std::cout << "Find '4': " << tree->search(4) << "\n";

	std::cout << "Print tree PreOrder traversal: ";
	tree->print();

	std::cout << "\nDelete '4': ";
	tree->deleteNode(4);
	tree->print();
	std::cout << std::endl;

	std::cout << "Find '4': " << tree->search(4) << "\n";

	delete tree;
	system("pause");
	return 0;
}