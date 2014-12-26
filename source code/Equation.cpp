#include "Equation.h"


Equation::Equation() { }


Equation::Equation(string EQ) {
	this->PrepareEquation(EQ);
}


Equation::~Equation() { }


void Equation::PrepareEquation(string EQ) {
	this->Parse(EQ);
	this->InfixToPrefix();
	this->prefixTree.BuildTree(this->prefixTree.GetRoot(), &(this->prefix));
	this->prefixTree.SimplifyTree(this->prefixTree.GetRoot());
	this->FillCoefficients();
	this->Differentiate();
}


bool Equation::IsLinear() {
	for(int i = 0; i < 11; i++) {
		if((i < 4 || i > 6) && this->coefficients[i] != 0) return false;
	}
	return true;
}


bool Equation::AbsoluteValueExists() {
	return (this->coefficients[5] != 0);
}


void Equation::Parse(string equation) {
	// Removing all spaces
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

	for(int i = 0; i < equation.size() - 1; i++) {
		// Converting =-4 -> =0-4 or =-x -> =(0-1)x
		if(equation[i] == '=' && equation[i + 1] == '-') {
			if(isdigit(equation[i + 2])) equation.insert(i + 1, 1, '0');
			else {
				equation.insert(i + 2, "1)");
				equation.insert(i + 1, "(0");
			}
		}

		// Converting 2x -> 2*x or 2(x+2) -> 2*(x+2) or (2+5)x -> (2+5)*x
		if(((isdigit(equation[i]) || equation[i] == ')') && isalpha(equation[i + 1])) || (isdigit(equation[i]) && equation[i + 1] == '(')) {
			equation.insert(i + 1, 1, '*');
		}
	}

	// Parsing
	string token;
	for(int i = 0; i < equation.size(); i++) {
		if(isalpha(equation[i])) {
			token += equation[i];
			if(i + 1 < equation.size() && equation[i + 1] == '^') {
				token = token + equation[i + 1] + equation[i + 2];
				i += 2;
			}
		}
		else if(!isdigit(equation[i])) {
			token += equation[i];
		}
		else {
			while(i < equation.size() && (isdigit(equation[i]) || equation[i] == '.')) {
				token += equation[i];
				i++;
			}
		}
		infix.push_back(token);
		if(isdigit(token[0])) i--;
		token = "";
	}

	if(!token.empty()) infix.push_back(token);
	for(int i = 0; i < infix.size(); i++) {
		// converting x^1x^2 -> x^1*x^2
		if(i + 1 < infix.size()) {
			bool isOperand = false, nextIsOperand = false;
			for(int j = 0; j < infix[i].size(); j++) {
				if(isalpha(infix[i][j])) {
					isOperand = true;
					break;
				}
			}

			for(int j = 0; j < infix[i + 1].size(); j++) {
				if(isalpha(infix[i + 1][j])) {
					nextIsOperand = true;
					break;
				}
			}

			if(isOperand && nextIsOperand) infix.insert(infix.begin() + i + 1, "*");
		}

		// converting x -> x^1
		if(isalpha(infix[i][0])) {
			infix[i].insert(0, 1, '1');
			int ind = infix[i].find('^');
			if(ind == -1) infix[i] += "^1";
		}
	}
}


void Equation::InfixToPrefix() {
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

	reverse(prefix.begin(), prefix.end());
}


void Equation::FillCoefficients() {
	for(int i = 0; i < 11; i++) this->coefficients[i] = 0;
	this->prefixTree.PrefixToInfix(this->prefixTree.GetRoot()->GetLeft(), this->coefficients, 1);
	this->prefixTree.PrefixToInfix(this->prefixTree.GetRoot()->GetRight(), this->coefficients, -1);
}


void Equation::Differentiate() {
	for(int i = 1; i < 11; i++) this->firstDerivativeCoefficients[i - 1] = this->coefficients[i] * (i - 5);
}


double Equation::SubstituteInTree(double X) {
	this->prefixTree.SetValueOfX(X);
	return this->prefixTree.SolveTree(this->prefixTree.GetRoot());
}


double Equation::substituteInFunction(double X) {
	double value = 0;
	for(int i = 0; i < 5; i++) value += this->coefficients[i] / pow(X, i);
	for(int i = 5; i < 11; i++) value += this->coefficients[i] * pow(X, i - 5);
	return value;
}


double Equation::substituteInDerivative(double X) {
	double value = 0;
	for(int i = 0; i < 5; i++) value += this->firstDerivativeCoefficients[i] / pow(X, i);
	for(int i = 5; i < 11; i++) value += this->firstDerivativeCoefficients[i] * pow(X, i - 5);
	return value;
}