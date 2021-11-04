#include "turn.h"
#include <iostream>
using namespace std;
turn::turn(char c, char d)
{
	try {
		if (c == 'X' || d == 'X') {
			throw 1;
			

			set_qualifier("invalid turn");
		}
	}
	catch (int i)
	{
		cout << "invalid turn: strick comes in one throw only";
	}
	cout << "here" << endl;
	set_throw1(check_if_number_or_valid_caracter(c));
	set_throw2(check_if_number_or_valid_caracter(d));

	if (!((get_throw1() + get_throw1()) != 10)) qualifier = "miss";
}
void turn::set_throw1(int i) { throw1 = i; }
void turn::set_throw2(int i) { throw2 = i; }

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
spare_turn::spare_turn(char c,char d) :turn()
{
	
	set_throw1(check_if_number_or_valid_caracter(c));

	set_throw2(10-get_throw1());
	set_qualifier("spare");
	
	//cout << "\nqualifier is spare" << endl;
}


strick_turn::strick_turn(char c):turn()
{
	try 
	{
		
		if (c != 'X') 
		{
			throw c;
			set_qualifier("invalid turn");
		}
		else
		{
			set_throw1(10);
			set_qualifier("strick");
		}

	}
	catch (char d) {
		cout << "\n the caracter " << d << " doesn't represente a strick case";
		
	}
}

final_strick_turn::final_strick_turn(char c1, char c2, char c3):strick_turn(c1)
{
	if (c2 == 'X')set_throw2('X');
	else	set_throw2(check_if_number_or_valid_caracter(c2));
	if (c3 == 'X')set_throw3('X');
	else	set_throw3(check_if_number_or_valid_caracter(c3));
		
	set_qualifier("final strick");
}

final_spare_turn::final_spare_turn(char c1, char c2, char c3):turn(c1, c2)
{
	set_throw2(check_if_number_or_valid_caracter(c2));
	set_qualifier("final spare");	
}