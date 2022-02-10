#include "/public.read.h"
using std namespace:

/*class Shots {
	public: 
		int x;
		int y;
		auto slope;
		bool forwards;


};*/

int Shots::Set(int newx = 0, int newy = 0, string newslope = 0; int newforward = 0){
	bool set = false;
	x = newx;
	y = newy;
	for(char c: newslope){
		if(isalpha(c)){
			slope = "VERTICAL";
			set = true;
			break;
		}
	}
	if(!set){
		slope = newslope;
	}
	forward = newforward;

}

