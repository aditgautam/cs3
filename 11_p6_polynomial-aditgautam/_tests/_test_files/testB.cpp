#include "gtest/gtest.h"
#include "../../includes/poly/poly.h"
#include <iostream>
#include <iomanip>
using namespace std;

bool test_poly(bool debug = false)
{
  cout << "\n============================" << endl;
  cout << "       START POLY TEST " << endl;
  cout << "============================\n" << endl;

  cout << "Tests constructors, printing, and assignment operator\n" << endl;

  double coefs1[] = {8.0,5.0,6.0,0.0,4.0};
  double coefs2[] = {2.0,7.0,3.0,0.0, 1.0, 9.0};
  double coefs3[] = {0.0,0.0,0.0,0.0};
  Poly p(coefs1, 4);
  Poly q(coefs2, 5);
  Poly t(coefs3, 3);
  Poly e;
  cout << "(Standard Poly) p: " << p << endl;
  cout << "Expected Output: 4.0x^4 +0.0x^3 +6.0x^2 +5.0x +8.0\n" << endl;

  cout << "(Standard Poly) q:" << q << endl;
  cout << "Expected Output: 9.0x^5 +1.0x^4 +0.0x^3 +3.0x^2 +7.0x +2.0\n" << endl;

  cout << "(Zero Poly) t: " << t << endl;
  cout << "Expected Output: 0.0\n" << endl;

  cout << "(Empty Poly) e: " << e << endl;
  cout << "Expected Output: 0.0\n" << endl;

  e = p;

  cout << "e = p: " << e << endl;
  cout << "Expected Output: 4.0x^4 +0.0x^3 +6.0x^2 +5.0x +8.0\n" << endl;

  e = q;

  cout << "e = q: " <<  e << endl;
  cout << "Expected Output: 9.0x^5 +1.0x^4 +0.0x^3 +3.0x^2 +7.0x +2.0\n" << endl;

  cout << "\n============================" << endl;
  cout << "        END POLY TEST " << endl;
  cout << "============================\n" << endl;

  return true;
}

