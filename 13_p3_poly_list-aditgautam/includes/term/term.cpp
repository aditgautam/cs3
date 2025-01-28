#include "term.h"

Term::Term()
{
    _coef = 0;
    _exp = 0;
}
Term::Term(double coef, int exp)
{
    _coef = coef;
    _exp = exp;
}

bool operator ==(const Term& lhs, const Term& rhs)
{
    return lhs._exp == rhs._exp;
}
bool operator !=(const Term& lhs, const Term& rhs)
{
    return !(lhs == rhs);
}
bool operator >(const Term& lhs, const Term& rhs)
{
    return lhs._exp > rhs._exp;
}
bool operator <(const Term& lhs, const Term& rhs)
{
    return lhs._exp < rhs._exp;
}

    //used in Poly division operator
Term operator / (const Term& lhs, const Term& rhs)
{
    assert(rhs._coef != 0 && "Attempted to divide a term by 0");
    double result_coef = lhs._coef / rhs._coef;
    int result_exp = lhs._exp - rhs._exp;
    return Term(result_coef, result_exp);
}
Term operator * (const Term& lhs, const Term& rhs)
{
    double result_coef = lhs._coef * rhs._coef;
    int result_exp = lhs._exp + rhs._exp;
    return Term(result_coef, result_exp);
}

Term operator + (const Term& lhs, const Term& rhs)
{
    assert(lhs._exp == rhs._exp && "exponents must be equal");
    return Term(lhs._coef + rhs._coef, lhs._exp);
}
Term operator - (const Term& lhs, const Term& rhs)
{
    assert(lhs._exp == rhs._exp && "exponents must be equal");
    return Term(lhs._coef - rhs._coef, lhs._exp);
}

Term Term::operator - () const
{
    Term result = *this;
    result._coef = -result._coef;
    return result;
}

ostream& operator <<(ostream& outs, const Term& t)
{
    outs << fixed << setprecision(1); //Sets double precision
    if( t._exp == 0 ){
        outs << t._coef;
    }
    else if( t._exp == 1){
        outs << t._coef << "X";
    }
    else{
        outs << t._coef << "X^" << t._exp;
    }
    return outs;
}

bool double_equals(double left, double right)
{
    if(abs(left - right) < epsilon)
    {
        return true;
    }
    return false;
}