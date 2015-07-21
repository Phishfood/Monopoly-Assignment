#include "Go.h"


Go::Go(string fileInput)
{
	SetName(fileInput);
	SetOwner();
}


Go::~Go(void)
{
}

void Go::PlayerLanded(Player* lander)
{
	lander->PassGo();
}

void Go::SetGroupMember(int index, Square* member)
{
	cout << "If you are reading this, something went wrong!" << endl;
}

