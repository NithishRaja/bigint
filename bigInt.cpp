/****
  * File containing class for big integers
  *
  */

// Dependencies
#include <iostream>
#include <string>

// Set namespace
using namespace std;

class BigInt {
  private:
  string value;
  public:
  // Define constructor
  BigInt(string val){
    // Remove leading zeroes
    while(val.length() > 1 && ((int)val[0] - 48) == 0){
      string temp = "";
      for(int i=1;i<val.length();++i){
        temp = temp + val[i];
      }
      val = temp;
    }
    // Set value
    value = val;
  }
  // Function to return value
  string get(){
    return value;
  }

  // Overload addition operator
  BigInt operator + (BigInt second_operand){
    // Initialise string to hold result
    string result = "";
    // Initialise integer to hold carry
    int carry = 0;
    // Initialise counter
    int counter1 = value.length() - 1;
    int counter2 = second_operand.value.length() - 1;
    // Iterate till atleast one of the operand is fully traversed
    while(counter1>=0 && counter2>=0){
      // Add digits at current counter
      int res = ((int)value[counter1] - 48) + ((int)second_operand.value[counter2] - 48) + carry;
      // Update carry
      carry = res/10;
      // Update result
      result = to_string(res%10) + result;
      // Update counter
      --counter1;
      --counter2;
    }
    // Add remaining digits from operand 1
    while(counter1>=0){
      int res = ((int)value[counter1] - 48) + carry;
      // Update carry
      carry = res/10;
      // Update result
      result = to_string(res%10) + result;
      // Update counter
      --counter1;
    }
    // Add remaining digits from operand 2
    while(counter2>=0){
      int res = ((int)second_operand.value[counter2] - 48) + carry;
      // Update carry
      carry = res/10;
      // Update result
      result = to_string(res%10) + result;
      // Update counter
      --counter2;
    }
    // If carry is non zero, add it to end
    if(carry != 0){
      result = to_string(carry) + result;
    }
    // Initialise BigInt object with result
    BigInt result_obj(result);
    // Return BigInt object
    return result_obj;
  }

  // Overload multiplication operator
  BigInt operator * (BigInt second_operand){
    // Initialise BigInt to hold product
    BigInt product("0");
    // Initialise counter for operand 2
    int counter2 = second_operand.value.length() - 1;
    // Iterate till digits in operand 2 is exhausted
    while(counter2 >= 0){
      // Initialise string to hold result
      string result = "";
      // Add zero for each stage in process
      for(int i=0;i<second_operand.value.length()-1-counter2;++i){
        result = result+"0";
      }
      // Initialise variable to hold carry
      int carry = 0;
      // Initialise counter for operand 1
      int counter1 = value.length() - 1;
      // Iterate till digits in operand 1 is exhausted
      while(counter1 >= 0){
        // Calculate product of current digits
        int res = ((int)value[counter1] - 48)*((int)second_operand.value[counter2] - 48) + carry;
        // Update carry
        carry = res/10;
        // Update result
        result = to_string(res%10) + result;
        // Update counter 1
        --counter1;
      }
      // Check if carry is not zero
      if(carry != 0){
        result = to_string(carry) + result;
      }
      // Update product
      product = product+BigInt(result);
      // Update counter 2
      --counter2;
    }
    // Return product
    return product;
  }

  // Overload subtraction operator (operator works on the assumption that operand 2 <= operand 1)
  BigInt operator - (BigInt second_operand){
    // Initialise string to hold result
    string result = "";
    // Initialise counters for both operands
    int counter1 = value.length() - 1;
    int counter2 = second_operand.value.length() - 1;
    // Initialise flag to indicate borrowing
    bool borrow = false;
    // Iterate till operand 2 is exhausted
    while(counter2 >= 0){
      // Initialise variables to hold current digits
      int operand1_digit = ((int)value[counter1] - 48);
      int operand2_digit = ((int)second_operand.value[counter2] - 48);
      // Update operand 1 digit if previously borrowed
      if(borrow){
        // Reset borrow flag if operand 1 digit is greater than zero
        if(operand1_digit > 0){
          borrow = false;
        }
        // Reduce digit by 1 to account for borrowing
        --operand1_digit;
      }
      // Initialise variable to hold current result
      int res;
      // Check if borrowing should occur
      if(operand1_digit < operand2_digit){
        // Calculate difference with borrow
        res = 10 + operand1_digit - operand2_digit;
        // Update borrow flag
        borrow = true;
      }else{
        // Calculate difference without borrow
        res = operand1_digit - operand2_digit;
      }
      // Update result string
      result = to_string(res) + result;
      // Update counters
      --counter1;
      --counter2;
    }
    // Iterate till operand 1 is exhausted
    while(counter1 >= 0){
      // Initialise variable to hold current digits
      int operand1_digit = ((int)value[counter1] - 48);
      // Update operand 1 digit if previously borrowed
      if(borrow){
        // Reset borrow flag if operand 1 digit is greater than zero
        if(operand1_digit > 0){
          borrow = false;
          // Reduce digit by 1 to account for borrowing
          --operand1_digit;
        }else if(operand1_digit == 0){
          // Digit is zero, therefore previous borrow did not occur from current digit
          operand1_digit = 9;
        }
      }
      // Update result string
      result = to_string(operand1_digit) + result;
      // Update counter 1
      --counter1;
    }
    // Initialise BigInt object with result
    BigInt result_obj(result);
    // Return BigInt object
    return result_obj;
  }

