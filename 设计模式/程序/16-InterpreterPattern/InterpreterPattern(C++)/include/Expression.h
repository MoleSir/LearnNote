#ifndef __EXPRESSION_H__
#define __EXPRESSION_H__
#include <string>

namespace InterpreterPattern
{
    class Expression
    {
    public:
        virtual bool Interpreter(const std::string& context)  = 0;
        virtual ~Expression();
    };
}


#endif