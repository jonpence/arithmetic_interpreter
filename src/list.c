#include "list.h"

// init_list() takes a size_t, which specifies the initial holding capacity
// of the array dynamically allocated within the function body. It then
// manually allocates space for the List struct, and its array field, and
// returns the List pointer.
List* init_list(size_t capacity) {
    List* new_list = (List*) malloc(sizeof(List));

    set_capacity(new_list, capacity);
    set_size(new_list, 0);

    new_list->array = (Expression_Tree**) malloc(sizeof(Expression_Tree*) * get_capacity(new_list));

    return new_list;
}

// at() takes a list and a size_t i, and returns the element at index i
// of the list's array field.
Expression_Tree* at(List* list, size_t i) {
    return list->array[i];
}

// get_capacity() takes a list and returns its capacity.
size_t get_capacity(List* list) {
    return list->capacity;
}

// get_size() takes a list and returns its size.
size_t get_size(List* list) {
    return list->size;
}

// set_capacity() takes a list and a size_t capacity, and sets the list's
// capacity to the input parameter capacity.
void set_capacity(List* list, size_t capacity) {
    list->capacity = capacity;
}

// set_size() takes a list and a size_t size, and sets the list's
// size to the input parameter size.
void set_size(List* list, size_t size) {
    list->size = size;
}

// append() takes a list and an Expression_Tree pointer, and then attempts to
// place that pointer to the end of the array field of the list. If the list
// is already full, then create a new array of double the old capacity,
// copy over all the elements, and then perform the append operation.
void append(List* list, Expression_Tree* obj) {
    // If the list's array is already full, then create a new array at double
    // the list's capacity and copy over all of the elements from the old array.
    // Then update the list's capacity field.
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

// is_empty() takes a list and returns an integer corresponding to the boolean
// case of whether or not the list's size is equal to 0.
int is_empty(List* list) {
    return get_size(list) == 0;
}

// print_all_items() takes a list, and iterates (from 0 to list.size) through
// the elements of its array field, each time printing the index and calling
// the Expression_Tree* print_expression_tree() function on the element at
// each index.
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
