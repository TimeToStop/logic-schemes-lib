#pragma once

#include "../elements/element.h"

#include <memory>
#include <list>
#include <set>

class LifeSpan
{
private:
    static LifeSpan* _global;

public:
	LifeSpan();
	~LifeSpan();

    void toUpdate(const std::shared_ptr<Element>&);
    void toNotify(const std::shared_ptr<DataOut>&);
    void addElement(const std::shared_ptr<Element>&);

    void execute();

    static LifeSpan* global();

private:
    std::set<std::shared_ptr<Element>> _to_update;
    std::set<std::shared_ptr<Element>> _all_elements;
    std::set<std::shared_ptr<DataOut>> _to_notify;
};

