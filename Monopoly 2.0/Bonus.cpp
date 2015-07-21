#include "Bonus.h"
#include "Game.h"


Bonus::Bonus(string fileInput)
{
	SetName(fileInput);
	SetOwner();
}


Bonus::~Bonus(void)
{
}

void Bonus::PlayerLanded(Player* lander)
{
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
}

void Bonus::SetGroupMember(int index, Square* member)
{
	cout << "If you are reading this, something went wrong!" << endl;
}

