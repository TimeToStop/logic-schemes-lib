#include "buffer.h"

Buffer::Buffer(Schema* schema):
    MonophaseElement(schema)
{
}

Buffer::~Buffer()
{
}

void Buffer::calculate()
{
    Signal signal = _inputs[0]->signal();
    _outputs[0]->setSignal(signal);
}
