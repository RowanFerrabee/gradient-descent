template <class T> class Optimizer {
	public:
		Optimizer();
		Optimizer(double _scale, double _threshold, double (*cost)(T params[], int n));
		void interate(T params[], int n);
		void optimize(T params[], int n);
		void setScale(double _scale) {
			scale = _scale;
		}
		void setThreshold(double _threshold) {
			threshold = _threshold;
		}
		void setCostFunction(double (*_cost)(T params[], int n)) {
			cost = _cost;
		}
	private:
		double scale;
		double threshold;
		double dx;
		double (*cost)(T params[], int n);
};