/* expression_tree.h
 *
 * This file defines a type called Expression_Tree, which is the abstract syntax tree of type Expression.
 * It takes an expression, and forms a tree of it according to an order of operations. It then stores the
 * tree and is capable of being called to evaluate the expression, at which point it performs the evaluation
 * and returns the result of the expression.
 *
 */

#ifndef EXPRESSION_TREE_H
#define EXPRESSION_TREE_H

#include <stdio.h>
#include "expression.h"

/* .................... */
/* DATA DEFINITIONS     */
/* .................... */

typedef struct {
    Expression* expr;
   
    Expression_Node* root;
    int result;
} Expression_Tree;

/* .................... */
/* FUNCTION DEFINITIONS */
/* .................... */

Expression_Tree* init_tree();
Expression_Tree* parse_expr_to_tree(Expression* expr);

int evaluate(Expression_Tree* expr_tree);

int get_result(Expression_Tree* expr_tree);
Expression* get_expression(Expression_Tree* expr_tree);
Expression_Node* get_root(Expression_Tree* expr_tree);

void set_result(Expression_Tree* expr_tree, int result);
void set_expression(Expression_Tree* expr_tree, Expression* expr);
void set_root(Expression_Tree* expr_tree, Expression_Node* expr_node);

void print_expression_tree(Expression_Tree* expr_tree);

#endif
