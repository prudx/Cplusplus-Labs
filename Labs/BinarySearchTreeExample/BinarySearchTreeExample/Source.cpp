#include <iostream>;
#include <cstdlib>;
#include "BST.h";

using namespace std;

int main()
{

	int TreeKeys[16] = { 50, 76, 21, 4, 32, 64, 15, 52, 14, 100, 83, 2, 3, 70, 87, 80 };
	BST myTree;
	int input = 0;

	cout << "Printing the tree in order\nBefore adding numbers\n";

	myTree.PrintInOrder();

	for (int i = 0; i < 16; i++)
	{
		myTree.AddLeaf(TreeKeys[i]);
	}

	cout << "Printing the tree in order\nAfter adding numbers\n";

	myTree.PrintInOrder();

	cout << endl;

	cout << "Checking if leaf\n";
	myTree.IsLeaf(100);


	//Print all parents and children in tree
	/*for (int i = 0; i < 16; i++)
	{
		myTree.PrintChildren(TreeKeys[i]);
	}
	*/

	cout << "The smallest value in the tree is " << myTree.FindSmallest() << endl;

	cout << "Enter a key value to delete. Enter -1 to stop the process\n";

	while (input != -1)
	{
		cout << "Delete Node: ";
		cin >> input;
		{
			if (input != -1)
			{
				cout << endl;
				myTree.ReturnNode(input);
				myTree.PrintInOrder();
				cout << endl;
			}
		}	
	}

	system("pause");

	return 0;
}