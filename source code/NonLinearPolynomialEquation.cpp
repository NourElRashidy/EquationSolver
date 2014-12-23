#include "NonLinearPolynomialEquation.h"


NonLinearPolynomialEquation::NonLinearPolynomialEquation(string EQ) {
	this->Equation::Equation(EQ);
	this->FillCoefficients();
	if(!this->coefficients[5]) this->solutionSet.push_back(0);
	this->Differentiate();
	for(int i = -10000; i <= 10000; i++) this->SolveByNewtonMethod(i, 100);
	Tools::Unique(&(this->solutionSet));
	this->PrintResult();
}


NonLinearPolynomialEquation::~NonLinearPolynomialEquation() { }


void NonLinearPolynomialEquation::FillCoefficients() {
	for(int i = 0; i < 11; i++) coefficients[i] = 0;
	prefixTree.PrefixToInfix(prefixTree.GetRoot()->GetLeft(), coefficients, 1);
	prefixTree.PrefixToInfix(prefixTree.GetRoot()->GetRight(), coefficients, -1);
}

void NonLinearPolynomialEquation::Differentiate() {
	for(int i = 1; i < 11; i++) this->firstDerivativeCoefficients[i - 1] = this->coefficients[i] * (i-5);
}


double NonLinearPolynomialEquation::substituteInFunction(double X) {
	double value = 0;
	for(int i = 0; i < 5; i++) value += this->coefficients[i] / pow(X, i);
	for(int i = 5; i < 11; i++) value += this->coefficients[i] * pow(X, i-5);
	return value;
}


double NonLinearPolynomialEquation::substituteInDerivative(double X) {
	double value = 0;
	for(int i = 0; i < 5; i++) value += this->firstDerivativeCoefficients[i] / pow(X, i);
	for(int i = 5; i < 11; i++) value += this->firstDerivativeCoefficients[i] * pow(X, i-5);
	return value;
}


void NonLinearPolynomialEquation::SolveByNewtonMethod(double X, int iterations) {
	if(iterations == 0) return;
	double y = this->substituteInFunction(X), yDash = this->substituteInDerivative(X);
	if(abs(yDash) < eps) return;
	double newX = X - (y / yDash);
	if(abs(newX - X) / abs(newX) < tolerance) {
		this->solutionSet.push_back(newX);
		return;
	}
	this->SolveByNewtonMethod(newX, iterations - 1);
}