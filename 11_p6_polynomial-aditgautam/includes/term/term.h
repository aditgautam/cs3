#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>

using namespace std;

const double epsilon = .001;

struct Term{
    double _coef;
    int _exp;

    Term();
    Term(double coef, int exp);
    friend bool operator ==(const Term& lhs, const Term& rhs);
    friend bool operator !=(const Term& lhs, const Term& rhs);
    friend bool operator >(const Term& lhs, const Term& rhs);
    friend bool operator <(const Term& lhs, const Term& rhs);

    //used in Poly division operator
    friend Term operator / (const Term& lhs, const Term& rhs);
    friend Term operator * (const Term& lhs, const Term& rhs);
    friend Term operator + (const Term& lhs, const Term& rhs);
    friend Term operator - (const Term& lhs, const Term& rhs);

    friend ostream& operator <<(ostream& outs, const Term& t);
};

bool double_equal(const double d1, const double d2);