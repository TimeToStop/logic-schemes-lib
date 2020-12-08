#pragma once
#include "monophaseelement.h"

class Not: public MonophaseElement
{
public:
    Not(Schema*);
    virtual ~Not();

	virtual void calculate() override;
};

