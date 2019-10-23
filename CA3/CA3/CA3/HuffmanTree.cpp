#include <iostream>
#include <fstream>
#include "HuffmanTree.h"
#include "TreeNode.h"
using namespace std;


HuffmanTree::HuffmanTree()
{
}

HuffmanTree::~HuffmanTree()
{
	root = nullptr;
}

void HuffmanTree::BuildHuffTree(map<char, int>& frequency)
{
	TreeNode *left, *right, *top;
	map<char, string> mapping = map<char, string>();

	//populate heap
	for (auto element : frequency) {
		TreeNode *temp = new TreeNode();
		temp->letter = element.first;
		temp->frequency = element.second;
		minHeap.push(temp);
	}

	//set our eofmarker
	TreeNode *eofmarker = new TreeNode();
	eofmarker->letter = '¬';
	eofmarker->frequency = 1;
	minHeap.push(eofmarker);

	while (minHeap.size() != 1) {
		left = minHeap.top();
		minHeap.pop();
		right = minHeap.top();
		minHeap.pop();

		top = new TreeNode('#', left->frequency + right->frequency);
		top->left = left;
		top->right = right;
		minHeap.push(top);
	}

	root = minHeap.top();
	mapping = HuffCodes(minHeap.top(), "");
	Encode(mapping);
}

map<char, string> HuffmanTree::HuffCodes(TreeNode * subTree, string str)
{
	if (!subTree) 
	{
		return mapping;
	}
	else {
		HuffCodes(subTree->left, str + "0");
		HuffCodes(subTree->right, str + "1");

		if (subTree->letter != '#') {
			subTree->code = str;
			cout << "Character: " << subTree->letter << "\t\t Assigned code: " << subTree->code << endl;

			mapping.insert(pair<char, string>(subTree->letter, subTree->code));
		}
		return mapping;
	}
	//else with nested if
}


void HuffmanTree::Encode(map<char, string> &mapping) //takes built map as parm
{
	char ch;
	ifstream inputFile("catext.txt");	
	ofstream outputFile("encoded.txt"); 

	while (inputFile.get(ch)) {
		for (auto element : mapping) {
			if (ch == element.first) {
				outputFile << element.second; //writes letters assigned bits to output
			}
		}
	}		
}

//public call to private method
void HuffmanTree::Decode()
{
	ifstream inputFile("encoded.txt");
	ofstream outputFile("decoded.txt");

	Decode(root, inputFile, outputFile);
}

//private method
void HuffmanTree::Decode(TreeNode * root, ifstream & inputFile, ofstream & outputFile)
{
	TreeNode *currentN = root;
	char ch;
	
	while (inputFile.get(ch)) {
		if (ch == '0') {
			currentN = currentN->left;
		}
		else {
			currentN = currentN->right;
		}

		if (currentN->left == nullptr && currentN->right == nullptr) {
			outputFile << currentN->letter;
			currentN = root;
		}
	}
	inputFile.close();
	outputFile.close();
}

