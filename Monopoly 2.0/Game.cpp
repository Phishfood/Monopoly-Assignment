#include "Game.h"			//class definiton

#include <fstream>			//file reading

/*************************************************
***		CONSTRUCTORS AND DESTRUCTOR				**
*************************************************/

Game::Game(string seedFilePath, string squaresFilePath, int numPlayers, int numTurns)
{
	ifstream seedFile, squaresFile;
	
	//read in seed from file. 
	seedFile.open(seedFilePath);
	if( seedFile.is_open() ) 
	{
		seedFile >> seed;
	}
	else
	{
		cout << "Error reading the seed!" << endl;
	}

	seedFile.close();

	srand( seed );

	//read in the board from a file
	squaresFile.open(squaresFilePath);		//open the file
	if( squaresFile.is_open() )				//check for success
	{
		string buffer;
		size_t found;
		Square* newSquare;
		squareCount = 0;
		while ( !squaresFile.eof() )			//load 26 squares hopefully
		{
			getline(squaresFile, buffer); // I would use squaresFile.getLine() but using a string rather than a char* makes the next bit much easier. 
			
			//check for digits
			found = buffer.find_first_of("0123456789");

			if(found == string::npos)		//no digits - special square.
			{
				if( buffer.compare("GO") == 0 )
				{
					newSquare = new Go(buffer);
				}
				else if( buffer.compare("Bonus") == 0  )
				{
					newSquare = new Bonus(buffer);
				}
				else if( buffer.compare("Penalty")  == 0 )
				{
					newSquare = new Penalty(buffer);
				}
				else if( buffer.compare("Jail") == 0 )
				{
					newSquare = new Jail(buffer);
				}
				else if( buffer.compare("Go to Jail") == 0  )
				{
					newSquare = new GoToJail(buffer);
				}
				else if( buffer.compare("Free Parking") == 0  )
				{
					newSquare = new FreeParking(buffer);
				}
				else
				{
					if(buffer.length() > 9)
					{
						string temp = buffer.substr( buffer.length() - 7);
						if( temp.compare("Airport")  == 0 )
						{
							newSquare = new Airport(buffer);
						}
					}
				}
				//newSquare = new SpecialSquare(buffer);
				//cout << "NEW: " << newSquare << buffer << endl;
			}
			else							//digits - make a street square. 
			{
				newSquare = new Street(buffer);
				//cout << "NEW: " << newSquare << buffer << endl;
			}

			//put the square onto the list.
			boardList.push_back(newSquare);
			squareCount++;
		}
	}
	else
	{
		cout << "error reading the board!" << endl;
	}
	//now link the streets into groups for double rent
	LinkStreets();

	//create the players.
	if(numPlayers > MAX_PLAYERS)		//cap to maximum.
	{
		numPlayers = MAX_PLAYERS;
	}
	//set the player count.
	playerCount = numPlayers;

	//initialise the players.
	for( int i = 0; i < numPlayers; i++ ){
		players[i] = new Player(PIECES[i]);
	}

	//set the turn count
	if( numTurns > MAX_TURNS)	//cap to maximum
	{
		numTurns = MAX_TURNS;
	}
	turnCount = numTurns;

}


Game::~Game(void)
{
	list<Square*>::iterator it;
	it = boardList.begin();
	while(it != boardList.end())
	{
		delete (*it);
		it = boardList.erase(it);
	}
	for(int i = 0; i < playerCount; i++ )
	{
		delete players[i];
	}
}

/*************************************************
***		HELPERS 								**
*************************************************/

int Game::DiceRoll()
{
	return static_cast<int>( static_cast<double> (rand()) / (RAND_MAX + 1) * 6.0f + 1 );
}

void Game::LinkStreets()
{
	int lastColour = -1;	//last colour found
	int currentColour = -1;	//colour of the current square
	
	Square* group[MAX_GROUP_SZIE];	//pointers to the whole group

	//initialise pointers
	for (int i = 0; i < MAX_GROUP_SZIE; i++)
	{
		group[i] = 0;
	}

	int membersFound = 0;	//number of members of the group found so far.
	
	list<Square*>::iterator it = boardList.begin();
	while ( it != boardList.end() )	//search all squares linear
	{
		currentColour = (*it)->GetColour();	//save the colour of the current square, we need it several times
		if( currentColour >= 0 )	//if the square has a colour, act. Else ignore it.
		{
			if( lastColour == currentColour )
			{
				//current group
				//store the pointer for group processing.
				group[membersFound] = (*it);
				membersFound++;

			}
			else
			{
				//new group
				
				//complete old group
				for( int i = 0; i < membersFound; i++ )
				{
					for( int j = 0; j < membersFound; j++ )
					{
						group[i]->SetGroupMember(j, group[j]);
					}
				}
				//reset pointers
				for( int i = 0; i < MAX_GROUP_SZIE; i++)
				{
					group[i] = 0;
				}

				//set the colour ready for the new group
				lastColour = currentColour;

				//set the first pointer
				group[0] = (*it);
				//reset the counter
				membersFound = 1;
			}
		}
		it++;
	}

	//catch the last group on the board. No need to reset anything here.
	for( int i = 0; i < membersFound; i++ )
	{
		for( int j = 0; j < membersFound; j++ )
		{
			group[i]->SetGroupMember(j, group[j]);
		}
	}

}


/*************************************************
***		GAMEPLAY								**
*************************************************/

void Game::PlayTurn(){
	for(int i = 0; i < playerCount; i++ )
	{
		MovePlayer(players[i]);
	}
}

void Game::MovePlayer(Player* player)
{
	int position = player->GetPosition();	//get the old position
	int roll = DiceRoll();

	cout << endl << player->GetName() << " rolls " << roll << endl;

	position += roll;					//add a dice roll to it
	if( position >= squareCount )			//check for "overflow"
	{
		position %= squareCount;			//bring back in range of the board
		if(position != 0)					//if not landed on go (ie, passed go).. Landing on Go is handled by the GO square.
		{
			player->PassGo();
		}
	}

	player->SetPosition(position);

	//call the right function for the square landed on.
	list<Square*>::iterator it;
	it = boardList.begin();
	for(int i = 0; i < position; i++)
	{
		it++;
	}

	cout << player->GetName() << " lands on " << (*it)->GetName() << endl;

	(*it)->PlayerLanded(player);

	cout << player->GetName() << " has balance ";
	player->DisplayBalance();
	cout << endl;

}

void Game::PlayGame()
{
	for( int i = 0; i < turnCount; i++ ){
		cout << endl;
		cout << "*************************" << endl;
		printf( "*         Turn %2d       *\n", i);
		cout << "*************************" << endl;
		PlayTurn();
		system("pause");
	}
}