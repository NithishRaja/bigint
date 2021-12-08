/****
  * File containing unit tests for BigInt class
  *
  */

// Dependencies
#include <iostream>
#include <string>
// Local Dependencies
#include "bigInt.cpp"

// Set namespace
using namespace std;

#define print_status cout<<" + "<<__FUNCTION__;if(flag){cout<<" succeeded\n";}else{cout<<" failed\n";}

void test_addition_equal_size(){
  // Initialise string to hold input
  string val1 = "4321";
  string val2 = "3210";
  // Initialise string to hold expected output
  string expected_result = "7531";
  // Initialise BigInt objects
  BigInt op1(val1);
  BigInt op2(val2);
  // Perform addition
  BigInt res = op1+op2;
  // Initialise flag
  bool flag = true;
  // Compare result
  if(res.get() != expected_result){
    flag = false;
  }
  print_status
}

void test_addition_inequal_size(){
  // Initialise string to hold input
  string val1 = "14321";
  string val2 = "3210";
  // Initialise string to hold expected output
  string expected_result = "17531";
  // Initialise BigInt objects
  BigInt op1(val1);
  BigInt op2(val2);
  // Perform addition
  BigInt res = op1+op2;
  // Initialise flag
  bool flag = true;
  // Compare result
  if(res.get() != expected_result){
    flag = false;
  }
  print_status
}

void test_addition_final_carry(){
  // Initialise string to hold input
  string val1 = "999999994321";
  string val2 = "6210";
  // Initialise string to hold expected output
  string expected_result = "1000000000531";
  // Initialise BigInt objects
  BigInt op1(val1);
  BigInt op2(val2);
  // Perform addition
  BigInt res = op1+op2;
  // Initialise flag
  bool flag = true;
  // Compare result
  if(res.get() != expected_result){
    flag = false;
  }
  print_status
}

void test_addition_identity(){
  // Initialise string to hold input
  string val1 = "0";
  string val2 = "6210";
  // Initialise string to hold expected output
  string expected_result = "6210";
  // Initialise BigInt objects
  BigInt op1(val1);
  BigInt op2(val2);
  // Perform addition
  BigInt res = op1+op2;
  // Initialise flag
  bool flag = true;
  // Compare result
  if(res.get() != expected_result){
    flag = false;
  }
  print_status
}

void test_multiplication_equal_size(){
  // Initialise string to hold input
  string val1 = "4321";
  string val2 = "6210";
  // Initialise string to hold expected output
  string expected_result = "26833410";
  // Initialise BigInt objects
  BigInt op1(val1);
  BigInt op2(val2);
  // Perform multiplication
  BigInt res = op1*op2;
  // Initialise flag
  bool flag = true;
  // Compare result
  if(res.get() != expected_result){
    flag = false;
  }
  print_status
}

void test_multiplication_inequal_size(){
  // Initialise string to hold input
  string val1 = "124321";
  string val2 = "6210";
  // Initialise string to hold expected output
  string expected_result = "772033410";
  // Initialise BigInt objects
  BigInt op1(val1);
  BigInt op2(val2);
  // Perform multiplication
  BigInt res = op1*op2;
  // Initialise flag
  bool flag = true;
  // Compare result
  if(res.get() != expected_result){
    flag = false;
  }
  print_status
}

void test_multiplication_identity(){
  // Initialise string to hold input
  string val1 = "124321";
  string val2 = "1";
  // Initialise string to hold expected output
  string expected_result = "124321";
  // Initialise BigInt objects
  BigInt op1(val1);
  BigInt op2(val2);
  // Perform multiplication
  BigInt res = op1*op2;
  // Initialise flag
  bool flag = true;
  // Compare result
  if(res.get() != expected_result){
    flag = false;
  }
  print_status
}

void test_multiplication_with_zero(){
  // Initialise string to hold input
  string val1 = "124321";
  string val2 = "0";
  // Initialise string to hold expected output
  string expected_result = "0";
  // Initialise BigInt objects
  BigInt op1(val1);
  BigInt op2(val2);
  // Perform multiplication
  BigInt res = op1*op2;
  // Initialise flag
  bool flag = true;
  // Compare result
  if(res.get() != expected_result){
    flag = false;
  }
  print_status
}

void test_multiplication_large_values(){
  // Initialise string to hold input
  string val1 = "9223372036854775808";
  string val2 = "2";
  // Initialise string to hold expected output
  string expected_result = "18446744073709551616";
  // Initialise BigInt objects
  BigInt op1(val1);
  BigInt op2(val2);
  // Perform multiplication
  BigInt res = op1*op2;
  // Initialise flag
  bool flag = true;
  // Compare result
  if(res.get() != expected_result){
    flag = false;
  }
  print_status
}

