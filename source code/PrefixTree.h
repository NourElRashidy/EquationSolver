#include "Node.h"

enum Relation {
	Equal,
	LeftGreater,
	LeftSmaller
};

class PrefixTree {
private:
	Node *root;
	double unknownValue;
public:
	PrefixTree();
	~PrefixTree();
	void SetUnknownValue(double UnknownValue);
	void BuildTree(vector<string> *equation);
	Relation SolveTree();
	double SolveBranch(Node *CurrentRoot);
};
