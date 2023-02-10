/* C++实现解释器模式 */
#include "Expression.h"
#include "Implement.h"
#include <iostream>
#include <string>
using namespace InterpreterPattern;


int main()
{
    // 创建一些表达式
    Expression* isMale = new TerminalExpression("Male");
    Expression* isFemale = new TerminalExpression("Female");
    Expression* isMarried = new TerminalExpression("Married");
    Expression* isJohn = new TerminalExpression("John");

    std::cout << "John is male? " << isMale->Interpreter("Male") << std::endl;
    
    OrExpression isMaleOrJohn(isMale, isJohn);

    std::cout << "Tom is male or John? " << isMaleOrJohn.Interpreter("Tom Male") 
              << std::endl;
    
    AndExpression isFemaleAndMarried(isMarried, isFemale);

    std::cout << "Julie is married-woman? " << isFemaleAndMarried.Interpreter("Married Female")
              << std::endl;


    delete isMale;
    delete isFemale;
    delete isMarried;
    delete isJohn;

    return 0; 
}  