#ifndef SHUNTING_YARD_H
#define SHUNTING_YARD_H

#include "../token/token.h"
#include "../token/integer.h"
#include "../token/function.h"
#include "../token/operator.h"
#include "../token/leftparen.h"
#include "../token/rightparen.h"
#include "../stack/MyStack.h"
#include "../queue/MyQueue.h"


using namespace std;

class ShuntingYard{
    public:
        ShuntingYard() = default;
        ShuntingYard(const Queue<Token*>& infix) : _infix(infix) {};
        void infix(const Queue<Token*>& infix) {_infix = infix;};
        Queue<Token*> postfix();
        Queue<Token*> postfix(Queue<Token*> infix);

    private:
        Queue<Token*> _infix;
        bool is_operator(Token* token) const;
        void apply_parenthesis(Stack<Token*>& operatorStack, Queue<Token*>& postfixQueue, Token* token);
        void apply_operator(Stack<Token*>& operatorStack, Queue<Token*>& postfixQueue, Token* token);

};

#endif