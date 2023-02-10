#ifndef __CANVAS_H__
#define __CANVAS_H__
#include <memory>

class Tool;

class Canvas 
{
public:
    Canvas() noexcept;

    void MouseDown() noexcept;

    void MouseUp() noexcept;
    
    Tool* GetCurrentTool() const noexcept;

    void SetCurrentTool(Tool* newTool);

private:
    std::unique_ptr<Tool> _currentTool;
};


#endif