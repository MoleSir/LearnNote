#include "BrushTool.h"
#include <iostream>


void BrushTool::MouseDown() const noexcept
{
    std::cout << "Brush icon\n";
}


void BrushTool::MouseUp() const noexcept
{
    std::cout << "Draw a line\n";
}


BrushTool::~BrushTool()
{
    std::cout << "Destory a Brush Tool\n";
}