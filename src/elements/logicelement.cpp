#include "logicelement.h"

#include "../schemes/schema.h"
#include "../components/datain.h"
#include "../components/dataout.h"

#include <stdexcept>

LogicElement::LogicElement(Schema* schema):
    Element(schema)
{
}

LogicElement::~LogicElement()
{
}

bool LogicElement::canAddOutput() const
{
    return _outputs.size() == 0;
}

