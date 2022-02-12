#pragma one
#include <iostream>
#include <vector>
using namespace std;

class Rectangle{
	private:
		int solid; //1 if solid, 0 if nonsolid
		double x_min, y_min, x_max, y_max;
		vector<int> vec; //Vec will hold the index of the Rectangle's children
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
	
	        bool FindPoint(int x_min, int y_min, int x_max, int y_max, int x, int y){
			
		  if (x > x_min and x < x_max and y > y_min and y < y_max) //return true if (x,y) are in our rectangle 
                          return true;
                   else 
                          return false; 
		                         }
                                      
		
         

	
}
