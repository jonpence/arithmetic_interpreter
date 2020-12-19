/* dfa_transition.h
 *
 * This file defines type DFA_Transition, which is a deterministic finite
 * automaton state transition.
 *
 */

#ifndef DFA_TRANSITION_H
#define DFA_TRANSITION_H

#include <stdlib.h>

/* .................... */
/* DATA DEFINITIONS     */
/* .................... */

typedef struct DFA_State DFA_State;
typedef struct
{
    char       symbol;
    DFA_State* dest;
}
DFA_Transition;

/* .................... */
/* FUNCTION DEFINITIONS */
/* .................... */

/* CONSTRUCTORS */
DFA_Transition* init_dfa_transition(char init_symbol, DFA_State* init_dest);

/* ACCESSORS    */
char            get_symbol(DFA_Transition* dfa_transition);
DFA_State*      get_dest(DFA_Transition* dfa_transition);

/* MUTATORS     */
void            set_symbol(DFA_Transition* dfa_transition, char new_symbol);
void            set_dest(DFA_Transition* dfa_transition, DFA_State* new_dest);

/* VALIDATORS   */
int             is_transition_symbol(DFA_Transition* dfa_transition, char input_symbol);

#endif
