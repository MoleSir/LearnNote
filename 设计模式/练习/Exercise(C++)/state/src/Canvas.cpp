#include "Canvas.h"
#include "Tool.h"
#include "SelectionTool.h"
#include "BrushTool.h"
#include <memory>


Canvas::Canvas() noexcept
    : _currentTool(std::unique_ptr<Tool>(nullptr)) {}


void Canvas::MouseDown() noexcept
{
    if (this->_currentTool.get() != nullptr) 
        this->_currentTool->MouseDown();
}


void Canvas::MouseUp() noexcept
{
    if (this->_currentTool.get() != nullptr) 
        this->_currentTool->MouseUp();
}


Tool* Canvas::GetCurrentTool() const noexcept
{
    return this->_currentTool.get();
}


void Canvas::SetCurrentTool(Tool* newTool)
{
    this->_currentTool.reset(newTool);
}