bool test_add(bool debug = false)
{
  cout << "\n============================" << endl;
  cout << "     START ADDITION TEST " << endl;
  cout << "============================\n" << endl;

  double coefs[] = {8.0,5.0,6.0,0.0,4.0};
  double coefs2[] = {2.0,-7.0,3.0,0.0, 1.0, 9.0};
  Term t(0,5);
  Term t1(5,0);
  Term t2(0,0);
  Term t7(2, 11);
  Term t3(1,2);
  Term t4(2,4);
  Term t5(3,6);
  Poly p1(coefs2, 5);
  Poly p(coefs, 4);
  Poly mpt;

  cout << "============================" << endl;
  cout << "TESTNG STANDRD / EDGE CASES: " << endl;
  cout << "============================\n" << endl;
  cout << "p: " << p << endl;

  cout << "polynomial + term with 0 coefficient" << endl;
  cout << "p + " << t << " = " << p + t << endl;
  cout << "Expected Output: 4.0x^4 +0.0x^3 +6.0x^2 +5.0x +8.0\n" << endl;

  cout << "polynomial + constant term, 0 order" << endl;
  cout << "p + " << t1 << " = " << p + t1 << endl;
  cout << "Expected Output: 4.0x^4 +0.0x^3 +6.0x^2 +5.0x +13.0\n" << endl;

  cout << "polynomial + 0 term" << endl;
  cout << "p + " << t2 << " = " << p + t2 << endl;
  cout << "Expected Output: 4.0x^4 +0.0x^3 +6.0x^2 +5.0x +8.0\n" << endl;

  cout << "polynomial + high order term, checks resizing" << endl;
  cout << "p + " << t7 << " = " << p + t7 << endl;
  cout << "Expected Output: 2.0x^11 +0.0x^10 +0.0x^9 +0.0x^8 +0.0x^7 +0.0x^6 +0.0x^5 +4.0x^4 +0.0x^3 +6.0x^2 +5.0x +8.0\n" << endl;

  cout << "adding term to empty polynomial" << endl;
  cout << "empty + t3 = " << mpt + t5 << endl;
  cout << "Expected Output: 3.0x^6 +0.0x^5 +0.0x^4 +0.0x^3 +0.0x^2 +0.0x +0.0\n" << endl;

  cout << "sequential addition of terms" << endl;
  cout << "p + " << t3 << " + " << t4 << " + " << t5 << " = " <<  p + t3 + t4 + t5 <<endl;
  cout << "Expected Output: \n" << endl;

  cout << "============================" << endl;
  cout << "   TESTING POLY + POLY: " << endl;
  cout << "============================\n" << endl;

  cout << "p1: " << p << endl;
  cout << "p2: " << p1 << endl;

  cout << "(Standard Poly + Poly) p1 + p2 = " << endl;
  cout << p + p1 << endl;
  cout << "Expected Output: 9.0x^5 +5.0x^4 +0.0x^3 +9.0x^2 -2.0x +10.0\n" << endl;

  cout << "(Sequential addition of polynomials) p1 + p2 + p2 + p2 = " << endl;
  cout << p + p1 + p1 + p1 << endl;
  cout << "Expected Output: 27.0x^5 +7.0x^4 +0.0x^3 +15.0x^2 -16.0x +14.0\n" << endl;

  cout << "============================" << endl;
  cout << "TESTING POLY + POLY EDGE CASES: " << endl;
  cout << "============================\n" << endl;

  double coefs3[] = {8.0,5.0,6.0,0.0,4.0};
  double coefs4[] = {2.0,7.0,3.0,0.0,1.0,9.0};
  double coefs5[] = {0.0,0.0,0.0,0.0};
  double coefs5a[] = {3.0,4.0,0.0,0.0};
  double coefs6[] = {-8.0,-5.0,-6.0,0.0,-4.0};
  double coefs7[] = {12, -4, 23, 5, 0, 49, 37, 6, 19, 3, -10, 45, 15, 20, 48, -8, 33, 7, -1, 22, 50, 17, -9, 27, 40, 13, -3, 36, 44, 25, 2, 16, 18, 39, -6, 30, 21, 9, -7, 31};
  Poly o(coefs3, 4);
  Poly u(coefs4, 5);
  Poly y(coefs5, 3);
  Poly y2(coefs5a, 3);
  Poly g(y);
  Poly h(coefs5, 3);
  Poly f(coefs3, -1);
  Poly z(coefs6, 4);
  Poly empty;
  Poly large(coefs7, 39);

  Term l(0,0);

  cout << "(Standard Case) o + u = " << endl;
  cout << "Sum: " << o + u << endl;
  cout << "Expected Output: 9.0x^5 +5.0x^4 +0.0x^3 +9.0x^2 +12.0x +10.0\n" << endl;

  cout << "(Poly + Self) o + o = " << endl;
  cout << "Sum: " << o + o << endl;
  cout << "Expected Output: 8.0x^4 +0.0x^3 +12.0x^2 +10.0x +16.0\n" << endl;

  cout << "(poly + poly with all negative coefficients) o + z = " << endl;
  cout << "Sum: " << o + z << endl;
  cout << "Expected Output: 0.0\n" << endl;

  cout << "(empty poly + poly) empty + o " << endl;
  cout << "Sum: " << empty + o << endl;
  cout << "Expected Output: 4.0x^4 +0.0x^3 +6.0x^2 +5.0x +8.0\n" << endl;

  cout << "(empty poly + poly with all negative coefficients) empty + z " << endl;
  cout << "Sum: " << empty + z << endl;
  cout << "Expected Output: -4.0x^4 +0.0x^3 -6.0x^2 -5.0x -8.0\n" << endl;

  cout << "(empty poly + empty poly) empty + empty " << endl;
  cout << "Sum: " << empty + empty << endl;
  cout << "Expected Output: 0.0\n" << endl;

  cout << "(empty poly + zero term) empty + l " << endl;
  cout << "Sum: " << empty + l << endl;
  cout << "Expected Output: 0.0\n" << endl;

  cout << "(zero poly + zero poly) y + y " << endl;
  cout << "Sum: " << y + y << endl;
  cout << "Expected Output: 0.0\n" << endl;

  cout << "(empty poly sequential addition) empty + y + h + o + u " << endl;
  cout << "Sum: " << empty + y + h + o + u << endl;
  cout << "Expected Output: 9.0x^5 +5.0x^4 +0.0x^3 +9.0x^2 +12.0x +10.0\n" << endl;

  cout << "(empty poly + large order polynomial) empty + large " << endl;
  cout << "Sum: " << empty + large << endl;
  cout << "Expected Output: 31.0x^39 -7.0x^38 +9.0x^37 +21.0x^36 +30.0x^35 -6.0x^34 +39.0x^33 +18.0x^32 +16.0x^31 +2.0x^30 +25.0x^29 +44.0x^28 +36.0x^27 -3.0x^26 +13.0x^25 +40.0x^24 +27.0x^23 -9.0x^22 +17.0x^21 +50.0x^20 +22.0x^19 -1.0x^18 +7.0x^17 +33.0x^16 -8.0x^15 +48.0x^14 +20.0x^13 +15.0x^12 +45.0x^11 -10.0x^10 +3.0x^9 +19.0x^8 +6.0x^7 +37.0x^6 +49.0x^5 +0.0x^4 +5.0x^3 +23.0x^2 -4.0x +12.0\n" << endl;

  cout << "(larger order + large order) large + large " << endl;
  cout << "Sum: " << large + large << endl;
  cout << "Expected Output: 62.0x^39 -14.0x^38 +18.0x^37 +42.0x^36 +60.0x^35 -12.0x^34 +78.0x^33 +36.0x^32 +32.0x^31 +4.0x^30 +50.0x^29 +88.0x^28 +72.0x^27 -6.0x^26 +26.0x^25 +80.0x^24 +54.0x^23 -18.0x^22 +34.0x^21 +100.0x^20 +44.0x^19 -2.0x^18 +14.0x^17 +66.0x^16 -16.0x^15 +96.0x^14 +40.0x^13 +30.0x^12 +90.0x^11 -20.0x^10 +6.0x^9 +38.0x^8 +12.0x^7 +74.0x^6 +98.0x^5 +0.0x^4 +10.0x^3 +46.0x^2 -8.0x +24.0\n" << endl;

  cout << "\n============================" << endl;
  cout << "     END ADDITION TEST " << endl;
  cout << "============================\n" << endl;

  return true;
}

