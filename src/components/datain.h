#pragma once
#include "data.h"

class Element;

class DataIn : public Data
{
public:
    DataIn(const std::string&, Element*);
	virtual ~DataIn();

	virtual void notify() override;

private:
	Element* _element;
};

