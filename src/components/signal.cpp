#include "signal.h"

Signal::Signal(SignalValue value):
    _value(value)
{
}

Signal::Signal(const Signal& other):
    _value(other._value)
{
}

Signal::~Signal()
{
}

int Signal::intValue() const
{
    return (int)_value;
}

SignalValue Signal::value() const
{
    return _value;
}

void Signal::setValue(SignalValue value)
{
    _value = value;
}

Signal& Signal::operator=(const Signal& other)
{
    _value = other._value;
    return *this;
}

Signal& Signal::operator=(SignalValue value)
{
    _value = value;
    return *this;
}

bool Signal::operator==(const Signal& other)
{
    return _value == other._value;
}

bool Signal::operator!=(const Signal& other)
{
    return _value != other._value;
}

Signal Signal::operator!()
{
    switch (_value)
    {
    case SignalValue::HIGH: 
        _value = SignalValue::LOW;
        break;
    case SignalValue::LOW:
        _value = SignalValue::HIGH;
        break;
    case SignalValue::NOT_SET:
        break;
    }

    return *this;
}

Signal Signal::operator&(const Signal& other)
{
    if (_value == SignalValue::NOT_SET
        || other._value == SignalValue::NOT_SET)
    {
        return Signal(SignalValue::NOT_SET);
    }
    else
    {
        return Signal((SignalValue)(intValue() & other.intValue()));
    }
}

Signal Signal::operator|(const Signal& other)
{
    if (_value == SignalValue::NOT_SET
        || other._value == SignalValue::NOT_SET)
    {
        return Signal(SignalValue::NOT_SET);
    }
    else
    {
        return Signal((SignalValue)(intValue() | other.intValue()));
    }
}

Signal Signal::operator^(const Signal& other)
{
    if (_value == SignalValue::NOT_SET
        || other._value == SignalValue::NOT_SET)
    {
        return Signal(SignalValue::NOT_SET);
    }
    else
    {
        return Signal((SignalValue)(intValue() ^ other.intValue()));
    }
}

Signal Signal::operator&(SignalValue value)
{
    if (_value == SignalValue::NOT_SET
        || value == SignalValue::NOT_SET)
    {
        return Signal(SignalValue::NOT_SET);
    }
    else
    {
        return Signal((SignalValue)(intValue() & (int)value));
    }
}

Signal Signal::operator|(SignalValue value)
{
    if (_value == SignalValue::NOT_SET
        || value == SignalValue::NOT_SET)
    {
        return Signal(SignalValue::NOT_SET);
    }
    else
    {
        return Signal((SignalValue)(intValue() | (int)value));
    }
}

Signal Signal::operator^(SignalValue value)
{
    if (_value == SignalValue::NOT_SET
        || value == SignalValue::NOT_SET)
    {
        return Signal(SignalValue::NOT_SET);
    }
    else
    {
        return Signal((SignalValue)(intValue() ^ (int)value));
    }
}

Signal& Signal::operator&=(const Signal& other)
{
    if (_value == SignalValue::NOT_SET
        || other._value == SignalValue::NOT_SET)
    {
        _value = SignalValue::NOT_SET;
    }
    else
    {
        _value = (SignalValue)(intValue() & (int)other.intValue());
    }

    return *this;
}

Signal& Signal::operator|=(const Signal& other)
{
    if (_value == SignalValue::NOT_SET
        || other._value == SignalValue::NOT_SET)
    {
        _value = SignalValue::NOT_SET;
    }
    else
    {
        _value = (SignalValue)(intValue() | (int)other.intValue());
    }

    return *this;
}

Signal& Signal::operator^=(const Signal& other)
{
    if (_value == SignalValue::NOT_SET
        || other._value == SignalValue::NOT_SET)
    {
        _value = SignalValue::NOT_SET;
    }
    else
    {
        _value = (SignalValue)(intValue() ^ (int)other.intValue());
    }

    return *this;
}

Signal& Signal::operator&=(SignalValue value)
{
    if (_value == SignalValue::NOT_SET
        || value == SignalValue::NOT_SET)
    {
        _value = SignalValue::NOT_SET;
    }
    else
    {
        _value = (SignalValue)(intValue() & (int)value);
    }

    return *this;
}

Signal& Signal::operator|=(SignalValue value)
{
    if (_value == SignalValue::NOT_SET
        || value == SignalValue::NOT_SET)
    {
        _value = SignalValue::NOT_SET;
    }
    else
    {
        _value = (SignalValue)(intValue() | (int)value);
    }

    return *this;
}

Signal& Signal::operator^=(SignalValue value)
{
    if (_value == SignalValue::NOT_SET
        || value == SignalValue::NOT_SET)
    {
        _value = SignalValue::NOT_SET;
    }
    else
    {
        _value = (SignalValue)(intValue() ^ (int)value);
    }

    return *this;
}
