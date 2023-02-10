#include "TableObserver.h"
#include "Observer.h"
#include "Subject.h"
#include <memory>
#include <vector>
#include <iostream>
#include <cstdio>


TableObserver::TableObserver(Subject* subject) noexcept
    : Observer(subject) {}


void TableObserver::Update() noexcept
{
    std::cout << "Table Update!\n";

    double sum = 0;
    const std::vector<double>& data = this->_subject->GetData();
    for (auto iter = data.begin(); iter != data.end(); ++iter)
        sum += *iter;

    for (int i = 0; i < data.size(); ++i)
        std::cout << "+----------";
    std::cout << "+\n";

    for (auto iter = data.begin(); iter != data.end(); ++iter)
    {
        printf("|  %.4f  ", *iter / sum);
    }
    std::cout << "|\n";

    for (int i = 0; i < data.size(); ++i)
        std::cout << "+----------";
    std::cout << "+\n";
}