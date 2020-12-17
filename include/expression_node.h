/* expression_node.h
 *
 * Defines an Expression_Node for use in Expression and Expression_Tree.
 *
 */

#ifndef EXPRESSION_NODE_H
#define EXPRESSION_NODE_H

#include "expression_token.h"

/* .................... */
/* DATA DEFINITIONS     */
/* .................... */

typedef struct _expr_node {
  Expression_Token* expr;

  struct _expr_node*  left_operand;
  struct _expr_node* right_operand;
} Expression_Node;

/* .................... */
/* FUNCTION DEFINITIONS */
/* .................... */

Expression_Node* init_node(Expression_Token* expr_token);

Expression_Token* get_expr(Expression_Node* expr_node);
Expression_Node* get_left_operand(Expression_Node* expr_node);
Expression_Node* get_right_operand(Expression_Node* expr_node);

void set_expr(Expression_Node* expr_node, Expression_Token* expr_token);
void set_left_operand(Expression_Node* expr_node, Expression_Node* operand_node);
void set_right_operand(Expression_Node* expr_node, Expression_Node* operand_node);

#endif
