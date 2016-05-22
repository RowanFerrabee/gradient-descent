#include "gradient-descent.h"
#include <cmath>

template <class T> Optimizer::Optimizer() {
	scale = -1;
	threshold = -1;
	cost = NULL;
	dx = 0.001;
}

template <class T> Optimizer::Optimizer(double _scale, double _threshold, double (*_cost)(T params[], int n)) {
	scale = _scale;
	threshold = _threshold;
	cost = _cost;
	dx = 0.001;
}

template <class T> double interate(T params[], int n) {
	if (step < 0 || threshold < 0 || cost == NULL) {
		return 0;
	}
	double totalIncrement = 0;
	double* gradient = new double[n];
	for (int i=0; i<n; i++) {

		//gradient[i] = (cost(param[i]+dx) - cost(param[i])) / dx;
		params[i] += dx;
		gradient[i] = cost(params, n);
		params[i] -= dx;
		gradient[i] -= cost(params, n);
		gradient[i] = gradient[i]/step;

		//Multiply by predefined scale factor and increment the parameters
		params[i] += gradient*scale;

		//Sum total increments so that calling function can know how large a step was taken
		totalIncrement += gradient*scale;

	}
	return totalIncrement;
}

template <class T> void optimize(T params[], int n) {
	double totalIncrement;
	do {
		totalIncrement = iterate(params, n);
	} while (costIncrement < threshold);
}

