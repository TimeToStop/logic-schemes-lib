#include "or.h"

#include "../components/datain.h"
#include "../components/dataout.h"

Or::Or(Schema* schema):
    MultiPhaseElement(schema)
{
}

Or::~Or()
{
}

void Or::calculate()
{
    Signal s(SignalValue::LOW);

    for (std::shared_ptr<DataIn> input : _inputs)
    {
        s |= input->signal();
    }

    _outputs[0]->setSignal(s);
}
