#include <stdio.h>
#include "expression_token.h"

void test_init_operator() {
  printf("Testing init_operator()...\n");
  Expression_Token* test_token = init_operator(NullOperation);

  if (is_null_operator(get_operator(test_token)))
    printf("...init_operator() PASS\n\n");
  else
    printf("...init_operator() FAIL\n\n");
}

void test_init_operand() {
  printf("Testing init_operand()...\n");
  Expression_Token* test_token = init_operand(100);

  if (get_operand(test_token) == 100)
    printf("...init_operand() PASS\n\n");
  else
    printf("...init_operand() FAIL\n\n");
}

void test_set_operator() {
  printf("Testing set_operator()...\n");
  Expression_Token* test_token = init_operator(NullOperation);
  set_operator(test_token, Addition);

  if (!is_null_operator(get_operator(test_token)))
    printf("...set_operator() PASS\n\n");
  else
    printf("...set_operator() FAIL\n\n");
}

void test_set_operand() {
  printf("Testing set_operand()...\n");
  Expression_Token* test_token = init_operand(100);
  set_operand(test_token, 0);

  if (get_operand(test_token) != 100)
    printf("...set_operand() PASS\n\n");
  else
    printf("...set_operand() FAIL\n\n");
}

void test_is_operator() {
  printf("Testing is_operator()...\n");
  Expression_Token* test_token = init_operator(NullOperation);

  if (is_operator(test_token))
    printf("...is_operator() PASS\n\n");
  else
    printf("...is_operator() FAIL\n\n");
}

void test_is_operand() {
  printf("Testing is_operand()...\n");
  Expression_Token* test_token = init_operand(100);

  if (is_operand(test_token))
    printf("...is_operand() PASS\n\n");
  else
    printf("...is_operand() FAIL\n\n");
}

void test_print_token() {
  printf("Testing print_token()...\n");
  Expression_Token* test_token_operator = init_operator(NullOperation);
  Expression_Token* test_token_operand = init_operand(100);

  printf("...Printing operator NullOperation:\n");
  print_token(test_token_operator);
  printf("\n");
  printf("...Printing operand 100:\n");
  print_token(test_token_operand);
  printf("\n\n");
}

int main() {

  test_init_operator();
  test_init_operand();
  test_set_operator();
  test_set_operand();
  test_is_operator();
  test_is_operand();
  test_print_token();

  return 0;
}
