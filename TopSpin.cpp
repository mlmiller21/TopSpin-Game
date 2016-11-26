#include "TopSpin.h"

TopSpin::TopSpin(int topsize, int boardsize)
{
	this->topSize = topsize;	//Allows values for top and board to be modified
	this->boardSize = boardsize;

	if (boardsize >1 && topsize < boardsize)
	{
		for (int i = 1;i <= boardsize;i++)	//as long as parameter is met, numbers are added to list, otherwise default values of top size 4 and board size 20 are used
		{
			board.addTail(i);		
		}
	}
	else
	{
		topSize = 4;
		boardSize = 20;
		for (int i = 1; i <= boardSize;i++)
		{
			board.addTail(i);
		}
	}

	xd = board.begin();
}

void TopSpin::shiftLeft(int a)	//Using an iterator to travere traverse through the circularlist to the left
{								//Based off inputted value to shift a set amount of times
	for (int i = 0;i < a;i++)
	{
		++xd;
	}
}

void TopSpin::shiftRight(int a)
{
	for (int i = 0; i < a;i++)
	{
		--xd;
	}
}

void TopSpin::spin()
{
	CircularDoublyLinkedList<int>::iterator first, second;	//Spin takes advantage of the fact that the topsize number will always be even
	first = xd;												//Uses iterators to swap one half of the topsize and then the other half
	second = xd;
	int temp;

	for (int i = 1; i < topSize;i++)
	{
		++second;
	}

	for (int i = 0; i < topSize / 2;i++)
	{
		 
		temp = first.getValue();
		first.setValue(second.getValue());
		second.setValue(temp);

		++first;
		--second;
	}
}


bool TopSpin::isSolved()	//Creates a new iterator to preserve the old one, and compares the index to the linked list
{							//To check if the values match, returns true if all values match otherwise returns false
	CircularDoublyLinkedList<int>::iterator xp = xd;
	bool win;
	for (int i = 1;i <= boardSize;i++)
	{
		if (i == xp.getValue())
		{
			win = true;
		}
		else
		{
			win = false;
			break;
		}
		++xp;
	}
	if (win == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int TopSpin::getBoard()
{
	return boardSize;
}

void TopSpin::setBoard(int a)
{
	boardSize = a;
}

int TopSpin::getTop()
{
	return topSize;
}

void TopSpin::setTop(int a)
{
	topSize = a;
}
