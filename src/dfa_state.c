#include "dfa_state.h"

/* CONSTRUCTORS */
DFA_State* init_dfa_state(int init_terminal_flag, DFA_Map* init_next_states) {
    DFA_State* new_dfa_state = (DFA_State*) malloc(sizeof(DFA_State));

    set_terminal_flag(new_dfa_state, init_terminal_flag);
    set_next_states(new_dfa_state, init_next_states);

    return new_dfa_state;
}

/* ACCESSORS    */
int get_terminal_flag(DFA_State* dfa_state) {
    return dfa_state->terminal_flag;
}

DFA_Map* get_next_states(DFA_State* dfa_state) {
    return dfa_state->next_states;
}

/* MUTATORS     */
void set_terminal_flag(DFA_State* dfa_state, int new_terminal_flag) {
    dfa_state->terminal_flag = (new_terminal_flag != 0);
}

void set_next_states(DFA_State* dfa_state, DFA_Map* new_next_states) {
    dfa_state->next_states = new_next_states;
}

/* VALIDATORS   */
int is_terminal(DFA_State* dfa_state) {
    return get_terminal_flag(dfa_state) == 1;
}
