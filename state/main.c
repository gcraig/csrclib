#include <stdio.h>
#include <stdlib.h>

#include "state.h"

/*
    gcc state.h state.c main.c -o main -std=c11 -Wall
    cppcheck, splint
*/

//
// State Machine Test Harness
//
int main()
{
	printf("Hello, world!\nCreating a test State Machine.\n");

    /* Create the parent start state */
    state_t *parent = new_parent_state(NULL);
	State *s = new_parent_state(NULL);

    /* Create a child state of the parent/start state */
    state_t *child = new_child_state("Ordered", parent);

    printf("States created\n");
    printf("Parent           : 0x%x\n", &parent);
    printf("Child            : 0x%x\n", &child);
    printf("Parent state name: %s\n", parent->state_name);
    printf("Child state name : %s\n", child->state_name);
    printf("Child state      : %s\n", parent->child);

	//
	// ch_idx
	//
	
    /* or */
    /* XXX pointer arithmetic */
    /* XXX child is not being printed, why? */
    for (int i=0;i<255;i++)
    {
//        printf("%s\n", parent->children[i]->state_name);
    }
    
	//free_state(parent);
	free(child);
	free(parent);
}
