//
// Created by Adit Gautam on 10/15/24.
//

#include "poly.h"

Poly::Poly() {
    _poly = List<Term>(false);
    _poly.insert(Term(0.0, 0));
    _order = 0;
}

Poly::Poly(const Poly& other){
    _poly = other._poly;
    _order = other._order;
}

Poly& Poly::operator =(const Poly& RHS){
    if(this == &RHS){
        return *this;
    }
    _poly = RHS._poly;
    _order = RHS._order;
    return *this;
}

Poly::Poly(double *term_array, int order) {
    for(int i = 0; i <= order; i++){
        if(!double_equals(term_array[i], 0.0)){
            Term term(term_array[i], i);
            _poly.insert(term);
        }
    }
    _order = order;
}

Poly::Poly(const vector<double> &terms) {
    _poly = List<Term>(false,false);
    for(int i = 0; i <= terms.size(); i++){
        if(!double_equals(terms[i], 0.0)){
            Term term(terms[i], i);
            _poly.insert(term);
        }
    }
    if(_poly.empty()){
        _poly.insert(Term(0.0,0));
    }
    _order = _poly.begin() -> _exp;
    // _poly.insert(Term(0.0, 0));
    // _order = 0;
}

Poly &Poly::operator+=(const Term &t) {
    _poly.insert_and_add(t);
    remove_empty_terms();
    return *this;
}

Poly &Poly::operator*=(const Term &t) {
    List<Term>::Iterator walker = _poly.begin();
    while(walker != _poly.end()){
        *walker = (*walker) * t;
        ++walker;
    }
    remove_empty_terms();
    return *this;
}

Poly &Poly::operator+=(const Poly &RHS) {
    List<Term>::Iterator walker = RHS._poly.begin();
    while(walker != RHS._poly.end()){
        _poly.insert_and_add(*walker);
        ++walker;
    }
    remove_empty_terms();
    return *this;
}

Poly &Poly::operator*=(const Poly &RHS) {
    Poly result;

    for(List<Term>::Iterator walker = RHS._poly.begin(); walker != RHS._poly.end(); ++walker){
        Poly temp = *this;
        temp *= *walker;
        result += temp;
    }
    *this = result;
    return *this;
}

Poly &Poly::operator-=(const Poly &RHS) {
    *this += -RHS;
    return *this;
}

Poly Poly::operator-() const {
    Term negative (-1.0, 0);
    Poly result = *this;
    return result *= negative;
}

const Term &Poly::operator[](const int exp) const {

}

Term &Poly::operator[](const int exp) {

}

bool operator==(const Poly &left, const Poly &right){
    if(left._order != right._order){
        return false;
    }
    List<Term>::Iterator left_walker = left._poly.begin();
    List<Term>::Iterator right_walker = right._poly.begin();

    while(left_walker != left._poly.end() && right_walker != right._poly.end()){
        if(!(double_equals(left_walker -> _coef, right_walker -> _coef)) || left_walker -> _exp != right_walker -> _exp){
            return false;
        }
        ++left_walker;
        ++right_walker;
    }
    if( left_walker != left._poly.end() || right_walker != right._poly.end()){
        return false;
    }
    return true;
}
bool operator!=(const Poly &left, const Poly &right){
    return !(left == right);

}
Poly operator+(const Poly &left, const Poly &right){
    Poly result = left;
    result += right;
    result.remove_empty_terms();
    return result;
}
Poly operator -(const Poly& left, const Poly& right){
    Poly result = left;
    result -= right;
    result.remove_empty_terms();
    return result;
}
Poly operator * (const Poly& left, const Poly& right){
    Poly result = left;
    result *= right;
    result.remove_empty_terms();
    return result;

}
Poly operator/(const Poly &left, const Poly &right){
    Poly quotient;
    Poly remainder = left;

    while(remainder._order >= right._order){
        Term remainder_leading_term = *remainder._poly.begin();
        Term divisor_leading_term = *right._poly.begin();

        if(double_equals(divisor_leading_term._coef, 0.0)){
            return Poly();
        }
        if(left._order == 0 && right._order == 0)
        {
            Term result = (*left._poly.begin() / *right._poly.begin());
            quotient._poly.insert_and_add(result);
            quotient._order = 0;
            return quotient;
        }


        Term quotient_term = remainder_leading_term / divisor_leading_term;

        quotient += quotient_term;
        Poly subtraction_result = right * quotient_term;

        remainder -= subtraction_result;
        // remainder.remove_empty_terms();
    }

    return quotient;

}
Poly operator%(const Poly &left, const Poly &right){
    Poly quotient;
    Poly remainder = left;

    while(remainder._order >= right._order){
        Term remainder_leading_term = *remainder._poly.begin();
        Term divisor_leading_term = *right._poly.begin();

        if(double_equals(divisor_leading_term._coef, 0.0)){
            return Poly();
        }

        Term quotient_term = remainder_leading_term / divisor_leading_term;

        quotient += quotient_term;
        Poly subtraction_result = right * quotient_term;

        remainder -= subtraction_result;
        // remainder.remove_empty_terms();
    }

    // quotient.remove_empty_terms();

    return remainder;
}


Poly operator + (const Poly& left, const Term& t){
    Poly result = left;
    result+=t;
    result.remove_empty_terms();
    return result;

}
Poly operator * (const Poly& left, const Term& t){
    Poly result = left;
    result*=t;
    result.remove_empty_terms();
    return result;
}

ostream& operator << (ostream& outs, const Poly& print_me){
    List<Term>::Iterator walker = print_me._poly.begin();

    if( walker == print_me._poly.end() ){
        outs << "0.0 (empty)" << endl;
        return outs;
    }

    outs << *walker;
    ++walker;

    while(walker != print_me._poly.end()){
        if(walker -> _coef >= 0.0){
            outs << " + " << *walker;
        }
        else{
            outs << " - " << Term(-walker->_coef, walker ->_exp);
        }
        ++walker;
    }
    outs << endl;
    return outs;
}
istream& operator >> (istream& outs, Poly& read_me){
    return outs;
}

void Poly::remove_empty_terms(){
    List<Term>::Iterator walker = _poly.begin();
    while(walker != _poly.end()){
        if(double_equals(walker->_coef, 0.0)){
            List<Term>::Iterator temp = walker;
            ++walker;
            _poly.Delete(temp);
        }
        else{
            ++walker;
        }
    }
    if(_poly.empty()){
        _poly.insert(Term(0.0, 0));
        _order = 0;
    }
    else{
        _order = _poly.begin() ->_exp;
    }
}
