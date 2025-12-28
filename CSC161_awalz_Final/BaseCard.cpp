#include "BaseCard.h"

void BaseCard::drawCard() const
{
	for (int i = 0; i < 7; i++)std::cout << card[i] << std::endl;
	
}

BaseCard::BaseCard()
{
	face = "Fake";
	symbol = "~";
	deck = "";
	symbolList = "";

	value = 0;
	size = 0;


	card = new std::string[7];

	flip = false;
	house = false;

	card[0] += "";
	card[1] += "";
	card[2] += "";
	card[3] += "";
	card[4] += "";
	card[5] += "";
	card[6] += "";
}

BaseCard::BaseCard(int num)
{

	//Assigns values and faces to each card made
	num %= 13;
	if (num == 1) {
		face = "A";
		value = 11;
	}
	else if (num == 11) {
		face = "J";
		value = 10;
	}
	else if (num == 12) {
		face = "Q";
		value = 10;
	}
	else if (num == 0) {
		face = "Q";
		value = 10;
	}
	else { 
		value = num;
		face = std::to_string(num);
	}

	symbol = "~";
	deck = face;
	symbolList = "";
	size=1;

	flip = false;
	house = false;
	card = new std::string[7];

}

void BaseCard::addCard(BaseCard newCard)
{
	
	card[0] += newCard.card[0];
	card[1] += newCard.card[1];
	card[2] += newCard.card[2];
	card[3] += newCard.card[3];
	card[4] += newCard.card[4];
	card[5] += newCard.card[5];
	card[6] += newCard.card[6];

	//Increases deck size, total hand value, deck values (1,Q,6,etc), and symbols
	size++;
	value += newCard.value;
	deck += newCard.face;
	symbolList += newCard.symbol;

}

void BaseCard::addCardFlip(BaseCard newCard)
{
	card[0] += "  _______ ";
	card[1] += "  |?    | ";
	card[2] += "  |     | ";
	card[3] += "  |  ?  | ";
	card[4] += "  |     | ";
	card[5] += "  |    ?| ";
	card[6] += "  |_____| ";
	size++;
	value += newCard.value;
	deck += newCard.face;
}

bool BaseCard::hasAce()
{
	if (deck.length() == 0) return false;

	for (int i = 0; i < deck.length(); i++) {
		if (deck[i] == 'A') {
			if (value > 21) {
				deck[i] = 'a';
				value -= 10;
			}
			return true;
		}
	}
	return false;
}

void BaseCard::unFlip()
{
	card[1][3] = deck[0];
	card[3][5] = symbolList[0];
	card[5][7] = deck[0];

}


bool BaseCard::operator==(const BaseCard& right) const
{
	return value == right.value;
}

BaseCard& BaseCard::operator+=(const BaseCard& add)
{
	if (add.flip) addCardFlip(add);
	else addCard(add);
	return *this;
}

std::ostream& operator<<(std::ostream& os, const BaseCard& card)
{
	std::string temp = "";
	for (int i = 0; i < 7; i++) {
		temp += card.card[i];
		temp += "\n";
	}
 


	os << temp;
	return os;
}
