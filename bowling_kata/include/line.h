#ifndef LINE 2
#define LINE 2
#include <string>
#include "turn.h"
using namespace std;
class line
{
	string str;
	turn tu[10];
	// to do

public:
	line();
	line(string str);
	string get_str() { return str; }
	bool divide_by_turn();
	turn get_turn(int i) { return tu[i]; }
	void set_turn(turn tur,int  i) { tu[i] = tur; }
	bool counte_score();
};


#endif \\2