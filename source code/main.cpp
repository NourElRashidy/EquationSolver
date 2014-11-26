#include "Equation.h"

int main() {
	string s;
	while(getline(cin, s)) {
		if(s.empty()) continue;
		Equation newEquation(s);
		if(!newEquation.Valid()) {
			cout << "INVALID EQUATION!!\n";
			continue;
		}
		cout << "------> x = ";
		newEquation.PrintResult();
	}
	return 0;
}