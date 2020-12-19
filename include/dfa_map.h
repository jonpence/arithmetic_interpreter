/* dfa_map.h
 *
 * This file defines type DFA_Map, which is a deterministic finite automaton
 * transition map.
 *
 */

#ifndef DFA_MAP_H
#define DFA_MAP_H

#include "dfa_transition.h"

/* .................... */
/* DATA DEFINITIONS     */
/* .................... */

typedef struct
{
    size_t           num_transitions;
    DFA_Transition** transitions;
}
DFA_Map;

/* .................... */
/* FUNCTION DEFINITIONS */
/* .................... */

/* CONSTRUCTORS */
DFA_Map*         init_dfa_map();

/* ACCESSORS    */
size_t           get_num_transitions(DFA_Map* dfa_map);
DFA_Transition** get_transitions(DFA_Map* dfa_map);
DFA_State*       get_next_state(DFA_Map* dfa_map, char input_symbol);

/* MUTATORS     */
void             set_num_transitions(DFA_Map* dfa_map, size_t new_num_transitions);
void             set_transitions(DFA_Map* dfa_map, DFA_Transition** new_transitions);

#endif
