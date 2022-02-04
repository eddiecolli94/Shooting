#include "/public/read.h"
//#include "/public/rtx_on/map"
#include <iostream>
#include <vector>
using namespace std;

class Rect{
	double minx = 0, miny = 0, maxx = 0, maxy = 0;
	vector<Rect> children;
	public: 
	Rect() {}
	Rect(double new_minx, double new_miny, double new_maxx, double new_maxy) {
		minx = new_minx;
		miny = new_miny;
		maxx = new_maxx;
		maxy = new_maxy;
	}
	double get_minx() const {return minx;}
	double get_miny() const {return miny;}
	double get_maxx() const {return maxx;}
	double get_maxy() const {return miny;}
	void set_minx (double new_minx) {minx = new_minx;}
	void set_miny (double new_miny) {miny = new_miny;}
	void set_maxx (double new_maxx) {maxx = new_maxx;}
	void set_maxy (double new_maxy) {maxy = new_maxy;}
	void push_child (Rect const child) {
		children.push_back(child);
	}
	friend ostream& operator<< (ostream& outs, Rect& rec) {
		outs << "Rectangle :\n";
		outs << "\tmin x: " << rec.minx << endl;
		outs << "\tmin y: " << rec.miny << endl;
		outs << "\tmax x: " << rec.maxx << endl;
        outs << "\tmax y: " << rec.maxy << endl;
		return outs;
	}
	friend istream& operator>> (istream& ins, Rect& rec) {
		ins >> rec.minx >> rec.miny >> rec.maxx >> rec.maxy;
		return ins;
	}
};

int main() {
	vector <Rect> vec;	
	Rect rec;
	return 0;
}
