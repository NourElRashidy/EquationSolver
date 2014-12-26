#include "LinearEquationSolver.h"


LinearEquationSolver::LinearEquationSolver() { }


LinearEquationSolver::LinearEquationSolver(Equation* EQ) : EquationSolver(EQ) { }


LinearEquationSolver::~LinearEquationSolver() { }


void LinearEquationSolver::Solve() {
	this->solutionSet.push_back(this->SolveByBisection(BShigh, BSlow, maxBSiterations));
	this->SolutionsFractions();
}

double LinearEquationSolver::SolveByBisection(double high, double low, int iterations) {
	double middle = (high + low) / 2;
	if(iterations <= 0) {
		return middle;
	}

	double relationForMid = this->equation->SubstituteInTree(middle);
	if(abs(relationForMid) < tolerance) return middle;

	double relationForHigh = this->equation->SubstituteInTree(high);
	if(relationForMid == relationForHigh) return this->SolveByBisection(middle, low, iterations - 1);
	return this->SolveByBisection(high, middle, iterations - 1);
}