#include "counter_type.h"

using namespace std;

Counter_Type::Counter_Type()
{
    _count = 0;
    _error = false;
}
Counter_Type::Counter_Type(int n)
{
    _count = n;
    _error = false;
}

bool Counter_Type::inc()
{
    _count++;
    return true;
}

bool Counter_Type::dec()
{
    if(_count == 0)
    {
        _error = true;
        return false;
    }
    _count--;
    return true;
}

bool Counter_Type::is_error() const
{
    if(_error)
    {
        return true;
    }
    return false;
}

bool Counter_Type::reset()
{
    _count = 0;
    _error = false;
    if(_count == 0 && _error == false)
    {
        return true;
    }
    return false;
}

int Counter_Type::count() const
{
    return _count;
}

void display()
{

}


