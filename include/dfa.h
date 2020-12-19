/* dfa.h
 *
 * This file defines type DFA, which is a deterministic finite automaton.
 *
 */

#ifndef DFA_H
#define DFA_H

/* .................... */
/* DATA DEFINITIONS     */
/* .................... */

#include "dfa_state.h"

typedef struct
{
    DFA_State*  start_state;
}
DFA;

/* .................... */
/* FUNCTION DEFINITIONS */
/* .................... */

/* CONSTRUCTORS */
DFA*        init_dfa();

/* ACCESSORS    */
DFA_State*  get_start_state(DFA* dfa);
DFA_State** get_terminal_states(DFA* dfa);

/* MUTATORS     */
void        set_start_state(DFA* dfa);

/* VALIDATORS   */
int         is_member(DFA* dfa, char* word);

#endif
