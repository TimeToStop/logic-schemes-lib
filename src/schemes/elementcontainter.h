#pragma once
#include "../elements/element.h"
#include "lifespan.h"

class ElementContainer
{
public:
    ElementContainer(Schema*);
	virtual ~ElementContainer();

	template<typename T>
	std::shared_ptr<T> add();

	std::shared_ptr<Element> get(size_t);

private:
    Schema* _schema;
	std::vector<std::shared_ptr<Element>> _elements;
};

template<typename T>
inline std::shared_ptr<T> ElementContainer::add()
{
	static_assert(std::is_base_of<Element, T>::value, "Create only derived from Element");
	std::shared_ptr<T> e = std::make_shared<T>(_schema);
	_elements.push_back(e);
    LifeSpan::global()->addElement(e);
	return e;
}
