#include <stdio.h>

#include "dfa_transition.h"
#include "dfa_state.h"

void test_init_dfa_transition() {
    printf("Testing init_dfa_transition()...\n");

    DFA_Transition* test_dfa_transition = init_dfa_transition('a', NULL);

    if (test_dfa_transition) {
        printf("...init_dfa_transition() PASS\n\n");
    } else {
        printf("...init_dfa_transition() FAIL\n\n");
    }
}

void test_get_symbol() {
    printf("Testing get_symbol()...\n");

    DFA_Transition* test_dfa_transition = init_dfa_transition('a', NULL);

    if (get_symbol(test_dfa_transition) == 'a') {
        printf("...get_symbol() PASS\n\n");
    } else {
        printf("...get_symbol() FAIL\n\n");
    }
}

void test_get_dest() {
    printf("Testing get_dest()...\n");

    DFA_Transition* test_dfa_transition = init_dfa_transition('a', (DFA_State*) malloc(sizeof(DFA_State)));

    if (get_dest(test_dfa_transition)) {
        printf("...get_dest() PASS\n\n");
    } else {
        printf("...get_dest() FAIL\n\n");
    }
}

void test_set_symbol() {
    printf("Testing set_symbol()...\n");

    DFA_Transition* test_dfa_transition = init_dfa_transition('a', NULL);
    set_symbol(test_dfa_transition, 'b');

    if (test_dfa_transition->symbol == 'b') {
        printf("...set_symbol() PASS\n\n");
    } else {
        printf("...set_symbol() FAIL\n\n");
    }
}

void test_set_dest() {
    printf("Testing set_dest()...\n");

    DFA_Transition* test_dfa_transition = init_dfa_transition('a', (DFA_State*) malloc(sizeof(DFA_State)));
    DFA_State* test_dfa_state = (DFA_State*) malloc(sizeof(DFA_State));
    set_dest(test_dfa_transition, test_dfa_state);

    if (test_dfa_transition->dest == test_dfa_state) {
        printf("...set_dest() PASS\n\n");
    } else {
        printf("...set_dest() FAIL\n\n");
    }
}

void test_is_transition_symbol() {
    printf("Testing is_transitioni_symbol()...\n");

    DFA_Transition* test_dfa_transition = init_dfa_transition('a', (DFA_State*) malloc(sizeof(DFA_State)));

    if (is_transition_symbol(test_dfa_transition, 'a')) {
        printf("...is_transition_symbol() PASS\n\n");
    } else {
        printf("...is_transition_symbol() FAIL\n\n");
    }
}


int main() {

    test_init_dfa_transition();
    test_get_symbol();
    test_get_dest();
    test_set_symbol();
    test_set_dest();
    test_is_transition_symbol();

    return 0;
}
