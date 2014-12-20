#include "LinearPolynomialEquation.h"


LinearPolynomialEquation::LinearPolynomialEquation() { }


LinearPolynomialEquation::LinearPolynomialEquation(string equation) {
	this->Parse(equation);
	this->InfixToPrefix();
	this->prefixTree.BuildTree(&prefix);
	this->SolveByBisection();
}


LinearPolynomialEquation::~LinearPolynomialEquation() { }


void LinearPolynomialEquation::Parse(string equation) {
	// Remove all spaces
	string tempInfix;
	for(int i = 0; i < equation.size(); i++) {
		if(equation[i] != ' ') tempInfix += equation[i];
	}
	equation = tempInfix;

	// Converting -x -> (0-1)x
	if(equation[0] == '-') {
		if(isdigit(equation[1])) equation.insert(0, 1, '0');
		else {
			equation.insert(1, "1)");
			equation.insert(0, "(0");
		}
	}

	// Converting 2x -> 2*x or 2(x+2) -> 2*(x+2) or (2+5)x -> (2+5)*x
	for(int i = 0; i < equation.size() - 1; i++) {
		if(equation[i] == '=' && equation[i + 1] == '-') {
			if(isdigit(equation[i + 2])) equation.insert(i + 1, 1, '0');
			else {
				equation.insert(i + 2, "1)");
				equation.insert(i + 1, "(0");
			}
		}

		if(((isdigit(equation[i]) || equation[i] == ')') && isalpha(equation[i + 1])) || (isdigit(equation[i]) && equation[i + 1] == '(')) {
			equation.insert(i + 1, 1, '*');
		}
	}

	// Parsing
	string token;
	for(int i = 0; i < equation.size(); i++) {
		if(!isdigit(equation[i])) token += equation[i];
		while(i < equation.size() && (isdigit(equation[i]) || equation[i] == '.')) {
			token += equation[i];
			i++;
		}

		this->infix.push_back(token);
		if(isdigit(token[0])) i--;
		token = "";
	}

	if(!token.empty()) this->infix.push_back(token);
}


void LinearPolynomialEquation::InfixToPrefix() {
	stack<string> tokens, operators;
	for(int i = 0; i < this->infix.size(); i++) {
		if(isdigit(this->infix[i][0]) || isalpha(this->infix[i][0])) {
			tokens.push(this->infix[i]);
		}
		else if(this->infix[i][0] == '(') {
			operators.push(this->infix[i]);
		}
		else if(this->infix[i][0] == ')') {
			while(!operators.empty() && operators.top() != "(") {
				tokens.push(operators.top());
				operators.pop();
			}
			operators.pop();
		}
		else {
			while(!operators.empty() && Tools::Precedence(operators.top()) >= Tools::Precedence(this->infix[i])) {
				tokens.push(operators.top());
				operators.pop();
			}
			operators.push(this->infix[i]);
		}
	}

	while(!operators.empty()) {
		tokens.push(operators.top());
		operators.pop();
	}

	while(!tokens.empty()) {
		this->prefix.push_back(tokens.top());
		tokens.pop();
	}
}


void LinearPolynomialEquation::SolveByBisection() {
	double low = -1e15, high = 1e15, mid;
	int numberOfIterations = 70;

	while(high > low + eps && numberOfIterations>0) {
		mid = (high + low) / 2;

		this->prefixTree.SetValueOfX(mid);
		double relationForMid = this->prefixTree.SolveTree(this->prefixTree.GetRoot());

		this->prefixTree.SetValueOfX(high);
		double relationForHigh = this->prefixTree.SolveTree(this->prefixTree.GetRoot());

		if(relationForMid == relationForHigh) high = mid;
		else low = mid;

		numberOfIterations--;
	}

	this->solutionSet.push_back(mid);
}