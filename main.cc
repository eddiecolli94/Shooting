#include "/public/read.h"
#include "ray.h"
#include <vector>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <algorithm>
using namespace std;

//GL; HF
void die(string s = "BAD INPUT!") {
        cout << s << endl;
        exit(EXIT_FAILURE);
}

vector<Rectangle> load_map(const string &s) {
	int is_solid = 0;
	double min_x_value = 0, min_y_value = 0, max_x_value = 0, max_y_value = 0;
	vector<int> kids;
	vector<Rectangle> map;
	ifstream ins(s);
	while(ins) {
		string input = readline(ins);
		stringstream iss(input);
		iss >> is_solid >> min_x_value >> min_y_value >> max_x_value >> max_y_value;
		if(!iss) break;
		while(iss) {
			if(!iss) break;
			int child_index = 0;
			iss >> child_index;
			kids.push_back(child_index);
		}
		kids.pop_back();
		Rectangle Rect(is_solid, min_x_value, min_y_value, max_x_value, max_y_value);
		for(int i : kids) Rect.push_children(i);
		map.push_back(Rect);
		kids.clear();
	}
	return map;
}

vector<Ray> load_shots(const string &s) {
	double x_val = 0, y_val = 0;
	string temp = "";
	double slope_val = 0;
	int direc = 0;
	vector<Ray> shot;
	ifstream ins(s);
	while(ins) {
		string input = readline(ins);
		stringstream iss(input);
		iss >> x_val >> y_val >> temp >> direc;
		if(!iss) break;
		if(isdigit(temp.at(0))) slope_val = stod(temp);
		else if (temp.size() > 1 and temp.at(0) == '-' and isdigit(temp.at(1))) slope_val = stod(temp);
		else {
			temp = "Vertical";
		}
		Ray bullet(x_val, y_val, slope_val, direc);
		if(temp != "")bullet.set_vertical(temp);
		else temp.clear();
		shot.push_back(bullet);
	}
	return shot;
}
template <class T>
ostream& operator<<(ostream &outs, const vector<T> &vec) {
        for (const auto &a : vec) outs << a << endl;
        return outs;
}

 bool FindPoint(double x_min, double y_min, double x_max, double y_max, double x, double y){
          if (x > x_min and x < x_max and y > y_min and y < y_max) //return true if (x,y) are in our rectangle
              return true;
           else
              return false;
        }


void take_shot(){
	string win = "HIT! Location: ";
	string lose = "MISS!";
	Ray win_loc;
	bool hit = false;
	string str;
	double x_val = 0;
	double y_val = 0;
	string temp;
	double slope = 0;
	int direction = 0;
	double a,b,c,d;
	cout << "Please enter the min and max points for a Rectangle (example: 0 0 10 20 to make a box from (0,0) to (10,20)):" << endl;
	cin >> a >> b >> c >> d;
	Rectangle rec(1,a,b,c,d);

	cout << "Please enter a shot (for example: 0 5 1.1 1 means it comes from (0 5) heading up at a slope of 1.1 in the forwards direction):" << endl;
	cin >> x_val >> y_val >> temp >> direction;
	if(isdigit(temp.at(0))) slope = stod(temp);
	else if (temp.size() > 1 and temp.at(0) == '-' and isdigit(temp.at(1))) slope = stod(temp);
	else {
		temp = "Vertical";
	}
	Ray bullet(x_val, y_val, slope, direction);
	if(temp != "")bullet.set_vertical(temp);
	
	//if the point is inside the rectangle
	if(FindPoint(a, b, c, d, x_val, y_val)) {
		cout << fixed;
		cout.precision(2);
		cout << "HIT! Location: (" << x_val << "," << y_val << ")" << endl;
		exit(0);
	}
	//set shot to the origin and move rectangle accordingly
	double x_diff = 0 - x_val;
	double y_diff = 0 - y_val;
	rec.set_x_min(a - x_diff);
	rec.set_y_min(a - y_diff);
	rec.set_x_max(a - x_diff);
	rec.set_y_max(a - y_diff);
	if(direction == 0) direction = -1;
	slope = slope * direction;
	double pt_direction = 0; //this will be used to check if vertical shots are going in the right direction or missing entirely

	if(bullet.get_vert() == "Vertical") {
		if(x_val > rec.get_x_min() and x_val < rec.get_x_max()) {
			pt_direction = rec.get_y_min() - y_val;
			if(pt_direction > 0 and direction > 0) {
				cout << fixed;
				cout.precision(2);
				cout << "HIT! Location: (" << x_val << "," << rec.get_y_min() << ")" << endl;
				exit(0);
			}
			else if(pt_direction < 0 and direction < 0) {
				cout << fixed;
				cout.precision(2);
				cout << "HIT! Location: (" << x_val << "," << rec.get_y_max() << ")" << endl;
				exit(0);
			}
			else {
				cout << "MISS!" << endl;
				exit(0);
			}
		}
	}

	double coll_y = rec.get_x_min() * slope;
	if(coll_y >= rec.get_y_min() and coll_y <= rec.get_x_max()) hit = true;
	

	if(hit){
		cout << fixed;
		cout.precision(2);
		cout << win  << "(" << rec.get_x_min() - x_diff << "," << coll_y - y_diff << ")" <<endl;
	}else{
		cout << lose << endl;
	}

}


int main() {
	//The (void)! is just there to ignore the return value of system, which otherwise will warn
	//Or we could do #pragma GCC diagnostic ignored "-Wunused-result" 
	// but that would only work for GCC
	(void)!system("/usr/bin/figlet RTX ON");
	string filename1 = read("Please enter the map filename:\n");
	vector<Rectangle> boxes = load_map(filename1);
	if (!boxes.size()) die("Could not open file");
	string filename2 = read("Please enter filename with the shots:\n");
	vector<Ray> shots = load_shots(filename2);
	if (!shots.size()) die("Could not open file");
	cout << "Menu:\n" <<
			"1) Print the world of boxes\n" <<
			"2) Print the list of shots\n" <<
			"3) Check the boxes for correctness\n" <<
			"4) See if two rectangles overlap\n" <<
			"5) See if a ray hits a rectangle\n" <<
			"6) Output a list of all solid boxes colliding\n" <<
			"7) Fire all shots and see which box is getting hit the most\n";

        //Let's do a switch with an enum because why not the kids love it
	enum CHOICES {PRINT_BOXES=1, PRINT_SHOTS, CHECK_CORRECTNESS, OVERLAP_CHECK, TAKE_SHOT, OVERLAP_ALL, TAKE_ALL_SHOTS};
	const int choice = read("Please enter choice:\n");
	switch (choice) {
			case PRINT_BOXES:
					cout << fixed;
					cout.precision(2);
					cout << boxes; //Print a vector!
					break;
			case PRINT_SHOTS:
					cout << fixed;
					cout.precision(2);
					cout << shots; //Print a vector!
					break;
			case CHECK_CORRECTNESS:
					check_correctness(boxes);
					break;
			case OVERLAP_CHECK:
					overlap_check();
					break;
			case TAKE_SHOT:
					take_shot();
					break;
			case OVERLAP_ALL:
//					overlap_all(boxes);
					break;
			case TAKE_ALL_SHOTS:
//					take_all_shots(boxes,shots);
					break;
			default:
					die("Unknown choice");
	}
}
