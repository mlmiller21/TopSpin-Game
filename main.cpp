#include "TopSpin.h"
#include <iostream>
#include <ctime>
using namespace std;


int main() {
	int numMoves = 0;	//numMoves is used to shuffle the puzzle

	int boardSize, topSize;
	cout << "Enter board size and top size, make sure board size is greater than the top size\nBoard size: ";
	cin >> boardSize;
	cout << "Top size: ";
	cin >> topSize;

	TopSpin a(topSize, boardSize);	//New object a is created based off the user inputted parameters

	cout << "Enter number of moves to initalize board with: ";
	cin >> numMoves;

	srand(time(NULL));
	for (int i = 0; i < numMoves; ++i)
	{
		int numShifts = (rand() %19)  + 1;	//Randomly generates list based off shifts and spins
		for (int j = 0; j < numShifts; ++j)
		{
			a.shiftLeft(j);
		}
		a.spin();
	}

	while (a.isSolved()==0)
	{
		cout << endl << a << endl << endl;
		int n;
		cout << "PLease choose from the following options, enter your choice by entereing the corresponding number: " << endl;
		cout << "1. Shift\n2. Spin\n3. Quit\n";
		cin >> n; 

		switch (n) {
		case 1:
			int x, y;
			cout << "\nShift left or right:\n1. Left \n2. Right\n";
			cin >> x;
			cout << "\nHow many times: ";
			cin >> y;
			if (x == 1)
			{
				a.shiftLeft(y);	//Shift number of y times
				
			}
			else
			{
				a.shiftRight(y);
				
			}
			break;
		case 2:
			a.spin();
			break;
		case 3:
			return 0;
			break;
		}
		if (a.isSolved()) //If the puzzle is solved, exits from loop
			break;
	}
	cout << endl << a << endl;
	if (a.isSolved() == 1) 
		cout << "\nCONGRATULATIONS!\n\n";
}
