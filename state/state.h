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

    state_t *next_state; 

    state_t *prev_state;

    state_t **out_states;

    state_t **in_states;

};

/* Prototypes */

// struct state *new_state(char *state_name);
state_t *new_state(char *state_name); /* returns NULL on out of memory */

int free_state_machine(state_t*); /* goes through entire linked list freeing all memory */

#endif /* STATE_H */


/*

http://stackoverflow.com/questions/10243149/why-is-typedef-struct-foo-foo-considered-harmful

typedef struct
{
  //...
}              t_mytype;
//...
t_mytype thing;

*/