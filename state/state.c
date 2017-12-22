#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "state.h"

//
// Create the parent Start state
// Return NULL on memory error
//
state_t * new_parent_state(char * state_name) 
{
    /* XXX pass in states and link them up, prev and nexts */ 

    state_t *parent = (state_t *) malloc(sizeof(struct state));

	printf("Sizeof Parent (about 2kb): %i\n", sizeof(struct state) * 8);
	
    parent->ch_idx = 0;

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


//
// Create a child state of parent
// Adding to the inbound conditions and guards
//
state_t * new_child_state(char *state_name, state_t *parent) 
{
    /* XXX strcmp, chomp? */
    /* XXX create a common function both new state functions call */
//    if (NULL == parent || NULL == state_name || strcmp("", state_name))
//    {
//        return NULL; /* XXX error - how to handle? */
//    }
    
    state_t *child = (state_t *) malloc(sizeof(struct state));

	if (NULL != child) {

        /* assign the child to the parent's tracking array */
        //parent->children[0] = child;
        //parent->children[parent->chndx++] = child;
        //parent->children = ++child;
        parent->child = child;
        
        /* assign the child's name */
       	strcpy(child->state_name, state_name);
        printf("%s\n", child->state_name);
        printf("%s\n", state_name);

    } else {

        free(child);
    }

	return child;
}

void free_state(state_t *s) 
{
    free(s);
}
