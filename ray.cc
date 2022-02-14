#include "ray.h"

Ray::Ray() {
	loc.x = 0;	
	loc.y = 0;	
	slope = 0;
	vertical = "";
	direction = 0; //0 backwards, 1 forwards
}

Ray::Ray(double new_x, double new_y, double new_slope, int new_direction) {
	loc.x = new_x;
	loc.y = new_y;
	slope = new_slope; //may need to check for Squirrel here
	direction = new_direction;
}

void Ray::set_location(double new_x, double new_y){
	loc.x = new_x;
	loc.y = new_y;
}

void Ray::set_vertical(string new_vert) {
	vertical = new_vert;
}

void Ray::set_slope(double new_slope) {slope = new_slope;}
void Ray::set_direction(int new_direction) {
	direction = new_direction;
}
double Ray::get_x_loc() const {return loc.x;}
double Ray::get_y_loc() const {return loc.y;}
double Ray::get_slope() const {return slope;}
string Ray::get_vert() const {return vertical;}
ostream& operator<<(ostream &outs, const Ray &shot) {
	outs << "(" << shot.loc.x << "," << shot.loc.y << ") Slope: ";
	if(shot.vertical == "Vertical") outs << "Vertical";
	else outs << shot.slope;

	if(shot.direction == 0) outs << " Backwards";
	if(shot.direction == 1) outs << " Forwards";
	return outs;
}

int Ray::get_direction() const {return direction;}
void Ray::take_shot() {}
void Ray::take_all_shots(const vector<Rectangle> &boxes, const vector<Ray> &shots) {}
