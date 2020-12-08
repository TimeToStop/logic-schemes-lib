#ifndef PRINTER_H
#define PRINTER_H

#include "userinput.h"

class Printer
{
public:
    static void print(const std::string& global_name, const SignalValue&);

private:
    Printer() = delete;
    Printer(const Printer&) = delete;
    Printer(Printer&&) = delete;
    ~Printer() = delete;
};

#endif // PRINTER_H
