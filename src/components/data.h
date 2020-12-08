#pragma once
#include "signal.h"

#include <string>

class Data
{
public:
    Data(const std::string&);
	virtual ~Data();

	virtual void notify() = 0;

    void setPrintable(bool);
	void setSignal(const Signal&);

    Signal signal() const;
    std::string name() const;

protected:
    bool _is_printable;
	Signal _signal;
    std::string _name;
};

