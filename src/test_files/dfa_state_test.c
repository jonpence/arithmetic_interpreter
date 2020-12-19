#include <stdio.h>
#include "dfa_state.h"

void test_init_dfa_state()
{
    printf("Testing init_dfa_state()...\n");

    DFA_State* test_dfa_state = init_dfa_state(0, NULL);

    if (test_dfa_state) {
        printf("...init_dfa_state() PASS\n\n");
    } else {
        printf("...init_dfa_state() FAIL\n\n");
    }
}

void test_get_terminal_flag()
{
    printf("Testing get_terminal_flag()...\n");

    DFA_State* test_dfa_state = init_dfa_state(999, NULL);

    if (get_terminal_flag(test_dfa_state) == 1) {
        printf("...get_terminal_flag() PASS\n\n");
    } else {
        printf("...get_terminal_flag() FAIL\n\n");
    }
}

void test_get_next_states()
{
    printf("Testing get_next_states()...\n");

    DFA_Map* test_dfa_map = (DFA_Map*) malloc(sizeof(DFA_Map));
    DFA_State* test_dfa_state = init_dfa_state(0, test_dfa_map);

    if (get_next_states(test_dfa_state) == test_dfa_map) {
        printf("...get_next_states() PASS\n\n");
    } else {
        printf("...get_next_states() FAIL\n\n");
    }
}

void test_set_terminal_flag()
{
    printf("Testing set_terminal_flag()...\n");

    DFA_State* test_dfa_state = init_dfa_state(0, NULL);
    set_terminal_flag(test_dfa_state, 1);

    if (get_terminal_flag(test_dfa_state) == 1) {
        printf("...set_terminal_flag() PASS\n\n");
    } else {
        printf("...set_terminal_flag() FAIL\n\n");
    }
}

void test_set_next_states()
{
    printf("Testing set_next_states()...\n");

    DFA_Map* test_dfa_map1 = (DFA_Map*) malloc(sizeof(DFA_Map));
    DFA_Map* test_dfa_map2 = (DFA_Map*) malloc(sizeof(DFA_Map));

    DFA_State* test_dfa_state = init_dfa_state(0, test_dfa_map1);

    set_next_states(test_dfa_state, test_dfa_map2);

    if (get_next_states(test_dfa_state) == test_dfa_map2) {
        printf("...get_next_states() PASS\n\n");
    } else {
        printf("...get_next_states() FAIL\n\n");
    }
}

void test_is_terminal()
{
    printf("Testing is_terminal()...\n");

    DFA_State* test_dfa_state = init_dfa_state(1, NULL);

    if (is_terminal(test_dfa_state)) {
        printf("...is_terminal() PASS\n\n");
    } else {
        printf("...is_terminal() FAIL\n\n");
    }
}

int main()
{
    test_init_dfa_state();
    test_get_terminal_flag();
    test_get_next_states();
    test_set_terminal_flag();
    test_set_next_states();
    test_is_terminal();

    return 0;
}
