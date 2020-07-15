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

enum pokemonTypes
{
	//Pokemon and their moves are assigned certain types. These types have several strengths and weaknesses in both offense and defense.
	NoneT, normal, fire, water, electrc, grass, ice, fight, poison, ground, flying, psychic, bug, rock, ghost, dragon, dark, steel, fairy
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
	phys,
	spec,
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
	pokemonTypes moveType;
	moveCategory moveKind;
	int basePower;
	int accuracy;
	int PP;
};

struct Pokemon			//Properties of the actual Pokemon 
{
	string pokemonName;
	pokemonStats stats;
	vector <pokemonTypes> userType;
	vector<pokemonTMHM> userMoves;
	pokemonStatusConditions0 statusBefore;
	pokemonStatusConditions1 statusAfter;
};

//CLASS
class pokemonDb
{
public:		//data types
	vector <Pokemon> pokemonRoster;
	vector <pokemonTMHM> moveRoster;
	
public:		//function types
	void weatherReport(int& weather_life, bool change_weather, pokemonWeather& weather);
	pokemonDb();


private:	//data types
	vector <int> tempType;
	int weather_life;
	pokemonWeather weather;

private:	//function types
	pokemonTypes int_to_type(int tempType);

};

