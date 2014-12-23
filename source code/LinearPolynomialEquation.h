#pragma once
#include "Equation.h"

class LinearPolynomialEquation : public Equation {
public:
	LinearPolynomialEquation(string);
	~LinearPolynomialEquation();
	double SolveByBisection(double, double, int);
};

