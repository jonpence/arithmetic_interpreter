#include <stdio.h>
#include "list.h"

void test_init_list() {
  printf("Testing init_list()...\n");

  List* test_list = init_list(2);

  if (get_capacity(test_list) == 2)
    printf("...init_list() PASS\n\n");
  else
    printf("...init_list() FAIl\n\n");
}

void test_is_empty() {
  printf("Testing is_empty()...\n");

  List* test_list = init_list(2);

  if (is_empty(test_list))
    printf("...is_empty() PASS\n\n");
  else
    printf("...is_empty() FAIL\n\n");
}

void test_append() {
  printf("Testing append()...\n");

  List* test_list = init_list(2);
  Expression_Tree* test_tree1 = init_tree();
  Expression_Tree* test_tree2 = init_tree();
  Expression_Tree* test_tree3 = init_tree();
  Expression_Tree* test_tree4 = init_tree();

  append(test_list, test_tree1);
  append(test_list, test_tree2);
  append(test_list, test_tree3);
  append(test_list, test_tree4);

  if (get_size(test_list) ==  get_capacity(test_list))
    printf("...append() PASS\n\n");
  else
    printf("...append() FAIL\n\n");
}

void test_at() {
  printf("Testing at()...\n");

  List* test_list = init_list(2);
  Expression_Tree* test_tree1 = init_tree();
  Expression_Tree* test_tree2 = init_tree();
  Expression_Tree* test_tree3 = init_tree();
  Expression_Tree* test_tree4 = init_tree();

  append(test_list, test_tree1);
  append(test_list, test_tree2);
  append(test_list, test_tree3);
  append(test_list, test_tree4);

  if (at(test_list, 0) == test_tree1 && at(test_list, 1) == test_tree2 && at(test_list, 2) == test_tree3 && at(test_list, 3) == test_tree4)
    printf("...at() PASS\n\n");
  else
    printf("...at() FAIL\n\n");
}


int main() {

    test_init_list();
    test_is_empty();
    test_append();
    test_at();

    return 0;
}
