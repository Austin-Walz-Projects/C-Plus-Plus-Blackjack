#pragma once
#include "BaseCard.h"
class HeartCard :
    public BaseCard
{
public:
    void drawCard() const;

    HeartCard(int num);

    void setSymbol() { symbol = "H"; }
    void setValue(int num) { value = num; }
};

