#include "rational.h"

Rational::Rational()
{
    _n = 0;
    _d = 1;
}
Rational::Rational(int num, int denom)
{
    _n = num;
    _d = denom;
}
Rational::Rational(int w)
{
    _n = w;
    _d = 1;
}

void Rational::set(int num, int denom)
{
    _n = num;
    _d = denom;
}
void Rational::set_num(int n)
{
    _n = n;
}
void Rational::set_denom(int d)
{
    _d = d;
}

int Rational::get_num() const
{
    return _n;
}
int Rational::get_denom() const
{
    return _d;
}

int Rational::error() const
{
    return is_error();
}     //return error state
string Rational::error_description() const
{
    if(is_error() == 1)
    {
        return "Denominator is zero";
    }
    return "no error";
}
void Rational::reset()
{
    _n = 0;
    _d = 1;
    _error = 0;
}

Rational operator +(const Rational &num1, const Rational &num2)
{
    if(num1.error() == 1 || num2.error() ==1)
    {
        return Rational(1,0);
    }
    Rational result;
    if(num1.get_denom() == num2.get_denom())
    {
        result.set_num(num1.get_num() + num2.get_num());
        result.set_denom(num1.get_denom());
        return result;
    }

    result.set_num((num1.get_num() * num2.get_denom()) + (num2.get_num() * num1.get_denom()));
    result.set_denom((num1.get_denom() * num2.get_denom()));

    return result;

}
Rational operator -(const Rational &num1, const Rational &num2)
{
    if(num1.error() == 1 || num2.error() ==1)
    {
        return Rational(1,0);
    }
    Rational result;
    if(num1.get_denom() == num2.get_denom())
    {
        result.set_num(num1.get_num() - num2.get_num());
        result.set_denom(num1.get_denom());
        return result;
    }

    result.set_num((num1.get_num() * num2.get_denom()) - (num2.get_num() * num1.get_denom()));
    result.set_denom((num1.get_denom() * num2.get_denom()));

    return result;
}
Rational operator *(const Rational &num1, const Rational &num2)
{
    if(num1.error() == 1 || num2.error() ==1)
    {
        return Rational(1,0);
    }
    Rational result;

    result.set_num(num1.get_num() * num2.get_num());
    result.set_denom(num1.get_denom() * num2.get_denom());

    return result;
}
Rational operator /(const Rational &num1, const Rational &num2)
{
    if(num1.error() == 1 || num2.error() ==1)
    {
        return Rational(1,0);
    }
    Rational result;

    result.set_num(num1.get_num() * num2.get_denom());
    result.set_denom(num1.get_denom() * num2.get_num());

    return result;
}

ostream& operator <<(ostream &outs, const Rational &num)
{
    if(num.is_error() == 1)
    {
        return cout << "UNDEFINED";
    }
    return cout << num.get_num() << "/" << num.get_denom();
}
istream& operator >>(istream &ins, Rational &num)
{
    return ins;
}

int Rational::is_error() const
{
    if(_d == 0)
    {
        return 1;
    }
    return 0;
}