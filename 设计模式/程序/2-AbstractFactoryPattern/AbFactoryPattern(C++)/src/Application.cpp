#include "AbstractFactory.h"
#include "KeyboradFactory.h"
#include "ProcessorFactory.h"
#include "ScreenFactory.h"
#include <string>
using namespace ComputerMaking;

void TestEachFactory()
{
    ScreenFactory* huaweiScreenFactory = new HuaweiScreenFactory();
    ProcessorFactory* appleProcessorFactory = new AppleProcessorFactory();
    KeyboardFactory* xiaomiKeyboardFactory = new XiaomiKeyboardFactory();

    Screen* huaweiScreen = huaweiScreenFactory->GetScreen();
    Processor* appleProcessor = appleProcessorFactory->GetProcessor();
    Keyboard* xiaomiKeyborad = xiaomiKeyboardFactory->GetKeyborad();

    appleProcessor->ProcessTask("Input and OutPut!");
    std::string str = xiaomiKeyborad->Typewrite();
    huaweiScreen->Display(str);

    delete huaweiScreen;
    delete huaweiScreenFactory;
    delete appleProcessorFactory;
    delete appleProcessor;
    delete xiaomiKeyboardFactory;
    delete xiaomiKeyborad;
}

void TestAbstractFactory()
{
    ComputerFactory* appleComputerFactory = new AppleComputerFactory();
    Computer* appleComputer =  appleComputerFactory->GetComputer();

    delete appleComputerFactory;
}

int main()
{
    // TestEachFactory();
    TestAbstractFactory();
    return 0;
}