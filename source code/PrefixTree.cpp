#include "PrefixTree.h"


PrefixTree::PrefixTree() : root(new Node()) { }


PrefixTree::~PrefixTree() { }


void PrefixTree::SetValueOfX(double X) {
	this->valueOfX = X;
}


void PrefixTree::SetRoot(string value) {
	this->root = new Node(value);
}


Node* PrefixTree::GetRoot() {
	return this->root;
}


void PrefixTree::BuildTree(Node* currentNode, vector<string> *equation) {
	currentNode->SetNodeValue((*equation).back());
	(*equation).pop_back();
	if(currentNode->GetNodeType() == Operand) return;

	currentNode->SetRight(new Node());
	BuildTree(currentNode->GetRight(), equation);
	currentNode->SetLeft(new Node());
	BuildTree(currentNode->GetLeft(), equation);
}


void PrefixTree::SimplifyTree(Node* currentNode) {
	if(currentNode->GetNodeType() != Operator) return;

	if(currentNode->GetRight() != NULL) SimplifyTree(currentNode->GetRight());
	if(currentNode->GetLeft() != NULL) SimplifyTree(currentNode->GetLeft());

	// converting 9-x -> 9+(-x)
	if(currentNode->GetNodeType() == Operator && currentNode->GetOperator() == '-') {
		currentNode->GetRight()->SetDblValue(currentNode->GetRight()->GetDblValue()*-1);
		currentNode->SetNodeValue("+");
	}

	if(currentNode->GetRight() == NULL || currentNode->GetRight()->GetNodeType() == Operator || currentNode->GetLeft() == NULL || currentNode->GetLeft()->GetNodeType() == Operator) 
		return;

	// doing the operations in this subtree and putting their result in this node
	double newNodeValue;
	int newPowOfX;
	bool change = false;
	if(currentNode->GetOperator() == '+' && currentNode->GetLeft()->GetPowOfX() == currentNode->GetRight()->GetPowOfX()) {
		newNodeValue = currentNode->GetLeft()->GetDblValue() + currentNode->GetRight()->GetDblValue();
		newPowOfX = currentNode->GetLeft()->GetPowOfX();
		change = true;
	}
	else if(currentNode->GetOperator() == '-' && currentNode->GetLeft()->GetPowOfX() == currentNode->GetRight()->GetPowOfX()) {
		newNodeValue = currentNode->GetLeft()->GetDblValue() - currentNode->GetRight()->GetDblValue();
		newPowOfX = currentNode->GetLeft()->GetPowOfX();
		change = true;
	}
	else if(currentNode->GetOperator() == '*') {
		newNodeValue = currentNode->GetLeft()->GetDblValue() * currentNode->GetRight()->GetDblValue();
		newPowOfX = currentNode->GetLeft()->GetPowOfX() + currentNode->GetRight()->GetPowOfX();
		change = true;
	}
	else if(currentNode->GetOperator() == '/') {
		newNodeValue = currentNode->GetLeft()->GetDblValue() / currentNode->GetRight()->GetDblValue();
		newPowOfX = currentNode->GetLeft()->GetPowOfX() - currentNode->GetRight()->GetPowOfX();
		change = true;
	}

	// merging the childs into current node and deleting un needed nodes
	if(change) {
		delete currentNode->GetLeft();
		delete currentNode->GetRight();
		currentNode->SetLeft(NULL);
		currentNode->SetRight(NULL);
		currentNode->SetDblValue(newNodeValue);
		currentNode->SetPowOfX(newPowOfX);
		currentNode->SetNodeType(Operand);
	}
}


void PrefixTree::PrefixToInfix(Node* currentNode, double co[], int factor) {
	if(currentNode->GetLeft() == NULL && currentNode->GetRight() == NULL) {
		co[currentNode->GetPowOfX() + 5] += factor*currentNode->GetDblValue();
		return;
	}

	PrefixToInfix(currentNode->GetLeft(), co, factor);
	PrefixToInfix(currentNode->GetRight(), co, factor);
}


double PrefixTree::SolveTree(Node* currentNode) {
	if(currentNode->GetNodeType() == Operand) return currentNode->GetDblValue()*pow(this->valueOfX,currentNode->GetPowOfX());

	double leftBranch = this->SolveTree(currentNode->GetLeft()),
		rightBranch = this->SolveTree(currentNode->GetRight());

	if(currentNode->GetOperator() == '+') return leftBranch + rightBranch;
	else if(currentNode->GetOperator() == '-') return leftBranch - rightBranch;
	else if(currentNode->GetOperator() == '*') return leftBranch * rightBranch;
	else if(currentNode->GetOperator() == '/') return leftBranch / rightBranch;
	else return ((abs(leftBranch - rightBranch) > eps) && (leftBranch > rightBranch)) - ((abs(leftBranch - rightBranch) > eps) && (rightBranch > leftBranch));
}