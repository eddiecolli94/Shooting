#pragma one
#include <sstream>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct Point {
	double x, y;
};

class Rectangle{
	private:
		int solid; //1 if solid, 0 if nonsolid
		Point min;
		Point max;
		vector<int> children; //Vec will hold the index of the Rectangle's children
		vector<int> *child_ptr; //help us gain access to the data inside the class's vector
	public:
		Rectangle();
		Rectangle(int new_solid, double new_x_min, double new_y_min, double new_x_max, double new_y_max);
		int get_solid() const;
		double get_x_min() const;
		double get_y_min() const;
		double get_x_max() const;
		double get_y_max() const;
		void set_solid(int new_solid);
		void set_x_min(double new_x_min);
		void set_y_min(double new_y_min);
		void set_x_max(double new_x_max);
		void set_y_max(double new_y_max);
		void push_children(int index);
		vector<int> get_vec_ptr() const;
		friend ostream& operator<<(ostream &outs, const Rectangle &rec);
		void overlap_check();
		void overlap_all(const vector<Rectangle> &boxes);
		void check_correctness(const vector<Rectangle> &boxes);
};
