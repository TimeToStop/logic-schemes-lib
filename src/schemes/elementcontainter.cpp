#include "elementcontainter.h"

#include "../components/datain.h"
#include "../components/dataout.h"

ElementContainer::ElementContainer(Schema* schema):
    _schema(schema)
{
}

ElementContainer::~ElementContainer()
{
}

std::shared_ptr<Element> ElementContainer::get(size_t index)
{
    return _elements[index];
}
