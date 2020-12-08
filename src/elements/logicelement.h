#pragma once
#include "element.h"

class LogicElement : public Element
{
public:
    LogicElement(Schema*);
	virtual ~LogicElement();

    virtual bool canAddOutput() const override final;
};

