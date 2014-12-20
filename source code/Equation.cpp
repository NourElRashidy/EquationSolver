#include "Equation.h"


Equation::Equation() { 
	this->solutionSet.clear();
}


Equation::~Equation() { }


void Equation::PrintResult() {
	cout << "x = ";
	for(int i = 0; i < this->solutionSet.size(); i++) {
		pair<long long, long long> fraction = Tools::GetFraction(this->solutionSet[i]);
		cout << this->solutionSet[i];
		if(fraction.second!=1) cout << " (" << fraction.first << "/" << fraction.second << ")";
		if(i != this->solutionSet.size() - 1) cout << " or ";
	}
}