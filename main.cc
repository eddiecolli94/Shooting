#include "/public/read.h"
using namespace std;

//GL; HF

int main() {
	//The (void)! is just there to ignore the return value of system, which otherwise will warn
	//Or we could do #pragma GCC diagnostic ignored "-Wunused-result" 
	// but that would only work for GCC
	(void)!system("/usr/bin/figlet RTX ON");
}
