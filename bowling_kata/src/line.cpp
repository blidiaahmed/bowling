#include "line.h"
#include <iostream>
#include <string>
using namespace std;

line::line(string str)
{
	try { if (!divide_by_turn()) throw "invalid string"; }
	catch (string s)
	{
		cout << "error:" << s;
	}
}

	

bool divide_by_turn()
{

	return true;
}
bool counte_score() {
	return true;
}