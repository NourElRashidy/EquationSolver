#pragma once
#include "EquationSolver.h"
class NonLinearEquationSolver :	public EquationSolver {
public:
	NonLinearEquationSolver();
	NonLinearEquationSolver(Equation*);
	~NonLinearEquationSolver();
	virtual void Solve();
	void SolveByNewtonMethod(double, int);
};

