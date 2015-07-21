#include "Penalty.h"
#include "Game.h"

Penalty::Penalty(string fileInput)
{
	SetName(fileInput);
	SetOwner();
}


Penalty::~Penalty(void)
{
}

void Penalty::PlayerLanded(Player* lander)
{

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
	
}

void Penalty::SetGroupMember(int index, Square* member)
{
	cout << "If you are reading this, something went wrong!" << endl;
}

