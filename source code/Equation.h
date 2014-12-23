#pragma once
#include "PrefixTree.h"


class Equation {
protected:
	vector<string> infix, prefix;
	PrefixTree prefixTree;
	vector<double> solutionSet;
public:
	Equation();
	Equation(string);
	~Equation();
	static bool IsLinear(string);
	void Parse(string);
	void InfixToPrefix();
	void PrintResult();
};