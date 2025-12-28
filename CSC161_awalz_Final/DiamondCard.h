#pragma once
#include "BaseCard.h"
class DiamondCard :
    public BaseCard
{
public:
    void drawCard() const;

    DiamondCard(int num);

    void setSymbol() { symbol = "D"; }
    void setValue(int num) { value = num; }
};

