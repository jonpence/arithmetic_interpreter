#include <stdlib.h>
#include "expression_node.h"

Expression_Node* init_node(Expression_Token* expr_token) {
  Expression_Node* new_node = (Expression_Node*)malloc(sizeof(Expression_Node));

  new_node->expr = expr_token;
  new_node->left_operand = NULL;
  new_node->right_operand = NULL;

  return new_node;
}

Expression_Token* get_expr(Expression_Node* expr_node) {
  if (expr_node == NULL)
    return NULL;
  else
    return expr_node->expr;
}

Expression_Node* get_left_operand(Expression_Node* expr_node) {
  return expr_node->left_operand;
}

Expression_Node* get_right_operand(Expression_Node* expr_node) {
  return expr_node->right_operand;
}
void set_expr(Expression_Node* expr_node, Expression_Token* expr_token) {
  expr_node->expr = expr_token;
}

void set_left_operand(Expression_Node* expr_node, Expression_Node* operand_node) {
  expr_node->left_operand = operand_node;
}

void set_right_operand(Expression_Node* expr_node, Expression_Node* operand_node) {
  expr_node->right_operand = operand_node;
}
