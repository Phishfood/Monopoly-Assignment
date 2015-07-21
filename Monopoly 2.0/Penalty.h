#pragma once
#include "square.h"
class Penalty :
	public Square
{
public:
	Penalty(string fileInput);
	~Penalty(void);
	virtual void PlayerLanded(Player* landed);
	virtual int GetColour() { return -1; }
	virtual void SetGroupMember(int index, Square* member);
	
	//only needed for testing.
	virtual int GetType(){ return PENALTY; };
	virtual int GetRentCost(){ return -1; };
	virtual int GetBuyCost(){ return -1; }
};

