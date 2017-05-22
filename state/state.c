#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "state.h"

/*
 * Create the parent Start state
 * Return NULL on malloc error
 */
state_t *
new_parent_state(char *state_name) 
{
    /* XXX pass in states and link them up, prev and nexts */ 
    /* struct state = typedef struct state state_t */

    state_t *parent = (state_t *) malloc(sizeof(struct state));

    parent->chndx = 0;

	if (NULL != parent) {
        
        if (NULL == state_name)
        {
        	strcpy(parent->state_name, "Start");
        }

    } else {

        free(parent);
    }

	return parent;
}


/*
 * Create a child state of parent
 * Adding to the inbound conditions and guards
 */
state_t *
new_child_state(char *state_name, state_t *parent) 
{
    /* XXX strcmp, chomp? */
    /* XXX create a common function both new state functions call */
    if (NULL == parent || NULL == state_name || strcmp("", state_name))
    {
        return NULL; /* XXX error - how to handle? */
    }
    
    state_t *child = (state_t *) malloc(sizeof(struct state));

	if (NULL != child) {

        /* assign the child to the parent's tracking array */
        parent->children[parent->chndx++] = child;
        
        /* assign the child's name */
       	strcpy(child->state_name, state_name);

    } else {

        free(child);
    }

	return child;
}

void
free_state_machine(state_t *s) 
{
    free(s);
}