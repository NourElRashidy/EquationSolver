#include "NonLinearPolynomialEquation.h"


NonLinearPolynomialEquation::NonLinearPolynomialEquation() { }


NonLinearPolynomialEquation::NonLinearPolynomialEquation(double equation[5]) {
	for(int i = 0; i < 5; i++) this->coefficients[i] = equation[i];
	if(!this->coefficients[0]) this->solutionSet.push_back(0);
	this->Differentiate();
	for(int i = -10000; i <= 10000; i++) this->SolveByNewtonMethod(i, 100);
	Tools::Unique(&(this->solutionSet));
}


NonLinearPolynomialEquation::~NonLinearPolynomialEquation() { }


void NonLinearPolynomialEquation::Differentiate() {
	for(int i = 1; i < 5; i++) this->firstDerivativeCoefficients[i - 1] = this->coefficients[i] * i;
}


double NonLinearPolynomialEquation::substituteInFunction(double X) {
	double value = 0;
	for(int i = 0; i < 5; i++) value += this->coefficients[i] * pow(X, i);
	return value;
}


double NonLinearPolynomialEquation::substituteInDerivative(double X) {
	double value = 0;
	for(int i = 0; i < 5; i++) value += this->firstDerivativeCoefficients[i] * pow(X, i);
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