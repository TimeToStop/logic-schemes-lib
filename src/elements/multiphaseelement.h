#pragma once
#include "logicelement.h"

class MultiPhaseElement : public LogicElement
{
public:
    MultiPhaseElement(Schema*);
	virtual ~MultiPhaseElement();

    virtual bool canAddInput() const override final;
};

