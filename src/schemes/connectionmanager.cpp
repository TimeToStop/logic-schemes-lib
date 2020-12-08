#include "connectionmanager.h"

#include <stdexcept>

ConnectionManager::ConnectionManager():
	_connections()
{
}

ConnectionManager::~ConnectionManager()
{
}

bool ConnectionManager::isConnected(const std::shared_ptr<DataOut>& out)
{
    return _connections.find(out) != _connections.end();
}

void ConnectionManager::connect(const std::shared_ptr<DataOut>& out,
                                const std::shared_ptr<DataIn>&   in)
{
	const auto& it = _connections.find(out);

	if (it == _connections.end())
	{
        std::list<std::shared_ptr<DataIn>> connected;
		connected.push_back(in);

        _connections.insert({ out, connected });
	}
	else
	{
		it->second.push_back(in);
	}
}

const std::list<std::shared_ptr<DataIn>>& ConnectionManager::get(const std::shared_ptr<DataOut>& out) const
{
    const auto& it = _connections.find(out);

	if (it != _connections.end())
	{
		return it->second;
	}
	else
	{
		throw std::runtime_error("DataOut did not connected but required");
	}
}
