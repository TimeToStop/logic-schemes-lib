#ifndef USERINPUT_H
#define USERINPUT_H

#include <iostream>
#include "../schemes/schema.h"

class UserInput
{
public:
    UserInput(int argc, char* argv[]);
    ~UserInput();

    void initIO(const std::vector<std::shared_ptr<DataIn>>&, const std::vector<std::shared_ptr<DataOut>>&);
};

#endif // USERINPUT_H
