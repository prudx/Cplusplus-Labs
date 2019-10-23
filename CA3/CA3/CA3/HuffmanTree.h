#pragma once
#include "TreeNode.h"
#include <queue>
#include <map>
#include <string>
using namespace std;

class HuffmanTree
{
public:
	HuffmanTree();
	~HuffmanTree();
	void BuildHuffTree(map<char, int> &frequency);

	map<char, string> HuffCodes(TreeNode * subTree, string str);
	void Encode(map<char, string> &mapping);
	void Decode();
private:
	void Decode(TreeNode * root, ifstream &inputFile, ofstream &outputFile);
	TreeNode *root;
	priority_queue<TreeNode*, vector<TreeNode*>, TreeNode> minHeap;
	map<char, string> mapping = map<char, string>();
};


