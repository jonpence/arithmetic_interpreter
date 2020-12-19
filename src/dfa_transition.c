#include "dfa_transition.h"

DFA_Transition* init_dfa_transition(char init_symbol, DFA_State* init_dest) {
    DFA_Transition* new_dfa_transition = (DFA_Transition*) malloc(sizeof(DFA_Transition));

    set_symbol(new_dfa_transition, init_symbol);
    set_dest(new_dfa_transition, init_dest);

    return new_dfa_transition;
}

char get_symbol(DFA_Transition* dfa_transition) {
    return dfa_transition->symbol;
}

DFA_State* get_dest(DFA_Transition* dfa_transition) {
    return dfa_transition->dest;
}

void set_symbol(DFA_Transition* dfa_transition, char new_symbol) {
    dfa_transition->symbol = new_symbol;
}

void set_dest(DFA_Transition* dfa_transition, DFA_State* new_dest) {
    dfa_transition->dest = new_dest;
}

int is_transition_symbol(DFA_Transition* dfa_transition, char input_symbol) {
    return get_symbol(dfa_transition) == input_symbol;
}
