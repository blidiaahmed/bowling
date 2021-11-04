#include "line.h"
#include <iostream>
#include <string>
using namespace std;

line::line(string str)
{
	try 
	{ 
		set_str(str);
		divide_by_turn();
		//if (false) { throw 3; }
	}
	catch (int i)
	{
		if (i==0) cout << "error:" << i << ", excessively long string";
	}
}

	

bool line::divide_by_turn()
{
	int turn_cursor = 0;
	int str_array_cursor = 0;

	while (str_array_cursor <= str.size() && turn_cursor<=9)
	{
		//strick
		if (str[str_array_cursor] == 'X' && turn_cursor != 9)
		{
			
			tu[turn_cursor] = strick_turn('X');
			str_array_cursor++;
			
		}
		
		//spare case
		if (((48 <= str[str_array_cursor] &&
				str[str_array_cursor] <= 57 &&
				(str[str_array_cursor + 1] =='/')
			)
			||
			((48 <= str[str_array_cursor+1] &&
				str[str_array_cursor+1] <= 57 &&
				(str[str_array_cursor] == '/')
			)))&&
			turn_cursor != 9) 
		{
			
			
			tu[turn_cursor] = spare_turn(str[str_array_cursor],	str[str_array_cursor + 1]);

			str_array_cursor += 2;
		}
		//normal case
		if (48 <= str[str_array_cursor] && str[str_array_cursor] <= 57 &&
			48 <= str[str_array_cursor + 1] && str[str_array_cursor + 1] <= 57
			)
		{
			tu[turn_cursor] = turn(str[str_array_cursor], str[str_array_cursor + 1]);
			str_array_cursor += 2;
		}
		cout << "\n turn_cursor=" << turn_cursor << "strlen="<< str.length()<< "str_array_cursor"<< str_array_cursor << endl;
		if (turn_cursor == 9 && str_array_cursor+1<= str.length()) {
			//final spare case
			if (
				(((48 <= str[str_array_cursor] && str[str_array_cursor] <= 57)
					&& str[str_array_cursor + 1] == '/') ||
					((48 <= str[str_array_cursor + 1] && str[str_array_cursor + 1] <= 57)
						&& str[str_array_cursor] == '/'))
				)
			{

				tu[turn_cursor] = final_spare_turn(str[str_array_cursor],
					str[str_array_cursor + 1], str[str_array_cursor + 2]);
				str_array_cursor += 3;

			}

			//final strick
			if (str[str_array_cursor] == 'X' && turn_cursor == 9)
			{


				tu[turn_cursor] = final_strick_turn('X',
					str[str_array_cursor + 1],
					str[str_array_cursor + 2]);
				str_array_cursor += 3;

			}
		}
		turn_cursor++;
		

	}

	
	if (str_array_cursor <= str.size()-1) {
		cout << str_array_cursor << endl;
		throw 0;
	}

	
	return false;
}



bool line::counte_score() {
	return true;
}