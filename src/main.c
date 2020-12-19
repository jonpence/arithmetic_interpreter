/* main.c
 *
 * This file contains the main function. It enables a user to enter in an arithmetic expression
 * into a buffer, and then will evaluate the expression according to arithmetic rules, and then
 * display the result of the operation.
 */

#include <stdio.h>
#include <string.h>
#include "expression_tree.h"
#include "list.h"

#define BUF_SIZE 500

// Command enumerates different types of valid commands that are accepted by the interpreter.
typedef enum Command {
  NullCommand,
  Help,
  Table,
  PrintExpression,
  PrintTree,
  Result,
  Exit
} Command;

// tokenize_command(input) takes a string, ideally of the form <!command optparam>, then tokenizes it and returns the token.
Command tokenize_command(char* input) {
  size_t i = 0;
  char command[BUF_SIZE];

  while (input[i] != ' ' && input[i] != '\n') {
    i++;
  }

  substr(input, command, 0, i);

  if (!strcmp(command, "!help")) {
    return Help;
  } else if (!strcmp(command, "!table")) {
    return Table;
  } else if (!strcmp(command, "!print_expr")) {
    return PrintExpression;
  } else if (!strcmp(command, "!print_tree")) {
    return PrintTree;
  } else if (!strcmp(command, "!result")) {
    return Result;
  } else if (!strcmp(command, "!exit")) {
    return Exit;
  } else {
    return NullCommand;
  }
}

// main() begins a loop that accepts a command/expression until the user issues an EOF character or executes the '!exit' command.
int main() {
  char input[BUF_SIZE];
  Expression* expr = NULL;
  Expression_Tree* expr_tree = NULL;

  // Hold valid expressions which have been entered into this list.
  List* expr_tree_table = init_list(2);

  printf("Press Ctrl+D or enter '!exit' to exit.\nEnter '!help' for a list of commands \n\n> ");
  while (fgets(input, BUF_SIZE, stdin)) {
    // If input is empty, just do nothing.
    if (input[0] == '\n') {
      ;
    // If an input begins with !, then it ought to be interpreted as a command, and not an expression.
    } else if (input[0] == '!') {
      switch(tokenize_command(input)) {
        case Help:
          printf("-- !help............Prints this menu.\n");
          printf("-- !table...........Prints all expressions in the expression table.\n");
          printf("-- !print_expr n....Prints the expression of id n.\n");
          printf("-- !print_tree n....Prints the parenthized expression of id n.\n");
          printf("-- !result n........Prints the result of evaluating expression of id n.\n");
          printf("-- !exit n..........Exits the interpreter.\n");
          printf("\n");
          break;
        case Table:
          print_all_items(expr_tree_table);
          break;
        case PrintExpression:
          printf("print expr\n\n");
          break;
        case PrintTree:
          printf("print tree\n\n");
          break;
        case Result:
          printf("result\n\n");
          break;
        case Exit:
          return 0;
        case NullCommand:
          printf("Command unrecognized.\n\n");
      }
    } else {
      // If the input is not a command, then try to tokenize it into an expression.
      expr = tokenize_expression(input);
      // Then validate that the expression makes sense (begins/ends with operands, contains no NullOperation operators).
      if (validate_semantics(expr)) {
        expr_tree = parse_expr_to_tree(expr);
        printf("Result: %d\n", get_result(expr_tree));
        printf("Adding expression as id: %d\n\n", get_size(expr_tree_table));
        append(expr_tree_table, expr_tree);
      } else {
        printf("Invalid expression.\n\n");
      }
    }

    printf("> ");
  }

  return 0;
}
