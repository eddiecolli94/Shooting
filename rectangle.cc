#include <rectangle.h>

void Rectangle::die() {
	cout << "BAD INPUT!" << endl; 
	exit(EXIT_FAILURE);
}

Rectangle::Rectangle() {
	solid = 1; //assume the rectangle is solid as the default
	x_min = 0;
	y_min = 0;
	x_max = 0;
	y_max = 0;
}
Rectangle::Rectangle(int new_solid, double new_x_min, double new_y_min, double new_x_max, double new_y_max) {
	if(new_solid != 0 or new_solid != 1) die(); //this line may need to be changed to allow for weird input
	solid = new_solid;
	x_min = new_x_min;
	y_min = new_x_min;
	x_max = new_x_max;
	y_max = new_x_max;
}
int Rectangle::get_solid() const{return solid;}
double Rectangle::get_x_min() const{return x_min;}
double Rectangle::get_y_min() const{return y_min;}
double Rectangle::get_x_max() const{return x_max;}
double Rectangle::get_y_max() const{return y_max;}
void Rectangle::set_solid(int new_solid) {solid = new_solid;}
void Rectangle::set_x_min(double new_x_min) {x_min = new_x_min;}
void Rectangle::set_y_min(double new_y_min) {y_min = new_y_min;}
void Rectangle::set_x_max(double new_x_max) {x_max = new_x_max;}
void Rectangle::set_y_max(double new_y_max) {y_max = new_y_max;}
void Rectangle::push_children (int index) {vec.push_back(index);}
//int Rectangle::get_child_index() {}
