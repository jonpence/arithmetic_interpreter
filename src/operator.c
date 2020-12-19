#include "operator.h"

// op_to_string takes an Operator enum and returns a string corresponding to the
// operation's name in English.
char* op_to_string(Operator op) {
  switch(op) {
    case NullOperation:
      return "NullOperation";
    case Multiplication:
      return "Multiplication";
    case Division:
      return "Division";
    case Addition:
      return "Addition";
    case Subtraction:
      return "Subtraction";
  }
}

// op_to_symbol() takes an Operator enum and returns a string corresponding to
// the symbol of the operation in arithmetic format.
char* op_to_symbol(Operator op) {
  switch(op) {
    case NullOperation:
      return "NULL";
    case Multiplication:
      return "*";
    case Division:
      return "/";
    case Addition:
      return "+";
    case Subtraction:
      return "-";
  }
}

// is_null_operator() takes an Operator enum and returns an integer representing
// the boolean case of whether or not the accepted Operator is a NullOperation.
int is_null_operator(Operator op) {
  return op == NullOperation;
}
