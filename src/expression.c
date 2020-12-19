#include <stdlib.h>
#include <stdio.h>
#include "expression.h"

// substr() takes two char* and two size_t. It then places the characters
// in the first char* from the first size_t to the second size_t into the
// second char*. Functionally, it takes a substring of the first char* and
// places it into the second char*.
void substr(char* source, char* destination, size_t n, size_t len) {
  size_t i = 0;
  while (i < len) {
    destination[i] = source[n];
    i++;
    n++;
  }
  destination[i] = '\0';
}

// init_expression() manually allocates a new Expression and returns its pointer.
Expression* init_expression() {
  Expression* new_expression = (Expression*)malloc(sizeof(Expression));

  new_expression->head = NULL;
  new_expression->tail = NULL;
  new_expression->ptr = NULL;

  return new_expression;
}

// tokenize_expression() takes a char* and tokenizes its lexemes, forms an
// an Expression from those tokens, and returns a pointer to that Expression.
Expression* tokenize_expression(char* token_stream) {

    Expression* new_expression = init_expression();

    size_t i = 0;
    size_t len;

    char operand_str[100];

    // Continually iterate through the char* until we've reached a newline or
    // the char* null-terminates.
    while (token_stream[i] != '\n' && token_stream[i] != '\0') {
      if (isdigit(token_stream[i])) {
        len = 0;

        // If we get a digit character, then we're going to be dealing with
        // an operand, so continually iterate until we no longer get a digit
        // character.
        while (isdigit(token_stream[i])) {
          len++;
          i++;
        }

        // Then take a substring of the input corresponding to the complete
        // operand and place it into operand_str.
        substr(token_stream, operand_str, i - len, len);

        // Make a new Expression_Token of type t_operand, and append it to the
        // expression.
        append_token(new_expression, init_operand(atoi(operand_str)));

        if (token_stream[i] == '\n' || token_stream[i] == '\0') break;
      }

      // Analyze a character as an operation. If none are recognized, form
      // a NullOperation token. Append the new Operator token.
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

// init_expression_copy() takes an Expression*, copies its value using subexpr(),
// and returns a pointer to the copy.
Expression* init_expression_copy(Expression* expr) {
  return subexpr(get_head(expr), get_tail(expr));
}

// init_expression_copy_reverse() takes an Expression*, copies its value in
// reverse using subexpr_reverse(), and returns a pointer to the copy.
Expression* init_expression_copy_reverse(Expression* expr) {
  return subexpr_reverse(get_head(expr), get_tail(expr));
}

// subexpr() takes two Expression_Node* params, then iterates from the first
// to the second param, all the while copying the intermediate notes into
// a new Expression. Then it returns a pointer to the newly formed Expression.
Expression* subexpr(Expression_Node* start, Expression_Node* end) {
  Expression* new_expr = init_expression();
  Expression_Node* node_ptr = start;

  while (node_ptr && node_ptr != get_right_operand(end)) {
    append_token(new_expr, get_expr(node_ptr));
    node_ptr = get_right_operand(node_ptr);
  }

  return new_expr;
}

// subexpr_reverse() takes two Expression_Node* params, then iterates from the
// second to the first param, all the while copying the intermediate notes into
// a new Expression. Then it returns a pointer to the newly formed Expression.
Expression* subexpr_reverse(Expression_Node* start, Expression_Node* end) {
  Expression* new_expr = init_expression();
  Expression_Node* node_ptr = end;

  while (node_ptr && node_ptr != get_left_operand(start)) {
    append_token(new_expr, get_expr(node_ptr));
    node_ptr = get_left_operand(node_ptr);
  }

  return new_expr;
}

// reset_expression() takes an Expression* and resets the ptr field of its value
// to be equal to its value's head field.
void reset_expression(Expression* expr) {
  set_ptr(expr, get_head(expr));
}

// next_token() takes an Expression* and iterates the ptr field of its value to
// the next node within the expression.
int next_token(Expression* expr) {
  if (get_right_operand(get_ptr(expr)) == NULL) {
    set_ptr(expr, NULL);
    return 0;
  } else {
    set_ptr(expr, get_right_operand(get_ptr(expr)));
    return 1;
  }
}

// prev_token() takes an Expression* and iterates the ptr field of its value to
// the previous node within the expression.
int prev_token(Expression* expr) {
  if (get_left_operand(get_ptr(expr)) == NULL) {
    set_ptr(expr, NULL);
    return 0;
  } else {
    set_ptr(expr, get_left_operand(get_ptr(expr)));
    return 1;
  }
}

// get_head() takes an Expression* and returns the value of its
// value's head field.
Expression_Node* get_head(Expression* expr) {
  return expr->head;
}

// get_tail() takes an Expression* and returns the value of its
// value's tail field.
Expression_Node* get_tail(Expression* expr) {
  return expr->tail;
}

// get_ptr() takes an Expression* and returns the value of its
// value's ptr field.
Expression_Node* get_ptr(Expression* expr) {
  return expr->ptr;
}

// get_token() takes an Expression* and returns the value of its
// value's token field.
Expression_Token* get_current_token(Expression* expr) {
  return get_expr(get_ptr(expr));
}

// append_token() takes an Expression* and an Expression_Token*. If the
// value of Expression* is empty (i.e. its head is NULL), then it sets
// all three of its value's head, ptr, and tail fields equal to the
// Expression_Token*. Otherwise it sets its value's tail's next field to
// an Expression_Node* holding the Expression_Token* param, and sets its
// value's tail field equal to that newly formed Expression_Node*.
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

// set_head() takes an Expression* and an Expression_Node*, and sets
// the Expression*'s value's head field equal to the Expression_Node*
// paramter.
void set_head(Expression* expr, Expression_Node* expr_node) {
  expr->head = expr_node;
}

// set_tail() takes an Expression* and an Expression_Node*, and sets
// the Expression*'s value's tail field equal to the Expression_Node*
// paramter.
void set_tail(Expression* expr, Expression_Node* expr_node) {
  expr->tail = expr_node;
}

// set_ptr() takes an Expression* and an Expression_Node*, and sets
// the Expression*'s value's ptr field equal to the Expression_Node*
// paramter.
void set_ptr(Expression* expr, Expression_Node* expr_node) {
  expr->ptr = expr_node;
}

// validate_semantics() takes an Expression* and verifies that it begins and
// ends with an operand and contains no NullOperation valued operators.
int validate_semantics(Expression* expr) {
  // If the expression is empty or begins with anything but an operand,
  // then it is invalid.
  if (expr == NULL || !is_operand(get_current_token(expr)))
    return 0;

  // Use this variable to determine whether to check for the presence of an
  // operand or an operator.
  int check_flag = 0;

  while (next_token(expr)) {
    // If the function detects a NullOperation valued operator, then the
    // expression is invalid.
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

// print_expression() takes an Expression* and prints its elements in order.
void print_expression(Expression* expr) {
  Expression_Node* temp_ptr = get_head(expr);
  
  while (temp_ptr) {
    print_token(get_expr(temp_ptr));
    temp_ptr = get_right_operand(temp_ptr);
  }
}
