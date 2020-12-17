#include <stdio.h>
#include <string.h>
#include "operator.h"

void test_null_operator() {
  printf("Testing is_null_operator()...\n");

  Operator op = NullOperation;

  if (is_null_operator(op))
    printf("...is_null_operator() PASS\n\n");
  else
    printf("...is_null_operator() FAIL\n\n");
}

void test_op_to_string() {
  printf("Testing op_to_string()...\n");

  int fail_flag = 0;

  Operator ops[] = { NullOperation, Multiplication, Division, Addition, Subtraction };
  char* op_strings[] = { "NullOperation", "Multiplication", "Division", "Addition", "Subtraction" };

  for (size_t i = 0; i < NUM_OPS; i++) {
    if (strcmp(op_to_string(ops[i]), op_strings[i])) {
      fail_flag = 1;
      break;
    }
  }

  if (!fail_flag)
    printf("...op_to_string() PASS\n\n");
  else
    printf("...op_to_string() FAIL\n\n");
}

int main() {

  test_null_operator();
  test_op_to_string();

  return 0;
}
