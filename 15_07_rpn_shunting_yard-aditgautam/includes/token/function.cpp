#include "function.h"

double Function::apply(double operand) const{
    if(_name == "X"){
        return operand;
    }
    else if(_name == "sin"){
        return sin(operand);
    }
    else if(_name == "cos"){
        return cos(operand);
    }
    else if(_name == "tan"){
        return tan(operand);
    }
    else if(_name == "log"){
        if(operand < 0 ){
            throw domain_error("Log argument cannot be negative");
        }
        return log(operand);
    }
    else{
        throw invalid_argument("Not a valid function: " + _name);
    }
}