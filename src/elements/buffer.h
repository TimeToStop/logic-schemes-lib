#pragma once
#include "monophaseelement.h"

class Buffer : public MonophaseElement
{
public:
    Buffer(Schema*);
    virtual ~Buffer();

	virtual void calculate() override;
};

