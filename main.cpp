#include "includes.h"
#include <string>
#include <ctype.h>

using namespace std;

bool isNumber(const char* input){
	while(*input)
		if(!isdigit(*input))
			return false;
		else input++;
	return true;
}

int main()
{
	string numOfPieces, numofpegs;
	int pieces, pegs;
	while(true){
		system("CLS");
		cout << "Enter at least 1 piece" << endl;
		cout << "Enter # of pieces: ";
		
		cin >> numOfPieces;
		if(isNumber(numOfPieces.c_str())){
			cout << "Enter at least 1 to 9 pegs" << endl;
			cout << "Enter # of pegs: ";
			pieces = atoi(numOfPieces.c_str());
		} else continue;

		cin >> numofpegs;
		if(isNumber(numofpegs.c_str())){
			pegs = atoi(numofpegs.c_str());
			if(pieces > 0 && pegs > 0 && pegs <= 9)
				break;
		} else continue;
	}

	TowersofHanoi *test = new TowersofHanoi(pieces, pegs);

	test->PlayGame();
}