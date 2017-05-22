#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "state.h"

state_t *
new_state(char *state_name) 
{
    /* TODO: pass in states and link them up, prev and nexts */ 
    
    // struct state * s = () malloc(sizeof(struct state));
    state_t * s = (state_t *) malloc(sizeof(struct state));

	if (NULL != s) {
        
        if (NULL == state_name)
        {
        	strcpy( s->state_name, "Initial Parent" );
        }

    } else {

        free(s);
    }

	return s;
}

int
free_state_machine(state_t *s) 
{
    free(s);
    return(0);
}