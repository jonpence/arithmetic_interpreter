#include <stdio.h>
#include "dfa_map.h"

void test_init_dfa_map() {
    printf("Testing dfa_map()...\n");

    DFA_Map* test_dfa_map = init_dfa_map();

    if (test_dfa_map) {
        printf("...dfa_map() PASS\n\n");
    } else {
        printf("...dfa_map() FAIL\n\n");
    }
}

void test_get_num_transitions() {
    printf("Testing get_num_transitions()...\n");

    DFA_Map* test_dfa_map = init_dfa_map();
    test_dfa_map->num_transitions = 999;

    if (get_num_transitions(test_dfa_map) == 999) {
        printf("...get_num_transitions() PASS\n\n");
    } else {
        printf("...get_num_transitions() FAIL\n\n");
    }
}

void test_get_transitions() {
    printf("Testing get_transitions()...\n");

    DFA_Map* test_dfa_map = init_dfa_map();
    DFA_Transition** test_dfa_transitions = (DFA_Transition**) malloc(sizeof(DFA_Transition*));

    test_dfa_map->transitions = test_dfa_transitions;

    if (get_transitions(test_dfa_map) == test_dfa_transitions) {
        printf("...get_transitions() PASS\n\n");
    } else {
        printf("...get_transitions() FAIL\n\n");
    }
}

void test_get_next_state() {
    printf("Testing get_next_state()...\n");

    // TODO Finish implementing

    if (0) {
        printf("...get_next_state() PASS\n\n");
    } else {
        printf("...get_next_state() FAIL\n\n");
    }
}

void test_set_num_transitions() {
    printf("Testing set_num_transitions()...\n");

    DFA_Map* test_dfa_map = init_dfa_map();
    set_num_transitions(test_dfa_map, 999);

    if (test_dfa_map->num_transitions == 999) {
        printf("...set_num_transitions() PASS\n\n");
    } else {
        printf("...set_num_transitions() FAIL\n\n");
    }
}

void test_set_transitions() {
    printf("Testing set_transitions()...\n");

    DFA_Map* test_dfa_map = init_dfa_map();
    DFA_Transition** test_dfa_transitions = (DFA_Transition**) malloc(sizeof(DFA_Transition*));

    set_transitions(test_dfa_map, test_dfa_transitions);

    if (test_dfa_map->transitions == test_dfa_transitions) {
        printf("...set_transitions() PASS\n\n");
    } else {
        printf("...set_transitions() FAIL\n\n");
    }
}

int main() {

    test_init_dfa_map();
    test_get_num_transitions();
    test_get_transitions();
    test_get_next_state();
    test_set_num_transitions();
    test_set_transitions();

    return 0;
}
