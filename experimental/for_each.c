#include <stdio.h>

void 
for_each(char *p)
{
    for (int i = 0; i < 3; i++ )
    {
        printf("%c\n", *p);
        p++;
    }
}

int 
main() 
{
    printf("For_each, pointer arithmetic; macros next\n");

    char collection[] = { 'g', 'e', 'o' };

    char *ptr;

    ptr = collection;

    //char *ptr = &collection[0];

    for_each(ptr /*. callback_function_ptr */);
}
