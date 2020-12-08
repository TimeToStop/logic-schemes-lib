#include "not.h"

Not::Not(Schema* schema):
    MonophaseElement(schema)
{
}

Not::~Not()
{
}

void Not::calculate()
{
    Signal s = _inputs[0]->signal();
    _outputs[0]->setSignal(!s);
}
