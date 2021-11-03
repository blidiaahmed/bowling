#include "turn.h"
#include <iostream>
using namespace std;
void turn::set_throw1(int i) { throw1 = i; }
void turn::set_throw2(int i) { throw2 = i; }
strick_turn::strick_turn(char c):turn()
{
	try {
		
		if (c != 'X') throw c;
		else
			set_throw1(10);
	}
	catch (char d) {
		cout << "\nthe caracter " << d << " doesn't represente a strick case";
		
	}
}
turn::turn(char c, char d)
{
	
	try {
		

		if ((48 <= c && c <= 56) || c == '-' || c == '/')
			if ((48 <= c && c <= 56))
				set_throw2(c - 48);
			else
				set_throw2(c);
		else
			
			throw c;
	}
	catch (char e) {
		cout << "\nthe caracter " << e << " is not valid";

	}

	try {
		if ((48 <= d && d <= 56) || d == '-' || d == '/')
			if ((48 <= d && d <= 56))
				set_throw2(d - 48);
			else
				set_throw2(d);
		else
			throw d;
	}
	catch (char e) {
		cout << "\nthe caracter " << e << " is not valid";

	}

	if (!((get_throw1() + get_throw1()) == 10)) qualifier = "miss";
	
	

}
int  turn::check_if_number_or_valid_caracter(char d) {

	try {
		if ((48 <= d && d <= 56) || d == '-' || d == '/')
			if ((48 <= d && d <= 56))
				return (d - 48);
			else
				return (d);
		else
			throw d;
	}
	catch (char e) {
		cout << "\nthe caracter " << e << " is not valid";

	}

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