#ifndef LINE 2
#define LINE 2
#include <string>
#include "turn.h"
using namespace std;
class line
{
	string str;
	turn tu[10];
	int scores[10];
	// to do

public:
	line();
	line(string str);
	string get_str() { return str; }
	turn get_turn(int i) { return tu[i]; }
	void set_turn(turn tur,int  i) { tu[i] = tur; }
	void set_str(string strr) { str = strr; }

	bool divide_by_turn();
	bool counte_score();
};


#endif \\2