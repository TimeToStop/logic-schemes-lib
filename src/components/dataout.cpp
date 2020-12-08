#include "dataout.h"

#include "datain.h"
#include "../schemes/connectionmanager.h"
#include "../schemes/lifespan.h"

DataOut::DataOut(const std::string& name, ConnectionManager* manager):
    Data(name),
	_manager(manager)
{
}

DataOut::~DataOut()
{
}

void DataOut::notifyConnectedInputs()
{
    if (_manager->isConnected(shared_from_this()))
    {
        std::list<std::shared_ptr<DataIn>> elements = _manager->get(shared_from_this());

        for (const std::shared_ptr<DataIn>& element : elements)
        {
            element->setSignal(_signal);
        }
    }
}

void DataOut::notify()
{
    LifeSpan::global()->toNotify(shared_from_this());
}
