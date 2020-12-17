#include <stdio.h>
#include "expression.h"

void test_init_expression() {
  printf("Testing init_expression()...\n");
  Expression* test_expression = init_expression();

  if (!get_ptr(test_expression) && !get_head(test_expression) && !get_tail(test_expression))
    printf("...init_expression() PASS\n\n");
  else
    printf("...init_expression() FAIL\n\n");
}

void test_next_token() {
  printf("Testing next_token()...\n");
  Expression* test_expression = init_expression();

  Expression_Token* test_token1 = init_operand(1);
  Expression_Token* test_token2 = init_operand(2);
  Expression_Token* test_token3 = init_operand(3);

  append_token(test_expression, test_token1);
  append_token(test_expression, test_token2);
  append_token(test_expression, test_token3);

  next_token(test_expression);

  if (get_expr(get_ptr(test_expression)) == test_token2)
    printf("...next_token() PASS\n\n");
  else
    printf("...next_token() FAIL\n\n");
}

void test_prev_token() {
  printf("Testing prev_token()...\n");
  Expression* test_expression = init_expression();

  Expression_Token* test_token1 = init_operand(1);
  Expression_Token* test_token2 = init_operand(2);
  Expression_Token* test_token3 = init_operand(3);

  append_token(test_expression, test_token1);
  append_token(test_expression, test_token2);
  append_token(test_expression, test_token3);

  set_ptr(test_expression, get_tail(test_expression));

  prev_token(test_expression);
  prev_token(test_expression);

  if (get_expr(get_ptr(test_expression)) == test_token1)
    printf("...prev_token() PASS\n\n");
  else
    printf("...prev_token() FAIL\n\n");
}

void test_append_token() {
  printf("Testing append_token()...\n");

  Expression* test_expression = init_expression();

  Expression_Token* test_token1 = init_operand(1);
  Expression_Token* test_token2 = init_operand(2);
  Expression_Token* test_token3 = init_operand(3);

  append_token(test_expression, test_token1);
  append_token(test_expression, test_token2);
  append_token(test_expression, test_token3);

  int operand1 = get_operand(get_expr(get_head(test_expression)));
  int operand2 = get_operand(get_expr(get_tail(test_expression)));

  if (operand1 == 1 && operand2 == 3)
    printf("...append_token() PASS\n\n");
  else
    printf("...append_token() FAIL\n\n");
}

void test_set_head() {
  printf("Testing set_head()...\n");

  Expression* test_expression = init_expression();
  Expression_Token* test_token = init_operand(0);
  Expression_Node* test_node = init_node(test_token);

  set_head(test_expression, test_node);

  if (get_head(test_expression) == test_node)
    printf("...set_head() PASS\n\n");
  else
    printf("...set_head() FAIL\n\n");
}

void test_set_tail() {
  printf("Testing set_tail()...\n");

  Expression* test_expression = init_expression();
  Expression_Token* test_token = init_operand(0);
  Expression_Node* test_node = init_node(test_token);

  set_tail(test_expression, test_node);

  if (get_tail(test_expression) == test_node)
    printf("...set_tail() PASS\n\n");
  else
    printf("...set_tail() FAIL\n\n");
}

void test_set_ptr() {
  printf("Testing set_ptr()...\n");

  Expression* test_expression = init_expression();
  Expression_Token* test_token = init_operand(0);
  Expression_Node* test_node = init_node(test_token);

  set_ptr(test_expression, test_node);

  if (get_ptr(test_expression) == test_node)
    printf("...set_ptr() PASS\n\n");
  else
    printf("...set_ptr() FAIL\n\n");
}

void test_print_expression() {
  printf("Testing print_expression()...\n");

  Expression* test_expression = init_expression();

  Expression_Token* test_operand1 = init_operand(1);
  Expression_Token* test_operand2 = init_operand(2);
  Expression_Token* test_operand3 = init_operand(3);

  Expression_Token* test_operator1 = init_operator(Addition);
  Expression_Token* test_operator2 = init_operator(Subtraction);

  append_token(test_expression, test_operand1);
  append_token(test_expression, test_operator1);
  append_token(test_expression, test_operand2);
  append_token(test_expression, test_operator2);
  append_token(test_expression, test_operand3);

  print_expression(test_expression);
  printf("\n\n");
}

void test_subexpr() {
  printf("Testing subexpr()...\n");

  char* test_token_stream = "1 + 2 * 3 - 4 / 5 + 6 * 7 - 8 / 9 + 10";
  Expression* test_expression = tokenize_expression(test_token_stream);

  next_token(test_expression);
  next_token(test_expression);
  next_token(test_expression);
  next_token(test_expression);

  Expression* test_sub_expression1 = subexpr(get_head(test_expression), get_ptr(test_expression));
  Expression* test_sub_expression2 = subexpr(get_ptr(test_expression), get_tail(test_expression));

  if (get_operand(get_expr(get_tail(test_sub_expression1))) == get_operand(get_expr(get_head(test_sub_expression2))))
    printf("...subexpr() PASS\n\n");
  else
    printf("...subexpr() FAIL\n\n");
}

int main() {
  test_init_expression();
  test_next_token();
  test_prev_token();
  test_append_token();
  test_set_head();
  test_set_tail();
  test_set_ptr();
  test_print_expression();
  test_subexpr();

  return 0;
}
