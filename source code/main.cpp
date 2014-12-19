#include "Equation.h"

int main() {
	/*string s;
	while(getline(cin, s)) {
		if(s.empty()) continue;
		Equation newEquation(s);
		cout << "------> x = ";
		newEquation.PrintResult();
	}*/

	double arr[7];
	for(int i = 0; i < 7; i++) cout<<"x^"<<i<<"    \n", cin >> arr[i];
	//reverse(arr, arr + 7);
	Equation newE(arr);
	return 0;
}