#pragma one
#include <iostream>
using namespace std;

class Rectangle{
	private:
		int solid; //1 if solid, 0 if nonsolid
		double x_min, y_min, x_max, y_max;
		Vec<int> vec; //Vec will hold the index of the Rectangle's children
	public:
		int get_x_min() const;
		int get_y_min() const;
		int get_x_max() const;
		int get_y_max() const;
		void set_x_min(int new_x_min);
		void set_y_min(int new_y_min);
		void set_x_max(int new_x_max);
		void set_y_max(int new_y_max);
		void push_children(int index);
		//int get_child_index();
}
