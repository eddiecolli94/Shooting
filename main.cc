#include "/public/read.h"
#include "ray.h"
#include <vector>
#include <iostream>
using namespace std;

//GL; HF
void die(string s = "BAD INPUT!") {
        cout << s << endl;
        exit(EXIT_FAILURE);
}

vector<Rectangle> load_map(const string &s) {
	ifstream file (s);
	string input;
	vector<Rectangle> map;
	while(file) {
		int is_solid = 0;
		double min_x_val = 0;
		double min_y_val = 0;
		double max_x_val = 0;
		double max_y_val = 0;
		Rectangle temp(is_solid, min_x_val, min_y_val, max_x_val, max_y_val);
		map.push_back(temp);
	}
	return map;
}

vector<Ray> load_shots(const string &s) {
	vector<Ray> shots;
	return shots;
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
	if (!boxes.size()) die("Empty File!");
//	string filename2 = read("Please enter filename with the shots:\n");
//	vector<Ray> shots = load_shots(filename2);
//	if (!shots.size()) die("Empty File!");
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
					cout << boxes; //Print a vector!
					break;
			case PRINT_SHOTS:
	//				cout << shots; //Print a vector!
					break;
			case CHECK_CORRECTNESS:
//					check_correctness(boxes);
					break;
			case OVERLAP_CHECK:
//					overlap_check();
					break;
			case TAKE_SHOT:
//					take_shot();
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
