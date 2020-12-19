#include <stdlib.h>
#include <stdio.h>
#include "expression_token.h"

// init_operator() takes an Operator enum, and then manually allocates space
// for a new Expression_Token struct using the Operator parameter. It then
// returns a pointer to the newly allocated struct.
Expression_Token* init_operator(Operator val) {
  Expression_Token* new_token = (Expression_Token*)malloc(sizeof(Expression_Token));
  new_token->type = t_operator;
  new_token->operator = val;

  return new_token;
}

// init_operand() takes an int, and then manually allocates space
// for a new Expression_Token struct using the int parameter. It then
// returns a pointer to the newly allocated struct.
Expression_Token* init_operand(int val) {
  Expression_Token* new_token = (Expression_Token*)malloc(sizeof(Expression_Token));
  new_token->type = t_operand;
  new_token->operand = val;

  return new_token;
}

// get_operator() takes an expression token, and returns the value of its
// operator field.
Operator get_operator(Expression_Token* expr_token) {
  return expr_token->operator;
}

// get_operand() takes an expression token, and returns the value of its
// operand field.
int get_operand(Expression_Token* expr_token) {
  return expr_token->operand;
}

// set_operator() takes an expression token and an Operator enum, and sets the
// expression token's operator field equal to the Operator parameter.
void set_operator(Expression_Token* expr_token, Operator val) {
  expr_token->type = t_operator;
  expr_token->operator = val;
}

// set_operand() takes an expression token and an int, and sets the
// expression token's operand field equal to the int parameter.
void set_operand(Expression_Token* expr_token, int val) {
  expr_token->type = t_operand;
  expr_token->operand = val;
}

// is_operator() takes an expression token and returns whether or not that
// token's type corresponds to an operator.
int is_operator(Expression_Token* expr_token) {
  return expr_token->type == t_operator;
}

// is_operand() takes an expression token and returns whether or not that
// token's type corresponds to an operand.
int is_operand(Expression_Token* expr_token) {
  return expr_token->type == t_operand;
}

// print_token() takes an expression token and prints its value, being either
// an Operator enum or an operand int value.
void print_token(Expression_Token* expr_token) {
  if (is_operator(expr_token))
    printf("(%s)",op_to_string(get_operator(expr_token)));
  else
    printf("(%d)",get_operand(expr_token));
}
