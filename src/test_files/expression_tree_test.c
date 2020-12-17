#include <stdio.h>
#include "expression_tree.h"

void test_init_tree() {
  printf("Testing init_tree()...\n");

  Expression_Tree* test_expr_tree = init_tree();

  if (test_expr_tree->root == NULL && test_expr_tree->result == 0)
    printf("...init_tree() PASS\n\n");
  else
    printf("...init_tree() FAIL\n\n");
}

void test_parse_expr_to_tree() {
  printf("Testing parse_expr_to_tree()...\n");

  char* test_token_stream = "1 + 2 * 3 - 4 / 5 + 6 * 7 - 8 / 9 + 10";
  Expression* test_expr = tokenize_expression(test_token_stream);
  Expression_Tree* test_expr_tree = parse_expr_to_tree(test_expr);

  if (get_operator(get_expr(get_root(test_expr_tree))) == Subtraction)
    printf("...parse_expr_to_tree() PASS\n\n");
  else
    printf("...parse_expr_to_tree() FAIL\n\n");
}

void test_evaluate() {
  printf("Testing evaluate()...\n");

  char* test_token_stream = "10 + 20 + 50 / 10 / 5 * 10 - 7";
  Expression* test_expr = tokenize_expression(test_token_stream);
  Expression_Tree* test_expr_tree = parse_expr_to_tree(test_expr);

  printf("%d", evaluate(test_expr_tree));

  if (get_result(test_expr_tree) == 33)
    printf("...evaluate() PASS\n\n");
  else
    printf("...evaluate() FAIL\n\n");
}

void test_get_result() {
  printf("Testing get_result()...\n");

  Expression_Tree* test_expr_tree = init_tree();
  set_result(test_expr_tree, 10);

  if (get_result(test_expr_tree) == 10)
    printf("...get_result() PASS\n\n");
  else
    printf("...get_result() FAIL\n\n");
}

void test_print_expression_tree() {
  printf("Testing print_expression_tree()...\n");

  char* test_token_stream = "1 + 2 * 3 - 4 / 5 + 6 * 7 - 8 / 9 + 10";
  Expression* test_expr = tokenize_expression(test_token_stream);
  Expression_Tree* test_expr_tree = parse_expr_to_tree(test_expr);

  print_expression_tree(test_expr_tree);
  printf("\n\n");
}

int main() {

    test_init_tree();
    test_parse_expr_to_tree();
    test_evaluate();
    test_get_result();
    test_print_expression_tree();

  return 0;
}
