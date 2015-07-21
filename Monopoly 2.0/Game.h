#pragma once
//constants
#include "consts.h"

//#include "SpecialSquare.h"
#include "Airport.h"
#include "Bonus.h"
#include "FreeParking.h"
#include "Go.h"
#include "GoToJail.h"
#include "Jail.h"
#include "Penalty.h"
#include "Street.h"
#include "Player.h"

//standard includes
#include <list>				//list STL for squares

//my classes.

class Game
{
private:
	int seed;			//seed for the random number generator.
	int playerCount;	//number of players in the game.
	int squareCount;	//number of squares on the board.
	int turnCount;
	list<Square*> boardList;
	Player* players[MAX_PLAYERS];

public:
	//constructors and destructor
	Game(string seedFilePath, string squaresFilePath, int numPlayers, int numTurns);
	~Game(void);

	//helpers
	void LinkStreets();
	static int DiceRoll();

	//gameplay
	void PlayTurn();
	void MovePlayer(Player* player);
	void PlayGame();

};

