#ifndef STATE_H
#define STATE_H

/*#pragma once*/

#include <stddef.h>

typedef struct state state_t; /* convention xxx_t */
typedef struct state state;   
typedef struct state State;   

static struct state {
	char 		state_name[255]; /* = NULL;*/
    int			ch_idx; /* child index */
	state_t 	*child; /* child state_t */
    state_t 	*next_state; 
    state_t 	*prev_state;
    state_t 	**out_states;
    state_t 	**in_states;
};

//
// parent = state_new("parent", NULL);
// child  = state_new("child",  parent);
// state_free(child);
//
// new/free			Memory allocation
// init/destroy		Non-memory allocation
//
// State	=	newState()/freeState()
// state	=	state_new()/state_free()
//

extern state_t *new_parent_state(char *state_name);

state_t *new_child_state(char *state_name, state_t *parent); /* returns NULL on out of memory */

void free_state(state_t *s); /* goes through entire linked list freeing all memory */

#endif /* STATE_H */
