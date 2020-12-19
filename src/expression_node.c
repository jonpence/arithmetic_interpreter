#include <stdlib.h>
#include "expression_node.h"

// init_node() takes an expression token, manually allocates a new
// Expression_Node, sets that newly allocated Expression_Node's
// expr field to the expression token parameter, and returns a
// pointer to the newly allocated Expression_Node.
Expression_Node* init_node(Expression_Token* expr_token) {
  Expression_Node* new_node = (Expression_Node*)malloc(sizeof(Expression_Node));

  new_node->expr = expr_token;
  new_node->left_operand = NULL;
  new_node->right_operand = NULL;

  return new_node;
}

// get_expr() takes an Expression_Node* and returns the value of its
// expr field.
Expression_Token* get_expr(Expression_Node* expr_node) {
  if (expr_node == NULL)
    return NULL;
  else
    return expr_node->expr;
}

// get_left_operand() takes an Expression_Node* and returns the value of its
// left_operand field.
Expression_Node* get_left_operand(Expression_Node* expr_node) {
  return expr_node->left_operand;
}

// get_right_operand() takes an Expression_Node* and returns the value of its
// right_operand field.
Expression_Node* get_right_operand(Expression_Node* expr_node) {
  return expr_node->right_operand;
}

// set_expr() takes an Expression_Node* and an Expression_Token*, and sets the
// expr field of the Expression_Node pointed to by the Expression_Node* parameter
// equal to the Expression_Token* parameter.
void set_expr(Expression_Node* expr_node, Expression_Token* expr_token) {
  expr_node->expr = expr_token;
}

// set_left_operand() takes two Expression_Node* parameters, and sets the
// left_operand field of the Expression_Node pointed to by the first
// Expression_Node* parameter equal to the second Expression_Node* parameter.
void set_left_operand(Expression_Node* expr_node, Expression_Node* operand_node) {
  expr_node->left_operand = operand_node;
}

// set_right_operand() takes two Expression_Node* parameters, and sets the
// right_operand field of the Expression_Node pointed to by the first
// Expression_Node* parameter equal to the second Expression_Node* parameter.
void set_right_operand(Expression_Node* expr_node, Expression_Node* operand_node) {
  expr_node->right_operand = operand_node;
}
