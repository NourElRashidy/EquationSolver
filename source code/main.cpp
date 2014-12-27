#include "LinearEquationSolver.h"
#include "NonLinearEquationSolver.h"


int main() {
	//test
	string str;
	while(getline(cin,str)) {
		Equation *EQ = new Equation(str);
		EquationSolver *solver;
		if(EQ->IsLinear()) solver = new LinearEquationSolver(EQ);
		else solver = new NonLinearEquationSolver(EQ);

		solver->Solve();
		vector<double> *SS = solver->GetSolutionSet();
		vector<pair<long long, long long> > *FR = solver->GetFractions();
	}

	return 0;
}
