#include "Stack.h"
#include <cstring>
#include <cctype>

double applyOperator(double a, double b, char op) {
    switch (op) {
        case '+':
            return a + b;
        case '*':
            return a * b;
    }
    return 0;
}

int precedence(char op) {
    if (op == '+' || op == '*') {
        return 1; 
    }
    return 0;
}

double Calc(char* expr) {
    Stack values(100); 
    Stack ops(100);   

    for (int i = 0; i < strlen(expr); i++) {
        
        if (isdigit(expr[i])) {
            double value = expr[i] - '0'; 
            values.push(value);
        }
        
        else if (expr[i] == '(') {
            ops.push(expr[i]);
        }
        
        else if (expr[i] == ')') {
            while (!ops.isEmpty() && ops.getTop() != '(') {
                double val2 = values.pop();
                double val1 = values.pop();
                char op = ops.pop();
                double result = applyOperator(val1, val2, op);
                values.push(result);
            }
            ops.pop(); 
        }
        
        else if (expr[i] == '+' || expr[i] == '*') {
            while (!ops.isEmpty() && precedence(ops.getTop()) >= precedence(expr[i])) {
                double val2 = values.pop();
                double val1 = values.pop();
                char op = ops.pop();
                double result = applyOperator(val1, val2, op);
                values.push(result);
            }
            ops.push(expr[i]);
        }
    }

    
    while (!ops.isEmpty()) {
        double val2 = values.pop();
        double val1 = values.pop();
        char op = ops.pop();
        double result = applyOperator(val1, val2, op);
        values.push(result);
    }

    return values.pop();
}
