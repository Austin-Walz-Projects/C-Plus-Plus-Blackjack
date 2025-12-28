#pragma once
#include "BaseCard.h"
class SpadeCard :
    public BaseCard
{
public:
    void drawCard() const;

    SpadeCard(int num);

    void setSymbol() { symbol = "S"; }
    void setValue(int num) { value = num; }
};

