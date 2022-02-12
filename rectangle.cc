#include "rectangle.h"

Rectangle::Rectangle() {
	solid = 1; //assume the rectangle is solid as the default
	min.x = 0;
	min.y = 0;
	max.x = 0;
	max.y = 0;
}
Rectangle::Rectangle(int new_solid, double new_x_min, double new_y_min, double new_x_max, double new_y_max) {
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
}
ostream& operator<<(ostream &outs, const Rectangle &rec) {
	outs << rec.solid << " " << rec.get_x_min() << " " << rec.get_y_min() << " " << rec.get_x_max() << " " << rec.get_y_max();
	return outs;
}
void overlap_all(const vector<Rectangle> &boxes) {
    vector<Rectangle> map = boxes;
    bool check = true;
    for(int i = 0; i < map.size()-1; i++) {
        for(int j = i; j < map.size(); j++) {
            if ((map.at(i).get_x_min() < map.at(j).get_x_max()) and (map.at(i).get_x_max() > map.at(j).get_x_min()) and (map.at(i).get_y_max() < map.at(j).get_y_min()) and (map.at(i).get_y_min() > map.at(j).get_y_max())){
                cout << "Map Error: Box " << j << endl;
            }
        }
    }
    cout << "Map Correct" << endl;
}
void check_correctness(const vector<Rectangle> &boxes) {
	for(int i = 0; i < boxes.size(); i++) {
		for(int i = 0; i < boxes.size()-1; i++) {
        for(int j = i; j < boxes.size(); j++) {
            if ((boxes.at(i).get_x_min() < boxes.at(j).get_x_max()) and (boxes.at(i).get_x_max() > boxes.at(j).get_x_min()) and (boxes.at(i).get_y_max() < boxes.at(j).get_y_min()) and (boxes.at(i).get_y_min() > boxes.at(j).get_y_max())){
                cout << "Map Error: Box " << j << endl;
                exit(-1);
            }
        }
    }
    cout << "Map Correct" << endl;

	}
}

