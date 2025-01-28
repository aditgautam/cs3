#ifndef INTEGER_H
#define INTEGER_H

#include "token.h"

using namespace std;

class Integer : public Token{
    public:
        Integer() : Token(1), _value(0) {};
        Integer(int number) : Token(1), _value(number) {};
        Integer(const string& number) : Token(1) {_value = stod(number);};

        double get_value() const override {return _value;};

    private:
        double _value;
};

#endif