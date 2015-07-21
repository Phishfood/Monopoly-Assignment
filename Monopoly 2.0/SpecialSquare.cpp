#include "SpecialSquare.h"
#include "Game.h"

SpecialSquare::SpecialSquare(string fileInput)
{
	SetName(fileInput);
	if( fileInput.compare("GO") == 0 )
	{
		squareType = GO;
	}
	else if( fileInput.compare("Bonus") == 0  )
	{
		squareType = BONUS;
	}
	else if( fileInput.compare("Penalty")  == 0 )
	{
		squareType = PENALTY;
	}
	else if( fileInput.compare("Jail") == 0 )
	{
		squareType = JAIL;
	}
	else if( fileInput.compare("Go to Jail") == 0  )
	{
		squareType = GO_TO_JAIL;
	}
	else if( fileInput.compare("Free Parking") == 0  )
	{
		squareType = FREE_PARKING;
	}
	else
	{
		if(fileInput.length() > 9)
		{
			string temp = fileInput.substr( fileInput.length() - 7);
			if( temp.compare("Airport")  == 0 )
			{
				squareType = AIRPORT;
			}
		}
	}

	//cout << "New Special Square created with type " << squareType << endl;

}

SpecialSquare::~SpecialSquare(void)
{
}

void SpecialSquare::PlayerLanded(Player* lander)
{
	//retrieve square owner for later. Only needed in Airport, but c++ doesn't like declarations in a switch.
	Player* owner = GetOwner();

	//switch on the square type
	switch(squareType)
	{
		case GO:
			lander->PassGo();
			break;
		case AIRPORT:
			if(owner == 0 || owner == NULL)
			{
				if(lander->GetBalance() > AIRPORT_COST){
					lander->Debit(AIRPORT_COST);
					SetOnwer(lander);
					cout << lander->GetName() << " bought " << GetName() << " for " << POUND << AIRPORT_COST << endl;
				}
			}
			else if(lander != owner )
			{
				lander->Debit(FLY_COST);
				owner->Credit(FLY_COST);
				cout << lander->GetName() << " pays " << POUND << FLY_COST << " flying costs." << endl;
			}
			break;
		case BONUS:
			switch( Game::DiceRoll() )
			{
				case 1:
					cout << "Find some money. " << lander->GetName() << " gains " << POUND << FIND_MONEY  << endl;
					lander->Credit(FIND_MONEY);
					break;
				case 2:
					cout << "Win a competition. " << lander->GetName() << " gains " << POUND << WIN_MONEY  << endl;
					lander->Credit(WIN_MONEY);
					break;
				case 3:
					cout << "Tax Rebate. " << lander->GetName() << " gains " << POUND << TAX_REBATE  << endl;
					lander->Credit(TAX_REBATE);
					break;
				case 4:
					cout << "Win the lottery. " << lander->GetName() << " gains " << POUND << LOTTERY << endl;
					lander->Credit(LOTTERY);
					break;
				case 5:
					cout << "Recieve a bequest. " << lander->GetName() << " gains " << POUND << BEQUEST  << endl;
					lander->Credit(BEQUEST);
					break;
				case 6:
					cout << "It's your birthday. " << lander->GetName() << " gains " << POUND << BIRTHDAY  << endl;
					lander->Credit(BIRTHDAY);
					break;
				default:
					cout << "Wait, what? How did DiceRoll() output something that isn't 1-6?" << endl;
					break;
			}// end bonus switch
			break;
		case PENALTY:
			switch( Game::DiceRoll() )
			{
				case 1:
					cout << "Pay food bill. " << lander->GetName() << " loses " << POUND << FOOD_BILL << endl;
					lander->Debit(FOOD_BILL);
					break;
				case 2:
					cout << "Pay phone bill. " << lander->GetName() << " loses " << POUND << PHONE_BILL << endl;
					lander->Debit(PHONE_BILL);
					break;
				case 3:
					cout << "Pay heating bill. " << lander->GetName() << " loses " << POUND << HEAT_BILL << endl;
					lander->Debit(HEAT_BILL);
					break;
				case 4:
					cout << "Pay vehicle tax. " << lander->GetName() << " loses " << POUND << V_TAX << endl;
					lander->Debit(V_TAX);
					break;
				case 5:
					cout << "Pay fuel bill. " << lander->GetName() << " loses " << POUND << FUEL_BILL << endl;
					lander->Debit(FUEL_BILL);
					break;
				case 6:
					cout << "Pay windfall tax. " << lander->GetName() << " loses " << POUND << WIND_TAX << endl;
					lander->Debit(WIND_TAX);
					break;
				default:
					cout << "Wait, what? How did DiceRoll() output something that isn't 1-6?" << endl;
					break;
			}//end penalty switch
			break;
		case JAIL:
			cout << "Just Visiting" << endl;
			break;
		case GO_TO_JAIL:
			lander->GoToJail();
			cout << lander->GetName() << " goes to Jail" << endl;
			cout << lander->GetName() << " pays " << POUND << JAIL_COST << endl;
			lander->Debit(JAIL_COST);
			break;
		case FREE_PARKING:
			cout << lander->GetName() << " is just resting. " << endl;
			break;
		default:
			cout << "Oh dear, this square has no idea what it is. That can't be a good sign." << endl;
			break;
	}
}

void SpecialSquare::SetGroupMember(int index, Square* member)
{
	cout << "If you are reading this, something went wrong!" << endl;
}

int SpecialSquare::GetType()
{
	return squareType;
}