  // Overload factorial operator
  BigInt operator ! (){
    // Initialise BigInt object to hold result
    BigInt result_obj(value);
    // Initialise BigInt object to hold counter
    BigInt counter(value);
    // Initialise BigInt object to hold value 1
    BigInt one("1");
    // Update counter
    counter = counter-one;
    // Iterate till counter becomes 1
    while(counter.get() != one.get()){
      // Multiple counter with result
      result_obj = result_obj*counter;
      // Update counter
      counter = counter-one;
    }
    // Return result object
    return result_obj;
  }

  // Overload exponentiation operator
  BigInt operator ^ (long long int exponent){
    // Initialise BigInt objects
    BigInt result_obj("1");
    BigInt temp(value);
    // Iterate till exponent becomes 0
    while(exponent > 0){

      // Check if exponent is divisible by 2
      if(exponent%2==1){
        result_obj = result_obj*temp;
      }
      temp = temp*temp;
      // Update exponent
      exponent = exponent/2;
    }
    // Return result object
    return result_obj;
  }

  // Overload equals operator
  bool operator == (BigInt second_operand){
    // Initialise result
    bool result = true;
    // Compare length of strings
    if(value.length() != second_operand.value.length()){
      result = false;
    }else{
      // Compare each digit
      for(int i=0;i<value.length();++i){
        // Get current digits
        int operand1_digit = ((int)value[i] - 48);
        int operand2_digit = ((int)second_operand.value[i] - 48);
        // Compare current digits
        if(operand1_digit != operand2_digit){
          // Update result
          result = false;
          // Exit loop
          break;
        }
      }
    }
    // Return result
    return result;
  }

  // Overload greater than operator
  bool operator > (BigInt second_operand){
    // Initialise result
    bool result = true;
    // Compare length of strings
    if(value.length() < second_operand.value.length()){
      // Update result
      result = false;
    }else if(value.length() > second_operand.value.length()){
      // Update result
      result = true;
    }else if(value.length() == second_operand.value.length()){
      BigInt temp(value);
      // Check for equality
      if(temp == second_operand){
        result = false;
      }else{
        // Compare each digit
        for(int i=0;i<value.length();++i){
          // Get current digits
          int operand1_digit = ((int)value[i] - 48);
          int operand2_digit = ((int)second_operand.value[i] - 48);
          // Compare current digits
          if(operand1_digit < operand2_digit){
            // Update result
            result = false;
            // Exit loop
            break;
          }else if(operand1_digit > operand2_digit){
            // Update result
            result = true;
            // Exit loop
            break;
          }
        }
      }
    }
    // Return result
    return result;
  }

  // Overload lesser than operator
  bool operator < (BigInt second_operand){
    BigInt temp(value);
    // Initialise result
    bool result = (second_operand > temp);
    // Return result
    return result;
  }

  // Overload not equals operator
  bool operator != (BigInt second_operand){
    BigInt temp(value);
    // Initialise result
    bool result = !(temp == second_operand);
    // Return result
    return result;
  }

  // Overload greater than or equals operator
  bool operator >= (BigInt second_operand){
    BigInt temp(value);
    // Initialise result
    bool result = !(temp < second_operand);
    // Return result
    return result;
  }

  // Overload lesser than or equals operator
  bool operator <= (BigInt second_operand){
    BigInt temp(value);
    // Initialise result
    bool result = !(temp > second_operand);
    // Return result
    return result;
  }

