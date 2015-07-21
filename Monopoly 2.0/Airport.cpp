#include "Airport.h"


Airport::Airport(string fileInput)
{
	SetName(fileInput);
	SetOwner();
}


Airport::~Airport(void)
{
}

void Airport::PlayerLanded(Player* lander)
{
	//retrieve square owner for later. 
	Player* owner = GetOwner();

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

}

void Airport::SetGroupMember(int index, Square* member)
{
	cout << "If you are reading this, something went wrong!" << endl;
}