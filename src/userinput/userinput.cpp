#include "userinput.h"

UserInput::UserInput(int argc, char *argv[])
{
    for(int i = 1; i < argc; i++)
    {

    }
}

UserInput::~UserInput()
{
}

void UserInput::initIO(const std::vector<std::shared_ptr<DataIn>>& inputs, const std::vector<std::shared_ptr<DataOut>>& outputs)
{
    for(const std::shared_ptr<DataIn>& input : inputs)
    {
        std::cout << input->name() << ": ";

        while(true)
        {
            char buffer;
            std::cin >> buffer;
            if(buffer == '0')
            {
                input->setSignal(SignalValue::LOW);
                break;
            }
            else if (buffer == '1')
            {
                input->setSignal(SignalValue::HIGH);
                break;
            }
            else
            {
                std::cout << "Unknown signal value(0, 1)" << std::endl;
            }
        }
    }

    for(const std::shared_ptr<DataOut>& output : outputs)
    {
        output->setPrintable(true);
    }
}
