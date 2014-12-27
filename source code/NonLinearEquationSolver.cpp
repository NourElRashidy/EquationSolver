#include "NonLinearEquationSolver.h"


NonLinearEquationSolver::NonLinearEquationSolver() { }


NonLinearEquationSolver::NonLinearEquationSolver(Equation *EQ) : EquationSolver(EQ) { }


NonLinearEquationSolver::~NonLinearEquationSolver() { }


void NonLinearEquationSolver::Solve() {
	if(abs(this->equation->substituteInFunction(0))<tolerance) this->solutionSet.push_back(0);

	for(int i = -10000; i <= 10000; i++) {
		this->SolveByNewtonMethod(i, 100);
	}

	Tools::Unique(&(this->solutionSet));
	this->SolutionsFractions();
}


void NonLinearEquationSolver::SolveByNewtonMethod(double X, int iterations) {
	if(iterations == 0) return;
	double y = this->equation->substituteInFunction(X), yDash = this->equation->substituteInDerivative(X);
	if(abs(yDash) < eps) return;
	double newX = X - (y / yDash);
	if(abs(newX - X) / abs(newX) < tolerance) {
		this->solutionSet.push_back(newX);
		return;
	}
	this->SolveByNewtonMethod(newX, iterations - 1);
}