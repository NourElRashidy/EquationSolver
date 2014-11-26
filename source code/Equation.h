#include "PrefixTree.h"

class Equation {
private:
	string infix;
	vector<string> parsedInfix;
	double result;
	long long numerator, denominator;
	bool valid;
public:
	vector<string> prefix;
	Equation();
	Equation(string equation);
	~Equation();
	bool Valid();
	void PrintResult();
	long long GCD(long long a, long long b);
	void GetFraction();
	void ParseInfix();
	int Precedence(string Operator);
	void GetPrefix();
	void SolveEquation();
};
