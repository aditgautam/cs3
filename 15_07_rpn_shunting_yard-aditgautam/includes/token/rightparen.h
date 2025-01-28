#ifndef RIGHTPAREN_H
#define RIGHTPAREN_H

#include "token.h"

using namespace std;

class RightParen : public Token{
    public:
        RightParen() : Token(4) {};
        double get_value() const override {throw logic_error("Left Parenthesis have no numerical value");};
};

#endif