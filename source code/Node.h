#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <float.h>
#include <cmath>
#include <algorithm>
using namespace std;

const double eps = 1e-14;
const double tolerance = 1e-14;
const double BSeps = 1e-12;

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

	Node(string*);
	~Node();
	void SetNodeType();
	void SetRight(Node*);
	void SetLeft(Node*);
	Node *GetRight();
	Node *GetLeft();
};
