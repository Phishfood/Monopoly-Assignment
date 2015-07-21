#include "Street.h"
#include <string>

Street::Street(string fileInput)
{
	//initialise owner to null
	SetOwner();

	//extract the name from the string
	size_t found,found2;
	found = fileInput.find_first_of("0123456789");
	SetName( fileInput.substr(0, found-1) );

	string integers[3], data;

	data = fileInput.substr(found);
	
	found = data.find_first_of(" ");
	integers[0] = data.substr(0,found);

	found2 = data.find_first_of(" ", found+1);
	integers[1] =  data.substr(found,(found2-found));

	found = data.find_first_of(" ", found2+1);
	integers[2] =  data.substr(found2,(found-found2));

	buyCost = stoi(integers[0]);
	rentCost = stoi(integers[1]);
	colourGroup = stoi(integers[2]);

	//initialise group pointers
	for(int i = 0; i < MAX_GROUP_SZIE; i++)
	{
		groupProperties[i] = nullptr;
	}
}


Street::~Street(void)
{
}

void Street::PlayerLanded(Player* lander)
{
	Player* owner = GetOwner();
	if(owner == 0 || owner == NULL)
	{
		if(lander->GetBalance() > 0)
		{
			lander->Debit(buyCost);
			SetOnwer(lander);
			cout << lander->GetName() << " bought " << GetName() << " for " << POUND << buyCost << endl;
		}
	}
	else if(lander != owner )
	{
		//check for group ownership
		bool ownsGroup = true;			//assume they do until proven otherwise
		for( int i = 0; i < MAX_GROUP_SZIE; i++ )
		{
			if( groupProperties[i] != nullptr && groupProperties[i] != 0)			//check for null - not all groups have 3. 
			{
				if( groupProperties[i]->GetOwner() != owner )		//compare owner of group street with owner of current street. I
				{													//if they don't match, break.
					ownsGroup = false;
					break;
				}
			}
		}

		if(ownsGroup)
		{					// double rent
			lander->Debit(2 * rentCost);
			owner->Credit(2 * rentCost);
			cout << lander->GetName() << " pays " << POUND << 2 * rentCost << " double rent costs." << endl;
		}
		else
		{					// single rent
			lander->Debit(rentCost);
			owner->Credit(rentCost);
			cout << lander->GetName() << " pays " << POUND << rentCost << " rent costs." << endl;
		}
		
	}
}

int Street::GetColour()
{
	return colourGroup;
}

 void Street::SetGroupMember(int index, Square* member)
{

	groupProperties[index] = member;
}