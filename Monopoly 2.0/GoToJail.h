#pragma once
#include "square.h"
class GoToJail :
	public Square
{
public:
	GoToJail(string fileInput);
	~GoToJail(void);
	virtual void PlayerLanded(Player* landed);
	virtual int GetColour() { return -1; }
	virtual void SetGroupMember(int index, Square* member);
	
	//only needed for testing.
	virtual int GetType(){ return GO_TO_JAIL; };
	virtual int GetRentCost(){ return -1; };
	virtual int GetBuyCost(){ return -1; }
};

