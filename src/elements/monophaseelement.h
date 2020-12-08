#pragma once
#include "logicelement.h"

class MonophaseElement : public LogicElement
{
public:
    MonophaseElement(Schema*);
	virtual ~MonophaseElement();

    virtual bool canAddInput() const override final;
};

