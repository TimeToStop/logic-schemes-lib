#pragma once
#include "multiphaseelement.h"

class And : public MultiPhaseElement
{
public:
    And(Schema*);
    virtual ~And();

	virtual void calculate() override;
};

