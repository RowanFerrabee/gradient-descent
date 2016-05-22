template <class T> class Optimizable {
	public:
		Optimizable();
		Optimizable(double _scale, double _threshold);
		void iterate(T params[], int n);
		void optimize(T params[], int n);
		void setScale(double _scale) {
			scale = _scale;
		}
		void setThreshold(double _threshold) {
			threshold = _threshold;
		}
		virutal double costFunction(T params[], int n) = 0;
	private:
		double scale;
		double threshold;
		double dx;
};