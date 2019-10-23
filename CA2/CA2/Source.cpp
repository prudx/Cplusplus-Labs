#include "BinarySearchTree.h"
#include <iostream>

int main() {
	BinarySearchTree *tree = new BinarySearchTree();

	//ADD
	std::cout << "Adding to tree...\n\n";
	tree->add(4);
	tree->add(2);
	tree->add(6);
	tree->add(1);
	tree->add(3);
	tree->add(5);
	tree->add(7);

	//PREORDER
	std::cout << "Print in preOrder traversal: \t\t";
	tree->print();

	//HEIGHT
	std::cout << "\n\nWhat is the height of the tree?: \t";
	std::cout << tree->height();

	//SIZE (NOT COUNTING ACCURATE)
	std::cout << "\n\nHow many nodes in the tree?: \t\t";
	std::cout << tree->size();

	//FIND
	std::cout << "\n\nFind the number 3: \t\t\t";
	if (tree->find(3) == true) {
		std::cout << "Found\n\n";
	}
	else {
		std::cout << "Not Found\n\n";
	}

	//DELETE
	std::cout << "Delete the number 3... \n\n";
	tree->deleteNode(3);

	//PROVE DELETE WORKS
	std::cout << "Print in preOrder traversal: \t\t";
	tree->print();

	//PROVE DELETE WORKS
	std::cout << "\n\nFind the number 3 after delete: \t";
	if (tree->find(3) == true) {
		std::cout << "Found\n\n";
	}
	else {
		std::cout << "Not Found\n\n";
	}

	//IS BALANCED
	std::cout << "Is node balanced?: \t\t\t";
	if (tree->isBalanced() == true) {
		std::cout << "Yes\n\n";
	}
	else {
		std::cout << "No\n\n";
	}

	std::cout << "Adding number 12 and 14 to tree...\n\n";
	tree->add(12);
	tree->add(14);

	std::cout << "Is node still balanced?: \t\t";
	if (tree->isBalanced() == true) {
		std::cout << "Yes\n\n";
	}
	else {
		std::cout << "No\n\n";
	}

	std::cout << "Deleting 12 and 14... \n\n";
	tree->deleteNode(12);
	tree->deleteNode(14);

	//IS COMPLETE (Nearly working)
	std::cout << "Is node complete?: \t\t\t";
	if (tree->isComplete() == true) {
		std::cout << "Yes\n\n";
	}
	else {
		std::cout << "No\n\n";
	}
	 
	std::cout << "Adding number 12 to tree...\n\n";
	tree->add(12);

	std::cout << "Is node complete?: \t\t\t";
	if (tree->isComplete() == true) {
		std::cout << "Yes\n\n";
	}
	else {
		std::cout << "No\n\n";
	}



	/*
					4
			2				6
		1		3		5		7
	
	
	
	*/

	system("pause");
	return 0;
}