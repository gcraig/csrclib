#ifndef STATE_H
#define STATE_H

/*#pragma once*/

#include <stddef.h>

/* Declarations and Initializations */

typedef struct state state_t; /* convention xxx_t */

//typedef struct state *state_t; /* convention xxx_t */

struct state
{
	char state_name[255]; /* = NULL;*/

    state_t *children[255];

    int chndx;

    state_t *next_state; 
    state_t *prev_state;

    state_t **out_states;
    state_t **in_states;

};

/* Prototypes */

state_t *new_parent_state(char *state_name);

state_t *new_child_state(char *state_name, state_t *parent); /* returns NULL on out of memory */

void free_state_machine(state_t *s); /* goes through entire linked list freeing all memory */

#endif /* STATE_H */
