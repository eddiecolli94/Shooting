#include "rectangle.h"

class Ray {
	private:
		Point loc;
		double slope;
	public:
		Ray();
		Ray(double new_x, double new_y, double new_slope);
		void set_location(double new_x, double new_y);
		void set_slope(double new_slope);
		double get_x_loc() const;	
		double get_y_loc() const;	
		double get_slope() const;
		void take_shot();
		void take_all_shots(const vector<Rectangle> &boxes, const vector<Ray> &shots);
};
