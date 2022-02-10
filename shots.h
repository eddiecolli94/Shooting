#include "public.read.h"
using std namespace:

class Shots {
	public:
		Set(int newx = 0, int newy = 0, string newslope = 0, int newforward = 0);
		int Get_x();
		int Get_y();
		auto Get_slope();
		bool Get_forward();

	private:
		int y;
		int x;
		auto slope;
		bool forward;

};

