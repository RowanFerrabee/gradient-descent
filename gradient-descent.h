class Optimizable {
	public:
		Optimizable();
		Optimizable(double _scale, double _threshold);
		double iterate();
		void optimize();
		void setScale(double _scale) {
			scale = _scale;
		}
		void setThreshold(double _threshold) {
			threshold = _threshold;
		}
		virtual double costFunction() = 0;
	protected:
		double *params;
		int n;
	private:
		double scale;
		double threshold;
		double dx;
};