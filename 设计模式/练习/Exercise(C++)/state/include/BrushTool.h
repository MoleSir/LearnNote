#ifndef __BRUSH_TOOL_H__
#define __BRUSH_TOOL_H__


#include "Tool.h"

class BrushTool : public Tool
{
public:
    virtual void MouseDown() const noexcept override ;
    virtual void MouseUp() const noexcept override;
    virtual ~BrushTool() override; 
};  


#endif