void test_subtraction_equal_size(){
  // Initialise string to hold input
  string val1 = "124320";
  string val2 = "100001";
  // Initialise string to hold expected output
  string expected_result = "24319";
  // Initialise BigInt objects
  BigInt op1(val1);
  BigInt op2(val2);
  // Perform subtraction
  BigInt res = op1-op2;
  // Initialise flag
  bool flag = true;
  // Compare result
  if(res.get() != expected_result){
    flag = false;
  }
  print_status
}

void test_subtraction_inequal_size(){
  // Initialise string to hold input
  string val1 = "124320";
  string val2 = "999";
  // Initialise string to hold expected output
  string expected_result = "123321";
  // Initialise BigInt objects
  BigInt op1(val1);
  BigInt op2(val2);
  // Perform subtraction
  BigInt res = op1-op2;
  // Initialise flag
  bool flag = true;
  // Compare result
  if(res.get() != expected_result){
    flag = false;
  }
  print_status
}

void test_subtraction_identity(){
  // Initialise string to hold input
  string val1 = "124320";
  string val2 = "0";
  // Initialise string to hold expected output
  string expected_result = "124320";
  // Initialise BigInt objects
  BigInt op1(val1);
  BigInt op2(val2);
  // Perform subtraction
  BigInt res = op1-op2;
  // Initialise flag
  bool flag = true;
  // Compare result
  if(res.get() != expected_result){
    flag = false;
  }
  print_status
}

void test_subtraction_with_equal_value(){
  // Initialise string to hold input
  string val1 = "124320";
  string val2 = "124320";
  // Initialise string to hold expected output
  string expected_result = "0";
  // Initialise BigInt objects
  BigInt op1(val1);
  BigInt op2(val2);
  // Perform subtraction
  BigInt res = op1-op2;
  // Initialise flag
  bool flag = true;
  // Compare result
  if(res.get() != expected_result){
    flag = false;
  }
  print_status
}

void test_subtraction_long_borrow(){
  // Initialise string to hold input
  string val1 = "100000000001";
  string val2 = "999";
  // Initialise string to hold expected output
  string expected_result = "99999999002";
  // Initialise BigInt objects
  BigInt op1(val1);
  BigInt op2(val2);
  // Perform subtraction
  BigInt res = op1-op2;
  // Initialise flag
  bool flag = true;
  // Compare result
  if(res.get() != expected_result){
    flag = false;
  }
  print_status
}

void test_subtraction_large_values(){
  // Initialise string to hold input
  string val1 = "18446744073709551616";
  string val2 = "9223372036854775808";
  // Initialise string to hold expected output
  string expected_result = "9223372036854775808";
  // Initialise BigInt objects
  BigInt op1(val1);
  BigInt op2(val2);
  // Perform subtraction
  BigInt res = op1-op2;
  // Initialise flag
  bool flag = true;
  // Compare result
  if(res.get() != expected_result){
    flag = false;
  }
  print_status
}

void test_factorial_small_value(){
  // Initialise string to hold input
  string val = "5";
  // Initialise string to hold expected output
  string expected_result = "120";
  // Initialise BigInt object
  BigInt op(val);
  // Calculate factorial
  BigInt res = !op;
  // Initialise flag
  bool flag = true;
  // Compare result
  if(res.get() != expected_result){
    flag = false;
  }
  print_status
}

void test_factorial_large_value(){
  // Initialise string to hold input
  // string val = "5";
  string val = "100";
  // Initialise string to hold expected output
  // string expected_result = "120";
  string expected_result = "93326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864000000000000000000000000";
  // Initialise BigInt object
  BigInt op(val);
  // Calculate factorial
  BigInt res = !op;
  // Initialise flag
  bool flag = true;
  // Compare result
  if(res.get() != expected_result){
    flag = false;
  }
  print_status
}

void test_exponentiation_small_values(){
  // Initialise string to hold base
  string base = "10";
  // Initialise variable to hold exponent
  long long int exponent = 15;
  // Initialise string to hold expected output
  string expected_result = "1000000000000000";
  // Initialise BigInt object
  BigInt op(base);
  // Perform exponentiation
  BigInt res = op^exponent;
  // Initialise flag
  bool flag = true;
  // Compare result
  if(res.get() != expected_result){
    flag = false;
  }
  print_status
}

void test_exponentiation_large_values(){
  // Initialise string to hold base
  string base = "2";
  // Initialise variable to hold exponent
  long long int exponent = 64;
  // Initialise string to hold expected output
  string expected_result = "18446744073709551616";
  // Initialise BigInt object
  BigInt op(base);
  // Perform exponentiation
  BigInt res = op^exponent;
  // Initialise flag
  bool flag = true;
  // Compare result
  if(res.get() != expected_result){
    flag = false;
  }
  print_status
}

void test_comparision_equality(){
  // Initialise string to hold input
  string val1 = "18446744073709551616";
  string val2 = "18446744073709551616";
  // Initialise BigInt objects
  BigInt op1(val1);
  BigInt op2(val2);
  // Test for equality
  bool flag = (op1 == op2);
  print_status
}

