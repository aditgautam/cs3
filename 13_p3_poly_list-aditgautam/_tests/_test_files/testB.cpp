#include "gtest/gtest.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include "../../includes/poly_list/poly.h"
using namespace std;

bool test_stub(bool debug = false)
{
  if (debug){
    cout << "testB:: test-sub() entering test_sub" << endl;
  }
  return true;
}

bool test_default_constructor(bool debug = false)
{
  Poly p;
  cout << p << endl;
  return true;
}

bool test_array_constructor(bool debug = false){

  double coefs[] = {1.0, 2.0, 3.0, 4.0};
  Poly p(coefs, 3);
  cout << p << endl;
  return true;
}

bool test_vector_constructor(bool debug = false){
  return true;
}

bool test_plus_equals_term(bool debug = false){
  double coefs[] = {1.0, 2.0, 3.0, 4.0};
  Poly p(coefs, 3);
  Term t(5.0, 3);
  cout << "P: "<< p << " T:"  << t << endl;
  p+=t;
  cout << p << endl;
  Term q(726.0, 0);
  cout << "Q: " << q << endl;
  p+=q;
  cout << p << endl;
  Term s(-600.0, 90);
  p+=s;
  cout << p << endl;
  return true;
}

bool test_times_equals_term(bool debug = false){
  double coefs[] = {1.0, 2.0, 3.0, 4.0};
  Poly p(coefs, 3);
  Term t(5.0, 3);
  cout << "P: "<< p << " T:"  << t << endl;
  p*=t;
  cout << p << endl;
  Term q(726.0, 0);
  cout << "Q: " << q << endl;
  p*=q;
  cout << p << endl;
  Term s(-600.0, 90);
  p*=s;
  cout << p << endl;
  return true;

}

bool test_plus_equals_poly(bool debug = false){
  double coefs[] = {1.0, 2.0, 3.0, 4.0};
  Poly p(coefs, 3);
  double coefs2[] = {5.0, 6.0, 7.0, 8.0};
  Poly q(coefs2, 3);
  cout << "P: " << p << "Q: " << q << endl;
  p+=q;
  cout << "p+=q = " << p << endl; 

  double coefs3[] = {1.0, 1.0, 1.0};
  Poly s(coefs3, 2);
  double coefs4[] = {-1.0, -1.0, -1.0};
  Poly t(coefs4, 2);
  cout << "P: " << s << "Q: " << t << endl;
  s+=t;
  cout << "p+=q = " << s << endl; 

  return true;
}

bool test_times_equals_poly(bool debug = false){
  double coefs[] = {1.0, 2.0, 3.0, 4.0};
  Poly p(coefs, 3);
  double coefs2[] = {5.0, 6.0, 7.0, 8.0};
  Poly q(coefs2, 3);
  p *= q;
  cout << "p*=q: " << p << endl;
  double coefs3[] = {0.0};
  Poly s;
  cout << "P *= empty poly: " << endl;
  p*=s;
  cout << p << endl;
  return true;
}

bool test_negation(bool debug=false){
  return true;
}

bool test_minus_equals_poly(bool debug = false){
  return true;
}
bool test_equality_operators(bool debug = false){
  double coefs1[] = {2.0,0.0,0.0,2.0,4.0,0.0,5.0};
  double coefs2[] = {3.0, 4.0, 5.0, 6.0};
  Poly p(coefs1, 6);
  Poly q(coefs2, 3);
  cout << "P: " << p << "Q: " << q << endl;
  cout << "p+q -p " << (p+q) - p << endl;
  return true;
}

TEST(TEST_STUB, TestStub) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_stub(false));
}

TEST(TEST_CONSTRUCTOR, TestDefaultConstructor){
  EXPECT_EQ(1, test_default_constructor(false));
}
TEST(TEST_CONSTRUCTOR, TestArrayConstructor){
  EXPECT_EQ(1, test_array_constructor(false));
}
TEST(TEST_CONSTRUCTOR, TestVectorConstructor){
  EXPECT_EQ(1, test_vector_constructor(false));
}
TEST(TEST_LOW_LEVEL, TestPlusEqualsTerm){
  EXPECT_EQ(1, test_plus_equals_term(false));
}
TEST(TEST_LOW_LEVEL, TestTimesEqualsTerm){
  EXPECT_EQ(1, test_times_equals_term(false));
}
TEST(TEST_LOW_LEVEL, TestPlusEqualsPoly){
  EXPECT_EQ(1, test_plus_equals_poly(false));
}
TEST(TEST_LOW_LEVEL, TestTimesEqualsPoly){
  EXPECT_EQ(1, test_times_equals_poly(false));
}
TEST(TEST_LOW_LEVEL, TestNegation){
  EXPECT_EQ(1, test_negation(false));
}
TEST(TEST_LOW_LEVEL, TestMinusEqualsPoly){
  EXPECT_EQ(1, test_minus_equals_poly(false));
}
TEST(TEST_TERM, TestEqualityOperators){
  EXPECT_EQ(1, test_equality_operators(false));
}



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running testB.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}
