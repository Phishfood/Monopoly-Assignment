#pragma once

#include "consts.h"

#include "Square.h"
#include "Player.h"

class Street :
	public Square
{
private:
	int buyCost;
	int rentCost;
	int colourGroup;
	Square* groupProperties[MAX_GROUP_SZIE];
public:
	//constructor(s)/destructor
	Street(string fileInput);
	~Street(void);

	//gameplay
	virtual void PlayerLanded(Player* lander);
	virtual int GetColour();
	virtual void SetGroupMember(int index, Square* member);
	
	//Testing
	virtual int GetType() { return -1; };
	virtual int GetRentCost() { return rentCost; };
	virtual int GetBuyCost(){ return buyCost; };
};

