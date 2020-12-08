#include "schema.h"

Schema::Schema():
    _inputs(),
    _outputs(),
    _container(this),
	_connections()
{
}

Schema::~Schema()
{
}

std::shared_ptr<Element> Schema::get(size_t index)
{
	return _container.get(index);
}

ConnectionManager* Schema::connectionManager()
{
    return &_connections;
}

void Schema::connect(const std::shared_ptr<DataOut>& out, const std::shared_ptr<DataIn>& in)
{
	_connections.connect(out, in);
}

const std::list<std::shared_ptr<DataIn>>& Schema::get(const std::shared_ptr<DataOut>& out)
{
    return _connections.get(out);
}

const std::shared_ptr<DataIn>& Schema::input(size_t indx) const
{
    return _inputs[indx];
}

const std::shared_ptr<DataOut>& Schema::output(size_t indx) const
{
    return _outputs[indx];
}

const std::vector<std::shared_ptr<DataIn>>& Schema::inputs() const
{
    return _inputs;
}

const std::vector<std::shared_ptr<DataOut>>& Schema::outputs() const
{
    return _outputs;
}

