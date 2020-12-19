#include "expression_tree.h"

// init_tree() manually allocates a new Expression_Tree and returns
// a pointer to it.
Expression_Tree* init_tree() {
    Expression_Tree* new_tree = (Expression_Tree*)malloc(sizeof(Expression_Tree));

    new_tree->result = 0;

    return new_tree;
}

// recursively_parse() takes an Expression* and parses its nodes into a syntax
// tree.
Expression_Node* recursively_parse(Expression* expr) {
    // If the expression's first and last elements are the
    // same, then it is an operand that we simply return.
    if (get_head(expr) == get_tail(expr))
        return get_head(expr);

    // asc_priorities defines the precedence of the Operator enums.
    Operator asc_priorities[] = { Subtraction, Addition, Division, Multiplication };

    // Iterate through all possible operators.
    for (size_t i = 0; i < NUM_OPS - 1; i++) {

        // Set the expression's pointer to be equal to its tail as we iterate
        // backwards.
        set_ptr(expr, get_tail(expr));

        // Do...
        do {
            // If the value of the node is an operator that we're currently checking for, then...
            if (is_operator(get_current_token(expr)) && get_operator(get_current_token(expr)) == asc_priorities[i]) {
                // Set this (sub-)tree's root equal to that operator node.
                Expression_Node* root = get_ptr(expr);

                // Recursively parse the left and right operands of our operator
                // root.
                Expression* left_expr = subexpr(get_head(expr), get_left_operand(get_ptr(expr)));
                Expression* right_expr = subexpr(get_right_operand(get_ptr(expr)), get_tail(expr));

                root->left_operand = recursively_parse(left_expr);
                root->right_operand = recursively_parse(right_expr);

                // Return the root.
                return root;
            }
        // ...while there are nodes to iterate backward through.
        } while (prev_token(expr));
    }

    return NULL;
}

// parse_expr_to_tree() takes an Expression* and creates a new Expression_Tree
// from recursively parsing the Expression*, and returns a pointer to it.
Expression_Tree* parse_expr_to_tree(Expression* expr) {
    Expression_Tree* new_tree = init_tree();

    set_expression(new_tree, expr);
    set_root(new_tree, recursively_parse(get_expression(new_tree)));
    set_result(new_tree, evaluate(new_tree));

    return new_tree;
}

// recursively_evaluate() takes an Expression_Node* which is a root of an
// Expression_Tree*, and finds the result of evaluating that tree's expression
// according to an order of operations which defined how the tree
// was parsed.
int recursively_evaluate(Expression_Node* root) {
    // If we have an operand, just return its int value.
    if (is_operand(get_expr(root)))
        return get_operand(get_expr(root));

    // Recursively parse the root's left and right operands.
    int left_val = recursively_evaluate(get_left_operand(root));
    int right_val = recursively_evaluate(get_right_operand(root));

    // Take the Operator enum value of our root, and perform some
    // arithmetic operation on left_val and right_val based on upon
    // the Operator value.
    switch(get_operator(get_expr(root))) {
        case Division:
            return left_val / right_val;
        case Multiplication:
            return left_val * right_val;
        case Addition:
            return left_val + right_val;
        case Subtraction:
            return left_val - right_val;
        case NullOperation:
            return 0;
    }
}

// evaluate() takes an Expression_Tree* and calls recursively_evaluate()
// on that tree's root.
int evaluate(Expression_Tree* expr_tree) {
    return recursively_evaluate(get_root(expr_tree));
}

// get_expression() takes an Expression_Tree* and returns its value's expr field.
Expression* get_expression(Expression_Tree* expr_tree) {
    return expr_tree->expr;
}

// get_root() takes an Expression_Tree* and returns its value's root field.
Expression_Node* get_root(Expression_Tree* expr_tree) {
    return expr_tree->root;
}

// get_result() takes an Expression_Tree* and returns its value's result field.
int get_result(Expression_Tree* expr_tree) {
    return expr_tree->result;
}

// set_expression() takes an Expression_Tree* and an Expression*, and sets the
// expr field of the Expression_Tree*'s value to the Expression* parameter.
void set_expression(Expression_Tree* expr_tree, Expression* expr) {
    expr_tree->expr = expr;
}

// set_root() takes an Expression_Tree* and an Expression_Node*, and sets the
// root field of the Expression_Tree*'s value to the Expression_Node* parameter.
void set_root(Expression_Tree* expr_tree, Expression_Node* expr_node) {
    expr_tree->root = expr_node;
}

// set_result() takes an Expression_Tree* and an int, and sets the
// result field of the Expression_Tree*'s value to the int parameter.
void set_result(Expression_Tree* expr_tree, int result) {
    expr_tree->result = result;
}

// recursively_print() takes an Expression_Node*, which is the root of some
// Expression_Tree, and recursively prints the Expression_Tree.
void recursively_print(Expression_Node* root) {
    if (is_operand(get_expr(root))) {
        // If the root is just some operand, print a string of its int value.
        printf("%d", get_operand(get_expr(root)));
    } else {
        // If we're on a new operator root, then begin by printing a '(', then...
        printf("(");

        // ...recursively print its left operand, then...
        recursively_print(get_left_operand(root));

        // ...print the character symbol of the root's Operator value, then...
        printf(" %s ", op_to_symbol(get_operator(get_expr(root))));

        // ...recursively print its right operand, then...
        recursively_print(get_right_operand(root));

        // ...terminate with a ')'.
        printf(")");
    }
}

// print_expression_tree() takes an Expression_Tree* and calls recursively_print()
// on the root of the Expression_Tree*'s value.
void print_expression_tree(Expression_Tree* expr_tree) {
    recursively_print(get_root(expr_tree));
}
