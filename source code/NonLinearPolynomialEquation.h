#pragma once
#include "Equation.h"


class NonLinearPolynomialEquation : public Equation {
private:
	double coefficients[5], firstDerivativeCoefficients[5];
public:
	NonLinearPolynomialEquation();
	NonLinearPolynomialEquation(double[]);
	~NonLinearPolynomialEquation();
	void Differentiate();
	double substituteInFunction(double);
	double substituteInDerivative(double);
	void SolveByNewtonMethod(double, int);
};

