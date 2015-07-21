#include "Jail.h"


Jail::Jail(string fileInput)
{
	SetName(fileInput);
	SetOwner();
}


Jail::~Jail(void)
{
}

void Jail::PlayerLanded(Player* lander)
{
	cout << "Just Visiting" << endl;
}

void Jail::SetGroupMember(int index, Square* member)
{
	cout << "If you are reading this, something went wrong!" << endl;
}

