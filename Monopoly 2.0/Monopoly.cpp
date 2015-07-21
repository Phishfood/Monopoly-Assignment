#include "consts.h"		//global constants.
#include "Game.h"		//main game class.

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

void TestFeatures();

int main (){
	cout << "Welcome to Monopoly" << endl << endl;

	int players, turns;

	cout << "How many players would you like?" << endl;
	cin >> players;

	cout << "How many turns would you like?" << endl;
	cin >> turns;

	Game* myGame = new Game("seed.txt", "Monopoly.txt", players, turns);

	myGame->PlayGame();

	delete myGame;

	TestFeatures();

	system("pause");
	_CrtDumpMemoryLeaks();
	return 0;
}


void TestFeatures(){
	//Unit testing regieme. 
	// 1) Creating squares			//done
	// 2) Penalty/bonus squares.	//done
	// 3) Airpots					//done
	// 3a) Buying					//done
	// 3b) Paying costs				//done
	// 4) Streets					//done
	// 4a) Buying					//done
	// 4b) Paying rent				//done
	// 4c) Full set rent			//done
	// 5) Dicerolls.				//done
	// 6) Go square.				//done
	// 7) Jail square.				//done
	// 7a) Fine						//done
	// 7b) Changing location		//N/A
	// 7c) Visiting

	int errorCount = 0;

	Square* testSquares[10];
	Player* testPlayers[4];

	//name buy rent colour
	//Red Road 60 5 0

	//TEST 1: CREATING SQUARES
	cout << "******************************" << endl;
	cout << "* TESTING SQUARE CREATION    *" << endl;
	cout << "******************************" << endl;

	testSquares[0] = new Go ("GO");
	testSquares[1] = new Street ("Red Lead 60 5 0");
	testSquares[2] = new Street ("Red Two 70 6 0");
	testSquares[3] = new Street ("Red Three 80 7 0");
	testSquares[4] = new Bonus ("Bonus");
	testSquares[5] = new Penalty ("Penalty");
	testSquares[6] = new Jail ("Jail");
	testSquares[7] = new GoToJail ("Go to Jail");
	testSquares[8] = new Airport ("Blackpool Airport");
	testSquares[9] = new FreeParking ("Free Parking");


	//group Red Lead with it's friends
	testSquares[1]->SetGroupMember(0, testSquares[1]);
	testSquares[1]->SetGroupMember(1, testSquares[2]);
	testSquares[1]->SetGroupMember(2, testSquares[3]);


	cout << endl << "All squares created, errors in square creation will be displayed below: " << endl;

	//compare the square's internal type with the expected type. IF they differ, error. 
	if( testSquares[0]->GetType() != GO )
	{
		cout << "GO Square created itself incorrectly!" << endl;
		errorCount++;
	}

	//streets return -1, not needing the smae type 
	if( testSquares[1]->GetType() != -1 )
	{
		cout << "Red Lead created itself incorrectly!" << endl;
		errorCount++;
	}

	//check internal values match - colour
	if(testSquares[1]->GetColour() != 0 )
	{
		cout << "Red Lead isn't red!" << endl;
		errorCount++;
	}

	// price
	if( testSquares[1]->GetBuyCost() != 60 )
	{
		cout << "Red Lead has the wrong Buy Cost" << endl;
		errorCount++;
	}
	
	//rent
	if( testSquares[1]->GetRentCost() != 5 )
	{
		cout << "Red Lead has the wrong rent!" << endl;
		errorCount++;
	}
	//assume if the first worked, the other two can't have failed. 


	//checking the remainder of the special squares.
	if( testSquares[4]->GetType() != BONUS )
	{
		cout << "Bonus Square created itself incorrectly!" << endl;
		errorCount++;
	}


	if( testSquares[5]->GetType() != PENALTY )
	{
		cout << "Penalty Square created itself incorrectly!" << endl;
		errorCount++;
	}


	if( testSquares[6]->GetType() != JAIL )
	{
		cout << "Jail Square created itself incorrectly! Send it to jail!" << endl;
		errorCount++;
	}


	if( testSquares[7]->GetType() != GO_TO_JAIL )
	{
		cout << "Go To Jail Square created itself incorrectly! Bad cop, no donut!" << endl;
		errorCount++;
	}


	if( testSquares[8]->GetType() != AIRPORT )
	{
		cout << "Airport Square created itself incorrectly!" << endl;
		errorCount++;
	}


	if( testSquares[9]->GetType() != FREE_PARKING )
	{
		cout << "Free Parking Square created itself incorrectly!" << endl;
		errorCount++;
	}

	testPlayers[0] = new Player("Alice");
	testPlayers[1] = new Player("Bob");
	testPlayers[2] = new Player("Charlie");
	testPlayers[3] = new Player("Dave");

	//TEST 2-4 - ensuring that players buy squares correctly and pay rent correctly. 
	cout << "******************************" << endl;
	cout << "* TESTING SQUARE INTERACTION *" << endl;
	cout << "******************************" << endl;
	cout << endl;

	cout << "Testing penalties on unowned squares, errors will be listed." << endl;

	int oldBalancePlayer;		//save the balances for reference
	int oldBalanceOwner;		


	//Test the Bonus Square

	//save the starting balance
	oldBalancePlayer = testPlayers[0]->GetBalance();
	//activate the square - should see correct output for bonus square
	cout << "Next line should indicate bonus payment." << endl;
	testSquares[4]->PlayerLanded( testPlayers[0] );

	//ensure balance has increased. Can't test for exact ammount without breaking the sequence of the RNG in the real app.
	if(testPlayers[0]->GetBalance() <= oldBalancePlayer)
	{
		cout << "No bonus paid out. " << endl;
		errorCount++;
	}

	cout << endl << endl;

	// Test the Penalty Square

	oldBalancePlayer = testPlayers[0]->GetBalance();
	//activate the square - should see the correct output for penalty square
	cout << "Next line should indicate penalty payment." << endl;
	testSquares[5]->PlayerLanded( testPlayers[0] );

	if(testPlayers[0]->GetBalance() >= oldBalancePlayer)
	{
		cout << "No penalty issued. " << endl;
		errorCount++;
	}

	cout << endl << endl;

	// Test the Go To Jail Square

	oldBalancePlayer = testPlayers[0]->GetBalance();

	//activate the square - should see the correct output for jail square
	cout << "Next line should indicate player has gone to jail." << endl;
	testSquares[7]->PlayerLanded( testPlayers[0] );

	if(testPlayers[0]->GetBalance() >= oldBalancePlayer)
	{
		cout << "No bail issued. " << endl;
		errorCount++;
	}

	cout << endl << endl;

	// Test the Airport

	oldBalancePlayer = testPlayers[0]->GetBalance();
	cout << "Next line should indicate player has gone to the airport" << endl;
	testSquares[8]->PlayerLanded( testPlayers[0] );
	if(testPlayers[0]->GetBalance() >= oldBalancePlayer)
	{
		cout << "No ticket issued. " << endl;
		errorCount++;
	}

	//Test a street purchase. Player should buy the street and pay the appropriate price
	oldBalancePlayer = testPlayers[0]->GetBalance();

	cout << "Next line should indicate the player has bought Red Lead" << endl;
	testSquares[1]->PlayerLanded( testPlayers[0] );
	if(testPlayers[0]->GetBalance() >= oldBalancePlayer)
	{
		cout << "Street not paid for. " << endl;
		errorCount++;
	}


	cout << endl << endl;

	//Test rent payment - Bob should pay rent to Alice. 
	oldBalancePlayer = testPlayers[1]->GetBalance();
	oldBalanceOwner = testPlayers[0]->GetBalance();

	cout << "Next line should indicate Bob has paid  regular rent to Alice for Red Lead" << endl;
	testSquares[1]->PlayerLanded( testPlayers[1] );

	if(testPlayers[0]->GetBalance() <= oldBalanceOwner)
	{
		cout << "Owner did not recieve rent!" << endl;
		errorCount++;
	}

	if(testPlayers[1]->GetBalance() >= oldBalancePlayer)
	{
		cout << "Player did not pay rent!" << endl;
		errorCount++;
	}

	cout << endl << endl;

	//test street grouping for double rent
	cout << endl << endl;

	cout << "Next lines should indicate Alice buys Red Two and Three" << endl;

	testSquares[2]->PlayerLanded(testPlayers[0]);
	testSquares[3]->PlayerLanded(testPlayers[0]);

	oldBalancePlayer = testPlayers[1]->GetBalance();
	oldBalanceOwner = testPlayers[0]->GetBalance();

	cout << "Alice now owns all three red streets, Bob should pay double rent." << endl;

	testSquares[1]->PlayerLanded(testPlayers[1]);

	if(testPlayers[0]->GetBalance() <= oldBalanceOwner)
	{
		cout << "Owner did not recieve rent!" << endl;
		errorCount++;
	}

	if(testPlayers[1]->GetBalance() >= oldBalancePlayer)
	{
		cout << "Player did not pay rent!" << endl;
		errorCount++;
	}

	cout << "******************************" << endl;
	cout << "* TESTING DICE ROLLS		  *" << endl;
	cout << "******************************" << endl;


	//Part 5) Testing Dicerolls. 
	cout << "Testing the dice" << endl;
	int diceTemp;
	for(int i = 0; i < 100; i++)
	{
		diceTemp = Game::DiceRoll();
		if( diceTemp > 0 && diceTemp < 7 )
		{
			cout << diceTemp << " , ";
		}
		else
		{
			cout << endl << "Diceroll out of range!" << diceTemp << endl;
			errorCount++;
			break;
		}
	}
	cout << endl;
}