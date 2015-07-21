#pragma once
#include "square.h"
class Jail :
	public Square
{
public:
	Jail(string fileInput);
	~Jail(void);
	virtual void PlayerLanded(Player* landed);
	virtual int GetColour() { return -1; }
	virtual void SetGroupMember(int index, Square* member);
	
	//only needed for testing.
	virtual int GetType(){ return JAIL; };
	virtual int GetRentCost(){ return -1; };
	virtual int GetBuyCost(){ return -1; }
};

