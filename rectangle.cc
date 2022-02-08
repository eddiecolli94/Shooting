#include <rectangle.h>

int Rectangle::get_x_min() const{return x_min;}
int Rectangle::get_y_min() const{return y_min;}
int Rectangle::get_x_max() const{return x_max;}
int Rectangle::get_y_max() const{return y_max;}
void Rectangle::set_x_min(int new_x_min) {x_min = new_x_min;}
void Rectangle::set_y_min(int new_y_min) {y_min = new_y_min;}
void Rectangle::set_x_max(int new_x_max) {x_max = new_x_max;}
void Rectangle::set_y_max(int new_y_max) {y_max = new_y_max;}
void Rectangle::push_children (int index) {vec.push_back(index);}
//int Rectangle::get_child_index() {}
