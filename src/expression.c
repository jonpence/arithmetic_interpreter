#include <stdlib.h>
#include <stdio.h>
#include "expression.h"

void substr(char* source, char* destination, size_t n, size_t len) {
  size_t i = 0;
  while (i < len) {
    destination[i] = source[n];
    i++;
    n++;
  }
  destination[i] = '\0';
}

Expression* init_expression() {
  Expression* new_expression = (Expression*)malloc(sizeof(Expression));

  new_expression->head = NULL;
  new_expression->tail = NULL;
  new_expression->ptr = NULL;

  return new_expression;
}

Expression* tokenize_expression(char* token_stream) {

    Expression* new_expression = init_expression();

    size_t i = 0;
    size_t len;

    char operand_str[100];

    while (token_stream[i] != '\n' && token_stream[i] != '\0') {
      if (isdigit(token_stream[i])) {
        len = 0;

        while (isdigit(token_stream[i])) {
          len++;
          i++;
        }
        substr(token_stream, operand_str, i - len, len);

        append_token(new_expression, init_operand(atoi(operand_str)));

        if (token_stream[i] == '\n' || token_stream[i] == '\0') break;
      }
      switch(token_stream[i]) {
        case '*':
          append_token(new_expression, init_operator(Multiplication));
          break;
        case '/':
          append_token(new_expression, init_operator(Division));
          break;
        case '+':
          append_token(new_expression, init_operator(Addition));
          break;
        case '-':
          append_token(new_expression, init_operator(Subtraction));
          break;
        case ' ':
          break;
        default:
          append_token(new_expression, init_operator(NullOperation));
      }
      i++;
    }

    return new_expression;
}

Expression* init_expression_copy(Expression* expr) {
  return subexpr(get_head(expr), get_tail(expr));
}

Expression* init_expression_copy_reverse(Expression* expr) {
  return subexpr_reverse(get_head(expr), get_tail(expr));
}

Expression* subexpr(Expression_Node* start, Expression_Node* end) {
  Expression* new_expr = init_expression();
  Expression_Node* node_ptr = start;

  while (node_ptr && node_ptr != get_right_operand(end)) {
    append_token(new_expr, get_expr(node_ptr));
    node_ptr = get_right_operand(node_ptr);
  }

  return new_expr;
}

Expression* subexpr_reverse(Expression_Node* start, Expression_Node* end) {
  Expression* new_expr = init_expression();
  Expression_Node* node_ptr = end;

  while (node_ptr && node_ptr != get_left_operand(start)) {
    append_token(new_expr, get_expr(node_ptr));
    node_ptr = get_left_operand(node_ptr);
  }

  return new_expr;
}

void reset_expression(Expression* expr) {
  set_ptr(expr, get_head(expr));
}

int next_token(Expression* expr) {
  if (get_right_operand(get_ptr(expr)) == NULL) {
    set_ptr(expr, NULL);
    return 0;
  } else {
    set_ptr(expr, get_right_operand(get_ptr(expr)));
    return 1;
  }
}

int prev_token(Expression* expr) {
  if (get_left_operand(get_ptr(expr)) == NULL) {
    set_ptr(expr, NULL);
    return 0;
  } else {
    set_ptr(expr, get_left_operand(get_ptr(expr)));
    return 1;
  }
}

Expression_Node* get_head(Expression* expr) {
  return expr->head;
}

Expression_Node* get_tail(Expression* expr) {
  return expr->tail;
}

Expression_Node* get_ptr(Expression* expr) {
  return expr->ptr;
}

Expression_Token* get_current_token(Expression* expr) {
  return get_expr(get_ptr(expr));
}

void append_token(Expression* expr, Expression_Token* new_token) {
  Expression_Node* new_node = init_node(new_token);

  if (!get_head(expr)) {
    set_head(expr, new_node);
    set_tail(expr, get_head(expr));
    set_ptr(expr, get_head(expr));
  } else {
    set_right_operand(get_tail(expr), new_node);
    set_left_operand(new_node, get_tail(expr));
    set_tail(expr, new_node);
  }
}

void set_head(Expression* expr, Expression_Node* expr_node) {
  expr->head = expr_node;
}

void set_tail(Expression* expr, Expression_Node* expr_node) {
  expr->tail = expr_node;
}

void set_ptr(Expression* expr, Expression_Node* expr_node) {
  expr->ptr = expr_node;
}

int validate_semantics(Expression* expr) {
  if (expr == NULL || !is_operand(get_current_token(expr)))
    return 0;

  int check_flag = 0;

  while (next_token(expr)) {
    if (is_operator(get_current_token(expr)) && is_null_operator(get_operator(get_current_token(expr))))
      return 0;

    if (check_flag) {
      if (!is_operand(get_current_token(expr))) {
        return 0;
      } else {
        check_flag = 0;
      }
    } else {
      if (!is_operator(get_current_token(expr))) {
        return 0;
      } else {
        check_flag = 1;
      }
    }
  }

  return 1;
}

void print_expression(Expression* expr) {
  Expression_Node* temp_ptr = get_head(expr);
  
  while (temp_ptr) {
    print_token(get_expr(temp_ptr));
    temp_ptr = get_right_operand(temp_ptr);
  }
}