bool test_sub(bool debug = false)
{
  cout << "\n============================" << endl;
  cout << "    START SUBTRACTION TEST " << endl;
  cout << "============================\n" << endl;

  double coefs[] = {8.0,5.0,6.0,0.0,4.0};
  Poly p(coefs, 4);

  cout << "============================" << endl;
  cout << "   TESTING POLY - POLY: " << endl;
  cout << "============================\n" << endl;

  double coefs2[] = {2.0,-7.0,3.0,0.0, 1.0, 9.0};
  Poly p1(coefs2, 5);

  cout << "p1: " << p << endl;
  cout << "p2: " << p1 << endl;

  cout << "(poly - poly) p1 - p2 = " << endl;
  cout << "Difference: " << p - p1 << endl;
  cout << "Expected Output: -9.0x^5 +3.0x^4 +0.0x^3 +3.0x^2 +12.0x +6.0\n" << endl;

  cout << "(sequential subtraction) p1 - p2 - p2 - p2 = " << endl;
  cout << "Difference: " << p - p1 - p1 - p1 << endl;
  cout << "Expected Output: -27.0x^5 +1.0x^4 +0.0x^3 -3.0x^2 +26.0x +2.0\n" << endl;

  cout << "============================" << endl;
  cout << "TESTING POLY - POLY EDGE CASES: " << endl;
  cout << "============================\n" << endl;

  double coefs3[] = {8.0,5.0,6.0,0.0,4.0};
  double coefs4[] = {2.0,7.0,3.0,0.0,1.0,9.0};
  double coefs5[] = {0.0,0.0,0.0,0.0};
  double coefs6[] = {-8.0,-5.0,-6.0,0.0,-4.0};
  double coefs7[] = {12, -4, 23, 5, 0, 49, 37, 6, 19, 3, -10, 45, 15, 20, 48, -8, 33, 7, -1, 22, 50, 17, -9, 27, 40, 13, -3, 36, 44, 25, 2, 16, 18, 39, -6, 30, 21, 9, -7, 31};
  Poly o(coefs3, 4);
  Poly u(coefs4, 5);
  Poly y(coefs5, 3);
  Poly g(y);
  Poly h(coefs5, 3);
  Poly f(coefs3, -1);
  Poly z(coefs6, 4);
  Poly empty;
  Poly large(coefs7, 39);

  cout << "(Standard case) o - u = " << endl;
  cout << "Difference: " << o - u << endl;
  cout << "Expected Output: -9.0x^5 +3.0x^4 +0.0x^3 +3.0x^2 -2.0x +6.0\n" << endl;

  cout << "(Poly - self) o - o = " << endl;
  cout << "Difference: " << o - o << endl;
  cout << "Expected Output: 0.0\n" << endl;

  cout << "(poly - poly with negative coefficients) o - z = " << endl;
  cout << "Difference: " << o - z << endl;
  cout << "Expected Output: 8.0x^4 +0.0x^3 +12.0x^2 +10.0x +16.0\n" << endl;

  cout << "(empty poly - poly) empty - o " << endl;
  cout << "Difference: " << empty - o << endl;
  cout << "Expected Output: -4.0x^4 +0.0x^3 -6.0x^2 -5.0x -8.0\n" << endl;

  cout << "(empty poly - poly with all negative coefficients) empty - z " << endl;
  cout << "Difference: " << empty - z << endl;
  cout << "Expected Output: 4.0x^4 +0.0x^3 +6.0x^2 +5.0x +8.0\n" << endl;

  cout << "(empty poly - empty poly) empty - empty " << endl;
  cout << "Difference: " << empty - empty << endl;
  cout << "Expected Output: 0.0\n" << endl;

  cout << "(zero poly - zero poly) y - y " << endl;
  cout << "Difference: " << y - y << endl;
  cout << "Expected Output: 0.0\n" << endl;

  cout << "(empty poly sequential subtraction) empty - y - h - o - u " << endl;
  cout << "Difference: " << empty - y - h - o - u << endl;
  cout << "Expected Output: -9.0x^5 -5.0x^4 +0.0x^3 -9.0x^2 -12.0x -10.0\n" << endl;

  cout << "(empty poly - large order poly) empty - large " << endl;
  cout << "Difference: " << empty - large << endl;
  cout << "Expected Output: -31.0x^39 +7.0x^38 -9.0x^37 -21.0x^36 -30.0x^35 +6.0x^34 -39.0x^33 -18.0x^32 -16.0x^31 -2.0x^30 -25.0x^29 -44.0x^28 -36.0x^27 +3.0x^26 -13.0x^25 -40.0x^24 -27.0x^23 +9.0x^22 -17.0x^21 -50.0x^20 -22.0x^19 +1.0x^18 -7.0x^17 -33.0x^16 +8.0x^15 -48.0x^14 -20.0x^13 -15.0x^12 -45.0x^11 +10.0x^10 -3.0x^9 -19.0x^8 -6.0x^7 -37.0x^6 -49.0x^5 +0.0x^4 -5.0x^3 -23.0x^2 +4.0x -12.0\n" << endl;

  cout << "(large order poly - large order poly) large - large " << endl;
  cout << "Difference: " << large - large << endl;
  cout << "Expected Output: 0.0\n" << endl;

  cout << "\n============================" << endl;
  cout << "    END SUBTRACTION TEST " << endl;
  cout << "============================\n" << endl;

  return true;
}

