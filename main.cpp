#include <iostream>
#include <cmath>
#include "gradient-descent.h"

using namespace std;

class MakeQuadratic : public Optimizable {
	//High cost if vals[] is not quadratic
	virtual double costFunction(double vals[], int n) {
		//In quadratic function, second differences should be constant
		//Therefore, have high cost if not constant second differences
		double cost = 0;
		for (int i=0; i<n-3; i++) {
			double thisSecondDiff = (vals[i+2]-vals[i+1]) - (vals[i+1]-vals[i]);
			double nextSecondDiff = (vals[i+3]-vals[i+2]) - (vals[i+2]-vals[i+1]);
			double diffSecondDiff = fabs(nextSecondDiff - thisSecondDiff);
			cost += diffSecondDiff;
		}
		cout << "Total cost: " << cost << endl;
		return cost;
	}
};

int main() {
	MakeQuadratic* m = new MakeQuadratic();
	m->setScale(0.02);
	m->setThreshold(8);

	int n = 9;
	double sequence[9] = {1,4,9,16,25,36,49,64,200};

	m->optimize(sequence, n);

	for (int i=0; i<n; i++) {
		cout << sequence[i] << ", ";
	} cout << endl;
}