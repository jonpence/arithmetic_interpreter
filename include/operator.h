/* operator.h
 *
 * This file defines an enum Operator for use in struct Expression_Token.
 *
 */

#ifndef OPERATOR_H
#define OPERATOR_H

#define NUM_OPS 5

/* .................... */
/* DATA DEFINITIONS     */
/* .................... */

typedef enum {
  NullOperation,
  Multiplication,
  Division,
  Addition,
  Subtraction
} Operator;

/* .................... */
/* FUNCTION DEFINITIONS */
/* .................... */

char* op_to_string(Operator op);
char* op_to_symbol(Operator op);

int is_null_operator(Operator op);

#endif
