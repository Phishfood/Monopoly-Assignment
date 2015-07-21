#include "Square.h"

/*************************************************
***		CONSTRUCTORS AND DESTRUCTOR				**
*************************************************/
Square::Square(void)
{
	owner = 0;
}


Square::~Square(void)
{
}

/*************************************************
***		OWNER									**
*************************************************/
void Square::SetOnwer(Player* buyer){
	owner = buyer;
}

void Square::SetOwner(){
	owner = 0;
}

Player* Square::GetOwner()
{
	return owner;
}

/*************************************************
***		NAME									**
*************************************************/

void Square::SetName(string newName)
{
	name = newName;
}

string Square::GetName()
{
	return name;
}

/*************************************************
***		TESTING									**
*************************************************/

bool Square::VerifyBoard()
{
/*	bool returnValue = true;
	if(jailDefined > 1)
	{
		cout << "Too many jails defined" << endl;
		returnValue =  false;
	}

	if( goDefined == 0 )
	{
		cout << "No Go square defined!" << endl;
		returnValue = false;
	}

	if ( goDefined > 1)
	{
		cout << "Multiple Go Squares defined!" << endl;
		returnValue = false;
	}

	if( goToJailDefined > 0 && jailDefined != 1 )
	{
		cout << "Go to Jail defined, but no Jail defined!" << endl;
		returnValue =  false;
	}

	if( streetsDefined < 5 )
	{
		cout << "Not enough streets defined!" << endl;
		returnValue =  false;
	}

	return returnValue;*/
	return true;
}