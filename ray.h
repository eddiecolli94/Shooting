#include "rectangle.h"

class Ray {
	private:
		Point loc;
		double slope; //use stod() from cctype library to turn any numbers into a double
		string vertical;
		int direction; //0 backwards, 1 forwards 
	public:
		Ray();
		Ray(double new_x, double new_y, double new_slope, int new_direction);
		void set_location(double new_x, double new_y);
		void set_slope(double new_slope);
		void set_direction(int new_direction);
		void set_vertical(string new_vert);
		double get_x_loc() const;	
		double get_y_loc() const;	
		double get_slope() const;
		int get_direction() const;
		void take_shot();
		void take_all_shots(const vector<Rectangle> &boxes, const vector<Ray> &shots);
		friend ostream& operator<<(ostream &outs, const Ray &shot);
};
