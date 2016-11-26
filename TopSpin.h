#pragma once
#include "CircularDoublyLinkedList.h"
#include <iostream>

class TopSpinADT {
public:
	// shifts the pieces 1 to the left
	virtual void shiftLeft() = 0;
	//shifts the pieces 1 to the right
	virtual void shiftRight() = 0;
	//reverses the pieces in the spin mechanism, IE if the 4 in the mechanism are
	// 1,4,3,6 we will have 6,3,4,1
	virtual void spin() = 0;
	//checks to see if the puzzle is solved that is to say the pieces are in numerical order 1-20
	virtual bool isSolved() = 0;
};

class TopSpin : public  TopSpinADT {
private:
	int topSize, boardSize;
	CircularDoublyLinkedList<int> board;

public:

	CircularDoublyLinkedList<int>::iterator xd;	//New iterator object "xd" is created

	TopSpin(int topsize, int boardsize);
	~TopSpin() {};
	void shiftLeft(int a);
	void shiftLeft() {};
	void shiftRight() {};
	void shiftRight(int a);
	void spin();
	bool isSolved();
	int getBoard();
	void setBoard(int a);
	int getTop();
	void setTop(int a);

	friend std::ostream& operator<< (std::ostream &os, TopSpin &ts) {	
		//Overload print function using ostream, uses for loop to print out the top surrounded by a box, followed				
		//By the rest of the list

		os << "[";
		for (int i = 0; i < ts.topSize; i++, ++(ts.xd))
		{
			os << ts.xd.getValue() << " ";
		}
		os << "] ";
		for (int i = ts.topSize; i < ts.boardSize; i++, ++(ts.xd))
		{
			os << ts.xd.getValue() << " ";
		}
		return os;
	}

};
