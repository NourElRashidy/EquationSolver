#include "LinearEquationSolver.h"
#include "NonLinearEquationSolver.h"


int main() {
	string str;
	while(getline(cin,str)) {
		Equation *EQ = new Equation(str);
		if(!(EQ->IsValid())) {
			cout << "Invalid Equation!\n";
			continue;
		}


		EquationSolver *solver;
		if(EQ->IsLinear()) solver = new LinearEquationSolver(EQ);
		else solver = new NonLinearEquationSolver(EQ);

		solver->Solve();
		vector<double> *SS = solver->GetSolutionSet();
		vector<pair<long long, long long> > *FR = solver->GetFractions();

		for(int i = 0; i < SS->size(); i++) cout << setprecision(15)<<(*SS)[i] << endl;
	}
	return 0;
}