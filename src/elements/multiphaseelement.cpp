#include "multiphaseelement.h"

#include "../components/datain.h"
#include "../schemes/schema.h"

MultiPhaseElement::MultiPhaseElement(Schema* schema):
    LogicElement(schema)
{
}

MultiPhaseElement::~MultiPhaseElement()
{
}

bool MultiPhaseElement::canAddInput() const
{
    return true;
}
