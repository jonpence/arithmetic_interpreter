/* expression.h
 *
 * This file defines a struct called Expression, which is a linked list whose nodes contain
 * a field of type Expression_Token. Expression_Token holds two values; the first field is
 * of type Expression_Type, and specifies whether the struct holds an operator or an operand.
 * If the first field is t_operator, then the second field will hold some value from the
 * Operator enum. If the first field is t_operand, the second field will hold some int.
 *
 */

#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <stdlib.h>
#include <ctype.h>
#include "expression_node.h"

/* .................... */
/* DATA DEFINITIONS     */
/* .................... */

typedef struct {
  Expression_Node* head;
  Expression_Node* tail;
  Expression_Node* ptr;
} Expression;

/* .................... */
/* FUNCTION DEFINITIONS */
/* .................... */

void substr(char* source, char* destination, size_t n, size_t len);

Expression* init_expression();
Expression* tokenize_expression(char* token_stream);
Expression* init_expression_copy(Expression* expr);
Expression* init_expression_copy_reverse(Expression* expr);
Expression* subexpr(Expression_Node* start, Expression_Node* end);
Expression* subexpr_reverse(Expression_Node* start, Expression_Node* end);

void reset_expression(Expression* expr);
int next_token(Expression* expr);
int prev_token(Expression* expr);

Expression_Node* get_head(Expression* expr);
Expression_Node* get_tail(Expression* expr);
Expression_Node* get_ptr(Expression* expr);
Expression_Token* get_current_token(Expression* expr);

void append_token(Expression* expr, Expression_Token* new_token);
void set_head(Expression* expr, Expression_Node* expr_node);
void set_tail(Expression* expr, Expression_Node* expr_node);
void set_ptr(Expression* expr, Expression_Node* expr_node);

int validate_semantics(Expression* expr);

void print_expression(Expression* expr);

#endif
