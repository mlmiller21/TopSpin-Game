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
		os << " ";
		for (int i = 0; i < ts.topSize; i++, ++(ts.xd))
		{
			if ((ts.xd.getValue()) >= 10)	//If the value is greater than 10, 3 dashes need to be printed to accomodate for
				os << "___";				//the 2 digits as well as the space, otherwise only 2 dashes are printed
			else
				os << "__";
		}
		for (int i = 0;i < ts.topSize;i++)
		{
			--(ts.xd);	//Since the for loop has the iterator traverse forward through the list, it must traverse backwards
		}				//an equal number of times
		os << "_" << std::endl << "|";
		for (int i = 0; i < ts.topSize; i++, ++(ts.xd))
		{
			if ((ts.xd.getValue()) >= 10)
				os << "   ";
			else
				os << "  ";
		}
		for (int i = 0;i < ts.topSize;i++)
		{
			--(ts.xd);
		}
		os << " |" << std::endl << "| ";
		for (int i = 0; i < ts.topSize; i++, ++(ts.xd))
		{
			os << ts.xd.getValue() << " ";	//Traverses through the list, and prints out the values for the top, based off 
		}									//the top size
		os << "| ";
		for (int i = ts.topSize; i < ts.boardSize; i++, ++(ts.xd))
		{
			os << ts.xd.getValue() << " ";	//Traverses through the list and prints out the rest of the board values
		}
		os << std::endl << "|";
		for (int i = 0; i < ts.topSize; i++, ++(ts.xd))
		{
			if ((ts.xd.getValue()) >= 10)
				os << "___";
			else
				os << "__";
		}
		for (int i = 0;i < ts.topSize;i++)
		{
			--(ts.xd);
		}
		os << "_|";
		return os;
	}

};
