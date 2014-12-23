#pragma once
#include "Equation.h"


class NonLinearPolynomialEquation : public Equation {
private:
	double coefficients[11], firstDerivativeCoefficients[11];
public:
	NonLinearPolynomialEquation(string);
	~NonLinearPolynomialEquation();
	void FillCoefficients();
	void Differentiate();
	double substituteInFunction(double);
	double substituteInDerivative(double);
	void SolveByNewtonMethod(double, int);
};

