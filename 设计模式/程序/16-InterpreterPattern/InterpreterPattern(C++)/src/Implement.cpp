#include "Implement.h"
#include <iostream>
#include <string>


namespace InterpreterPattern
{
    TerminalExpression::TerminalExpression(const std::string& data) : _data(data) 
    {}

    bool TerminalExpression::Interpreter(const std::string& context)  
    {
        if (context.find(this->_data) != -1)
            return true;
        else return false;
    }



    OrExpression::OrExpression(Expression* expression1, Expression* expression2):
        _expression1(expression1), _expression2(expression2)
    {}

    bool OrExpression::Interpreter(const std::string& context)  
    {
        return this->_expression1->Interpreter(context) || 
               this->_expression2->Interpreter(context);
    }



    AndExpression::AndExpression(Expression* expression1, Expression* expression2):
        _expression1(expression1), _expression2(expression2)
    {}

    bool AndExpression::Interpreter(const std::string& context)  
    {
        return this->_expression1->Interpreter(context) &&
               this->_expression2->Interpreter(context);
    }

    
}