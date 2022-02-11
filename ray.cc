#include "ray.h"

Ray::Ray() {
	loc.x = 0;	
	loc.y = 0;	
	slope = 0;
}

Ray::Ray(double new_x, double new_y, double new_slope) {
	loc.x = new_x;
	loc.y = new_y;
	slope = new_slope;
}

void Ray::set_location(double new_x, double new_y){
	loc.x = new_x;
	loc.y = new_y;
}

void Ray::set_slope(double new_slope) {slope = new_slope;}
double Ray::get_x_loc() const {return loc.x;}
double Ray::get_y_loc() const {return loc.y;}
double Ray::get_slope() const {return slope;}
void Ray::take_shot() {}
void Ray::take_all_shots(const vector<Rectangle> &boxes, const vector<Ray> &shots) {}
