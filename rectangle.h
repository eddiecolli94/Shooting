#pragma one
#include <iostream>
using namespace std;

void die();

class Rectangle{
	private:
		int solid; //1 if solid, 0 if nonsolid
		double x_min, y_min, x_max, y_max;
		Vec<int> vec; //Vec will hold the index of the Rectangle's children
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
		//int get_child_index();
}
