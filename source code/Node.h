#pragma once
#include "Tools.h"

enum NodeType {
	Operand,
	Operator,
	UnknownOperand
};

class Node {
private:
	Node *left, *right, *parent;
	NodeType nodeType;
	string nodeValue;
public:
	Node(string);
	~Node();
	void SetNodeType();
	void SetLeft(Node*);
	void SetRight(Node*);
	void SetParent(Node*);
	NodeType GetNodeType();
	Node *GetLeft();
	Node *GetRight();
	Node *GetParent();
	string GetNodeValue();
};

