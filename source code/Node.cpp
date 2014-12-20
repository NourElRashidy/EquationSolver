#include "Node.h"


Node::Node(string nodevalue) : nodeValue(nodevalue), left(NULL), right(NULL), parent(NULL) {
	this->SetNodeType();
}


Node::~Node() { }


void Node::SetNodeType() {
	if(isdigit(nodeValue[0])) this->nodeType = Operand;
	else if(isalpha(nodeValue[0])) this->nodeType = UnknownOperand;
	else this->nodeType = Operator;
}


void Node::SetLeft(Node *Left) {
	this->left = Left;
	Left->parent = this;
}


void Node::SetRight(Node *Right) {
	this->right = Right;
	Right->SetParent(this);
}


void Node::SetParent(Node *Parent) {
	this->parent = Parent;
}


NodeType Node::GetNodeType() {
	return this->nodeType;
}


Node* Node::GetLeft() {
	return this->left;
}


Node* Node::GetRight() {
	return this->right;
}


Node* Node::GetParent() {
	return this->parent;
}


string Node::GetNodeValue() {
	return this->nodeValue;
}