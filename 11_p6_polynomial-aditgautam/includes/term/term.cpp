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
    if(lhs._exp != rhs._exp)
    {
        return false;
    }
    if(!double_equal(lhs._coef, rhs._coef))
    {
        return false;
    }
    return true;
}
bool operator !=(const Term& lhs, const Term& rhs)
{
    if( lhs == rhs)
    {
        return false;
    }
    return true;
}
bool operator >(const Term& lhs, const Term& rhs)
{
    if(lhs._exp > rhs._exp)
    {
        return true;
    }
    if(lhs._coef > rhs._coef)
    {
        return true;
    }
    return false;
}
bool operator <(const Term& lhs, const Term& rhs)
{
    if(lhs > rhs)
    {
        return false;
    }
    return true;
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

ostream& operator <<(ostream& outs, const Term& t)
{
    outs << fixed << setprecision(1) << t._coef << "X^" << t._exp;
    return outs;
}

bool double_equal(const double d1, const double d2)
{
    if(abs(d1 - d2) < epsilon)
    {
        return true;
    }
    return false;
}