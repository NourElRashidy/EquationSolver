#include "EquationSolver.h"


EquationSolver::EquationSolver() { }


EquationSolver::EquationSolver(Equation* EQ) { 
	this->equation = EQ;
}


EquationSolver::~EquationSolver() { }


void EquationSolver::Solve() { }


void EquationSolver::SolutionsFractions() {
	this->fractions.resize(this->solutionSet.size());

	for(int i = 0; i < this->solutionSet.size(); i++) {
		this->fractions[i] = Tools::GetFraction(this->solutionSet[i]);
	}
}


vector<double>* EquationSolver::GetSolutionSet() {
	return &(this->solutionSet);
}


vector<pair<long long, long long> >* EquationSolver::GetFractions() {
	return &(this->fractions);
}