#pragma once
#include "../components/datain.h"
#include "../components/dataout.h"

#include <memory>
#include <vector>

using ID = unsigned long long;

class Schema;

class Element : public std::enable_shared_from_this<Element>
{
public:
    Element(Schema*);
	virtual ~Element();

	virtual void calculate() = 0;

    virtual bool canAddInput() const = 0;
    virtual bool canAddOutput() const = 0;

    void setId(ID id);

    std::shared_ptr<DataIn> addInput(const std::string&);
    std::shared_ptr<DataOut> addOutput(const std::string&);

    ID id() const;
    Schema* schema();

    size_t inputsNumber()  const;
    size_t outputsNumber() const;

    std::shared_ptr<DataIn> input(size_t) const;
    std::shared_ptr<DataOut> output(size_t) const;

protected:
    ID _id;
    Schema* _schema;
    std::vector<std::shared_ptr<DataIn>> _inputs;
    std::vector<std::shared_ptr<DataOut>> _outputs;
};

