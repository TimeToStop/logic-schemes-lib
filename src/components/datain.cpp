#include "datain.h"

#include "../elements/element.h"
#include "../schemes/lifespan.h"

DataIn::DataIn(const std::string& name, Element* element):
    Data(name),
    _element(element)
{
}

DataIn::~DataIn()
{
}

void DataIn::notify()
{
    LifeSpan::global()->toUpdate(_element->shared_from_this());
}
