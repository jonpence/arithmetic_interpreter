#include "operator.h"

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

int is_null_operator(Operator op) {
  return op == NullOperation;
}
