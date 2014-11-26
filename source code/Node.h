#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <float.h>
#include <cmath>

#define eps 1e-9
#define BSeps 1e-12
using namespace std;

enum NodeType {
	Operand,
	Operator,
	UnknownOperand
};

class Node {
private:
	Node *left, *right;
public:
	Node *parent;
	NodeType nodeType;
	string *nodeValue;

	Node(string *nodevalue);
	~Node();
	void SetNodeType();
	void SetRight(Node *Right);
	void SetLeft(Node *Left);
	Node *GetRight();
	Node *GetLeft();
};