bool test_multi(bool debug = false)
{
  cout << "\n============================" << endl;
  cout << "     START MULTI TEST " << endl;
  cout << "============================\n" << endl;

  double coefs1[] = {8.0,12.0,0.0,6.0,4.0};

  double coefs4[] = {7.0,3.0,2.0};
  double coefs5[] = {4.0,5.0,0.0,0.0,0.0,0.0,0.0};
  double coefs6[] = {4.0,5.0};
  Poly p(coefs1, 4);
  Poly g(coefs4,2);
  Poly n(coefs5, 6);
  Poly n2(coefs6,1);
  Term k(4,4);

  cout << "Standard poly * Term" << endl;
  cout << g << " * " << k << endl;
  cout << "Product: " << g * k << endl;
  cout << "Expected Output: 8.0x^6 +12.0x^5 +28.0x^4 +0.0x^3 +0.0x^2 +0.0x +0.0\n" << endl;

  cout << "Standard Poly * Poly" << endl;
  cout << p << " * " << g << endl;
  cout << "Product: " << p * g << endl;
  cout << "Expected Output: 8.0x^6 +24.0x^5 +46.0x^4 +66.0x^3 +52.0x^2 +108.0x +56.0\n" << endl;

  cout << "poly * larger order poly that has a lot of 0 coefficients" << endl;
  cout << p << " * " << n << endl;
  cout << "Product: " << p * n << endl;
  cout << "Expected Output: 20.0x^5 +46.0x^4 +24.0x^3 +60.0x^2 +88.0x +32.0\n" << endl;



  cout << "\n============================" << endl;
  cout << "     END MULTI TEST " << endl;
  cout << "============================\n" << endl;

  return true;
}

