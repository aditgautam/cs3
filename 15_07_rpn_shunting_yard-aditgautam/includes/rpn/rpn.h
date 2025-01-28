#ifndef RPN_H
#define RPN_H

#include "../token/token.h"
#include "../token/integer.h"
#include "../token/function.h"
#include "../token/operator.h"
#include "../stack/MyStack.h"
#include "../queue/MyQueue.h"

using namespace std;

class RPN{
    public:
        RPN(Queue<Token*> postfix);

        double operator()();
        double operator()(double evaluateMe);

        void set_input(Queue<Token*> new_postfix);

        friend ostream& operator <<(ostream& outs, RPN& printMe);

    private:
        Queue<Token*> _postfix;
        Stack<Token*> _stack;

        double evaluate(double variableValue = 0.0, bool useVariable = false);
        
};

#endif