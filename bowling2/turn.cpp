#include "turn.h"

turn::turn(char c)
{
	throw1 = 10;
}
turn::turn(char c, char d)
{
	throw1 = c - 30;
	throw2 = d - 30;
	//if !((throw1 + throw2) == 10) qualifier = "miss";
	

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