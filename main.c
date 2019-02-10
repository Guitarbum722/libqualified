#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "qual.h"

int 
main()
{
    // char *input = "\"Fir, ()st\",Middle,\"Phone , (home)\",Last";
    char *input = "First|Middle|\"Phone | (home)\"|Last";

    char sep = '|';
    char qual = '"';
    char *field;

    while ((field = strqsep(&input, sep, qual)) != NULL) {
        printf("field:    |%s\n", field);
    }
    free(field);
    return 0;
}