bool test_div(bool debug = false)
{
  cout << "\n============================" << endl;
  cout << "     START DIVISION TEST " << endl;
  cout << "============================\n" << endl;

  double coefs2[] = {7.0, 3.0, 2.0};
  double coefs1[] = {8.0, 12.0, 0.0, 6.0, 4.0};
  double coefs3[] = {4.0, 5.0, 0.0, 0.0, 0.0};
  double coefs4[] = {13.0};
  double coefs_zero[] = {0.0, 0.0, 0.0};
  double coefs5[] = {8.0, 9.0, 7.0, 6.0, 6.0, 12.0};

  Poly a(coefs1, 4);
  Poly b(coefs2, 2);
  Poly c(coefs3, 4);
  Poly d(coefs4, 0);
  Poly z(coefs5, 7);
  Poly zero_poly(coefs_zero, 2);

  cout << "Standard division:" << endl;
  cout << a << " / " << b << endl;
  cout << "Quotient: " << a / b << endl;
  cout << "Expected Output: 2.0x^2 +0.0x -7.0\n" << endl;

  cout << "low order / high order" << endl;
  cout << a << " / " << z << endl;
  cout << "Quotient: " << a / z << endl;
  cout << "Expected Output: 0.0\n" << endl;

  cout << "constant term" << endl;
  cout << a << " / " << d << endl;
  cout << "Quotient: " << a / d << endl;
  cout << "Expected Output: 0.3x^4 +0.5x^3 +0.0x^2 +0.9x +0.6\n" << endl;

  cout << "divide by self" << endl;
  cout << a << " / " << a << endl;
  cout << "Quotient: " << a / a << endl;
  cout << "Expected Output: 1.0\n" << endl;

  cout << "divide by zero" << endl;
  cout << a << " / " << zero_poly << endl;
  cout << "Quotient: " << a / zero_poly << endl;
  cout << "Expected Output: infx^4 +infx^3 nanx^2 +infx +inf\n" << endl;

  cout << "zero / zero" << endl;
  Poly zero_a(coefs_zero, 2);
  Poly zero_b(coefs_zero, 2);
  cout << zero_a << " / " << zero_b << endl;
  cout << zero_a / zero_b << endl;
  cout << "Expected Output: nan (NOT A NUMBER)\n" << endl;

  cout << "perfect division / no remainder" << endl;
  double coefs_a[] = {2.0, 4.0};
  double coefs_b[] = {2.0};
  Poly e(coefs_a, 1);
  Poly f(coefs_b, 0);
  cout << e << " / " << f << endl;
  cout << "Quotient: " << e / f << endl;
  cout << "Expected Output: 2.0x +1.0\n" << endl;

  cout << "constant" << endl;
  double coefs_a2[] = {2.0, 2.0};
  double coefs_b2[] = {1.0, 1.0};
  Poly g(coefs_a2, 1);
  Poly h(coefs_b2, 1);
  cout << g << " / " << h << endl;
  cout << "Quotient: " << g / h << endl;
  cout << "Expected Output: 2.0\n" << endl;

  cout << "\n============================" << endl;
  cout << "     END DIVISION TEST " << endl;
  cout << "============================\n" << endl;

  return true;
}

