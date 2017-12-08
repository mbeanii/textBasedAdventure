#pragma once

#ifndef TEXT_BASED_ADVENTURE_HEADER
#define TEXT_BASED_ADVENTURE_HEADER

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stdlib.h>
#include <time.h>

#include "Character.h"

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::map;

//PROTOTYPES

struct AttributeList;
struct Item;
struct CharacterList;
struct Location;
struct LocationList;
struct CommandList;
struct Game;

//DEFINITIONS

struct AttributeList
{
	int strength = 0;
	int speed = 0;
	int smarts = 0;
};

// Eventually, every item I may want more than one of will have its own class via inheritance. 
struct Item
{
	int identifier = 0;
	string description = "";
	AttributeList bonuses;
};


// Eventually, every character I may want more than one of will have its own class via inheritance. 
struct CharacterList
{
	Character PlayerCharacter;
	Character Billy;

	CharacterList();
};

CharacterList::CharacterList()
{

}

struct Location
{
	int identifier = 0;
	string description = "";
	vector<Location*> doorsHere = {};
	vector<Character*> charactersHere = {};
	vector<Item*> ItemsHere;
};

struct LocationList
{
	Location Home;
	Location Gym;
	Location School;
};

struct CommandList
{
	string move = "move";
};

struct Game
{
	string startMessage;
	string help;
	string currentCommand;
	CharacterList characterList;
	LocationList locationList;
	Location* currentLocation;
	Character* playerCharacter;
	CommandList commandList;

	Game();
	void getCommand();
	void parseCommand();
	void executeCommand();

	//location currentlocation;
	//character
};

Game::Game()
{
	startMessage = "";
	help = "";
	currentCommand = "";
	currentLocation = &locationList.Home;
	playerCharacter = &characterList.PlayerCharacter;
}

void Game::getCommand()
{
	cout << "What will you do?\n>";
	cin >> currentCommand;

}

void Game::parseCommand()
{

}

#endif