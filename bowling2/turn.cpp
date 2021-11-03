#include "turn.h"
#include <iostream>
using namespace std;
void turn::set_throw1(int i) { throw1 = 10; }
strick_turn::strick_turn(char c):turn(c,c)
{
	try {
		set_throw1(10);
		if (c != 'X') throw c;
	}
	catch (char d) {
		cout << " the letter " << d << "doesn't represente a strick case";
		
	}
}
turn::turn(char c, char d)
{
	throw1 = c - 30;
	throw2 = d - 30;
	if (!((throw1 + throw2) == 10)) qualifier = "miss";
	

}

final_strick_turn::final_strick_turn(char c1, char c2, char c3):turn(c1, c2)
{
	
	throw3= c3 - 30;
	set_qualifier("strick");
}

final_spare_turn::final_spare_turn(char c1, char c2, char c3):turn(c1, c2)
{
	throw3 = c3 - 30;
	set_qualifier("spare");
}