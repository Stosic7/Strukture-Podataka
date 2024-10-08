#include "Stack.h"
#include <cctype> 
#include <cstring> 

int calculatePostfixExpression(char* infix) {
    Stack stack(100);  
    
    for (int i = 0; i < strlen(infix); i++) {
        char current = infix[i];

        
        if (isdigit(current)) {
            stack.push(current - '0'); 
        }
        
        else if (current == '+' || current == '-' || current == '*' || current == '/') {
            double operand2 = stack.pop();
            double operand1 = stack.pop();
            double result;

            switch (current) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    if (operand2 == 0)
                        throw new exception("Division by zero!");
                    result = operand1 / operand2;
                    break;
                default:
                    throw new exception("Invalid operator!");
            }
            stack.push(result);
        }
    }

    
    return stack.pop();
}
