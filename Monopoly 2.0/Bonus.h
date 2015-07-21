#pragma once
#include "square.h"
class Bonus :
	public Square
{
public:
	Bonus(string fileInput);
	~Bonus(void);
	virtual void PlayerLanded(Player* landed);
	virtual int GetColour() { return -1; }
	virtual void SetGroupMember(int index, Square* member);
	
	//only needed for testing.
	virtual int GetType(){ return BONUS; };
	virtual int GetRentCost(){ return -1; };
	virtual int GetBuyCost(){ return -1; }
};