bool test_logic(bool debug = false)
{
  cout << "\n============================" << endl;
  cout << "      START LOGIC TEST " << endl;
  cout << "============================\n" << endl;

  double coefs1[] = {8.0,5.0,6.0,0.0,4.0};
  double coefs1a[] = {8.0,5.0,6.0,0.0,4.0};
  double coefs1b[] = {8.0,5.0,6.0,0.0,3.0};
  double coefs2[] = {2.0,7.0,3.0,0.0, 1.0, 9.0};
  double coefs3[] = {2.0,7.0,3.0,0.0, 1.0, 8.0};
  Poly p(coefs1, 4);
  Poly t(coefs1a, 4);
  Poly y(coefs1b, 4);
  Poly q(coefs2, 5);
  Poly r(coefs3, 5);
  Term a(3,2);
  Term d(3,2);
  Term b(3,1);
  Term c(0,0);

  cout << "\n============================" << endl;
  cout << "    TESTING POLY LOGIC: " << endl;
  cout << "============================\n" << endl;

  cout << "p: " << p << endl;
  cout << "q: " << q << endl;
  cout << "t: " << t << endl;
  cout << "y: " << y << endl;
  cout << "r: " << r << endl;

  if(p > q)
  {
    cout << "p > q" << endl;
  }
  else if(p == q)
  {
    cout << "p == q" << endl;
  }
  else
  {
    if(p < q)
    {
      cout << "p < q" << endl;
    }
  }

  if(p > t)
  {
    cout << "p > t" << endl;
  }
  else if(p == t)
  {
    cout << "p == t" << endl;
  }
  else
  {
    if(p < t)
    {
      cout << "p < t" << endl;
    }
  }

  if(p > y)
  {
    cout << "p > y" << endl;
  }
  else if(p == y)
  {
    cout << "p == y" << endl;
  }
  else
  {
    if(p < y)
    {
      cout << "p < y" << endl;
    }
  }

  if(p > p)
  {
    cout << "p > p" << endl;
  }
  else if(p == p)
  {
    cout << "p == p" << endl;
  }
  else
  {
    if(p < p)
    {
      cout << "p < p" << endl;
    }
  }

  if(r > q)
  {
    cout << "r > q" << endl;
  }
  else if(r == q)
  {
    cout << "r == q" << endl;
  }
  else
  {
    if(r < q)
    {
      cout << "r < q" << endl;
    }
  }

  cout << endl;
  cout << "EXPECTED OUTPUT: " << endl;
  cout << "p < q" << endl;
  cout << "p == t" << endl;
  cout << "p > y" << endl;
  cout << "p == p" << endl;
  cout << "r < q" << endl;

  cout << "\n============================" << endl;
  cout << "    TESTING TERM LOGIC: " << endl;
  cout << "============================\n" << endl;

  cout << "a: " << a << endl;
  cout << "b: " << b << endl;
  cout << "c: " << c << endl;
  cout << "d: " << d << endl;
  cout << endl;

  if(a > b)
  {
    cout << "a > b" << endl;
  }
  else if(a == b)
  {
    cout << "a == b" << endl;
  }
  else
  {
    if(a < b)
    {
      cout << "a < b" << endl;
    }
  }

  if(a > a)
  {
    cout << "a > a" << endl;
  }
  else if(a == a)
  {
    cout << "a == a" << endl;
  }
  else
  {
    if(a < a)
    {
      cout << "a < a" << endl;
    }
  }

  if(a > c)
  {
    cout << "a > c" << endl;
  }
  else if(a == c)
  {
    cout << "a == c" << endl;
  }
  else
  {
    if(a < c)
    {
      cout << "a < c" << endl;
    }
  }

  if(a > d)
  {
    cout << "a > d" << endl;
  }
  else if(a == d)
  {
    cout << "a == d" << endl;
  }
  else
  {
    if(a < d)
    {
      cout << "a < d" << endl;
    }
  }

  if(c > d)
  {
    cout << "c > d" << endl;
  }
  else if(c == d)
  {
    cout << "c == d" << endl;
  }
  else
  {
    if(c < d)
    {
      cout << "c < d" << endl;
    }
  }

  cout << endl;
  cout << "EXPECTED OUTPUT: " << endl;
  cout << "a > b" << endl;
  cout << "a == a" << endl;
  cout << "a > c" << endl;
  cout << "a == d" << endl;
  cout << "c < d" << endl;

  cout << "\n============================" << endl;
  cout << "     END LOGIC TEST " << endl;
  cout << "============================\n" << endl;

  cout << endl;

  return true;
}

TEST(TEST_POLY, TestPoly)
{
  EXPECT_EQ(1, test_poly(false));
}

TEST(TEST_OPERATORS, TestAdd)
{
  EXPECT_EQ(1, test_add(false));
}

TEST(TEST_OPERATORS, TestSub)
{
  EXPECT_EQ(1, test_sub(false));
}

TEST(TEST_OPERATORS, TestMulti)
{
  EXPECT_EQ(1, test_multi(false));
}

TEST(TEST_OPERATORS, TestDiv)
{
  EXPECT_EQ(1, test_div(false));
}

TEST(TEST_LOGIC, TestLogic)
{
  EXPECT_EQ(1, test_logic(false));
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running testB.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}


