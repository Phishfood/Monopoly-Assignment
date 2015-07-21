#pragma once
#include "square.h"
class FreeParking :
	public Square
{
public:
	FreeParking(string fileInput);
	~FreeParking(void);
	virtual void PlayerLanded(Player* landed);
	virtual int GetColour() { return -1; }
	virtual void SetGroupMember(int index, Square* member);
	
	//only needed for testing.
	virtual int GetType(){ return FREE_PARKING; };
	virtual int GetRentCost(){ return -1; };
	virtual int GetBuyCost(){ return -1; }
};

