#pragma once
#include "Node.h" 


class PrefixTree {
private:
	Node* root;
	double valueOfX;
public:
	PrefixTree();
	~PrefixTree();
	void SetValueOfX(double);
	Node* GetRoot();
	void BuildTree(vector<string>*);
	double SolveTree(Node*);
};

