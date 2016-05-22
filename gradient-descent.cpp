#include "gradient-descent.h"
#include <cmath>

Optimizable::Optimizable() {
	scale = -1;
	threshold = -1;
	dx = 0.001;
}

Optimizable::Optimizable(double _scale, double _threshold) {
	scale = _scale;
	threshold = _threshold;
	dx = 0.001;
}

double Optimizable::iterate(double params[], int n) {
	if (scale < 0 || threshold < 0) {
		return 0;
	}

	double totalCost = 0;
	double* gradient = new double[n];
	for (int i=0; i<n; i++) {
		//gradient[i] = (cost(param[i]+dx) - cost(param[i])) / dx;
		params[i] += dx;
		gradient[i] = costFunction(params, n);
		params[i] -= dx;
		gradient[i] -= costFunction(params, n);
		gradient[i] = gradient[i]/dx;

		//Multiply by predefined scale factor and decrement the gradient from parameters (gradient descent)
		params[i] -= gradient[i]*scale;

		totalCost += fabs(costFunction(params, n));
	}
	return totalCost;
}

void Optimizable::optimize(double params[], int n) {
	double totalCost, lastCost = iterate(params, n);
	do {
		totalCost = iterate(params, n);
		if (totalCost > lastCost) {
			scale = scale / 2;
		}
		lastCost = totalCost;
	} while (totalCost > threshold);
}
