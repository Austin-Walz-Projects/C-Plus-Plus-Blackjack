#pragma once
#include <iostream>
#include<string>
class BaseCard
{
public:
	virtual void drawCard() const;
	BaseCard();
	BaseCard(int num);
	void addCard(BaseCard newCard);
	void addCardFlip(BaseCard newCard);

	int getValue() const { return value; }
	int getSize() const { return size; }
	bool getHouse() const { return house; }

	void setFlip(bool status) { flip = status; }
	void setHouse(bool stat) { house = stat; }
	void setValue(int num) { value = num; }

	//If Value is over 21 and have an Ace to drop value will do so
	bool hasAce();

	//Reveals House's First Card during it's play
	void unFlip();

	//Overloads
	bool operator == (const BaseCard & right) const;

	//Combines Cards Easier
	BaseCard& operator+=(const BaseCard& add);

	//Allows output of the cards Horrizontally instead of Vertically
	friend std::ostream& operator << (std::ostream& os, const BaseCard& card);

protected:
	std::string symbol;
	std::string face;
	std::string* card;
	std::string deck;
	std::string symbolList;

	int value;
	int size;

	bool flip;
	bool house;
};

