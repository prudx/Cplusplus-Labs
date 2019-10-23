#include <iostream>
#include "BinaryTree.h"

int main() {
	BinaryTree *tree = new BinaryTree();

	tree->add(10);
	tree->add(15);
	tree->add(5);
	tree->add(3);
	tree->add(8);
	

	std::cout << "Height of tree: " << tree->height() << "\n";

	std::cout << "Has path sum of 18?: " << tree->hasPathSum(18) << "\n";

	std::cout << "Has path sum of 19?: " << tree->hasPathSum(19) << "\n";

	std::cout << "Has path sum of 25?: " << tree->hasPathSum(25) << "\n";

	std::cout << "Print root to leaf paths: \n";
	tree->printPaths();

	delete tree;
	system("pause");
	return 0;
}