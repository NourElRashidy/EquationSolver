#include "Node.h"

Node::Node(string *nodevalue) : nodeValue(nodevalue), left(NULL), right(NULL), parent(NULL) {
	SetNodeType();
}

Node::~Node() { }

void Node::SetNodeType() {
	if(isdigit((*nodeValue)[0])) nodeType = Operand;
	else if(isalpha((*nodeValue)[0])) nodeType = UnknownOperand;
	else nodeType = Operator;
}

void Node::SetRight(Node *Right) {
	right = Right;
	Right->parent = this;
}

void Node::SetLeft(Node *Left) {
	left = Left;
	Left->parent = this;
}

Node* Node::GetRight() {
	return right;
}

Node* Node::GetLeft() {
	return left;
}