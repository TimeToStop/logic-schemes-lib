#include "data.h"

#include "../userinput/printer.h"

Data::Data(const std::string& name):
    _is_printable(false),
    _signal(SignalValue::NOT_SET),
    _name(name)
{
}

Data::~Data()
{
}

void Data::setPrintable(bool b)
{
    _is_printable = b;
}

void Data::setSignal(const Signal& signal)
{
    _signal = signal;

    if (_is_printable && _signal != SignalValue::NOT_SET)
    {
        Printer::print(_name, _signal.value());
    }

    notify();
}

std::string Data::name() const
{
    return _name;
}

Signal Data::signal() const
{
    return _signal;
}
