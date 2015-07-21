#pragma once
#include "square.h"
class Go :
	public Square
{
public:
	Go(string fileInput);
	~Go(void);

	virtual void PlayerLanded(Player* landed);
	virtual int GetColour() { return -1; }
	virtual void SetGroupMember(int index, Square* member);
	
	//only needed for testing.
	virtual int GetType(){return GO; };
	virtual int GetRentCost(){ return -1; };
	virtual int GetBuyCost(){ return -1; }
};

