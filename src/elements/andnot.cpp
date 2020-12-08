#include "andnot.h"

#include "../components/datain.h"
#include "../components/dataout.h"

AndNot::AndNot(Schema* schema):
    MultiPhaseElement(schema)
{
}

AndNot::~AndNot()
{
}

void AndNot::calculate()
{
    Signal s(SignalValue::HIGH);

    for (std::shared_ptr<DataIn> input : _inputs)
    {
        s &= input->signal();
    }

    _outputs[0]->setSignal(!s);
}
