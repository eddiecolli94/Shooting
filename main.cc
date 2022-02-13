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
//					take_shot();
					break;
			case OVERLAP_ALL:
					overlap_all(boxes);
					break;
			case TAKE_ALL_SHOTS:
//					take_all_shots(boxes,shots);
					break;
			default:
					die("Unknown choice");
	}
}
