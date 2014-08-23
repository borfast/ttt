#include "treenode.h"

TreeNode::TreeNode(int value) {
	this->value = value;
}

TreeNode* TreeNode::getParent() {
	return this->parent;
}

std::vector<TreeNode*> TreeNode::getChildren() {
	return this->children;
}

int TreeNode::getValue() {
	return this->value;
}

void TreeNode::setValue(int value) {
	this->value = value;
}
