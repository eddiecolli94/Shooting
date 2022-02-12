#include "rectangle.h"

Rectangle::Rectangle() {
	solid = 1; //assume the rectangle is solid as the default
	min.x = 0;
	min.y = 0;
	max.x = 0;
	max.y = 0;
	vector<int> children;
}
Rectangle::Rectangle(int new_solid, double new_x_min, double new_y_min, double new_x_max, double new_y_max) {
	if(new_x_min > new_x_max or new_y_min > new_y_max) exit(-1);
	solid = new_solid;
	min.x = new_x_min;
	min.y = new_y_min;
	max.x = new_x_max;
	max.y = new_x_max;
	vector<int> children;
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
	children.push_back(index);
}

ostream& operator<<(ostream &outs, const Rectangle &rec) {
	outs << "(" << rec.get_x_min() << "," << rec.get_y_min() << ") to ";
	outs << "(" << rec.get_x_max() << "," << rec.get_y_max() << ") ";
	if(rec.solid == 0) outs << "NOT SOLID ";
	else outs << "SOLID";
	if(rec.children.size() > 0) {
		outs << "Children:";
		for(int i : rec.children) outs << " " << i;
	}
	return outs;
}

void overlap_all(const vector<Rectangle> &boxes) {
    vector<Rectangle> map = boxes;
    bool check = true;
    for(int i = 0; i < map.size()-1; i++) {
        for(int j = i; j < map.size(); j++) {
			if ((map.at(i).get_x_min() > map.at(j).get_x_max()) or (map.at(i).get_x_max() > map.at(j).get_x_min()) or (map.at(i).get_y_max() > map.at(j).get_y_min()) or (map.at(i).get_y_min() > map.at(j).get_y_max())) check = false;
                cout << "Map Error: Box " << j << endl;
        }
    }
    cout << "Map Correct" << endl;
}

void check_correctness(const vector<Rectangle> &boxes) {
}

void overlap_check() {
	bool check = true;
	cout << "Please enter the min and max points for a Rectangle (example: 0 0 10 20 to make a box from (0,0) to (10,20)):" << endl;
	double min_x = 0, min_y = 0, max_x = 0, max_y = 0;
//	string s = readline();
//	stringstream iss(s);
//	iss >> min_x >> min_y >> max_x >> max_y;
	cin >> min_x >> min_y >> max_x >> max_y;
	Rectangle rec1(0, min_x, min_y, max_x, max_y);
	cout << "And then again for a second Rectangle:" << endl;
//	s = readline();
//	stringstream iss(s);
//	iss >> min_x >> min_y >> max_x >> max_y;
	cin >> min_x >> min_y >> max_x >> max_y;
	Rectangle rec2(0, min_x, min_y, max_x, max_y);




if ((rec1.get_x_min() > rec2.get_x_max()) or (rec1.get_x_max() > rec2.get_x_min()) or (rec1.get_y_max() > rec2.get_y_min()) or (rec1.get_y_min() > rec2.get_y_max())) check = false;
	if(check) cout << "They don't intersect.\n";
	else cout << "They intersect!\n";
}



