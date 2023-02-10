#include "SelectionTool.h"
#include <iostream>


void SelectionTool::MouseDown() const noexcept
{
    std::cout << "Selection icon\n";
}


void SelectionTool::MouseUp() const noexcept
{
    std::cout << "Draw a dashed rectangle\n";
}


SelectionTool::~SelectionTool()
{
    std::cout << "Destroy a Selection Tool\n";
}