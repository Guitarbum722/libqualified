#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "qual.h"

int 
main()
{
    char *field, *input, *tofree;

    tofree = input = strdup("\"asd,|,|f\"|First|Middle|\"Phone | (home)\"|Last");

    char sep = '|';
    char qual = '"';

    while ((field = strqsep(&input, sep, qual)) != NULL) {
        printf("field:    |%s\n", field);
    }
    free(tofree);
    return 0;
}
