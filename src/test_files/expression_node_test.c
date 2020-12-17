#include <stdio.h>
#include "expression_node.h"

void test_init_node() {
  printf("Testing test_init_node()...\n");
  Expression_Token* test_token = init_operator(NullOperation);
  Expression_Node* test_node = init_node(test_token);

  if (is_null_operator(get_operator(get_expr(test_node)))) printf("test_init_node() PASS");
  else printf("test_init_node() FAIL");

  printf("\n\n");
}

void test_set_expr() {
  printf("Testing set_expr()...\n");
  Expression_Token* test_token = init_operator(NullOperation);
  Expression_Token* set_test_token = init_operator(Addition);
  Expression_Node* test_node = init_node(test_token);

  set_expr(test_node, set_test_token);

  if (!is_null_operator(get_operator(get_expr(test_node)))) printf("set_expr() PASS");
  else printf("set_expr() FAIL");

  printf("\n\n");
}

void test_set_left_operand() {
  printf("Testing set_left_operand()...\n");
  Expression_Token* test_token = init_operator(NullOperation);
  Expression_Node* test_node = init_node(test_token);

  Expression_Token* left_operand_token = init_operator(Addition);
  Expression_Node* left_operand_node = init_node(left_operand_token);

  set_left_operand(test_node, left_operand_node);

  if (!is_null_operator(get_operator(get_expr(get_left_operand(test_node))))) printf("set_left_operand PASS");
  else printf("set_left_operand FAIL");

  printf("\n\n");
}

void test_set_right_operand() {
  printf("Testing set_right_operand()...\n");
  Expression_Token* test_token = init_operator(NullOperation);
  Expression_Node* test_node = init_node(test_token);

  Expression_Token* right_operand_token = init_operator(Addition);
  Expression_Node* right_operand_node = init_node(right_operand_token);

  set_right_operand(test_node, right_operand_node);

  if (!is_null_operator(get_operator(get_expr(get_right_operand(test_node))))) printf("set_right_operand PASS");
  else printf("set_right_operand FAIL");

  printf("\n\n");
}

int main() {

  test_init_node();
  test_set_expr();
  test_set_left_operand();
  test_set_right_operand();

  return 0;
}
