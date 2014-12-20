#pragma once
#include "PrefixTree.h"


class Equation {
protected:
	vector<double> solutionSet;
public:
	Equation();
	~Equation();
	void PrintResult();
};