#pragma once
#include <map>
#include <list>
#include <vector>
#include <memory>

class DataIn;
class DataOut;

class ConnectionManager
{
public:
	ConnectionManager();
	~ConnectionManager();

    bool isConnected(const std::shared_ptr<DataOut>&);
    void connect(const std::shared_ptr<DataOut>&, const std::shared_ptr<DataIn>&);

    const std::list<std::shared_ptr<DataIn>>& get(const std::shared_ptr<DataOut>&) const;

private:
    std::map<std::shared_ptr<DataOut>, std::list<std::shared_ptr<DataIn>>> _connections;
};

