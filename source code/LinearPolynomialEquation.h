#pragma once
#include "Equation.h"

class LinearPolynomialEquation : public Equation {
private:
	vector<string> infix, prefix;
	PrefixTree prefixTree;
public:
	LinearPolynomialEquation();
	LinearPolynomialEquation(string);
	~LinearPolynomialEquation();
	void Parse(string);
	void InfixToPrefix();
	void SolveByBisection();
};

