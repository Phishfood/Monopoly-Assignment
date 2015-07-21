#include "GoToJail.h"


GoToJail::GoToJail(string fileInput)
{
	SetName(fileInput);
	SetOwner();
}


GoToJail::~GoToJail(void)
{
}

void GoToJail::PlayerLanded(Player* lander)
{
	lander->GoToJail();
	cout << lander->GetName() << " goes to Jail" << endl;
	cout << lander->GetName() << " pays " << POUND << JAIL_COST << endl;
	lander->Debit(JAIL_COST);
}

void GoToJail::SetGroupMember(int index, Square* member)
{
	cout << "If you are reading this, something went wrong!" << endl;
}

