#pragma once
#include "multiphaseelement.h"

class AndNot : public MultiPhaseElement
{
public:
    AndNot(Schema*);
    virtual ~AndNot();

	virtual void calculate() override;
};

