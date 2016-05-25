#include <iostream>
#include <cmath>
#include "gradient-descent.h"

using namespace std;

class BestFit : public Optimizable {
private:
	int numDataPoints;
	double* x_data;
	double* y_data;
public:
	BestFit(double x[], double y[], int num) {
		numDataPoints = num;
		x_data = new double [numDataPoints];
		y_data = new double [numDataPoints];
		for (int i=0; i<numDataPoints; i++) {
			x_data[i] = x[i];
			y_data[i] = y[i];
		}

		n = 2;
		params = new double [n];	//Two parameters, for this model: m and b
		for (int i=0; i<n; i++)		//Set them both to zero as a starting point
			params[i] = 0;

		setScale(0.001);			//Set scale (this part is tricky and often has to be tinkered with)
		setThreshold(0.0005);		//Set max allowable error as defined by cost function
	}

	~BestFit() {
		delete[] x_data;
		delete[] y_data;
		delete[] params;
	}

	//High cost if points are far away from line
	virtual double costFunction() {
		double sumSquares = 0;

		for (int i=0; i<numDataPoints; i++) {
			double error = y_data[i] - modelAt(x_data[i]);

			double squaredError = error*error;

			sumSquares += squaredError;
		}
		return sumSquares;
	}

	double modelAt(double x) {
		double m = params[0];
		double b = params[1];

		return m*x + b;
	}

	void printModel() {
		double m = params[0];
		double b = params[1];

		cout << "The model is y = " << m << "x + " << b << endl;
	}
};

int main() {
	double x_data[] = {0, 2, 4, 6, 8};
	double y_data[] = {1, 2, 3, 4, 5};

	BestFit line(x_data, y_data, 5);
	line.optimize();
	line.printModel();
}