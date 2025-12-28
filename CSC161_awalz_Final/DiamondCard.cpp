#include "DiamondCard.h"

void DiamondCard::drawCard() const
{
}

DiamondCard::DiamondCard(int num) :BaseCard(num)
{
	setSymbol();

	card[0] += "  _______ ";

	//If 10 since it's double digits it needs one less space
	if (face == "10")
		card[1] += "  |" + face + "   | ";
	else
		card[1] += "  |" + face + "    | ";

	card[2] += "  |     | ";
	card[3] += "  |  " + symbol + "  | ";
	card[4] += "  |     | ";

	//If 10 since it's double digits it needs one less space
	if (face == "10")
		card[5] += "  |   " + face + "| ";
	else
		card[5] += "  |    " + face + "| ";

	card[6] += "  |_____| ";
}
