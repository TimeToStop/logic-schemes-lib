#pragma once
#include  "multiphaseelement.h"

class OrNot : public MultiPhaseElement
{
public:
    OrNot(Schema*);
    virtual ~OrNot();

	virtual void calculate() override;
};

