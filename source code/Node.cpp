#include "Node.h"


Node::Node() : dblValue(0.0), powOfX(0), left(NULL), right(NULL), parent(NULL) { }


Node::Node(string nodevalue) : dblValue(0.0), powOfX(0), left(NULL), right(NULL), parent(NULL) {
	this->SetNodeValue(nodevalue);
}


Node::~Node() { }


void Node::SetDblValue(double value) {
	this->dblValue = value;
}


void Node::SetPowOfX(int value) {
	this->powOfX = value;
}


void Node::SetNodeValue(string value) {
	if(value.size() == 1 && !isdigit(value[0]) && !isalpha(value[0])) {
		this->opt = value[0];
		this->SetNodeType(Operator);
	}
	else {
		this->dblValue = stod(value);
		this->powOfX = Tools::GetPower(value);
		this->SetNodeType(Operand);
	}
}


void Node::SetNodeType(NodeType NT) {
	this->nodeType = NT;
}


void Node::SetLeft(Node *Left) {
	this->left = Left;
	if(Left != NULL) Left->parent = this;
}


void Node::SetRight(Node *Right) {
	this->right = Right;
	if(Right != NULL) Right->SetParent(this);
}


void Node::SetParent(Node *Parent) {
	this->parent = Parent;
}


double Node::GetDblValue() {
	return this->dblValue;
}


int Node::GetPowOfX() {
	return this->powOfX;
}


char Node::GetOperator() {
	return this->opt;
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