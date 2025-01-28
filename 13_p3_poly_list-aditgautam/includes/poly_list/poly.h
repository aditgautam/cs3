//
// Created by Adit Gautam on 10/15/24.
//

#ifndef BARKESHLI_S22_POLY_H
#define BARKESHLI_S22_POLY_H


#include "../node/node.h"
#include "../list_sorted/list_sorted.h"
#include "../term/term.h"
#include <iostream>
#include <vector>

using namespace std;


class Poly
{
public:

    Poly();
    Poly(double *term_array, int order);
    Poly(const vector<double>& terms);
    //big three?

    Poly(const Poly& other);
    Poly& operator =(const Poly& RHS);

    Poly& operator +=(const Term& t);
    Poly& operator *=(const Term& t);

    Poly& operator +=(const Poly& RHS);
    Poly& operator *=(const Poly& RHS);
    Poly& operator -=(const Poly& RHS);

    friend bool operator==(const Poly &left, const Poly &right);
    friend bool operator!=(const Poly &left, const Poly &right);
    friend Poly operator+(const Poly &left, const Poly &right);
    friend Poly operator -(const Poly& left, const Poly& right);
    friend Poly operator * (const Poly& left, const Poly& right);
    friend Poly operator/(const Poly &left, const Poly &right);
    friend Poly operator%(const Poly &left, const Poly &right);
    Poly operator-() const;

    friend Poly operator + (const Poly& left, const Term& t);
    friend Poly operator * (const Poly& left, const Term& t);

    friend ostream& operator << (ostream& outs, const Poly& print_me);
    friend istream& operator >> (istream& outs, Poly& read_me);

    const Term& operator [](const int exp) const;
    Term& operator [](const int exp);
    List<Term> list() const { return _poly; }

    void remove_empty_terms();

private:
    List<Term> _poly; //descending sorted list
    int _order;

};


#endif //BARKESHLI_S22_POLY_H
