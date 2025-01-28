#ifndef FUNCTION_H
#define FUNCTION_H

#include "token.h"

using namespace std;

class Function : public Token{
    public:
        Function(const string& name) : Token(5), _name(name) {};
        string get_name() const {return _name;};
        double apply(double operand) const;
        double get_value() const override {throw logic_error("Functions have no numerical value");};

    private:
        string _name;
};

#endif

