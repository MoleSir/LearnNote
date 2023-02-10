#include "Observer.h"
#include <bitset>
#include <iostream>


namespace ObserverPatternApp
{
    void BinaryObserver::Update(int newState) const
    {
        std::cout << "Binary String: " << (std::bitset<4>)newState << std::endl; 
    }

    void OctalObserver::Update(int newState) const
    {
        std::cout << "Octal String: " << std::oct << newState << std::endl; 
    }

    void HexaObserver::Update(int newState) const
    {
        std::cout << "Hexa String: " << std::hex << newState << std::endl; 
    }
}

