#include "operator.h"
#include <cassert>
#include <cmath>

Operator::Operator(const string& op) : Token(2), _op(op), _left_asc(op != "^"){
    set_precedence(op);
}

double Operator::get_value() const {
    throw logic_error("Operators have no value");
}

double Operator::operate(Token* LHS, Token* RHS){
    double lhs_value = LHS -> get_value();
    double rhs_value = RHS -> get_value();

    if(_op == "+"){
        return lhs_value + rhs_value;
    }
    else if(_op == "-"){
        return lhs_value - rhs_value;
    }
    else if(_op == "*"){
        return lhs_value * rhs_value;
    }
    else if(_op == "/"){
        if(rhs_value == 0){
            throw runtime_error("Cannot divide by 0");
        }
        return lhs_value/rhs_value;
    }
    else if(_op == "^"){
        return pow(lhs_value, rhs_value);
    }
    throw invalid_argument("This argument is not an operator: " + _op);
}

void Operator::set_precedence(const string& op){
    if(op == "+" || op == "-"){
        _precedence = 1;
    }
    else if( op == "*" || op == "/"){
        _precedence = 2;
    }
    else if( op == "^"){
        _precedence = 3;
    }
    else{
        throw invalid_argument("This argument is not an operator " + op);
    }
}