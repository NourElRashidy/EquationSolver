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
	void SetRoot(string);
	Node* GetRoot();
	void BuildTree(Node*, vector<string>*);
	void SimplifyTree(Node*);
	void PrefixToInfix(Node*, double[], int);
	double SolveTree(Node*);
};

