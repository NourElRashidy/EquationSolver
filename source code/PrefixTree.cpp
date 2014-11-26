#include "PrefixTree.h"

PrefixTree::PrefixTree() : root(NULL) { }

PrefixTree::~PrefixTree() { }

void PrefixTree::SetUnknownValue(double UnknownValue) {
	unknownValue = UnknownValue;
}

void PrefixTree::BuildTree(vector<string> *equation) {
	root = new Node(&((*equation)[0]));
	Node *currentNode = root;

	for(int i = 1; i < equation->size(); i++) {
		bool Set = false;
		while(!Set) {
			if(currentNode->GetRight() == NULL && currentNode->nodeType == Operator) {
				currentNode->SetRight(new Node(&((*equation)[i])));
				currentNode = currentNode->GetRight();
				Set = true;
			}
			else if(currentNode->GetLeft() == NULL && currentNode->nodeType == Operator) {
				currentNode->SetLeft(new Node(&((*equation)[i])));
				currentNode = currentNode->GetLeft();
				Set = true;
			}
			else {
				while(currentNode->nodeType == Operand || currentNode->nodeType == UnknownOperand || (currentNode->GetLeft() != NULL && currentNode->GetRight() != NULL && currentNode->parent != NULL)) {
					currentNode = currentNode->parent;
				}
			}
		}
	}
}

Relation PrefixTree::SolveTree() {
	double leftBranch = SolveBranch(root->GetLeft());
	double rightBranch = SolveBranch(root->GetRight());

	if(abs(rightBranch - leftBranch)<eps) return Equal;
	if(leftBranch>rightBranch) return LeftGreater;
	return LeftSmaller;
}

double PrefixTree::SolveBranch(Node *CurrentRoot) {
	if(CurrentRoot->nodeType == UnknownOperand) return unknownValue;
	if(CurrentRoot->nodeType == Operand) return (double) stod(*(CurrentRoot->nodeValue));

	double leftBranch = SolveBranch(CurrentRoot->GetLeft());
	double rightBranch = SolveBranch(CurrentRoot->GetRight());

	if(*(CurrentRoot->nodeValue) == "+") return leftBranch + rightBranch;
	if(*(CurrentRoot->nodeValue) == "-") return leftBranch - rightBranch;
	if(*(CurrentRoot->nodeValue) == "*") return leftBranch * rightBranch;
	if(*(CurrentRoot->nodeValue) == "/") return leftBranch / rightBranch;
}