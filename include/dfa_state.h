/* dfa_state.h
 *
 * This file defines type DFA_State, which is a deterministic finite automaton
 * state.
 *
 */

#ifndef DFA_STATE_H
#define DFA_STATE_H

#include <stdlib.h>
#include "dfa_map.h"

/* .................... */
/* DATA DEFINITIONS     */
/* .................... */

struct DFA_State
{
    int      terminal_flag;
    DFA_Map* next_states;
};

/* .................... */
/* FUNCTION DEFINITIONS */
/* .................... */

/* CONSTRUCTORS */
DFA_State* init_dfa_state(int init_terminal_flag, DFA_Map* init_next_states);

/* ACCESSORS    */
int        get_terminal_flag(DFA_State* dfa_state);
DFA_Map*   get_next_states(DFA_State* dfa_state);

/* MUTATORS     */
void       set_terminal_flag(DFA_State* dfa_state, int new_terminal_flag);
void       set_next_states(DFA_State* dfa_state, DFA_Map* new_next_states);

/* VALIDATORS   */
int        is_terminal(DFA_State* dfa_state);

#endif
