#ifndef _Piece_h_
#define _Piece_h_

using namespace std;

class Piece
{
public:
	Piece(int radius)
	{
		Radius = radius;
	}
	~Piece();

	int getRadius() { return Radius; }

private:
	int Radius;
};

class Peg
{
public:
	Peg(int height, int distanceBetweenPegs)
	{
		Width = distanceBetweenPegs;
		Pstack.resize(height, NULL);
	}
	~Peg();

	void printDisc(int discNum)
	{
		int radius = Pstack[discNum]->getRadius();
		for(int i = 0; i < Width; i++)
		{
			if(Width / 2 == i) cout << char(178);
			if(i >= (Width / 2) - radius && i <= (Width / 2) + radius - 1)
				cout << char(178);
			else
				cout << char(255);
		}
	}

	int getTopDiscIndex()
	{
		int i;
		for(i = 0; i < Pstack.size(); i++)
			if(Pstack[i] != NULL)
				break;
		while(i >= Pstack.size())
			i--;
		return i;
	}

	void moveDiscFromPegToPeg(Peg *B)
	{
		int oldIndex = this->getTopDiscIndex();
		int newIndex = B->getTopDiscIndex();

		if(this->Pstack[oldIndex] == NULL)
			return;

		int oldRadius = this->Pstack[oldIndex]->getRadius();
		int newRadius = -1;

		// cout << oldIndex << " " << newIndex << endl;

		if(B->Pstack[newIndex] != NULL)
			newRadius = B->Pstack[newIndex]->getRadius();
		else
			newRadius = 0;

		// cout << oldIndex << " " << newIndex << " " << oldRadius << " " << newRadius << endl;

		if(newRadius == 0)
		{
			B->Pstack[newIndex] = this->Pstack[oldIndex];
			this->Pstack[oldIndex] = NULL;
		}
		else if( oldRadius < newRadius )
		{
			B->Pstack[newIndex - 1] = this->Pstack[oldIndex];
			this->Pstack[oldIndex] = NULL;
		}
	}

	friend class TowersofHanoi;

private:
	int Width;
	vector<Piece*> Pstack;
};

#endif //_Piece_h_