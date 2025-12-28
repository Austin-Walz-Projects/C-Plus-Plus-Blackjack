#pragma once
#include "BaseCard.h"
class ClubCard :
    public BaseCard
{
public:
    void drawCard() const;

    ClubCard(int num);

    void setSymbol() { symbol = "C"; }
    void setValue(int num) { value = num; }
};

