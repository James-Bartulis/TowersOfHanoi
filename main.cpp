#include "includes.h"
#include <string>
#include <ctype.h>

using namespace std;

void SetFontSize(int size){
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;                   // Width of each character in the font
	cfi.dwFontSize.Y = size;                  // Height
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	std::wcscpy(cfi.FaceName, L"Consolas"); // Choose your font
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}

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
	SetFontSize(1000/(pieces*pegs));

	TowersofHanoi *test = new TowersofHanoi(pieces, pegs);

	test->PlayGame();
	SetFontSize(16);
}