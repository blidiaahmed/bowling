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
	bool divide_by_turn();
	bool counte_score();
};


#endif \\2