#include "monophaseelement.h"

#include "../schemes/schema.h"

#include <stdexcept>

MonophaseElement::MonophaseElement(Schema* schema):
    LogicElement(schema)
{
}

MonophaseElement::~MonophaseElement()
{
}

bool MonophaseElement::canAddInput() const
{
    return _inputs.size() == 0;
}
