#include <iostream>
#include "turn.h"
bool main(int argc, char* argv[])
{


    std::cout << "\n ******rrr********\n" << argc << argv[2];
    //defining a turn
    turn tu = turn(argv[2][0]);
    string e = "eee";
    tu.set_qualifier(e);
    //final_spare_turn('1', '9', '5');
    //final_strick_turn('1', '5','5');
    return false;
}