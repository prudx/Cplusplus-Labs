#include "TreeNode.h"

TreeNode::TreeNode()
{
}

TreeNode::TreeNode(char ch, int fr)
{
	letter = ch;
	frequency = fr;
	left = nullptr;
	right = nullptr;
}


TreeNode::~TreeNode()
{
	if (left == nullptr)
		delete left;
	if (right == nullptr)
		delete right;
}

int TreeNode::getFrequency()
{
	return frequency;
}

bool TreeNode::operator()(TreeNode * l, TreeNode * r)
{
	return (l->getFrequency() > r->getFrequency());
}



