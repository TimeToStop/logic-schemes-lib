#pragma once
#include"multiphaseelement.h"

class Or : public MultiPhaseElement
{
public:
    Or(Schema*);
    virtual ~Or();

	virtual void calculate() override;
};

