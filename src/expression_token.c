#include <stdlib.h>
#include <stdio.h>
#include "expression_token.h"

Expression_Token* init_operator(Operator val) {
  Expression_Token* new_token = (Expression_Token*)malloc(sizeof(Expression_Token));
  new_token->type = t_operator;
  new_token->operator = val;

  return new_token;
}

Expression_Token* init_operand(int val) {
  Expression_Token* new_token = (Expression_Token*)malloc(sizeof(Expression_Token));
  new_token->type = t_operand;
  new_token->operand = val;

  return new_token;
}

Operator get_operator(Expression_Token* expr_token) {
  return expr_token->operator;
}

int get_operand(Expression_Token* expr_token) {
  return expr_token->operand;
}

void set_operator(Expression_Token* expr_token, Operator val) {
  expr_token->type = t_operator;
  expr_token->operator = val;
}

void set_operand(Expression_Token* expr_token, int val) {
  expr_token->type = t_operand;
  expr_token->operand = val;
}

int is_operator(Expression_Token* expr_token) {
  return expr_token->type == t_operator;
}

int is_operand(Expression_Token* expr_token) {
  return expr_token->type == t_operand;
}

void print_token(Expression_Token* expr_token) {
  if (is_operator(expr_token))
    printf("(%s)",op_to_string(get_operator(expr_token)));
  else
    printf("(%d)",get_operand(expr_token));
}
