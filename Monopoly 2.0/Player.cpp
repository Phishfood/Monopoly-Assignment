#include "Player.h"

/*************************************************
***		CONSTRUCTORS AND DESTRUCTOR				**
*************************************************/

Player::Player(string piece)
{
	name = piece;
	balance = 1500;
	position = 0;
}


Player::~Player(void)
{
}

/*************************************************
***		NAME									**
*************************************************/

string Player::GetName()
{
	return name;
}


void Player::SetName(string newName)
{
	name = newName;
}

/*************************************************
***		BALANCE									**
*************************************************/

int Player::GetBalance()
{
	return balance;
}

void Player::DisplayBalance()
{
	cout << POUND;
	if( balance > 1000)
	{
		printf("%d,%d", balance / 1000, abs(balance % 1000) );
		
	}
	else
	{
		cout << balance;
	}
}

void Player::Credit(int amount)
{
	balance += amount;
}

void Player::Debit(int amount)
{
	balance -= amount;
}

/*************************************************
***		POSITION								**
*************************************************/

int Player::GetPosition(){
	return position;
}

void Player::SetPosition(int newPosition){
	position = newPosition;
}

void Player::GoToJail()
{

}

void Player::PassGo()
{
	cout << name << " passed go and collected " << POUND << "200." << endl;
	Credit(200);
}