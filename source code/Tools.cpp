#include "Tools.h"


int Tools::GetPower(string S) {
	bool absV = true;
	for(int i = 0; i < S.size(); i++) {
		if(isalpha(S[i])) {
			absV = false;
			break;
		}
	}

	if(absV) return 0;

	int power = 0, factor = 1, i;
	for(i = S.size() - 1; S[i] != '^' && S[i] != '-'; i--) {
		power += (S[i] - '0')*factor;
		factor *= 10;
	}

	if(S[i] == '-') power *= -1;
	return power;
}


string Tools::toString(double dbl) {
	ostringstream os;
	os << dbl;
	string str = os.str();
	return str;
}


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
	long long numerator = 1, numRemainder = 0, denominator = 0, denRemainder = 1, numeratorDenominatorGCD, temp;
	double ratio = result, quotient;
	do {
		quotient = floor(ratio);
		temp = numerator;
		numerator = quotient*numerator + numRemainder;
		numRemainder = temp;
		temp = denominator;
		denominator = quotient*denominator + denRemainder;
		denRemainder = temp;
		ratio = 1 / (ratio - quotient);
	} while(abs(result - numerator*1.0 / denominator) > tolerance);
	numeratorDenominatorGCD = GCD(numerator, denominator);
	numerator /= numeratorDenominatorGCD;
	denominator /= numeratorDenominatorGCD;
	return make_pair(numerator, denominator);
}


void Tools::Unique(vector<double> *SS) {
	sort((*SS).begin(), (*SS).end());
	for(int i = 0; i < (*SS).size(); i++) {
		for(int j = 0; j < i; j++) {
			if(abs((*SS)[i] - (*SS)[j]) < uniqueError) {
				(*SS).erase((*SS).begin() + i, (*SS).begin() + i + 1);
				i--;
				break;
			}
		}
	}
}
