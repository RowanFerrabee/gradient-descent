class Optimizable {
	public:
		Optimizable();
		Optimizable(double _scale, double _threshold);
		double iterate(double params[], int n);
		void optimize(double params[], int n);
		void setScale(double _scale) {
			scale = _scale;
		}
		void setThreshold(double _threshold) {
			threshold = _threshold;
		}
		virtual double costFunction(double params[], int n) = 0;
	private:
		double scale;
		double threshold;
		double dx;
};