void test_comparision_greater_than(){
  // Initialise string to hold input
  string val1 = "18446744073709551616";
  string val2 = "18446744073709551611";
  // Initialise BigInt objects
  BigInt op1(val1);
  BigInt op2(val2);
  // Test for equality
  bool flag = (op1 > op2);
  print_status
}

void test_comparision_lesser_than(){
  // Initialise string to hold input
  string val1 = "18446744073709551611";
  string val2 = "18446744073709551616";
  // Initialise BigInt objects
  BigInt op1(val1);
  BigInt op2(val2);
  // Test for equality
  bool flag = (op1 < op2);
  print_status
}

void test_division_zero_remainder(){
  // Initialise string to hold input
  string val1 = "18446744073709551616";
  string val2 = "9223372036854775808";
  // string val1 = "20";
  // string val2 = "2";
  // Initialise string to hold expected output
  string expected_result = "2";
  // Initialise BigInt objects
  BigInt op1(val1);
  BigInt op2(val2);
  // Perform subtraction
  BigInt res = op1/op2;
  // Initialise flag
  bool flag = true;
  // Compare result
  if(res.get() != expected_result){
    flag = false;
  }
  print_status
}

void test_division_non_zero_remainder(){
  // Initialise string to hold input
  string val1 = "18446744073709551620";
  string val2 = "9223372036854775808";
  // Initialise string to hold expected output
  string expected_result = "2";
  // Initialise BigInt objects
  BigInt op1(val1);
  BigInt op2(val2);
  // Perform subtraction
  BigInt res = op1/op2;
  // Initialise flag
  bool flag = true;
  // Compare result
  if(res.get() != expected_result){
    flag = false;
  }
  print_status
}

void test_modulo_zero_remainder(){
  // Initialise string to hold input
  string val1 = "18446744073709551616";
  string val2 = "9223372036854775808";
  // Initialise string to hold expected output
  string expected_result = "0";
  // Initialise BigInt objects
  BigInt op1(val1);
  BigInt op2(val2);
  // Perform subtraction
  BigInt res = op1%op2;
  // Initialise flag
  bool flag = true;
  // Compare result
  if(res.get() != expected_result){
    flag = false;
  }
  print_status
}

void test_modulo_non_zero_remainder(){
  // Initialise string to hold input
  string val1 = "18446744073709551616";
  string val2 = "922337203685477580";
  // Initialise string to hold expected output
  string expected_result = "16";
  // Initialise BigInt objects
  BigInt op1(val1);
  BigInt op2(val2);
  // Perform subtraction
  BigInt res = op1%op2;
  // Initialise flag
  bool flag = true;
  // Compare result
  if(res.get() != expected_result){
    flag = false;
  }
  print_status
}

void test_gcd_small_values(){
  // Initialise string to hold input
  string val1 = "4";
  string val2 = "2";
  // Initialise string to hold expected output
  string expected_result = "2";
  // Initialise BigInt objects
  BigInt op1(val1);
  BigInt op2(val2);
  // Perform subtraction
  BigInt res = op1.gcd(op2);
  // Initialise flag
  bool flag = true;
  // Compare result
  if(res.get() != expected_result){
    flag = false;
  }
  print_status
}

void test_gcd_large_values(){
  // Initialise string to hold input
  string val1 = "18446744073709551616";
  string val2 = "9223372036854775808";
  // Initialise string to hold expected output
  string expected_result = "9223372036854775808";
  // Initialise BigInt objects
  BigInt op1(val1);
  BigInt op2(val2);
  // Perform subtraction
  BigInt res = op1.gcd(op2);
  // Initialise flag
  bool flag = true;
  // Compare result
  if(res.get() != expected_result){
    flag = false;
  }
  print_status
}

int main(){
  test_addition_equal_size();
  test_addition_inequal_size();
  test_addition_final_carry();
  test_addition_identity();
  test_multiplication_equal_size();
  test_multiplication_inequal_size();
  test_multiplication_identity();
  test_multiplication_with_zero();
  test_multiplication_large_values();
  test_subtraction_equal_size();
  test_subtraction_inequal_size();
  test_subtraction_identity();
  test_subtraction_with_equal_value();
  test_subtraction_long_borrow();
  test_subtraction_large_values();
  test_factorial_small_value();
  test_factorial_large_value();
  test_exponentiation_small_values();
  test_exponentiation_large_values();
  test_comparision_equality();
  test_comparision_greater_than();
  test_comparision_lesser_than();
  test_division_zero_remainder();
  test_division_non_zero_remainder();
  test_modulo_zero_remainder();
  test_modulo_non_zero_remainder();
  test_gcd_small_values();
  test_gcd_large_values();
  // Exit successfully
  return 0;
}
