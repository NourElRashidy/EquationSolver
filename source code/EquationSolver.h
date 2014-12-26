#pragma once
#include "Equation.h"


class EquationSolver {
protected:
	Equation *equation;
	vector<double> solutionSet;
	vector<pair<long long, long long> > fractions;

public:
	EquationSolver();
	EquationSolver(Equation*);
	~EquationSolver();
	virtual void Solve();
	void SolutionsFractions();
	vector<double> *GetSolutionSet();
	vector<pair<long long, long long> > *GetFractions();
};

