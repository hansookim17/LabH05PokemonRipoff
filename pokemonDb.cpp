#include "pokemonDb.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

pokemonDb::pokemonDb()
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