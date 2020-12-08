#include "element.h"

#include "../schemes/schema.h"

Element::Element(Schema* schema):
    _id(0),
    _schema(schema)
{
}

Element::~Element()
{
}

void Element::setId(ID id)
{
    _id = id;
}

std::shared_ptr<DataIn> Element::addInput(const std::string& name)
{
    if (canAddInput())
    {
        std::shared_ptr<DataIn> in = std::make_shared<DataIn>(name, this);
        _inputs.push_back(in);
        return in;
    }
    else
    {
        throw std::runtime_error("Cannot add input");
    }
}

std::shared_ptr<DataOut> Element::addOutput(const std::string& name)
{
    if (canAddInput())
    {
        std::shared_ptr<DataOut> out = std::make_shared<DataOut>(name, _schema->connectionManager());
        _outputs.push_back(out);
        return out;
    }
    else
    {
        throw std::runtime_error("Cannot add output");
    }
}

ID Element::id() const
{
    return _id;
}

Schema* Element::schema()
{
    return _schema;
}

size_t Element::inputsNumber() const
{
    return _inputs.size();
}

size_t Element::outputsNumber() const
{
    return _outputs.size();
}

std::shared_ptr<DataIn> Element::input(size_t indx) const
{
    return _inputs[indx];
}

std::shared_ptr<DataOut> Element::output(size_t indx) const
{
    return _outputs[indx];
}
