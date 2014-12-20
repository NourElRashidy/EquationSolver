#include "Tools.h"


int Tools::Precedence(string Operator) {
	if(Operator == "=") return 0;
	if(Operator == "(") return 1;
	if(Operator == "+" || Operator == "-") return 2;
	if(Operator == "*" || Operator == "/") return 3;
}


long long Tools::GCD(long long a, long long b) {
	if(!b) return a;
	return GCD(b, a % b);
}


pair<long long, long long> Tools::GetFraction(double result) {
	int n1 = 1; int n2 = 0;
	int d1 = 0; int d2 = 1;
	double b = result;

	do {
		double a = floor(b);
		int temp = n1;
		n1 = a*n1 + n2;
		n2 = temp;
		temp = d1;
		d1 = a*d1 + d2;
		d2 = temp;
		b = 1 / (b - a);
	} while(abs(result - n1*1.0 / d1) > 1e-6);

	return make_pair(n1, d1);
}


void Tools::Unique(vector<double> *SS) {
	sort((*SS).begin(), (*SS).end());
	for(int i = 0; i < (*SS).size(); i++) {
		for(int j = 0; j < i; j++) {
			if(abs((*SS)[i] - (*SS)[j]) < 1e-7) {
				(*SS).erase((*SS).begin() + i, (*SS).begin() + i + 1);
				i--;
				break;
			}
		}
	}
}
