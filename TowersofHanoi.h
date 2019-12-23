#ifndef _TowersofHanoi_h_
#define _TowersofHanoi_h_

class TowersofHanoi
{
public:
	TowersofHanoi(int numOfPieces, int numofpegs)
	{
		autosolved = false;
		counter = 0;
		GameComplete = false;
		numOfPegs = numofpegs;
		height = numOfPieces + 1;
		distanceBetweenPegs = numOfPieces * 2;
		width = (distanceBetweenPegs * (numOfPegs + 1)) + numOfPegs; /// 0000 1 0000 1 0000 1 0000
		for(int i = 0; i < numOfPegs; i++)
			pegs.push_back(new Peg(height, distanceBetweenPegs));
		for (int i = numOfPieces; i > 0; i--)
			pegs[0]->Pstack[i] = new Piece(i);
	}
	~TowersofHanoi();

	void Display()
	{
		system("CLS");
		cout << counter++ << endl;
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < numOfPegs; j++)
				if(pegs[j]->Pstack[i] == NULL)
				{
					cout << string(pegs[j]->Width / 2, char(255));
					cout << char(178);
					cout << string(pegs[j]->Width / 2, char(255));
				}
				else
					pegs[j]->printDisc(i);
			cout << endl;
		}
	}

	void Input()
	{
		char input = _getch();
		char input2;
		switch(input)
		{
			case 'c':
				GameComplete = true;
				break;
			case char(49)...char(57):/// it works!! /// accepts 1-9 
				cout << input << " to _" << endl;
				input2 = _getch(); /// char(49) == 1
				if(input != input2 && (int)input2 >= 49 && (int)input2 <= 57) /// 48 is offset 
					pegs[(int)input - 48 - 1]->moveDiscFromPegToPeg(pegs[(int)input2 - 48 - 1]);
				break;
			case 'A':
			autosolved = true;
				switch(numOfPegs)
				{
					case 3:
						AutoSolve(height - 1, 1, numOfPegs, numOfPegs - 1);
						break;
					case 4 ... 9:
						AutoSolve4(height - 1, 1, numOfPegs, numOfPegs - 1, numOfPegs - 2);
						break;
					default:
						break;
				}
				break;
			default:
				counter--;
				break;
		}
	}

	void PlayGame()
	{
		if(numOfPegs <= 1){
			Display();
			cout << "Congrats, you win by default!" << endl;
			return;
		}
		while(!GameComplete)
		{
			Display();
			Input();
			CheckGameCompletion();
		}
	}

	void CheckGameCompletion()
	{
		if(pegs[pegs.size() - 1]->Pstack[1] != NULL)
		{
			GameComplete = true;
			Display();
			if(!autosolved)
				cout << "Congrats, you win!" << endl;
			else
				cout << "Auto solved :)" << endl;
		}
	}

	void AutoPegMove(int a, int b)
	{
		pegs[a - 1]->moveDiscFromPegToPeg(pegs[b - 1]);
		Display();
		CheckGameCompletion();
	}

	void AutoSolve(int n, int c, int g, int o)/// send height - 1, solve complete game
	{/// c g o current goal other
		if(n == 1)
		{
			AutoPegMove(c, g);
		}else
		{
			AutoSolve(n-1,c,o,g);
			AutoPegMove(c,g);
			AutoSolve(n-1,o,g,c);
		}
	}

	void AutoSolve4(int n, int c, int g, int o, int o2)
	{
		if(n == 0)
			return;
		if(n == 1)
		{
			AutoPegMove(c,g);
			return;
		}
		AutoSolve4(n - 2, c, o, o2, g);
		AutoPegMove(c, o2);
		AutoPegMove(c, g);
		AutoPegMove(o2, g);
		AutoSolve4(n - 2, o, g, c, o2);
	}

private:
	bool autosolved;
	int counter;
	bool GameComplete;
	int numOfPegs;
	int height;
	int width;
	int distanceBetweenPegs;
	vector<Peg*> pegs;
};

#endif //_TowersofHanoi_h_