  // // Overload division operator
  // BigInt operator / (BigInt divisor){
  //   // Initialise BigInt objects
  //   BigInt quotient("0");
  //   BigInt dividend(value);
  //   BigInt one("1");
  //   // Iterate till divisor becomes greater than dividend
  //   while(dividend >= divisor){
  //     // Subtract divisor from dividend
  //     dividend = dividend - divisor;
  //     // Update quotient
  //     quotient = quotient + one;
  //   }
  //   // Return quotient
  //   return quotient;
  // }

  // Function to calculate quotient by continuous division
  BigInt division_by_subtraction(BigInt dividend, BigInt divisor){
    // Initialise BigInt objects
    BigInt quotient("0");
    BigInt one("1");
    // Iterate till divisor becomes greater than dividend
    while(dividend >= divisor){
      // Subtract divisor from dividend
      dividend = dividend - divisor;
      // Update quotient
      quotient = quotient + one;
    }
    // Return quotient
    return quotient;
  }

  // Function to calculate remainder by continuous division
  BigInt remainder_by_subtraction(BigInt dividend, BigInt divisor){
    // Initialise BigInt objects
    BigInt quotient("0");
    BigInt one("1");
    // Iterate till divisor becomes greater than dividend
    while(dividend >= divisor){
      // Subtract divisor from dividend
      dividend = dividend - divisor;
      // Update quotient
      quotient = quotient + one;
    }
    // Return quotient
    return dividend;
  }

  // Overload division operator
  BigInt operator / (BigInt divisor){
    // Initialise BigInt object for zero
    BigInt zero("0");
    // Check if divisor is zero
    if(divisor == zero){
      throw "division by zero not allowed";
    }
    // Initialise counter
    int counter = 0;
    // Initialise string to hold dividend
    string dividend_string = "";
    // Initialise string to hold quotient
    string quotient_string = "";
    // Iterate over each character in value string
    while(counter < value.length()){
      // Update dividend string
      dividend_string = dividend_string + value[counter];
      // Initialise dividend object
      BigInt temp_dividend(dividend_string);
      // Compare dividend and divisor
      if(divisor <= temp_dividend){
        // Call function to perfrom division by subtraction
        BigInt temp_quotient = division_by_subtraction(temp_dividend, divisor);
        // Update quotient string
        quotient_string = quotient_string + temp_quotient.get();
        // Update dividend
        temp_dividend = remainder_by_subtraction(temp_dividend, divisor);
        // Update dividend string
        dividend_string = temp_dividend.get();
      }else{
        // Add zero to quotient
        quotient_string = quotient_string+"0";
      }
      // Update counter
      ++counter;
    }
    // Initialise quotient object
    BigInt quotient(quotient_string);
    // Return quotient
    return quotient;
  }

  // Overload remainder operator
  BigInt operator % (BigInt divisor){
    // Initialise BigInt object for zero
    BigInt zero("0");
    // Check if divisor is zero
    if(divisor == zero){
      throw "division by zero not allowed";
    }
    // Initialise counter
    int counter = 0;
    // Initialise string to hold dividend
    string dividend_string = "";
    // Initialise string to hold quotient
    string quotient_string = "";
    // Iterate over each character in value string
    while(counter < value.length()){
      // Update dividend string
      dividend_string = dividend_string + value[counter];
      // Initialise dividend object
      BigInt temp_dividend(dividend_string);
      // Compare dividend and divisor
      if(divisor <= temp_dividend){
        // Call function to perfrom division by subtraction
        BigInt temp_quotient = division_by_subtraction(temp_dividend, divisor);
        // Update quotient string
        quotient_string = quotient_string + temp_quotient.get();
        // Update dividend
        temp_dividend = remainder_by_subtraction(temp_dividend, divisor);
        // Update dividend string
        dividend_string = temp_dividend.get();
      }else{
        // Add zero to quotient
        quotient_string = quotient_string+"0";
      }
      // Update counter
      ++counter;
    }
    // Initialise remainder object
    BigInt remainder_obj(dividend_string);
    // Return quotient
    return remainder_obj;
  }

  // Function to calculate greatest common divisor
  BigInt gcd(BigInt second_operand){
    // Initialise BigInt object with current value
    BigInt operand1(value);
    // Check if second operand is zero
    if(second_operand.value == "0"){
      // Return result
      return operand1;
    }else{
      return second_operand.gcd(operand1%second_operand);
    }
  }
};
