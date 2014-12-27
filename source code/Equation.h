#pragma once
#include "PrefixTree.h"


class Equation {
protected:
	vector<string> infix, prefix;
	PrefixTree prefixTree;
	double coefficients[11], firstDerivativeCoefficients[11];
	vector<double> solutionSet;
public:
	Equation();
	Equation(string);
	~Equation();
	void PrepareEquation(string);
	bool IsValid();
	bool IsLinear();
	void Parse(string);
	void InfixToPrefix();
	void FillCoefficients();
	void Differentiate();
	double SubstituteInTree(double);
	double substituteInFunction(double);
	double substituteInDerivative(double);
};