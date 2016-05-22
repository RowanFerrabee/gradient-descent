#include "gradient-descent.h"

template <class T> Optimizable::Optimizable() {
	scale = -1;
	threshold = -1;
	dx = 0.001;
}

template <class T> Optimizable::Optimizable(double _scale, double _threshold) {
	scale = _scale;
	threshold = _threshold;
	dx = 0.001;
}

template <class T> double Optimizable::iterate(T params[], int n) {
	if (step < 0 || threshold < 0 || cost == NULL) {
		return 0;
	}

	double totalIncrement = 0;
	double* gradient = new double[n];
	for (int i=0; i<n; i++) {
		//gradient[i] = (cost(param[i]+dx) - cost(param[i])) / dx;
		params[i] += dx;
		gradient[i] = costFunction(params, n);
		params[i] -= dx;
		gradient[i] -= costFunction(params, n);
		gradient[i] = gradient[i]/dx;

		//Multiply by predefined scale factor and increment the parameters
		params[i] += gradient*scale;

		//Sum total increments so that calling function can know how large a step was taken
		totalIncrement += gradient*scale;
	}
	return totalIncrement;
}

template <class T> void Optimizable::optimize(T params[], int n) {
	double totalIncrement;
	do {
		totalIncrement = iterate(params, n);
	} while (costIncrement < threshold);
}
