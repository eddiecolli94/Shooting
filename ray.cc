#include "ray.h"

Ray::Ray() {
	loc.x = 0;	
	loc.y = 0;	
	slope = "vertical";
	direction = 0; //0 backwards, 1 forwards
}

Ray::Ray(double new_x, double new_y, string new_slope, int new_direction) {
	loc.x = new_x;
	loc.y = new_y;
	slope = new_slope; //may need to check for Squirrel here
	direction = new_direction;
}

void Ray::set_location(double new_x, double new_y){
	loc.x = new_x;
	loc.y = new_y;
}

void Ray::set_slope(string new_slope) {slope = new_slope;}
void Ray::set_direction(int new_direction) {
	direction = new_direction;
}
double Ray::get_x_loc() const {return loc.x;}
double Ray::get_y_loc() const {return loc.y;}
string Ray::get_slope() const {return slope;}
ostream& operator<<(ostream &outs, const Ray &shot) {
	outs << "(" << shot.loc.x << "," << shot.loc.y << ") ";
	if(isalpha(shot.slope.at(0))) outs << "Slope: Vertical ";
	else outs << "Slope: " << stod(shot.slope) << " ";
	if(shot.direction == 0) outs << "Backwards";
	else outs << "Forwards";
    return outs;
}

int Ray::get_direction() const {return direction;}
void Ray::take_shot() {}
void Ray::take_all_shots(const vector<Rectangle> &boxes, const vector<Ray> &shots) {}
