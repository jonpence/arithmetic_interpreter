#include "expression_tree.h"

Expression_Tree* init_tree() {
    Expression_Tree* new_tree = (Expression_Tree*)malloc(sizeof(Expression_Tree));

    new_tree->result = 0;

    return new_tree;
}

Expression_Node* recursively_parse(Expression* expr) {
    if (get_head(expr) == get_tail(expr))
        return get_head(expr);

    Operator asc_priorities[] = { Subtraction, Addition, Division, Multiplication };
    for (size_t i = 0; i < NUM_OPS - 1; i++) {
        set_ptr(expr, get_tail(expr));
        do {
            if (is_operator(get_current_token(expr)) && get_operator(get_current_token(expr)) == asc_priorities[i]) {
                Expression_Node* root = get_ptr(expr);

                Expression* left_expr = subexpr(get_head(expr), get_left_operand(get_ptr(expr)));
                Expression* right_expr = subexpr(get_right_operand(get_ptr(expr)), get_tail(expr));

                root->left_operand = recursively_parse(left_expr);
                root->right_operand = recursively_parse(right_expr);

                return root;
            }
        } while (prev_token(expr));
    }

    return NULL;
}

Expression_Tree* parse_expr_to_tree(Expression* expr) {
    Expression_Tree* new_tree = init_tree();

    set_expression(new_tree, expr);
    set_root(new_tree, recursively_parse(get_expression(new_tree)));
    set_result(new_tree, evaluate(new_tree));

    return new_tree;
}

int recursively_evaluate(Expression_Node* root) {
    if (is_operand(get_expr(root)))
        return get_operand(get_expr(root));

    int left_val = recursively_evaluate(get_left_operand(root));
    int right_val = recursively_evaluate(get_right_operand(root));

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

int evaluate(Expression_Tree* expr_tree) {
    return recursively_evaluate(get_root(expr_tree));
}

Expression* get_expression(Expression_Tree* expr_tree) {
    return expr_tree->expr;
}

Expression_Node* get_root(Expression_Tree* expr_tree) {
    return expr_tree->root;
}

int get_result(Expression_Tree* expr_tree) {
    return expr_tree->result;
}

void set_expression(Expression_Tree* expr_tree, Expression* expr) {
    expr_tree->expr = expr;
}

void set_root(Expression_Tree* expr_tree, Expression_Node* expr_node) {
    expr_tree->root = expr_node;
}

void set_result(Expression_Tree* expr_tree, int result) {
    expr_tree->result = result;
}

void recursively_print(Expression_Node* root) {
    if (is_operand(get_expr(root))) {
        printf("%d", get_operand(get_expr(root)));
    } else {
        printf("(");
        recursively_print(get_left_operand(root));
        printf(" %s ", op_to_symbol(get_operator(get_expr(root))));
        recursively_print(get_right_operand(root));
        printf(")");
    }
}

void print_expression_tree(Expression_Tree* expr_tree) {
    recursively_print(get_root(expr_tree));
}
