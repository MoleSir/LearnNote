using System;

namespace InterpreterPattern
{   
    /* 基类 */
    public interface Expression
    {
        bool Interpret(string context);   
    }
}