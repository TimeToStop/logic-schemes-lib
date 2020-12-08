#pragma once
#include "connectionmanager.h"
#include "elementcontainter.h"
#include "lifespan.h"

class Schema
{
public:
	Schema();
	~Schema();

    virtual void construct() = 0;

	template<typename T>
	std::shared_ptr<T> add();

	std::shared_ptr<Element> get(size_t);
    ConnectionManager* connectionManager();

    void connect(const std::shared_ptr<DataOut>&, const std::shared_ptr<DataIn>&);
    const std::list<std::shared_ptr<DataIn>>& get(const std::shared_ptr<DataOut>&);

    const std::shared_ptr<DataIn>& input(size_t) const;
    const std::shared_ptr<DataOut>& output(size_t) const;

    const std::vector<std::shared_ptr<DataIn>>& inputs() const;
    const std::vector<std::shared_ptr<DataOut>>& outputs() const;


protected:
    std::vector<std::shared_ptr<DataIn>> _inputs;
    std::vector<std::shared_ptr<DataOut>> _outputs;

private:
    ElementContainer _container;
	ConnectionManager _connections;
};

template<typename T>
inline std::shared_ptr<T> Schema::add()
{
	return _container.add<T>();
}
