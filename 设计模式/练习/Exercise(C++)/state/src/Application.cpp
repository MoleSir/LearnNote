#include "Canvas.h"
#include "Tool.h"
#include "SelectionTool.h"
#include "BrushTool.h"
#include <iostream>


int main()
{
    Canvas canvas;

    canvas.SetCurrentTool(new SelectionTool);
    canvas.MouseDown();
    canvas.MouseUp();

    canvas.SetCurrentTool(new BrushTool);
    canvas.MouseDown();
    canvas.MouseUp();

    return 0;
} 