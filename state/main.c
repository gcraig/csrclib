#include <stdio.h>
#include <stdlib.h>

#include "state.h"

/*
    gcc state.h state.c main.c -o main -std=c11 -Wall
*/

int 
main(int argc, char **argv)
{
	printf("Hello, world, creating a test State Machine\n");

	/*
        struct state *s = new_state(char state_name*)  vs.
        state_t *s = new_state("test");
    */

    /* Create the parent start state, name == 0 */
    state_t *s = new_state(NULL);

	printf( "%s\n", s->state_name );

	free_state_machine(s);
		
	return(0);
}
