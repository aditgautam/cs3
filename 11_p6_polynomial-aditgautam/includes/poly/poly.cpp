#include "poly.h"


Poly::Poly()
{
    _coefs = allocate<double>(1);
    _coefs[0] = 0.0;
    _order = 0;
}
Poly::Poly(double* coefs, int order)
{
    _order = order;
    _coefs = copy_array(coefs, order + 1);
    fix_order();
}

    //the BIG 3
Poly::Poly(const Poly& other)
{
    _order = other._order;
    _coefs = copy_array(other._coefs, other._order + 1);
}
Poly& Poly::operator =(const Poly& rhs)
{
    if(&rhs == this)
    {
        return *this;
    }
    delete [] _coefs;
    _order = rhs._order;
    _coefs = copy_array(rhs._coefs, rhs._order + 1);
    return *this;
}
Poly::~Poly()
{
    delete [] _coefs;
}

bool operator ==(const Poly& lhs, const Poly& rhs)
{
    if(lhs._order != rhs._order)
    {
        return false;
    }
    for(int i = 0; i <= lhs._order; i++)
    {
        if(lhs[i] != rhs[i])
        {
            return false;
        }
    }
    return true;
}
bool operator !=(const Poly& lhs, const Poly& rhs)
{
    return !(lhs == rhs);
}
bool operator >(const Poly& lhs, const Poly& rhs)
{
    if(lhs._order > rhs._order)
    {
        return true;
    }
    else if( lhs._order < rhs._order)
    {
        return false;
    }
    else
    {
    for (int i = lhs._order; i >= 0; --i) 
{
    if (lhs[i] > rhs[i])
    {
        return true;
    }
    else if (lhs[i] < rhs[i])
    {
        return false;
    }
}   }
    return true;
}
bool operator <(const Poly& lhs, const Poly& rhs)
{
    if(lhs > rhs)
    {
        return false;
    }
    return true;
}

Term Poly::operator[](int order) const
{
    return Term(*(_coefs + order), order);
}

Poly operator +(const Poly& lhs, const Term& t)
{
    Poly result(lhs);
    result.resize(t._exp);
    Term current_term(*(result._coefs + t._exp), t._exp);
    Term new_term = current_term + t;
    *(result._coefs + t._exp) = new_term._coef;
    result.fix_order();
    return result;
}
Poly operator +(const Poly& lhs, const Poly& rhs)
{
    Poly result(lhs);
    for( int i = 0; i <= rhs._order; i++)
    {
        Term rhs_term(rhs._coefs[i], i);
        result = result + rhs_term;
    }
    result.fix_order();
    return result;

}

Poly operator -(const Poly& p)
{
    Poly result(p);
    for(int i = 0; i <= p._order; i++)
    {
        result._coefs[i] = -result._coefs[i];
    }
    return result;
}
Poly operator - (const Poly& lhs, const Poly& rhs)
{
    Poly result = lhs + (-rhs);
    return result;
}

Poly operator *(const Poly& lhs, const Term& t)
{
    Poly result;
    result.resize(t._exp + lhs._order);
    for(int i = 0; i <= lhs._order; i++)
    {
        Term result_term = lhs[i] * t;
        result._coefs[i + t._exp] = result_term._coef;
    }
    result.fix_order();
    return result;
}
Poly operator *(const Poly& lhs, const Poly& rhs)
{
    Poly result;
    for(int i = 0; i <= rhs._order; i++)
    {
        result = result + (lhs * rhs[i]);
    }
    result.fix_order();
    return result;
}

Poly operator /(const Poly& lhs, const Poly& rhs)
{
    Poly quotient;
    Poly remainder = lhs;

    for (int i = remainder._order; i >= rhs._order; --i)
    {
        if (remainder._order < rhs._order)
        {
            break;                              //stop the loop early
        }

        Term leading_remainder = remainder[remainder._order];
        Term leading_rhs = rhs[rhs._order];             

        if (double_equal(leading_rhs._coef, 0.0))
        {
            Poly empty;
            return empty;
        }

        Term quotient_term = leading_remainder / leading_rhs;

        quotient = quotient + quotient_term;

        Poly subtraction_result = rhs * quotient_term;
        remainder = remainder - subtraction_result;
    }
    quotient.fix_order();

    return quotient;
}

Poly operator %(const Poly& lhs, const Poly& rhs)
{
    Poly quotient;
    Poly remainder = lhs;

    for (int i = remainder._order; i >= rhs._order; --i)
    {
        if (remainder._order < rhs._order)
        {
            break;                              //stop the loop early
        }

        Term leading_remainder = remainder[remainder._order];
        Term leading_rhs = rhs[rhs._order];             

        if (double_equal(leading_rhs._coef, 0.0))
        {
            Poly empty;
            return empty;
        }

        Term quotient_term = leading_remainder / leading_rhs;

        quotient = quotient + quotient_term;

        Poly subtraction_result = rhs * quotient_term;
        remainder = remainder - subtraction_result;

        remainder.fix_order();
    }
    quotient.fix_order();

    return remainder;
}

ostream& operator <<(ostream& outs, const Poly& p)
{
    for(int i = 0; i < p._order; i++)
    {
        outs << p[p._order - i] << " + ";
    }
    outs << p[0];
    return outs;
}
istream& operator >>(istream& ins, Poly& p)
{

}

double* Poly::get_coefs() const
{
    return _coefs;
}

void Poly::set_order(int new_order)
{

}                            //Not used!
void Poly::fix_order()
{
    double* coef = _coefs + _order;
    while(double_equal(*coef, 0.00) && coef > _coefs)
    {
        _order--;
        coef--;
    }
}

void Poly::resize(int new_order)
{
    if(new_order <= _order)
    {
        return; //Early return to consider edge cases where we dont need to resize
    }
    double* new_coefs_array = allocate<double>(new_order + 1);
    init_array(new_coefs_array, new_order + 1, 0.0);
    copy_array(new_coefs_array, _coefs, _order + 1);

    delete [] _coefs;

    _coefs = new_coefs_array;
    _order = new_order;
}

