#include< string>
#include < iostream>
using namespace std;

int turn_function(string str, int index)
{
	//cout << "***";
	int sum = 0;
	if (str[index] == 'X')
	{
		//cout << "str[index] == X" <<sum<< endl;

		sum += 10;
		//next turn
		if (str[index + 1] == 'X') { sum += 10; // cout << "str[index + 1] == 'X'" << sum << endl;
		}
		else if (str[index + 1] >= 48 && str[index + 1] <= 57) sum += str[index + 1] - 48;
		
		else { throw 0;return sum; }
		//second next turn
		if (str[index + 2] == 'X') { 
			sum += 10;// cout << "str[index + 2] == X " << sum << endl;
		}
		else if (str[index + 2] >= 48 && str[index + 2] <= 57) sum += str[index + 2] - 48;
		else if (str[index + 2] == '-') sum += 0;
		else if (str[index + 2] == '/')sum += 10 - (str[index + 2] - 48);
		else {
			throw 0;return sum;
		}
	}
	else if (str[index] >= 48 && str[index] <= 57)
	{
		
		sum += str[index] - 48;
		//cout << "\nelse if (str[index] >= 48 && str[index] <= 57)   " << sum << endl;
		if (str[index + 1] >= 48 && str[index + 1] <= 57) {
			//cout << "\nelse if (str[index+1] >= 48 && str[index+1] <= 57)   " << sum+ str[index + 1] << endl;

			return sum + str[index + 1]-48;
			}
		else if (str[index + 1] == '/') { 
			sum = 10 ;// cout << "\n(str[index + 1] == '/'" << sum << endl;
			if (str[index + 2] == 'X') { sum += 10; }
			else if (str[index + 2] >= 48 && str[index + 2] <= 57) { sum  += str[index + 2] - 48; }
		}
		else if (str[index + 1] == '-') return sum;
		else { throw 0; return sum; }
	}
	else { throw 0; return sum; }
	return sum;


}




int indexes_to_jumpe(string str, int index)
{
	if (str[index] == 'X') return 1;
	else return 2;

}


int counte_score(string str)
{
	int index=0,turn = 1,sum=0;
	while (turn <= 10)
	{	
		sum += turn_function( str,  index);
		//cout << "\indexes_to_jumpe( str,  index)==" << indexes_to_jumpe(str, index) << endl;
		index += indexes_to_jumpe( str,  index);
		if (str.length()  < index)throw 1;
		turn += 1;
	}

	if (str.length() != index) { 
		
		
		if (str.length() - 2 > index) { throw 1; }
		else if (!(str[index - 1] == '/' && index==str.length()-1) && !(str[index - 1] == 'X'&& index ==str.length()-2)) {
			throw 1;
		}
		
	}
	//cout << "\ns*****" << sum;
	return sum;
}