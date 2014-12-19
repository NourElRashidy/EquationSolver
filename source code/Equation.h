#include "PrefixTree.h"
#include <cmath>
const double ranges[] = {1e18, 1e17, 1e5, 1e5, 1e4, 1e3, 1e2};

class Equation {
private:
	string infix;
	vector<string> parsedInfix;
	double coefficients[7], firstDerivativeCoefficients[7];
	double startRange, endRange;
	double result;
	vector<double> solutionSet;
	long long numerator, denominator;
	bool foundSolution;
public:
	vector<string> prefix;
	Equation();
	Equation(string);
	Equation(double[]);
	~Equation();
	bool Valid();
	void PrintResult();
	long long GCD(long long, long long);
	void GetFraction();
	void FirstDerivative();
	void ParseInfix();
	int Precedence(string);
	void GetPrefix();
	void Bisection();
	void NewtonMethod(double, int);
	double substituteInEquation(double);
	double substituteInDerivative(double);
	void Unique();
};
