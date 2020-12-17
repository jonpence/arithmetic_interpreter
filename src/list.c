#include "list.h"

List* init_list(size_t capacity) {
    List* new_list = (List*) malloc(sizeof(List));

    set_capacity(new_list, capacity);
    set_size(new_list, 0);

    new_list->array = (Expression_Tree**) malloc(sizeof(Expression_Tree*) * get_capacity(new_list));

    return new_list;
}

Expression_Tree* at(List* list, size_t i) {
    return list->array[i];
}

size_t get_capacity(List* list) {
    return list->capacity;
}

size_t get_size(List* list) {
    return list->size;
}

void set_capacity(List* list, size_t capacity) {
    list->capacity = capacity;
}

void set_size(List* list, size_t size) {
    list->size = size;
}

void append(List* list, Expression_Tree* obj) {
    if (get_capacity(list) == get_size(list)) {
        size_t new_capacity = get_capacity(list) * 2;
        Expression_Tree** new_arr = (Expression_Tree**) malloc(sizeof(Expression_Tree*) * new_capacity);
        set_capacity(list, new_capacity);

        for (size_t i = 0; i < get_size(list); i++) {
            new_arr[i] = list->array[i];
        }

        Expression_Tree** temp = list->array;
        list->array = new_arr;
        free(temp);
    }

    list->array[get_size(list)] = obj;
    set_size(list, get_size(list) + 1);
}

int is_empty(List* list) {
    return get_size(list) == 0;
}

void print_all_items(List* list) {
    if (is_empty(list)) {
        printf("No items in the table!\n\n");
    } else {
        for (size_t i = 0; i < get_size(list); i++) {
            printf("id: %d\n", i);
            print_expression_tree(at(list, i));
            printf("\nResult: %d\n\n", get_result(at(list, i)));
        }
    }
}
