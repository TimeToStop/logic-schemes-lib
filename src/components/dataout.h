#pragma once
#include "data.h"

#include <memory>

class ConnectionManager;

class DataOut : public Data, public std::enable_shared_from_this<DataOut>
{
public:
    DataOut(const std::string&, ConnectionManager*);
	virtual ~DataOut();

    void notifyConnectedInputs();
	virtual void notify() override;

private:
	ConnectionManager* _manager;
};

