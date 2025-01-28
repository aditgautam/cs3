#ifndef LEFTPAREN_H
#define LEFTPAREN_H

#include "token.h"

class LeftParen : public Token{
    public: 
        LeftParen() : Token(3) {};
        double get_value() const override {throw logic_error("Left Parenthesis have no numerical value");};
};

#endif