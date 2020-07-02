#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

//LIST OF ENUMERATIONS
enum pokemonWeather
{
	clear, sunlight, rain, hail, sandstorm
};

enum pokemonTypes_preGen6
{
	//Pokemon and their moves are assigned certain types. These types have several strengths and weaknesses in both offense and defense.
	NoneT, normal, fire, water, electrc, grass, ice, fight, poison, ground, flying, psychic, bug, rock, ghost, dragon, dark, steel
};

enum pokemonStatusConditions0
{
	none0,
	paralysis, confusion, infatuation, freeze, sleepS
};

enum pokemonStatusConditions1
{
	none1,
	poison1, burn, curse
};

enum moveCategory
{
	physical,
	special,
	status
};


//LIST OF STRUCTS
struct pokemonStats
{
	int health;
	int attack;
	int defense;
	int spAttack;
	int spDefense;
	int speed;
};

struct pokemonTMHM		//Properties of moves a Pokemon makes
{
	string userName;
	pokemonTypes_preGen6 moveType;
	moveCategory moveKind;
	int basePower;
	int accuracy;
	int PP;
};

struct Pokemon			//Properties of the actual Pokemon 
{
	string pokemonName;
	pokemonStats stats;
	vector<pokemonTypes_preGen6> userType;
	vector<pokemonTMHM> userMoves;
	pokemonStatusConditions0 statusBefore;
	pokemonStatusConditions1 statusAfter;
};

//CLASS
class pokemonDb
{
public:
	vector <Pokemon> pokemonRoster;
	pokemonDb();
};
