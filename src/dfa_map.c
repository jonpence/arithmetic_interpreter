#include "dfa_map.h"

DFA_Map* init_dfa_map()
{
    return (DFA_Map*) malloc(sizeof(DFA_Map));
}

size_t get_num_transitions(DFA_Map* dfa_map)
{
    return dfa_map->num_transitions;
}

DFA_Transition** get_transitions(DFA_Map* dfa_map)
{
    return dfa_map->transitions;
}

DFA_State* get_next_state(DFA_Map* dfa_map, char input_symbol)
{
    for (size_t i = 0; i < get_num_transitions(dfa_map); i++) {
        if (is_transition_symbol(get_transitions(dfa_map)[i], input_symbol)) {
            return get_dest(get_transitions(dfa_map)[i]);
        }
    }

    return NULL;
}

void set_num_transitions(DFA_Map* dfa_map, size_t new_num_transitions)
{
    dfa_map->num_transitions = new_num_transitions;
}

void set_transitions(DFA_Map* dfa_map, DFA_Transition** new_transitions)
{
    dfa_map->transitions = new_transitions;
}
