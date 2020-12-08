#include "printer.h"

void Printer::print(const std::string& global_name, const SignalValue& value)
{
    std::string to_string;

    switch(value)
    {
    case SignalValue::HIGH:
        to_string = "1";
        break;
    case SignalValue::LOW:
        to_string = "0";
        break;
    case SignalValue::NOT_SET:
        to_string = "NS";
        break;
    default:
        to_string = "Error";
        break;
    }

    std::cout << "{\"" << global_name << "\":\"" << to_string << "\"}" << std::endl;
}
