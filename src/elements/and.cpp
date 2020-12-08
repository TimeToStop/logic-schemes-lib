#include "and.h"

#include "../components/datain.h"
#include "../components/dataout.h"


And::And(Schema* schema):
    MultiPhaseElement(schema)
{
}

And::~And()
{
}

void And::calculate()
{
    Signal s(SignalValue::HIGH);

    for (std::shared_ptr<DataIn> input : _inputs)
    {
        s &= input->signal();
    }

    _outputs[0]->setSignal(s);
}

