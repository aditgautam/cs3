#include "rpn.h"

RPN::RPN(Queue<Token*> postfix) : _postfix(postfix) {};

void RPN::set_input(Queue<Token*> new_postfix){
    _postfix = new_postfix;
}

double RPN::operator()(){
    return evaluate();
}

double RPN::operator()(double evaluateMe){
    return evaluate(evaluateMe, true);
}

double RPN::evaluate(double variableValue, bool useVariable){
    while(!_postfix.empty()){
        Token* token = _postfix.pop();

        switch(token -> get_type()){
            case 1: {                   //Integer
                _stack.push(token);
                break;
            }
            case 2 : {                  //Operator
                Operator* op = dynamic_cast<Operator*>(token);

                if(_stack.size() < 2){
                    throw runtime_error("Expected at least 2 operands in the stack");
                }

                Token* rhs = _stack.pop();
                Token* lhs = _stack.pop();

                double result = op -> operate(lhs, rhs);

                _stack.push(new Integer(result));

                delete lhs;
                delete rhs;
                break;
            }
            case 5 : {
                if(useVariable){
                    _stack.push(new Integer(variableValue));
                }
                else{
                    throw runtime_error("Variable being pushed did not have a value");
                }
                break;
            }
            default : {
                throw runtime_error("Token being created was not of a valid type: " );
            }
        }
    }

    if (_stack.size() != 1){
            throw runtime_error("Should only be one token in the stack");
        }

        double final_result = _stack.pop() -> get_value();

        while(!_stack.empty()){
            cout << "Stack was not empty, cleaning up" << endl;
            delete _stack.pop();
        }
    return final_result;
}