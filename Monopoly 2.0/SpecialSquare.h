#pragma once
#include "consts.h"

#include "Square.h"

class SpecialSquare :
	public Square
{
private:
	SpecialTypes squareType;
public:
	SpecialSquare(string fileInput);
	~SpecialSquare(void);
	virtual void PlayerLanded(Player* landed);
	virtual int GetColour() { return -1; }
	virtual void SetGroupMember(int index, Square* member);
	
	//only needed for testing.
	virtual int GetType();
	virtual int GetRentCost(){ return -1; };
	virtual int GetBuyCost(){ return -1; }
};

