#include "mcounter.h"
   
MCounter::MCounter()
{
    _count = 0;
    _error = false;
}
int MCounter::add_1()
{
    if(!check_error(1))
    {
        return add(1);
    }
    return -9999;
}
int MCounter::add_10()
{
    if(!check_error(10))
    {
        return add(10);
    }
    return -9999;
}
int MCounter::add_100()
{
    if(!check_error(100))
    {
        return add(100);
    }
    return -9999;
}
int MCounter::add_1000()
{
    if(!check_error(1000))
    {
        return add(1000);
    }
    return -9999;
}
int MCounter::reset()
{
    _error = false;
    return (_count = 0);
}                //reset error  state, _count
int MCounter::count() const
{
    return _count;
}          //returns _count

bool MCounter::error() const 
{
    return _error;
}         //returns _error

bool MCounter::is_error() const
{
    if(_count  > 9999)
    {
        return true;
    }
    return false;
}      //true  if an error has occurred

bool MCounter::check_error(int n)
{
    if(_count + n > 9999 || _count == -9999)
    {
        _error = true;
        _count = -9999;
        return true;
    }
    return false;
}
int MCounter::add(int n)
{
    _count += n;
    return _count;
}