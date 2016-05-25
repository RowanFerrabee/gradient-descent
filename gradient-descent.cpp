#include "gradient-descent.h"
#include <cmath>
#include <iostream>

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

double Optimizable::iterate() {
	if (scale < 0 || threshold < 0) {
		return 0;
	}

	double totalCost = 0;
	double* gradient = new double[n];
	for (int i=0; i<n; i++) {
		// The gradient is given by the following calculation:
		// gradient[i] = (cost(param[i]+dx) - cost(param[i])) / dx;
		params[i] += dx;
		gradient[i] = costFunction();
		params[i] -= dx;
		gradient[i] -= costFunction();
		gradient[i] = gradient[i]/dx;

		// Multiply by predefined scale factor and decrement the gradient from parameters (gradient descent)
		params[i] -= gradient[i]*scale;

	}

	// Return net cost so that we know when to exit optimization
	return costFunction();
}

void Optimizable::optimize() {
	double totalCost, lastCost = iterate();
	do {
		totalCost = iterate();

		// If cost ever increases, then scale is too high and must be reduced
		if (totalCost > lastCost) {
			scale = scale / 1.2;
		} 
		// If cost is ever unchanging, then min is reached (or scale is too low)
		else if (totalCost == lastCost) {
			// Assume min is reached for now.
			return;
		}

		lastCost = totalCost;

		std::cout << "Total cost: " << totalCost << std::endl;

		// Continue following gradient descent until cost is below set threshold
	} while (totalCost > threshold);
}
