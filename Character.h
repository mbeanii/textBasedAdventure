#pragma once

#ifndef CHARACTER
#define CHARACTER

struct Character
{
	int level;
	string description;
	AttributeList baseAttributes;
	AttributeList netAttributes;
	AttributeList modifiers;	// each attribute's modifier
	vector<Item> inventory;
	vector<Item> equippedItems;

	Character();
	Character(AttributeList startingAttributes, vector<Item> startingEquipment);
	void levelUp();
	void calculateAttributes(); // net attributes = base attributes + modifiers
	void equipItem(Item item);           // copies item into equippedItems and alters modifiers based on equipped item
	void calculateModifiers();
};

Character::Character()
{
	srand(time(NULL));
	level = 1;
	description = "Generic to the max!";
	baseAttributes.smarts = rand() % 18;
	baseAttributes.speed = rand() % 18;
	baseAttributes.strength = rand() % 18;
	calculateAttributes();
}

Character::Character(AttributeList startingAttributes, vector<Item> startingEquipment)
{
	Character();
	baseAttributes.smarts = startingAttributes.smarts;
	baseAttributes.speed = startingAttributes.speed;
	baseAttributes.strength = startingAttributes.strength;

	vector<Item>::iterator it;
	for (it = startingEquipment.begin(); it != startingEquipment.end(); ++it)
	{
		inventory.push_back(*it);
		equipItem(*it);
	}
}

void Character::levelUp()
{
	baseAttributes.smarts += 1;
	baseAttributes.speed += 1;
	baseAttributes.strength += 1;
}

void Character::calculateAttributes()
{
	calculateModifiers();
	netAttributes.smarts = baseAttributes.smarts + modifiers.smarts;
	netAttributes.speed = baseAttributes.speed + modifiers.speed;
	netAttributes.strength = baseAttributes.strength + modifiers.strength;
}

void Character::equipItem(Item item)
{
	equippedItems.push_back(item);
	modifiers.smarts += item.bonuses.smarts;
	modifiers.speed += item.bonuses.speed;
	modifiers.strength += item.bonuses.strength;
}

void Character::calculateModifiers()
{
	modifiers.smarts = 0;
	modifiers.speed = 0;
	modifiers.strength = 0;

	vector<Item>::iterator it;
	for (it = equippedItems.begin(); it != equippedItems.end(); ++it)
	{
		modifiers.smarts += it->bonuses.smarts;
		modifiers.speed += it->bonuses.speed;
		modifiers.strength += it->bonuses.strength;
	}
}

#endif