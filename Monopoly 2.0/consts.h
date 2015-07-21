#pragma once;


//memory leak detection.
#ifdef _DEBUG   
#ifndef DBG_NEW      
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )      
#define new DBG_NEW   
#endif
#endif  // _DEBUG

//standard classes
#include <string>
#include <iostream>
using namespace std;

//game config and arrays
const int MAX_PLAYERS = 10;
const int MAX_SQUARES = 40;
const int MAX_TURNS = 100;
const int MAX_STRING = 255;
const int MAX_GROUP_SZIE = 3;

//allow output of pound sign. 
const char POUND = 156;

//////////////////////
//  GAME RULES		//
//////////////////////

//general special square values
const int GO_MONEY = 200;
const int AIRPORT_COST = 200;
const int FLY_COST = 10;

//penalty costs
const int FOOD_BILL = 20;
const int PHONE_BILL = 50;
const int HEAT_BILL = 100;
const int V_TAX = 150;
const int FUEL_BILL = 200;
const int WIND_TAX = 300;

const int JAIL_COST = 50;

//bonus payouts
const int FIND_MONEY = 20;
const int WIN_MONEY = 50;
const int TAX_REBATE = 100;
const int LOTTERY = 150;
const int BEQUEST = 200;
const int BIRTHDAY = 300;

//special square types
enum SpecialTypes 
{
	GO,
	AIRPORT,
	BONUS,
	PENALTY,
	JAIL,
	GO_TO_JAIL,
	FREE_PARKING
};

const string PIECES[] = {	"Dog",
							"Car",
							"Iron",
							"Hat",
							"Ship", 
							"Hotel",
							"House",
							"Monacle",
							"Football",
							"Dollar Sign"
						};