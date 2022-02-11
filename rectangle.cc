#include "rectangle.h"

Rectangle::Rectangle() {
	solid = 1; //assume the rectangle is solid as the default
	min.x = 0;
	min.y = 0;
	max.x = 0;
	max.y = 0;
	child_ptr = nullptr;
}
Rectangle::Rectangle(int new_solid, double new_x_min, double new_y_min, double new_x_max, double new_y_max) {
	if(new_solid != 0 or new_solid != 1) exit(-1); 
	if(new_x_min > new_x_max or new_y_min > new_y_max) exit(-1);
	solid = new_solid;
	min.x = new_x_min;
	min.y = new_y_min;
	max.x = new_x_max;
	max.y = new_x_max;
}
int Rectangle::get_solid() const{return solid;}
double Rectangle::get_x_min() const{return min.x;}
double Rectangle::get_y_min() const{return min.y;}
double Rectangle::get_x_max() const{return max.x;}
double Rectangle::get_y_max() const{return max.y;}
void Rectangle::set_solid(int new_solid) {solid = new_solid;}
void Rectangle::set_x_min(double new_x_min) {min.x = new_x_min;}
void Rectangle::set_y_min(double new_y_min) {min.y = new_y_min;}
void Rectangle::set_x_max(double new_x_max) {max.x = new_x_max;}
void Rectangle::set_y_max(double new_y_max) {max.y = new_y_max;}
void Rectangle::push_children (int index) {
	//solid rectangles cannot have children
	if(solid) exit(-1); 
	children.push_back(index);
	if(children.size() == 1) child_ptr = &children;
}
ostream& operator<<(ostream &outs, const Rectangle &rec) {
	outs << rec.solid; 
	outs << rec.get_x_min();
	outs << rec.get_y_min();
	outs << rec.get_x_max();
	outs << rec.get_y_max();
	return outs;
}
vector<int> Rectangle::get_vec_ptr() const {return *child_ptr;}
void Rectangle::overlap_check() {}
void Rectangle::overlap_all(const vector<Rectangle> &boxes) {}
void Rectangle::check_correctness(const vector<Rectangle> &boxes) {}
