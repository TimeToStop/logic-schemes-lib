#include "ornot.h"

#include "../components/datain.h"
#include "../components/dataout.h"

OrNot::OrNot(Schema* schema):
    MultiPhaseElement(schema)
{
}

OrNot::~OrNot()
{
}

void OrNot::calculate()
{
    Signal s(SignalValue::LOW);

    for (std::shared_ptr<DataIn> input : _inputs)
    {
        s |= input->signal();
    }

    _outputs[0]->setSignal(!s);
}
