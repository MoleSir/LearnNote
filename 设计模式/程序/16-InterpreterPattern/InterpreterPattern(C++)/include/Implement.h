#ifndef __IMPLEMENT_H__
#define __IMPLEMENT_H__
#include "Expression.h"
#include <string>


namespace InterpreterPattern
{
    class TerminalExpression : public Expression
    {
    public: 
        TerminalExpression(const std::string& data);
        // 实现虚函数
        bool Interpreter(const std::string& context) override;

    private:
        std::string _data;
    };

    class OrExpression : public Expression
    {
    public:
        OrExpression(Expression* expression1, Expression* expression2);
        // 实现虚函数
        bool Interpreter(const std::string& context) override;

    private:
        Expression* _expression1;
        Expression* _expression2;
    };

    class AndExpression : public Expression
    {
    public:
        AndExpression(Expression* expression1, Expression* expression2);
        // 实现虚函数
        bool Interpreter(const std::string& context) override;
        
    private:
        Expression* _expression1;
        Expression* _expression2;
    };
}


#endif