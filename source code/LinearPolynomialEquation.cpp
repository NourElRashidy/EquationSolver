#include "LinearPolynomialEquation.h"


LinearPolynomialEquation::LinearPolynomialEquation(string EQ) { 
	this->Equation::Equation(EQ);
	this->solutionSet.push_back(this->SolveByBisection(BShigh, BSlow, maxBSiterations));
	this->PrintResult();
}


LinearPolynomialEquation::~LinearPolynomialEquation() { }


double LinearPolynomialEquation::SolveByBisection(double high, double low, int iterations) {
	double middle = (high + low) / 2;
	if(iterations <= 0) {
		return middle;
	}

	this->prefixTree.SetValueOfX(middle);
	double relationForMid = this->prefixTree.SolveTree(this->prefixTree.GetRoot());

	this->prefixTree.SetValueOfX(high);
	double relationForHigh = this->prefixTree.SolveTree(this->prefixTree.GetRoot());

	if(abs(relationForMid) < tolerance) return middle;

	if(relationForMid == relationForHigh) return SolveByBisection(middle, low, iterations - 1);
	return SolveByBisection(high, middle, iterations - 1);
}