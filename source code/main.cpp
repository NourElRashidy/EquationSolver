#include "LinearPolynomialEquation.h"
#include "NonLinearPolynomialEquation.h"


int main() {
	
	string str;
	while(getline(cin,str)) {
		if(Equation::IsLinear(str)) LinearPolynomialEquation LE(str);
		else NonLinearPolynomialEquation NLE(str);
	}

	return 0;
}