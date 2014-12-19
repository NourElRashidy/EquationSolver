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
	void SetUnknownValue(double);
	void BuildTree(vector<string>*);
	Relation SolveTree();
	double SolveBranch(Node*);
};
