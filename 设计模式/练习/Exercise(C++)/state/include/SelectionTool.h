#ifndef __SELECTION_TOOL_H__
#define __SELECTION_TOOL_H__


#include "Tool.h"

class SelectionTool : public Tool
{
public:
    virtual void MouseDown() const noexcept override;
    virtual void MouseUp() const noexcept override;
    virtual ~SelectionTool() override;
};  


#endif