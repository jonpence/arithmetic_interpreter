/* expression_token.h
 *
 * This file defines a struct Expression_Token, which holds the value of either an operator
 * or operand.
 *
 */

#ifndef EXPRESSION_TOKEN_H
#define EXPRESSION_TOKEN_H

#include "operator.h"

/* .................... */
/* DATA DEFINITIONS     */
/* .................... */

typedef enum _expr_type {
  t_operator,
  t_operand
} Expression_Type;

typedef struct _expr_token {
  Expression_Type type;

  union {
    Operator operator;
    int      operand;
  };
} Expression_Token;

/* .................... */
/* FUNCTION DEFINITIONS */
/* .................... */

Expression_Token* init_operator(Operator val);
Expression_Token* init_operand(int val);

Operator get_operator(Expression_Token* expr_token);
int get_operand(Expression_Token* expr_token);

void set_operator(Expression_Token* expr_token, Operator val);
void set_operand(Expression_Token* expr_token, int val);

int is_operator(Expression_Token* expr_token);
int is_operand(Expression_Token* expr_token);

void print_token(Expression_Token* expr_token);

#endif
