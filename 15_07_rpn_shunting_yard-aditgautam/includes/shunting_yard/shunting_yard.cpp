#include "shunting_yard.h"

Queue<Token*> ShuntingYard::postfix(){
    return postfix(_infix);
}

Queue<Token*> ShuntingYard::postfix(Queue<Token*> infix) {

    Queue<Token*> postfixQueue;                         //What we are returning
    Stack<Token*> operatorStack;

    for(Queue<Token*>::Iterator walker = infix.begin(); walker != infix.end(); ++walker){       //Traversing the whole queue

        Token* token = *walker;

        cout << "Processing token with type " << token -> get_type() << endl;

        if( token -> get_type() == 1 ) //If token is an integer
        {
            postfixQueue.push(token);   //Push the token to the postfix queue
        }
        else if(is_operator(token))    //If token is an operator
        {
            apply_operator(operatorStack, postfixQueue, token); //use helper function
        }
        else if( token -> get_type() == 3 || token -> get_type() == 4) //If token is parenthesis, helper handles type
        {
            apply_parenthesis(operatorStack, postfixQueue, token);
        }
        else if( token -> get_type() == 5)
        {
            postfixQueue.push(token);
        }
        else
        {
            throw runtime_error("Token type was invalid");
        }
    }
    while(!operatorStack.empty()){
        postfixQueue.push(operatorStack.pop());
    }
    return postfixQueue;
}

bool ShuntingYard::is_operator(Token* token) const{
    return token -> get_type() == 2;
}

void ShuntingYard::apply_parenthesis(Stack<Token*>& operatorStack, Queue<Token*>& postfixQueue, Token* token){
    if(token -> get_type() == 3)                //If left parentheses
    {
        operatorStack.push(token);
    }
    else if( token -> get_type() == 4){         //If right parentheses
        while(!operatorStack.empty() && operatorStack.top() -> get_type() != 3){
            postfixQueue.push(operatorStack.pop());
        }
        if(!operatorStack.empty() && operatorStack.top() -> get_type() == 3){
            delete operatorStack.pop();
        }
    }

}
void ShuntingYard::apply_operator(Stack<Token*>& operatorStack, Queue<Token*>& postfixQueue, Token* token){
        Operator* op = dynamic_cast<Operator*>(token);

    while(!operatorStack.empty() && is_operator(operatorStack.top())){
        Operator* topOperator = dynamic_cast<Operator*>(operatorStack.top());

        if(topOperator -> get_precedence() >= op -> get_precedence()){
            postfixQueue.push(operatorStack.pop());
        }
        else{
            break;
        }
    }
    operatorStack.push(token);
}