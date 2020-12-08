#include "lifespan.h"

LifeSpan* LifeSpan::_global = nullptr;

LifeSpan::LifeSpan():
    _to_update()
{
   _global = this;
}

LifeSpan::~LifeSpan()
{
}

void LifeSpan::toUpdate(const std::shared_ptr<Element>& element)
{
    _to_update.insert(element);
}

void LifeSpan::toNotify(const std::shared_ptr<DataOut>& output)
{
    _to_notify.insert(output);
}

void LifeSpan::addElement(const std::shared_ptr<Element>& element)
{
    _all_elements.insert(element);
}

void LifeSpan::execute()
{
	while (!_to_update.empty())
	{
        std::list<std::shared_ptr<Element>> list(_to_update.begin(), _to_update.end());
		_to_update.clear();
        _to_notify.clear();

        for (const std::shared_ptr<Element>& e : list)
		{
			e->calculate();
		}

        for (const std::shared_ptr<DataOut>& output : _to_notify)
        {
            output->notifyConnectedInputs();
        }
    }
}

LifeSpan* LifeSpan::global()
{
    return _global;
}
