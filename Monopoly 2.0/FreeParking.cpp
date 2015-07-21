#include "FreeParking.h"


FreeParking::FreeParking(string fileInput)
{
	SetName(fileInput);
	SetOwner();
}


FreeParking::~FreeParking(void)
{
}

void FreeParking::PlayerLanded(Player* lander)
{
	cout << lander->GetName() << " is just resting. " << endl;
}

void FreeParking::SetGroupMember(int index, Square* member)
{
	cout << "If you are reading this, something went wrong!" << endl;
}

