#pragma once

#include "consts.h"

class Player
{
private:
	string name;
	int balance;
	int position;
public:
	//constructors and destructor
	Player(string piece);
	~Player(void);
	
	//name
	string GetName();
	void SetName(string newName);
	
	//balance
	int GetBalance();
	void DisplayBalance();
	void Credit(int amount);
	void Debit(int amount);

	//position
	int GetPosition();
	void SetPosition(int newPosition);
	void GoToJail();
	void PassGo();

	//void AdvancePosition(int amount, int maxPosition);
};

