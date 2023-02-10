#ifndef __TOOL_H__
#define __TOOL_H__


class Tool
{
public:
    virtual void MouseDown() const noexcept = 0;
    virtual void MouseUp() const noexcept = 0;
    virtual ~Tool() {}
};


#endif