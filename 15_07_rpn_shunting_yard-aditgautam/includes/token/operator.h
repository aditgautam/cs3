#ifndef OPERATOR_H
#define OPERATOR_H

#include "token.h"

class Operator : public Token{
    public:
        Operator(const string& op);

        double operate(Token* LHS, Token* RHS);
        int get_precedence() const {return _precedence;};
        bool left_asc() const {return _left_asc;};
        double get_value() const override;

        
    private:
        string _op;
        int _precedence;
        bool _left_asc;

        void set_precedence(const string& op);
};

#endif