//	Name:	LabH05PokemonRipoff
//	Author:	Hansoo Kim
//	Date:	27 June 2020
//

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "pokemonDb.h"

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
	paralysis, confusion, infatuation, freeze, sleep
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
public:
	pokemonDb()
	{
		//This constructor establishes as a database for Pokemon
		int gen;
		ifstream pokemonRosterFile;

		pokemonRosterFile.open("pokemonRoster.txt.");

		cout << "How many generations of Pokemon would you like to include? ";
		cin >> gen;


		if (gen == 1)		//Collects all Pokemon data up to Generation I
		{
			pokemonRoster.resize(151);

			for (int i = 1; i <= 151; i++)
			{
				pokemonRoster[i - 1].userType.resize(2);
				pokemonRosterFile >> pokemonRoster[i - 1].pokemonName >> pokemonRoster[i - 1].stats.health >> pokemonRoster[i - 1].stats.attack >> pokemonRoster[i - 1].stats.defense >> pokemonRoster[i - 1].stats.spAttack >> pokemonRoster[i - 1].stats.spDefense >> pokemonRoster[i - 1].stats.speed >> pokemonRoster[i - 1].userType[0] >> pokemonRoster[i - 1].userType[1];
			}
		}
		else if (gen == 2)	//Collects all Pokemon data up to Generation II
		{
			pokemonRoster.resize(251);
			for (int i = 1; i <= 251; i++)
			{
				pokemonRoster[i - 1].userType.resize(2);
				pokemonRosterFile >> pokemonRoster[i - 1].pokemonName >> pokemonRoster[i - 1].stats.health >> pokemonRoster[i - 1].stats.attack >> pokemonRoster[i - 1].stats.defense >> pokemonRoster[i - 1].stats.spAttack >> pokemonRoster[i - 1].stats.spDefense >> pokemonRoster[i - 1].stats.speed >> pokemonRoster[i - 1].userType[0] >> pokemonRoster[i - 1].userType[1];
			}
		}
		else if (gen == 3)	//Collects all Pokemon data up to Generation III
		{
			pokemonRoster.resize(386);
			for (int i = 1; i <= 251; i++)
			{
				pokemonRoster[i - 1].userType.resize(2);
				pokemonRosterFile >> pokemonRoster[i - 1].pokemonName >> pokemonRoster[i - 1].stats.health >> pokemonRoster[i - 1].stats.attack >> pokemonRoster[i - 1].stats.defense >> pokemonRoster[i - 1].stats.spAttack >> pokemonRoster[i - 1].stats.spDefense >> pokemonRoster[i - 1].stats.speed >> pokemonRoster[i - 1].userType[0] >> pokemonRoster[i - 1].userType[1];
			}
		}
		else if (gen == 4)	//Collects all Pokemon data up to Generation IV
		{
			pokemonRoster.resize(493);
			for (int i = 1; i <= 493; i++)
			{
				pokemonRoster[i - 1].userType.resize(2);
				pokemonRosterFile >> pokemonRoster[i - 1].pokemonName >> pokemonRoster[i - 1].stats.health >> pokemonRoster[i - 1].stats.attack >> pokemonRoster[i - 1].stats.defense >> pokemonRoster[i - 1].stats.spAttack >> pokemonRoster[i - 1].stats.spDefense >> pokemonRoster[i - 1].stats.speed >> pokemonRoster[i - 1].userType[0] >> pokemonRoster[i - 1].userType[1];
			}
		}


		pokemonRosterFile.close();



	}

};

int main()
{
	pokemonDb nice;
	system("pause");
	return 0;
}








