#include "rectangle.h"

class Ray {
	private:
		Point loc;
		string slope; //use stod() from cctype library to turn any numbers into a double
		int direction; //0 backwards, 1 forwards 
	public:
		Ray();
		Ray(double new_x, double new_y, string new_slope, int new_direction);
		void set_location(double new_x, double new_y);
		void set_slope(string new_slope);
		void set_direction(int new_direction);
		double get_x_loc() const;	
		double get_y_loc() const;	
		string get_slope() const;
		int get_direction() const;
		void take_shot();
		void take_all_shots(const vector<Rectangle> &boxes, const vector<Ray> &shots);
		friend ostream& operator<<(ostream &outs, const Ray &shot);

};
