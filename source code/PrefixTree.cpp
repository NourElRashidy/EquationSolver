#include "PrefixTree.h"


PrefixTree::PrefixTree() : root(NULL) { }


PrefixTree::~PrefixTree() { }


void PrefixTree::SetValueOfX(double X) {
	this->valueOfX = X;
}

Node* PrefixTree::GetRoot() {
	return this->root;
}


void PrefixTree::BuildTree(vector<string> *equation) {
	this->root = new Node((*equation)[0]);
	Node *currentNode = root;
	for(int i = 1; i < equation->size(); i++) {
		bool Set = false;
		while(!Set) {
			if(currentNode->GetRight() == NULL && currentNode->GetNodeType() == Operator) {
				currentNode->SetRight(new Node((*equation)[i]));
				currentNode = currentNode->GetRight();
				Set = true;
			}
			else if(currentNode->GetLeft() == NULL && currentNode->GetNodeType() == Operator) {
				currentNode->SetLeft(new Node((*equation)[i]));
				currentNode = currentNode->GetLeft();
				Set = true;
			}
			else {
				while(currentNode->GetNodeType() != Operator || (currentNode->GetLeft() != NULL && currentNode->GetRight() != NULL && currentNode->GetParent() != NULL)) {
					currentNode = currentNode->GetParent();
				}
			}
		}
	}
}


double PrefixTree::SolveTree(Node* currentNode) {
	if(currentNode->GetNodeType() == UnknownOperand) return this->valueOfX;
	if(currentNode->GetNodeType() == Operand) return stod(currentNode->GetNodeValue());

	double leftBranch = this->SolveTree(currentNode->GetLeft()),
		   rightBranch = this->SolveTree(currentNode->GetRight());

	if(currentNode->GetNodeValue() == "+") return leftBranch + rightBranch;
	else if(currentNode->GetNodeValue() == "-") return leftBranch - rightBranch;
	else if(currentNode->GetNodeValue() == "*") return leftBranch * rightBranch;
	else if(currentNode->GetNodeValue() == "/") return leftBranch / rightBranch;
	else return ((abs(leftBranch - rightBranch)>eps) && (leftBranch>rightBranch)) - ((abs(leftBranch - rightBranch)>eps) && (rightBranch>leftBranch));
}