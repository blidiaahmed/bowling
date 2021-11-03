


#ifndef TURN 1
#define TURN 1
#include <string>
using namespace std;
class turn
{
private:
	int throw1;
	int throw2;
	string qualifier;
protected:
	void set_throw1(int i);
	void set_qualifier(string str) { qualifier = str; };
public:
	//turn();

	turn(char c, char d);
	string get_qualifier() { return qualifier; };
	
};

class strick_turn :turn
{
public:
	strick_turn(char c);
	
};
class final_strick_turn :turn
{
private:
	int throw3;

public:
	final_strick_turn(char c1, char c2, char c3);
	

};

class final_spare_turn :turn
{
	int throw3;

public:
	final_spare_turn(char c1, char c2, char c3);

};


#endif \\TURN