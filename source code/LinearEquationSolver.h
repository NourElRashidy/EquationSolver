#pragma once
#include "EquationSolver.h"


class LinearEquationSolver : public EquationSolver {
public:
	LinearEquationSolver();
	LinearEquationSolver(Equation*);
	~LinearEquationSolver();
	virtual void Solve();
	double SolveByBisection(double, double, int);

};

