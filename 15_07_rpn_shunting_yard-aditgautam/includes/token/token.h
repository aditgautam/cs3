#ifndef TOKEN_H
#define TOKEN_H

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cassert>

using namespace std;

class Token{
    public:
        Token();
        Token(int type) {_type = type;}

        virtual ~Token() = default;
        int get_type() const {return _type;}
        virtual double get_value() const {return 0.0;};

    private:
        int _type;
};

#endif