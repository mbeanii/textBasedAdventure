#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>
using std::cout;
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
struct Character;
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
};

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


struct Character
{
	int level = 0;
	string description = "";
	AttributeList baseAttributes;
	AttributeList netAttributes;
	vector<Item> inventory;
	vector<Item> equippedItems;

	Character(AttributeList startingAttributes, vector<Item> startingEquipment);
	void levelUp();
	void recalculateAttributes(); // net attributes = base attributes + all boosts/hinders
};

Character::Character(AttributeList startingAttributes, vector<Item> startingEquipment)
{

}

void Character::levelUp()
{
	baseAttributes.smarts += 1;
	baseAttributes.speed += 1;
	baseAttributes.strength += 1;
}

void Character::recalculateAttributes()
{
	netAttributes = 
}

struct Game
{
	string startMessage;
	string help;
	string currentCommand;
	Location currentLocation;
	Character playerCharacter;
	CharacterList characterList;
	LocationList locationList;
	CommandList commandList;

	Game();					// may have equivalently been called "initialize"
	void getCommand();
	void parseCommand();
	void executeCommand();

	//location currentlocation;
	//character
};