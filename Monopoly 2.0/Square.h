#pragma once
#include "consts.h"

#include "Player.h"

class Square
{
private:
	string name;
	Player* owner;
/*	static int jailPosition;
	static int goPosition;
	static int goDefined;
	static int jailDefined;
	static int goToJailDefined;
	static int airportsDefined;
	static int streetsDefined;
	static int bonusDefined;
	static int penaltyDefined;*/

public:
	//constructors and destructor
	Square(void);
	~Square(void);

	//gameplay
	virtual void PlayerLanded(Player* lander) = 0;	//no base class!
	virtual int GetColour() { return -1; }
	virtual void SetGroupMember(int index, Square* member) = 0;

	
	//Owner
	void SetOwner();
	void SetOnwer(Player* buyer);
	Player* GetOwner();
	
	//name
	void SetName(string newName);
	string GetName();

	//testing
	bool VerifyBoard();
	virtual int GetRentCost() = 0;
	virtual int GetBuyCost() = 0;
	virtual int GetType() = 0;
};

