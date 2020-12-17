/* main.c
 *
 * This file contains the main function. It enables a user to enter in an arithmetic expression
 * into a buffer, and then will evaluate the expression according to arithmetic rules, and then
 * display the result of the operation.
 */

#include <stdio.h>
#include "expression_tree.h"

#define BUFFER_SIZE 500

int main() {
  char input[BUFFER_SIZE];
  Expression* expr = NULL;
  Expression_Tree* expr_tree = NULL;

  printf("Press Ctrl+D to exit.\n\n> ");
  while (fgets(input, BUFFER_SIZE, stdin)) {
    expr = tokenize_expression(input);

    if (validate_semantics(expr)) {
      expr_tree = parse_expr_to_tree(expr);
      printf("Result: %d\n\n", get_result(expr_tree));
    } else {
      printf("Invalid expression.\n\n");
    }

    printf("> ");
  }

  return 0;
}
