/* list.h
 *
 * This file defines a list data structure, which is simply a dynamically resizing array.
 *
 */

#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#include "expression_tree.h"

typedef struct {
    size_t capacity;
    size_t size;

    Expression_Tree** array;
} List;

List* init_list(size_t capacity);

Expression_Tree* at(List* list, size_t i);
size_t get_capacity(List* list);
size_t get_size(List* list);

void set_capacity(List* list, size_t size);
void set_size(List* list, size_t size);

void append(List* list, Expression_Tree* obj);

int is_empty(List* list);

void print_all_items(List* list);

#endif
