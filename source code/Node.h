#pragma once
#include "Tools.h"

enum NodeType {
	Operand,
	Operator,
};

class Node {
private:
	Node *left, *right, *parent;
	NodeType nodeType;
	double dblValue;
	int powOfX;
	char opt;
public:
	Node();
	Node(string);
	~Node();
	void SetDblValue(double);
	void SetPowOfX(int);
	void SetNodeValue(string);
	void SetNodeType(NodeType);
	void SetLeft(Node*);
	void SetRight(Node*);
	void SetParent(Node*);
	double GetDblValue();
	int GetPowOfX();
	char GetOperator();
	NodeType GetNodeType();
	Node *GetLeft();
	Node *GetRight();
	Node *GetParent();
};

