#pragma once
#include "square.h"
class Airport :
	public Square
{
public:
	Airport(string fileInput);
	~Airport(void);
	virtual void PlayerLanded(Player* landed);
	virtual int GetColour() { return -1; }
	virtual void SetGroupMember(int index, Square* member);
	
	//only needed for testing.
	virtual int GetType(){ return AIRPORT; };
	virtual int GetRentCost(){ return -1; };
	virtual int GetBuyCost(){ return -1; }
};

