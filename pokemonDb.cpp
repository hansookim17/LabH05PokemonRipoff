#include "pokemonDb.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

//PUBLIC CLASSES + CONSTRUCTOR

void pokemonDb::weatherReport(int& weather_life, bool change_weather, pokemonWeather& weather)
{
	if (change_weather == true)
	{
		weather_life = 5;
	}
}

pokemonDb::pokemonDb()
{
	//This constructor establishes a database for Pokemon.
	int gen = 5;
	ifstream pokemonRosterFile;

	//STEP ONE: COLLECT POKEMON INFORMATION (complete)
	pokemonRosterFile.open("pokemonRoster.txt.");
	while (!(gen >= 1 && gen <= 4))
	{
		cout << "How many generations of Pokemon would you like to include? \n";
		cout << "Includes up to Generation IV \n" << "Generation: ";
		cin >> gen;


		//We cannot use enums in fstreams so we have to counteract that issue.

		if (gen == 1)		//Collects all Pokemon data up to Generation I
		{
			pokemonRoster.resize(151);
			tempType.resize(2);

			for (int i = 1; i <= 151; i++)
			{
				pokemonRoster[i - 1].userType.resize(2);
				pokemonRosterFile >> pokemonRoster[i - 1].pokemonName >> pokemonRoster[i - 1].stats.health >> pokemonRoster[i - 1].stats.attack >> pokemonRoster[i - 1].stats.defense >> pokemonRoster[i - 1].stats.spAttack 
					>> pokemonRoster[i - 1].stats.spDefense >> pokemonRoster[i - 1].stats.speed >> tempType[0] >> tempType[1];
				pokemonRoster[i - 1].userType[0] = (pokemonTypes)tempType[0];
				pokemonRoster[i - 1].userType[1] = (pokemonTypes)tempType[1];
			}
		}
		else if (gen == 2)	//Collects all Pokemon data up to Generation II
		{
			pokemonRoster.resize(251);
			for (int i = 1; i <= 251; i++)
			{
				pokemonRoster[i - 1].userType.resize(2);
				pokemonRosterFile >> pokemonRoster[i - 1].pokemonName >> pokemonRoster[i - 1].stats.health >> pokemonRoster[i - 1].stats.attack >> pokemonRoster[i - 1].stats.defense >> pokemonRoster[i - 1].stats.spAttack
					>> pokemonRoster[i - 1].stats.spDefense >> pokemonRoster[i - 1].stats.speed >> tempType[0] >> tempType[1];
				pokemonRoster[i - 1].userType[0] = (pokemonTypes)tempType[0];
				pokemonRoster[i - 1].userType[1] = (pokemonTypes)tempType[1];
			}
		}
		else if (gen == 3)	//Collects all Pokemon data up to Generation III
		{
			pokemonRoster.resize(386);
			for (int i = 1; i <= 251; i++)
			{
				pokemonRoster[i - 1].userType.resize(2);
				pokemonRosterFile >> pokemonRoster[i - 1].pokemonName >> pokemonRoster[i - 1].stats.health >> pokemonRoster[i - 1].stats.attack >> pokemonRoster[i - 1].stats.defense >> pokemonRoster[i - 1].stats.spAttack 
					>> pokemonRoster[i - 1].stats.spDefense >> pokemonRoster[i - 1].stats.speed >> tempType[0] >> tempType[1];
				pokemonRoster[i - 1].userType[0] = (pokemonTypes)tempType[0];
				pokemonRoster[i - 1].userType[1] = (pokemonTypes)tempType[1];
			}
		}
		else if (gen == 4)	//Collects all Pokemon data up to Generation IV
		{
			pokemonRoster.resize(493);
			for (int i = 1; i <= 493; i++)
			{
				pokemonRoster[i - 1].userType.resize(2);
				pokemonRosterFile >> pokemonRoster[i - 1].pokemonName >> pokemonRoster[i - 1].stats.health >> pokemonRoster[i - 1].stats.attack >> pokemonRoster[i - 1].stats.defense >> pokemonRoster[i - 1].stats.spAttack 
					>> pokemonRoster[i - 1].stats.spDefense >> pokemonRoster[i - 1].stats.speed >> tempType[0] >> tempType[1];
				pokemonRoster[i - 1].userType[0] = (pokemonTypes)tempType[0];
				pokemonRoster[i - 1].userType[1] = (pokemonTypes)tempType[1];
			}
		}
		else
			cout << "Invalid response: Try again. \n";

		tempType.clear();
	}
	pokemonRosterFile.close();

	//STEP TWO: COLLECT MOVE INFORMATION	(incomplete)
	pokemonRosterFile.open("pokemonMoves.txt");
	while (4 == 4) //This while-statement is extraneous beyond the purpose of conventional/visual organization
	{
		tempType.resize(1);
		if (gen == 1)
		{
			moveRoster.resize(165);

			for (int i = 0; i < 165; i++)
			{

			}
		}
		else if (gen == 2)
		{
			moveRoster.resize(250);

			for (int i = 0; i < 250; i++)
			{

			}
		}
		else if (gen == 3)
		{
			moveRoster.resize(353);

			for (int i = 0; i < 353; i++)
			{

			}
		}
		else if (gen == 4)
		{
			moveRoster.resize(466);

			for (int i = 0; i < 466; i++)
			{

			}
		}
	}
	pokemonRosterFile.close();


}

//PRIVATE CLASSES

pokemonTypes pokemonDb::int_to_type(int tempType)
{
	if (tempType == 0)		//int = 0
		return NoneT;
	else if (tempType == 1)	//int = 1
		return normal;
	else if (tempType == 2)	//int = 2
		return fire;
	else if (tempType == 3)	//int = 3
		return water;
	else if (tempType == 4)	//int = 4
		return electrc;
	else if (tempType == 5)	//int = 5
		return grass;
	else if (tempType == 6)		//int = 6
		return ice;
	else if (tempType == 7)	//int = 7
		return fight;
	else if (tempType == 8)	//int = 8
		return poison;
	else if (tempType == 9)	//int = 9
		return ground;
	else if (tempType == 10)	//int = 10
		return flying;
	else if (tempType == 11)	//int = 11
		return psychic;
	else if (tempType == 12)		//int = 12
		return bug;
	else if (tempType == 13)	//int = 13
		return rock;
	else if (tempType == 14)	//int = 14
		return ghost;
	else if (tempType == 15)	//int = 15
		return dragon;
	else if (tempType == 16)	//int = 16
		return dark;
	else if (tempType == 17)	//int = 17
		return steel;
}