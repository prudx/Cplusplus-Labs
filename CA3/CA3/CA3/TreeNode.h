#pragma once
#include <string>
class TreeNode
{
	friend class HuffmanTree;
public:
	TreeNode();
	TreeNode(char, int);
	~TreeNode();
	int getFrequency();
	bool operator()(TreeNode* l, TreeNode* r);
private:
	char letter;
	std::string code;
	int frequency;
	TreeNode *left, *right;
};

