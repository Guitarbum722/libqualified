#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "qual.h"

int 
main()
{
    char *field, *input, *tofree;

    tofree = input = strdup("Don|K|\"Moby, M.D.\"|don.moby@nothing.com");

    while ((field = strqsep(&input, "|", "\"")) != NULL) {
        printf("%s\n", field);
    }
    free(tofree);
    return 0;
}
